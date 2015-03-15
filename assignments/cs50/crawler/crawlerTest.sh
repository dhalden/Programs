day=$(date +"%a_%b_%d_%T_%Y")
touch crawlerTestlog.$day
make=$(make crawl)
test1=$(./crawler http://old-www.cs.dartmouth.edu/~cs50/tse/ 0 data)
	files=$(ls -l ./data | wc -l)
	if [ $files -eq 1 ]
		then
		echo "Success test 1!" >> 'crawlerTestlog'.$day
	else
		echo "Failure test 1"  >> 'crawlerTestlog'.$day
	fi

make=$(make crawl)

test1=$(./crawler http://old-www.cs.dartmouth.edu/~cs50/tse/ 1 data)
	files=$(ls -l ./data | wc -l)
	if [ $files -eq 7 ]
		then
		echo "Success test 2!"  >> 'crawlerTestlog'.$day
	else
		echo "Failure test 2"  >> 'crawlerTestlog'.$day
	fi

make=$(make crawl)

test1=$(./crawler http://old-www.cs.dartmouth.edu/~cs50/tse/ 2 data)
	files=$(ls -l ./data | wc -l)
	if [ $files -eq 1705 ]
		then
		echo "Success test 3!"  >> 'crawlerTestlog'.$day
	else
		echo "Failure test 3"  >> 'crawlerTestlog'.$day
	fi

make=$(make crawl)

test1=$(./crawler http://old-www.cs.dartmouth.edu/~cs50/tse/ 3 data)
	files=$(ls -l ./data | wc -l)
	if [ $files -eq 1705 ]
		then
		echo "Success test 4!"  >> 'crawlerTestlog'.$day
	else
		echo "Failure test 4"  >> 'crawlerTestlog'.$day
	fi

make=$(make crawl)

test1=$(./crawler http://old-www.cs.dartmouth.edu/~cs50/tse/ 5 data)
	if [ $test1 == 'Error: Maximum Depth exceeded' ]
		then
		echo "Success test 5!"  >> 'crawlerTestlog'.$day
	else
		echo "Failure test 5"  >> 'crawlerTestlog'.$day
	fi

test1=$(./crawler http://old-www.cs.dartmouth.edu/~cs50/tse/ asdf data)
	if [ $test1 == 'Error: you entered a non-numeric entry for Max Webpage depth' ]
		then
		echo "Success test 6!"  >> 'crawlerTestlog'.$day
	else
		echo "Failure test 6"  >> 'crawlerTestlog'.$day
	fi

test1=$(./crawler http://old-www.cs.dartmouth.edu/~cs50/tse/ 0 datas)
	if [ $test1 == 'Error: directory cannot be found' ]
		then
		echo "Success test 7!"  >> 'crawlerTestlog'.$day
	else
		echo "Failure test 7"  >> 'crawlerTestlog'.$day
	fi


test1=$(./crawler http://old-www.cs.dartmouth.edu/~cs50/tse/asdf 0 data)
	if [ $test1 == 'Error: Seed_Url not found' ]
		then
		echo "Success test 8!"  >> 'crawlerTestlog'.$day
	else
		echo "Failure test 8"  >> 'crawlerTestlog'.$day
	fi
	
