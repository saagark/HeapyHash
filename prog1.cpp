#include "prog1.h"
#include <iostream>
using namespace std;

Prog1::Prog1(){
	hashTable = new HashTable(101);
	minHeap = new MinHeap(101);
}

void Prog1::insert(int i){
	//get hash index add to node
	//add to heap, heap index will be added automatically
	//add to hash table
	if(hashTable->lookup(i) != NULL){
		cout << "error: item already present" << endl;
		return;
	}
	int hashIndex = hashTable->h(i);
	Node* nodeToAdd = new Node(i, 0, hashIndex);
	minHeap->insertToHeap(nodeToAdd);
	hashTable->insertToTable(nodeToAdd);
}

void Prog1::lookup(int i){
	// call lookup from hashTable
	if(hashTable->lookup(i)==NULL){
		cout << i << " not found" << endl;
	} else {
		cout << i << " found" << endl;
	}
}

void Prog1::deleteMin(){
	// get hash table index from node from heap
	// delete from heap
	// delete from hash table

	Node* minNode = minHeap->getMin();

	if(minNode == NULL){
		cout << "error: item not present" << endl;
	} else {
		int value = minNode->value;
		int heapIndex = hashTable->deleteFromTable(value);
		minHeap->deleteFromHeap(1);
		cout << value << endl;
	}
}

void Prog1::deleteFromStructures(int i){
	// get index of heap from hash table
	// delete from heap
	// delete from hash table
	Node* nodeToDelete = hashTable->lookup(i);
	if(nodeToDelete == NULL){
		cout << "error: item not present" << endl;
		return;
	}

	int value = nodeToDelete->value;
	int heapIndex = nodeToDelete->heapIndex;

	hashTable->deleteFromTable(value);
	minHeap->deleteFromHeap(heapIndex);


}

void Prog1::print(){
	// heapsort?
}
