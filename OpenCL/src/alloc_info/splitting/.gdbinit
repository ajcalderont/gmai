set logging file ../info.cfg

# Splitting support
break splitting.c:main:break_01
run
set logging overwrite off
set logging on
if main::h_3 == main::h_1
	printf "SPL %d\n", 1
else 
	printf "SPL %d\n", 0
end
set logging off
delete

# Finalization
continue
quit