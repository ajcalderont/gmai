set logging file ../info.cfg

# Expansion policy
break expansion.c:main:break_01
run
break mmap thread 1
continue
set logging overwrite off
set logging on
if main::index == main::max_allocations - 1
	printf "EXP When full\n"
else
	printf "EXP Treshold %d\n", main::index * main::granularity
end
set logging off
delete

# Finalization
continue
quit