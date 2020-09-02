set logging file ../info.cfg

# Allocator policy detection
break allocator_policy.c:main:break_01
run
set logging overwrite off
set logging on
if main::h_7 == main::h_5
	printf "POL Best fit\n"
else 
	if main::h_7 == main::h_6 + main::granularity
		printf "POL Next fit\n"
	else
		if main::h_7 == main::h_1
			if main::h_8 == main::h_1 + main::granularity
				printf "POL First fit\n"
			else
				if main::h_8 == main::h_3
					printf "POL Worst fit\n"
				else
					printf "POL Unrecognized policy\n"
				end
			end
		end
	end
end
set logging off
delete

# Finalization
continue
quit