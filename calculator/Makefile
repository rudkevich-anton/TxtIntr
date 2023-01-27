clean:

all17: main17 test17

main17: main17.cpp
	g++ -Wall -fexceptions -g -c -o main17.o main17.cpp
	g++ -o main17.exe main17.o
alltest: alltest
	teststrtol.exe 
	main.exe -l10 5 3 4
	testgetopt.exe -t5 -n "10 15"
test17:	test17
	main17.exe -a -v "1 2 3"
	main17.exe -a -v "1 2 3 4 5"
	main17.exe -s -v "5 1 1 1 1"
	main17.exe -h
	main17.exe -g
	main17.exe -v
