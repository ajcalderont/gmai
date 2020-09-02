POOL_SIZE := $$(awk '/PSZ/ {print $$2}' ../info.cfg)

larger_allocations:
	-@$(CC) -g larger_allocations.c -o larger_allocations -l OpenCL

get_alloc_info: larger_allocations
	-@gdb -batch-silent -iex "set auto-load safe-path /" --args larger_allocations $(POOL_SIZE) 2>/dev/null

.PHONY: clean

clean:
	-@rm -f larger_allocations