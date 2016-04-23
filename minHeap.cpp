#include "minHeap.h"
#include <iostream>


MinHeap::MinHeap(int heapSize){
	minHeap = new Node*[heapSize];
	emptyIndex = 1;
}

//inserts element and returns index of the value in the array
int MinHeap::insertToHeap(Node* nodeToAdd){
	minHeap[emptyIndex] = nodeToAdd;
	nodeToAdd->setHeapIndex(emptyIndex);
	percolateUp(emptyIndex);
	emptyIndex++;
	return emptyIndex-1;
}

//delete element
//replace deleted element with last element
//percolate down
void MinHeap::deleteFromHeap(int index){
	Node* nodeToDelete = minHeap[index];
	minHeap[index] = minHeap[emptyIndex-1];
	minHeap[index]->setHeapIndex(index);
	minHeap[emptyIndex-1] = NULL;
	delete nodeToDelete;
	emptyIndex--;
	percolateDown(index);
}


//do this with recursion since its easier
//if index is less than parent index, it swaps them until heap property is maintained
void MinHeap::percolateUp(int index){
	if(index == 1)
		return;
	int parentIndex = index/2;
	if(minHeap[index]->value < minHeap[parentIndex]->value){
		Node* temp = minHeap[index];
		minHeap[index] = minHeap[parentIndex];
		minHeap[index]->setHeapIndex(index);
		minHeap[parentIndex] = temp;
		minHeap[parentIndex]->setHeapIndex(parentIndex);
		MinHeap::percolateUp(parentIndex);
	}
}

//use recursion here too because its easier
void MinHeap::percolateDown(int index){
	int leftIndex = index*2;
	int rightIndex = (index*2) + 1;
	if(leftIndex >= emptyIndex)
		return;
	int indexOfMinimum = index; // assume for right now
	if(minHeap[index]->value > minHeap[leftIndex]->value) // compare with left index
		indexOfMinimum = leftIndex;
	if((rightIndex < emptyIndex) && (minHeap[index]->value > minHeap[rightIndex]->value)) // compare with right index, also need to check bounds
		indexOfMinimum = rightIndex;

	//check if swapping is necessary
	if(indexOfMinimum != index){
		Node* temp = minHeap[index];
		minHeap[index] = minHeap[indexOfMinimum];
		minHeap[index]->setHeapIndex(index);
		minHeap[indexOfMinimum] = temp;
		minHeap[indexOfMinimum]->setHeapIndex(indexOfMinimum);
		MinHeap::percolateDown(indexOfMinimum);
	}

}

void MinHeap::printTable(){
	for(int i = 1; i < emptyIndex; i++){
		std::cout << minHeap[i]->value << "@" << minHeap[i]->heapIndex << ",  ";
	}
	std::cout << std::endl;
}