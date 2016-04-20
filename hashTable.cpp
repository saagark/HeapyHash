#include "hashTable.h"
#include <iostream>
using namespace std;

HashTable::HashTable(int hValue){
	this->hashValue = hValue;
	hashTable = new HashTableEntry*[hashValue];
	for(int i =0; i<hashValue; i++)
		hashTable[i] = NULL;
}

void HashTable::insertToTable(Node* nodeToAdd){
	if(HashTable::lookup(nodeToAdd->value) != NULL){
		cout << nodeToAdd->value;
		cout << "error : item already exists" << endl;
		return;
	}
	HashTableEntry* entryToAdd = new HashTableEntry(nodeToAdd);
	int index = HashTable::h(nodeToAdd->value);
	cout << "insert " << nodeToAdd->value << " @ " << index << endl;
	if(hashTable[index]== NULL)
		hashTable[index] = entryToAdd;
	else{
		entryToAdd->next = hashTable[index];
		hashTable[index] = entryToAdd;
	}
}

Node* HashTable::lookup(int i){
	int index = HashTable::h(i);
	for(HashTableEntry* entryToCheck = hashTable[index]; entryToCheck != NULL; entryToCheck = entryToCheck->next){
		if (entryToCheck->entry->value == i){
			return entryToCheck->entry;
		}
	}
	return NULL;
}

int HashTable::deleteFromTable(int i){
	if(HashTable::lookup(i)==NULL){
		cout << "error: item not present" << endl;
		return -1;
	}
	else{
		int index = HashTable::h(i);
		for(HashTableEntry* entryToCheck = hashTable[index]; entryToCheck->next != NULL; entryToCheck = entryToCheck->next){
			if(entryToCheck->next->entry->value == i){ // check if next in array is the item to delete
				int heapIndex = entryToCheck->next->entry->heapIndex;
				HashTableEntry* temp = entryToCheck->next->next;
				delete entryToCheck->next;
				entryToCheck->next = temp;
				cout << "delete" << index << endl;
				return heapIndex;
			}
		}

	}
	return -1;
}