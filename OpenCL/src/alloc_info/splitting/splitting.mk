GRANULARITY := $$(awk '/GRN/ {print $$2}' ../info.cfg)

splitting:
	-@$(CC) -g splitting.c -o splitting -l OpenCL

get_alloc_info: splitting
	-@gdb -batch-silent -iex "set auto-load safe-path /" --args splitting $(GRANULARITY) 2>/dev/null

.PHONY: clean

clean:
	-@rm -f splitting