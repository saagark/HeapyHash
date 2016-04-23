#include "prog1.h"
#include <iostream>
#include <ifstream>

void insert(int i){
	//get hash index add to node
	//add to heap, heap index will be added automatically
	//add to hash table
	int hashIndex = HashTable::h(i);
	Node* nodeToAdd = new Node(i, 0, hashIndex);
	minHeap->insertToTable(nodeToAdd);
	hashTable->insertToTable(nodeToAdd);
}

void lookup(int i){
	// call lookup from hashTable
}

void deleteMin(){

}

void delete(int i){

}

void print(){

}
