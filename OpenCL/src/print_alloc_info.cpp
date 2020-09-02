#include <stdio.h>
#include "AllocatorInfo.h"

int main()
{
    AllocatorInfo info("info.cfg");
    printf("Device name: %s\n", info.deviceName);
    printf("OpenCL driver version: %s\n\n", info.driverVersion);
    printf("Pool size: %d bytes\n", info.poolSize);
    printf("Granularity: %d bytes\n\n", info.granularity);
    printf("Size classes: %s\n", info.sizeClassesDetected?"":"Not used");
    printf("Larger allocations: mmap rounded to next %d bytes multiple\n\n", info.largerMultiple);
    printf("Allocator policy: %s\n", info.policy);
    printf("Coalescing support: %s\n", info.coalescing?"Yes":"No");
    printf("Splitting support: %s\n", info.splitting?"Yes":"No");
    printf("Expansion policy: %s\n", info.expansionPolicy);
    printf("Pool usage: %s\n", info.poolUsage);
    printf("Shrinking support: %s\n", info.shrinking);
    return 0;
}