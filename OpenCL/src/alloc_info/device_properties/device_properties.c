#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

int main()
{
	// Initialization
	/*----------------------------------------------------------------------------------------*/
    cl_platform_id platform_id = NULL;
    cl_device_id device_id = NULL;
    cl_uint num_platforms;
    cl_uint num_devices;
    cl_int ret;
    
    ret = clGetPlatformIDs(1, &platform_id, &num_platforms);
    ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &num_devices);
    
    cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);

    // Device properties
	/*----------------------------------------------------------------------------------------*/
	static char device_name[40];
    ret = clGetDeviceInfo(device_id, CL_DEVICE_NAME, 40, device_name, NULL);

    static char driver_version[40];
    ret = clGetDeviceInfo(device_id, CL_DRIVER_VERSION, 40, driver_version, NULL);
	
    break_01: __attribute__((unused));

    // Finalization
	/*----------------------------------------------------------------------------------------*/
    ret = clReleaseContext(context);
    
	return 0;
}