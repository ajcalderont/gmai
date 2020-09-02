set logging file ../info.cfg

# Shrinking support
break shrinking.c:main:break_01
run
break mmap thread 1
break munmap thread 1
break shrinking.c:main:break_02
continue
set logging overwrite off
set logging on
if  main::flag == 0
	printf "SHR Yes. Any pool deleted\n"
else
	if main::flag == 1
		printf "SHR Yes. Last pool deleted\n"
	else
		printf "SHR No. Pools deleted at the end\n"
	end
end
set logging off
delete

# Finalization
continue
quit