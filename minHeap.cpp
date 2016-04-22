#include "minHeap.h"



MinHeap::MinHeap(int heapSize){
	minHeap = new Node*[heapSize];
	emptyIndex = 1;
}

//inserts element and returns index of the value in the array
int MinHeap::insertToTable(Node* nodeToAdd){
	minHeap[emptyIndex] = nodeToAdd;
	percolateUp(emptyIndex);
	emptyIndex++;
}

//delete element
//replace deleted element with last element
//percolate down
void MinHeap::delete(int index){
	Node* nodeToDelete = minHeap[index];
	minHeap[index] = minHeap[emptyIndex-1];
	minHeap[emptyIndex-1] = NULL;
	delete nodeToDelete;
	percolateDown(index);
	emptyIndex--;
}

void MinHeap::percolateUp(int index){

}

void MinHeap::percolateDown(int index){

}