// Heap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <chrono>

const long int MAX_SIZE = 200000;

struct Heap
{
	int size;
	int *data;
};

void init(Heap& heap);
void insert(Heap& heap, int value);
void print(Heap& heap);
void printHeap(Heap& heap);
void remove(Heap& heap);
void heapify(Heap& heap, int index);

void init(Heap& heap)
{
	heap.size = 0;
	heap.data = new int[MAX_SIZE];
}

void insert(Heap& heap, int value){
	
}
void printHeap(Heap& heap){
	int i = 0;
	int k = 1;
	while (i < heap.size) {
		while ((i < k) && (i < heap.size)) {
			std::cout << heap.data[i] << " ";
			i++;
		}
		std::cout << std::endl;
		k = k * 2 + 1;
	}
}
void buildHeap(Heap& heap) 
	{
		for (int i = heap.size / 2 - 1; i >= 0; i--)
			heapify(heap, i);
	}


void heapify(Heap& heap, int index) {
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left < heap.size) {
		if (heap.data[index] < heap.data[left])
		{
			int temp = heap.data[index];
			heap.data[index] = heap.data[left];
			heap.data[left] = temp;
			heapify(heap, left);
		}
	}
	if (right < heap.size)
	{
		if (heap.data[index] < heap.data[right])
		{
			int temp = heap.data[index];
			heap.data[index] = heap.data[right];
			heap.data[right] = temp;
			heapify(heap, right);
		}
	}
}

int main()
{
	const long int n = 100000;
	int test[n];
	for (int i = 0; i < n; i++)
	{
		test[i] = rand() % 100;
	}
	auto beginC = std::chrono::steady_clock::now();
	time_t startT, endT;
	time(&startT);
	clock_t start = clock();
	Heap heap;
	init(heap);
	
	for (int i = 0; i < n; i++) {
		heap.data[i] = test[i];
		
	}
	heap.size = n;
	buildHeap(heap);
	clock_t end = clock();
	time(&endT);
	auto endC = std::chrono::steady_clock::now();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	
	//std::cout << end << " " << start << std::endl;
	std::cout << seconds;
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(endC - beginC);

	
	
	double secondsT = difftime(endT, startT);
	std::cout << std::endl << secondsT;
	std::cout << std::endl << elapsed_ms.count();
	//printHeap(heap);
    //std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
