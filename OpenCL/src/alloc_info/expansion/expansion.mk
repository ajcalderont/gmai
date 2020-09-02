POOL_SIZE := $$(awk '/PSZ/ {print $$2}' ../info.cfg)
GRANULARITY := $$(awk '/GRN/ {print $$2}' ../info.cfg)

expansion:
	-@$(CC) -g expansion.c -o expansion -l OpenCL

get_alloc_info: expansion
	-@gdb -batch-silent -iex "set auto-load safe-path /" --args expansion $(POOL_SIZE) $(GRANULARITY) 2>/dev/null

.PHONY: clean

clean:
	-@rm -f expansion