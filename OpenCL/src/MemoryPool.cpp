#include "MemoryPool.h"

MemoryPool::MemoryPool(int poolSize, int granularity)
{
    this->poolSize = poolSize;
    this->granularity = granularity;
    this->memoryUsed = 0;
}

int MemoryPool::getPoolSize()
{
    return this->poolSize;
}

void MemoryPool::addUsed(char* id, int allocationSize)
{
    this->allocations.insert(pair<char*,int>(id, allocationSize));
    int realSize = ((allocationSize + this->granularity - 1) / this->granularity) * this->granularity;
    this->memoryUsed += realSize;
}

int MemoryPool::freeUsed(char* id)
{
    int allocationSize = allocations[id];
    this->allocations.erase(id);
    int realSize = ((allocationSize + this->granularity - 1) / this->granularity) * this->granularity;
    this->memoryUsed -= realSize;
    return allocationSize;
}

int MemoryPool::getMemoryUsed()
{
    return this->memoryUsed;
}

bool MemoryPool::canAllocate(int allocationSize)
{
    int realSize = ((allocationSize + this->granularity - 1) / this->granularity) * this->granularity;
    return (realSize <= (this->poolSize - this->memoryUsed));
}

bool MemoryPool::hasAllocation(char* id)
{
    return (this->allocations.find(id) != allocations.end());
}