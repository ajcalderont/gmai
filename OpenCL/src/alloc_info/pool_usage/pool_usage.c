#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

int main(int argc, char* argv[])
{
	// Initialization
	/*----------------------------------------------------------------------------------------*/
    static int pool_size = 0;
    pool_size = atoi(argv[1]);

    cl_platform_id platform_id = NULL;
    cl_device_id device_id = NULL;
    cl_uint num_platforms;
    cl_uint num_devices;
    cl_int ret;
    
    ret = clGetPlatformIDs(1, &platform_id, &num_platforms);
    ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &num_devices);
    
    cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);
    cl_command_queue command_queue = clCreateCommandQueue(context, device_id, 0, &ret);

	// Pool usage
	/*----------------------------------------------------------------------------------------*/
    int quarter = pool_size / 4;

    cl_mem buf_1 = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, quarter, NULL, &ret);
    cl_mem buf_2 = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, quarter, NULL, &ret);
    cl_mem buf_3 = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, quarter, NULL, &ret);
    cl_mem buf_4 = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, quarter, NULL, &ret);
    cl_mem buf_5 = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, quarter, NULL, &ret);
    cl_mem buf_6 = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, quarter, NULL, &ret);
    cl_mem buf_7 = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, quarter, NULL, &ret);
    cl_mem buf_8 = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, quarter, NULL, &ret);
    cl_mem buf_9 = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, quarter, NULL, &ret);
    char *h_1 = (char*)clEnqueueMapBuffer(command_queue, buf_1, CL_TRUE, CL_MAP_READ | CL_MAP_WRITE, 0, quarter, 0, NULL, NULL, &ret);
    char *h_2 = (char*)clEnqueueMapBuffer(command_queue, buf_2, CL_TRUE, CL_MAP_READ | CL_MAP_WRITE, 0, quarter, 0, NULL, NULL, &ret);
    char *h_3 = (char*)clEnqueueMapBuffer(command_queue, buf_3, CL_TRUE, CL_MAP_READ | CL_MAP_WRITE, 0, quarter, 0, NULL, NULL, &ret);
    char *h_4 = (char*)clEnqueueMapBuffer(command_queue, buf_4, CL_TRUE, CL_MAP_READ | CL_MAP_WRITE, 0, quarter, 0, NULL, NULL, &ret);
    char *h_5 = (char*)clEnqueueMapBuffer(command_queue, buf_5, CL_TRUE, CL_MAP_READ | CL_MAP_WRITE, 0, quarter, 0, NULL, NULL, &ret);
    char *h_6 = (char*)clEnqueueMapBuffer(command_queue, buf_6, CL_TRUE, CL_MAP_READ | CL_MAP_WRITE, 0, quarter, 0, NULL, NULL, &ret);
    char *h_7 = (char*)clEnqueueMapBuffer(command_queue, buf_7, CL_TRUE, CL_MAP_READ | CL_MAP_WRITE, 0, quarter, 0, NULL, NULL, &ret);
    char *h_8 = (char*)clEnqueueMapBuffer(command_queue, buf_8, CL_TRUE, CL_MAP_READ | CL_MAP_WRITE, 0, quarter, 0, NULL, NULL, &ret);
    char *h_9 = (char*)clEnqueueMapBuffer(command_queue, buf_9, CL_TRUE, CL_MAP_READ | CL_MAP_WRITE, 0, quarter, 0, NULL, NULL, &ret);

    ret = clEnqueueUnmapMemObject(command_queue, buf_1, h_1, 0, NULL, NULL);
    ret = clEnqueueUnmapMemObject(command_queue, buf_2, h_2, 0, NULL, NULL);
    ret = clEnqueueUnmapMemObject(command_queue, buf_5, h_5, 0, NULL, NULL);
    clFinish(command_queue);
    ret = clReleaseMemObject(buf_1);
    ret = clReleaseMemObject(buf_2);
    ret = clReleaseMemObject(buf_5);

    cl_mem buf_10 = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR, quarter, NULL, &ret);
    char *h_10 = (char*)clEnqueueMapBuffer(command_queue, buf_10, CL_TRUE, CL_MAP_READ | CL_MAP_WRITE, 0, quarter, 0, NULL, NULL, &ret);
    break_01: __attribute__((unused));

    ret = clEnqueueUnmapMemObject(command_queue, buf_3, h_3, 0, NULL, NULL);
    ret = clEnqueueUnmapMemObject(command_queue, buf_4, h_4, 0, NULL, NULL);
    ret = clEnqueueUnmapMemObject(command_queue, buf_6, h_6, 0, NULL, NULL);
    ret = clEnqueueUnmapMemObject(command_queue, buf_7, h_7, 0, NULL, NULL);
    ret = clEnqueueUnmapMemObject(command_queue, buf_8, h_8, 0, NULL, NULL);
    ret = clEnqueueUnmapMemObject(command_queue, buf_9, h_9, 0, NULL, NULL);
    ret = clEnqueueUnmapMemObject(command_queue, buf_10, h_10, 0, NULL, NULL);
    clFinish(command_queue);

	// Finalization
	/*----------------------------------------------------------------------------------------*/
    ret = clReleaseMemObject(buf_3);
    ret = clReleaseMemObject(buf_4);
    ret = clReleaseMemObject(buf_6);
    ret = clReleaseMemObject(buf_7);
    ret = clReleaseMemObject(buf_8);
    ret = clReleaseMemObject(buf_9);
    ret = clReleaseMemObject(buf_10);
    ret = clReleaseCommandQueue(command_queue);
    ret = clReleaseContext(context);

	return 0;
}