#ifndef ALLOCATORSTATUS_H
#define ALLOCATORSTATUS_H

#include "AllocatorInfo.h"
#include "MemoryPool.h"
#include <list>

using namespace std;

class AllocatorStatus
{
    public:
        AllocatorStatus(AllocatorInfo info);
        void addAllocation(char* id, int allocationSize);
        void removeAllocation(char* id);
        int getTotalMemoryReserved();
        int getMaximumMemoryReserved();
        int getMaximumUserMemory();
        void printStatus();
        void printMaximum();

    private:
        int poolSize;
        int granularity;
        int largeGranularity;
        int totalUserMemory;
        int maximumMemoryReserved;
        int maximumUserMemory;
        list<MemoryPool> memoryPools;
};

#endif
