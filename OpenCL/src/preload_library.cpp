#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <CL/cl.h>
#include "AllocatorInfo.h"
#include "AllocatorStatus.h"

typedef cl_mem (*real_clcreatebuffer_t)(cl_context context, cl_mem_flags flags, size_t size, void* host_ptr, cl_int* errcode_ret);
typedef cl_int (*real_clreleasememobject_t)(cl_mem memobj);

static AllocatorStatus *allocatorStatus;
static int verbose;
static int counter = 0;

void __attribute__ ((constructor)) lib_init(void)
{
    AllocatorInfo info("info.cfg");
    verbose = atoi(getenv("VERBOSITY"));
    allocatorStatus = new AllocatorStatus(info);
}

void __attribute__ ((destructor)) lib_fini(void)
{
    allocatorStatus->printMaximum();
    delete(allocatorStatus);
}

cl_mem clCreateBuffer(cl_context context, cl_mem_flags flags, size_t size, void* host_ptr, cl_int* errcode_ret)
{
    cl_mem memobj = ((real_clcreatebuffer_t)dlsym(RTLD_NEXT, "clCreateBuffer"))(context, flags, size, host_ptr, errcode_ret);
    allocatorStatus->addAllocation((char *)memobj, size);
    if(verbose)
    {
        fprintf(stderr, "%d. clCreateBuffer(%lu):\n", ++counter, size);
        allocatorStatus->printStatus();
    }
    return memobj;
}

cl_int clReleaseMemObject(cl_mem memobj)
{
    cl_int result = ((real_clreleasememobject_t)dlsym(RTLD_NEXT, "clReleaseMemObject"))(memobj);
    allocatorStatus->removeAllocation((char * )memobj);
    if(verbose)
    {
        fprintf(stderr, "%d. clReleaseMemObject():\n", ++counter);
        allocatorStatus->printStatus();
    }
    return result;
}