#ifndef MINHEAP_H
#define MINHEAP_H

#include "structures.h"

class MinHeap{

public:

	MinHeap(int heapSize);

	//inserts element and returns index of the value in the array
	int insertToTable(Node* nodeToAdd);

  	void delete(int index);

  	void percolateUp(int index);

  	void percolateDown(int index);
  private:
  	  Node** minHeap;
  	  int emptyIndex;
};

#endif