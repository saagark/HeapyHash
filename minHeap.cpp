#include "minHeap.h"
#include <iostream>


MinHeap::MinHeap(int heapSize){
	minHeap = new Node*[heapSize];
	emptyIndex = 1;
}

//inserts element and returns index of the value in the array
int MinHeap::insertToTable(Node* nodeToAdd){
	minHeap[emptyIndex] = nodeToAdd;
	percolateUp(emptyIndex);
	emptyIndex++;
	return emptyIndex-1;
}

//delete element
//replace deleted element with last element
//percolate down
void MinHeap::deleteFromTable(int index){
	Node* nodeToDelete = minHeap[index];
	minHeap[index] = minHeap[emptyIndex-1];
	minHeap[emptyIndex-1] = NULL;
	delete nodeToDelete;
	percolateDown(index);
	emptyIndex--;
}

void MinHeap::percolateUp(int index){
	if(index == 1)
		return;
	int parentIndex = index/2;
	if(minHeap[index]->value < minHeap[parentIndex]->value){
		Node* temp = minHeap[index];
		minHeap[index] = minHeap[parentIndex];
		minHeap[parentIndex] = temp;
		MinHeap::percolateUp(parentIndex);
	}
}

void MinHeap::percolateDown(int index){

}

void MinHeap::printTable(){
	for(int i = 1; i < emptyIndex; i++){
		std::cout << minHeap[i]->value << "@" << i << ",  ";
	}
	std::cout << std::endl;
}