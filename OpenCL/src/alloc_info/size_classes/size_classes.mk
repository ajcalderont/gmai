POOL_SIZE := $$(awk '/PSZ/ {print $$2}' ../info.cfg)
GRANULARITY := $$(awk '/GRN/ {print $$2}' ../info.cfg)

size_classes:
	-@$(CC) -g size_classes.c -o size_classes -l OpenCL

get_alloc_info: size_classes
	-@gdb -batch-silent -iex "set auto-load safe-path /" --args size_classes $(POOL_SIZE) $(GRANULARITY) 2>/dev/null

.PHONY: clean

clean:
	-@rm -f size_classes