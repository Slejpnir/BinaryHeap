// Heap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

const int MAX_SIZE = 100;

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
	Heap heap;
	init(heap);
	int test[10] = { 2,5,34,76,4,23,12,45,812,0 };
	for (int i = 0; i < 10; i++) {
		heap.data[i] = test[i];
		heap.size = 10;
	}
	buildHeap(heap);
	printHeap(heap);
    std::cout << "Hello World!\n";
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
