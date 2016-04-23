#include "prog1.h"
#include <iostream>

Prog1::Prog1(){
	hashTable = new HashTable(101);
	minHeap = new MinHeap(101);
}

void Prog1::insert(int i){
	//get hash index add to node
	//add to heap, heap index will be added automatically
	//add to hash table
	int hashIndex = hashTable->h(i);
	Node* nodeToAdd = new Node(i, 0, hashIndex);
	minHeap->insertToHeap(nodeToAdd);
	hashTable->insertToTable(nodeToAdd);
}

void Prog1::lookup(int i){
	// call lookup from hashTable
}

void Prog1::deleteMin(){
	// get hash table index from node from heap
	// delete from heap
	// delete from hash table
}

void Prog1::deleteFromStructures(int i){
	// get index of heap from hash table
	// delete from heap
	// delete from hash table
}

void Prog1::print(){
	// heapsort?
}
