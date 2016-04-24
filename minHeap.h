#ifndef MINHEAP_H
#define MINHEAP_H

#include "structures.h"

class MinHeap{

public:

	MinHeap(int heapSize);

	//inserts element and returns index of the value in the array
	int insertToHeap(Node* nodeToAdd);

  void deleteFromHeap(int index);

  void percolateUp(int index);

  void percolateDown(int index);

  Node* getMin();

  void printTable();

  private:
  	Node** minHeap;
  	int emptyIndex;
};

#endif