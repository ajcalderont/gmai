set logging file ../info.cfg

# Pool usage
break pool_usage.c:main:break_01
run
set logging overwrite off
set logging on
if main::h_10 == main::h_1
	printf "USG First available\n"
else
	if  main::h_10 == main::h_5
		printf "USG Best available\n"
	else
		if main::h_10 == main::h_9 + main::quarter
			printf "USG Last created\n"
		else
			printf "USG Unrecognized\n"
		end
	end
end
set logging off
delete

# Finalization
continue
quit