#ifndef ALLOCATORINFO_H
#define ALLOCATORINFO_H

class AllocatorInfo
{
    public:
        AllocatorInfo(const char* fileName);
        char deviceName[20];
        char driverVersion[10];
        char policy[20];
        char expansionPolicy[20];
        char poolUsage[20];
        char shrinking[30];
        int poolSize;
        int granularity;
        int sizeClassesDetected;
        int largerMultiple;
        int coalescing;
        int splitting;
};

#endif