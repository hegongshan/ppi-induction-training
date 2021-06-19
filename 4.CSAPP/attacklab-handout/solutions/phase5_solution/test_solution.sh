#!/bin/bash
solution_path_arr=$(ls . | grep -E ".txt$")
pass_count=0
fail_count=0

for s in ${solution_path_arr[*]}; do
	result=$(../../hex2raw -i $s |../../rtarget -q | grep -E "PASS")
	if [ -n "$result" ]; then
		pass_count=`expr ${pass_count} + 1`
	else
		fail_count=`expr ${fail_count} + 1`
	fi
done

echo "Number of PASS:${pass_count}, FAILURE: ${fail_count}"
!
