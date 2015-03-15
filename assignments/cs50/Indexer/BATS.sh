start=$(date +"%a_%b_%d_%T_%Y")
echo $start >> 'BATS.log'
rm BATS.log
touch BATS.log 
make=$(make clean_0)
make=$(make index)
echo "test with 1 file from crawl" >> 'BATS.log'
test1=$(./indexer data/ index.dat >> BATS.log)
	files=$(cat index.dat | wc -l)
	if [ $files -eq 46 ]
		then
		echo "Success test 1!" >> 'BATS.log'
	else
		echo "Failure test 1"  >> 'BATS.log'
	fi

make=$(make clean_1)

echo "test with 7 files from crawl" >> 'BATS.log'
test1=$(./indexer data/ index.dat >> BATS.log)
	files=$(cat index.dat | wc -l)
	if [ $files -eq 6679 ]
		then
		echo "Success test 2!"  >> 'BATS.log'
	else
		echo "Failure test 2"  >> 'BATS.log'
	fi

make=$(make clean_2)

echo "test with all files from crawl, and test reading in results" >> 'BATS.log'
test1=$(./indexer data/ index.dat index.dat new_index.dat)
	files=$(diff index.dat new_index.dat)
	if [ "$files" == '' ]
		then
		echo "Success test 3!"  >> 'BATS.log'
	else
		echo "Failure test 3"  >> 'BATS.log'
	fi

make=$(make clean_2)

echo "test giving 2 inputs instead of 3" >> 'BATS.log'
test1=$(./indexer data/ 2>&1) 
	if [ "$test1" == 'Error: not enough arguments provided' ]
		then
		echo "Success test 4!"  >> 'BATS.log'
	else
		echo "Failure test 4"  >> 'BATS.log'
	fi

echo "test giving non-existent directory" >> 'BATS.log'
test1=$(./indexer dat/ index.dat 2>&1)
	if [ "$test1" == 'Error: Could not resolve input to a directory' ]
		then
		echo "Success test 5!"  >> 'BATS.log'
	else
		echo "Failure test 5"  >> 'BATS.log'
	fi

make=$(make clean_3)
make=$(make index)
echo "test giving directory with no files" >> 'BATS.log'
test1=$(./indexer data/ index.dat 2>&1)
	if [ "$test1" == 'Error: Files Not Found in provided directory' ]
		then
		echo "Success test 6!"  >> 'BATS.log'
	else
		echo "Failure test 6"  >> 'BATS.log'
	fi


make=$(make clean_2)
echo "test giving 4 argumenst" >> 'BATS.log'
test1=$(./indexer data/ index.dat asdf 2>&1)
	if [ "$test1" == 'Error: Invalid number of arguments greater than 3' ]
		then
		echo "Success test 7!"  >> 'BATS.log'
	else
		echo "Failure test 7"  >> 'BATS.log'
	fi

echo "test giving non-existent read file" >> 'BATS.log'
test1=$(./indexer data/ index.dat asdfs new_index.dat 2>&1)
	if [ "$test1" == "Error: invalid data file" ]
		then
		echo "Success test 8!"  >> 'BATS.log'
	else
		echo "Failure test 8"  >> 'BATS.log'
	fi

echo "test giving read file in incorrect format" >> 'BATS.log'
test1=$(./indexer data/ index.dat BATS.sh new_index.dat 2>&1)
	if [ "$test1" == "Error: File is in incorrect format" ]
		then
		echo "Success test 9!"  >> 'BATS.log'
	else
		echo "Failure test 9"  >> 'BATS.log'
	fi
	
end=$(date +"%a_%b_%d_%T_%Y")
echo $end >> 'BATS.log'
	
