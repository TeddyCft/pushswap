#!/bin/bash

NUM_TESTS=$1
LS_SIZE=$2
LIMIT=$3
MAX_LINES=0
GLOBAL_RESULT="OK"

#----------------------------------------------------------
#generate lists of random numbers
gen_lists()
{
local size=$1
seq 0 $size | shuf | tr '\n' ' ' | sed 's/ $//'
}
#----------------------------------------------------------
#----------------------------------------------------------
#uses the checker to check the lists and keeps the maximum number of output
tester()
{
local input_list=$1
local result_file=$3

#calls push_swap and count output lines
output=$(./push_swap $input_list | tee /dev/tty | ./checker $input_list)

num_lines=$(echo "$output" | wc -l)

#updates the max number of lines get
if [ $num_lines -gt $MAX_LINES ]; then
	MAX_LINES=$num_lines
fi

#calls the checker to check the list
if echo "$output" | grep -q "KO" || echo "$output" | grep -q "Error" || $num_lines > $LIMIT; then
	GLOBAL_RESULT="KO"
	echo "$input_list" >> "invalid_tests.txt"
fi
}
#----------------------------------------------------------
#----------------------------------------------------------

for ((i = 1; i <= $NUM_TESTS; i++)); do
	random_list=$(gen_lists $LS_SIZE)
	
	result_file="invalid_test_$i.txt"
	
	tester "$random_list" $LS_SIZE $result_file
done

if [ "$GLOBAL_RESULT" == "OK" ]; then
	echo "All tests OK ! Yay !"
else
	echo "At least one test failed"
fi

echo "Less efficient : $MAX_LINES operation(s)" 
