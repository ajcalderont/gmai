CC = gcc
CXX = g++
program_name ?=
program_arguments ?=
verbosity ?= 0

export CC

info.cfg:
	@$(MAKE) -C alloc_info/device_properties -f device_properties.mk get_alloc_info
	@$(MAKE) -C alloc_info/pool_size -f pool_size.mk get_alloc_info
	@$(MAKE) -C alloc_info/granularity -f granularity.mk get_alloc_info
	@$(MAKE) -C alloc_info/size_classes -f size_classes.mk get_alloc_info
	@$(MAKE) -C alloc_info/larger_allocations -f larger_allocations.mk get_alloc_info
	@$(MAKE) -C alloc_info/allocator_policy -f allocator_policy.mk get_alloc_info
	@$(MAKE) -C alloc_info/coalescing -f coalescing.mk get_alloc_info
	@$(MAKE) -C alloc_info/splitting -f splitting.mk get_alloc_info
	@$(MAKE) -C alloc_info/expansion -f expansion.mk get_alloc_info
	@$(MAKE) -C alloc_info/pool_usage -f pool_usage.mk get_alloc_info
	@$(MAKE) -C alloc_info/shrinking -f shrinking.mk get_alloc_info
	-@cp alloc_info/info.cfg .

print_alloc_info: info.cfg
	-@$(CXX) AllocatorInfo.cpp print_alloc_info.cpp -o print_alloc_info

preload_library.so:
	-@$(CXX) -shared -fPIC MemoryPool.cpp AllocatorInfo.cpp AllocatorStatus.cpp preload_library.cpp -o preload_library.so -ldl

.PHONY: show_alloc_info memory_analysis clean clean_info

show_alloc_info: print_alloc_info
	-@./print_alloc_info

memory_analysis: info.cfg preload_library.so
	-@$(CC) -g $(program_name).c -o $(program_name) -l OpenCL
	-@VERBOSITY=$(verbosity) LD_PRELOAD="./preload_library.so" ./$(program_name) $(program_arguments) 2>$(program_name).txt
	-@cat $(program_name).txt

clean:
	-@rm -f preload_library.so

clean_info:
	@$(MAKE) -C alloc_info/device_properties -f device_properties.mk clean
	@$(MAKE) -C alloc_info/pool_size -f pool_size.mk clean
	@$(MAKE) -C alloc_info/granularity -f granularity.mk clean
	@$(MAKE) -C alloc_info/size_classes -f size_classes.mk clean
	@$(MAKE) -C alloc_info/larger_allocations -f larger_allocations.mk clean
	@$(MAKE) -C alloc_info/allocator_policy -f allocator_policy.mk clean
	@$(MAKE) -C alloc_info/coalescing -f coalescing.mk clean
	@$(MAKE) -C alloc_info/splitting -f splitting.mk clean
	@$(MAKE) -C alloc_info/expansion -f expansion.mk clean
	@$(MAKE) -C alloc_info/pool_usage -f pool_usage.mk clean
	@$(MAKE) -C alloc_info/shrinking -f shrinking.mk clean
	-@rm -f alloc_info/info.cfg
	-@rm -f print_alloc_info info.cfg