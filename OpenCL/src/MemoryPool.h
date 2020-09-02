#ifndef MEMORYPOOL_H
#define MEMORYPOOL_H

#include <map>

using namespace std;

class MemoryPool
{
    public:
        MemoryPool(int poolSize, int granularity);
        int getPoolSize();
        void addUsed(char* id, int allocationSize);
        int freeUsed(char* id);
        int getMemoryUsed();
        bool canAllocate(int allocationSize);
        bool hasAllocation(char* id);

    private:
        int poolSize;
        int granularity;
        int memoryUsed;
        map<char*,int> allocations;
};

#endif
