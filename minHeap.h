#ifndef MINHEAP_H
#define MINHEAP_H

#include "structures.h"

class MinHeap{

public:

	MinHeap(int heapSize);

	//inserts element and returns index of the value in the array
	int insertToTable(Node* nodeToAdd);

  	void deleteFromTable(int index);

  	void percolateUp(int index);

  	void percolateDown(int index);

  	void printTable();
  private:
  	  Node** minHeap;
  	  int emptyIndex;
};

#endif