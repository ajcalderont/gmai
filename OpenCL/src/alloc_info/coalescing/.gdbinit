set logging file ../info.cfg

# Coalescing support
break coalescing.c:main:break_01
run
set logging overwrite off
set logging on
if main::h_4 == main::h_1
	printf "CLS %d\n", 1
else 
	printf "CLS %d\n", 0
end
set logging off
delete

# Finalization
continue
quit