#ifndef MINHEAP_H
#define MINHEAP_H

#include "structures.h"

class MinHeap{

public:

	MinHeap(int heapSize);

	//inserts element and returns index of the value in the array
	int insertToTable(int i);

  	void delete(int index);

  	void percolateUp(int index);

  	void percolateDown(int index);
  private:
  	  Node** minHeap;
};

#endif