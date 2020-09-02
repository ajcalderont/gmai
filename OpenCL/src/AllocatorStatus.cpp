#include <stdio.h>
#include "AllocatorStatus.h"

AllocatorStatus::AllocatorStatus(AllocatorInfo info)
{
    this->poolSize = info.poolSize;
    this->granularity = info.granularity;
    this->largeGranularity = info.largerMultiple;
    this->totalUserMemory = 0; 
    this->maximumMemoryReserved = 0;
}

void AllocatorStatus::addAllocation(char* id, int allocationSize)
{
    bool newPool = true;
    for(list<MemoryPool>::iterator i = this->memoryPools.begin(); i != this->memoryPools.end(); ++i)
    {
        if(i->canAllocate(allocationSize))
        {
            i->addUsed(id, allocationSize);
            newPool = false;
            break;
        }
    }
    
    if(newPool)
    {
        int newPoolSize;
        if(allocationSize > this->poolSize)
            newPoolSize = ((allocationSize + this->largeGranularity - 1) / this->largeGranularity) * this->largeGranularity;
        else
            newPoolSize = this->poolSize;
        
        MemoryPool pool(newPoolSize, this->granularity);
        pool.addUsed(id, allocationSize);
        this->memoryPools.push_front(pool);
    }

    this->totalUserMemory += allocationSize;
    int currentTotal = this->getTotalMemoryReserved();
    if(currentTotal >= this->maximumMemoryReserved)
    {
        this->maximumMemoryReserved = currentTotal;
        this->maximumUserMemory = this->totalUserMemory;
    }
}

void AllocatorStatus::removeAllocation(char* id)
{
    int allocationSize = 0;
    for(list<MemoryPool>::iterator i = this->memoryPools.begin(); i != this->memoryPools.end(); ++i)
    {
        if(i->hasAllocation(id))
        {
            allocationSize = i->freeUsed(id);
            break;
        }
    }
    this->totalUserMemory -= allocationSize;
}

int AllocatorStatus::getTotalMemoryReserved()
{
    int totalMemoryReserved = 0;
    for(list<MemoryPool>::iterator i = this->memoryPools.begin(); i != this->memoryPools.end(); ++i)
    {
        totalMemoryReserved += i->getPoolSize();
    }
    return totalMemoryReserved;
}

int AllocatorStatus::getMaximumMemoryReserved()
{
    return this->maximumMemoryReserved;
}

int AllocatorStatus::getMaximumUserMemory()
{
    return this->maximumUserMemory;
}

void AllocatorStatus::printStatus()
{
    int totalMemoryReserved = this->getTotalMemoryReserved();
    int totalMemoryUsed = 0;
    for(list<MemoryPool>::iterator i = this->memoryPools.begin(); i != this->memoryPools.end(); ++i)
    {
        totalMemoryUsed += i->getMemoryUsed();
    }
    
    float percentageUsed = totalMemoryReserved > 0? (totalMemoryUsed/(float)totalMemoryReserved) * 100 : 0;
    float factor = this->totalUserMemory > 0? (totalMemoryReserved / (float)this->totalUserMemory) : 0;
    fprintf(stderr, "Total memory reserved by user: %d bytes\n", this->totalUserMemory);
    fprintf(stderr, "Total memory reserved by allocator: %d bytes (%.1fx the amount requested by user)\n", totalMemoryReserved, factor);
    fprintf(stderr, "Total memory used : %d bytes (%.1f%% of the memory reserved by allocator)\n\n", totalMemoryUsed, percentageUsed);
}

void AllocatorStatus::printMaximum()
{
    int maxUserMemory = this->getMaximumUserMemory();
    if(maxUserMemory > 0)
    {
        int maxMemoryReserved = this->getMaximumMemoryReserved();
        float factor = maxMemoryReserved / (float)maxUserMemory;
        fprintf(stderr, "Maximum memory requested by user: %d bytes\n", maxUserMemory);
        fprintf(stderr, "Maximum memory reserved by allocator: %d bytes (%.1fx the amount requested by user)\n\n", maxMemoryReserved, factor);
    }
}