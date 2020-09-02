GRANULARITY := $$(awk '/GRN/ {print $$2}' ../info.cfg)

allocator_policy:
	-@$(CC) -g allocator_policy.c -o allocator_policy -l OpenCL

get_alloc_info: allocator_policy
	-@gdb -batch-silent -iex "set auto-load safe-path /" --args allocator_policy $(GRANULARITY) 2>/dev/null

.PHONY: clean

clean:
	-@rm -f allocator_policy