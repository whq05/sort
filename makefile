all:	bubblesort bubblesort_better selectsort selectsort_better insertsort shellsort quicksort mergesort mergesort1\
	heapsort countsort countsort_better countsort_example bucketsort radixsort 

bubblesort:bubblesort.cpp
	g++ -g -o bubblesort bubblesort.cpp

bubblesort_better:bubblesort_better.cpp
	g++ -g -o bubblesort_better bubblesort_better.cpp

selectsort:selectsort.cpp
	g++ -g -o selectsort selectsort.cpp

selectsort_better:selectsort_better.cpp
	g++ -g -o selectsort_better selectsort_better.cpp

insertsort:insertsort.cpp
	g++ -g -o insertsort insertsort.cpp

shellsort:shellsort.cpp
	g++ -g -o shellsort shellsort.cpp

quicksort:quicksort.cpp
	g++ -g -o quicksort quicksort.cpp

mergesort:mergesort.cpp
	g++ -g -o mergesort mergesort.cpp

mergesort1:mergesort1.cpp
	g++ -g -o mergesort1 mergesort1.cpp

heapsort:heapsort.cpp
	g++ -g -o heapsort heapsort.cpp

countsort:countsort.cpp
	g++ -g -o countsort countsort.cpp

countsort_better:countsort_better.cpp
	g++ -g -o countsort_better countsort_better.cpp

countsort_example:countsort_example.cpp
	g++ -g -o countsort_example countsort_example.cpp

bucketsort:bucketsort.cpp
	g++ -g -o bucketsort bucketsort.cpp

radixsort:radixsort.cpp
	g++ -g -o radixsort radixsort.cpp

clean:
	rm -rf bubblesort bubblesort_better selectsort selectsort_better insertsort shellsort quicksort mergesort mergesort1
	rm -rf heapsort countsort countsort_better countsort_example bucketsort radixsort
