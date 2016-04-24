#include "hashTable.h"

HashTable::HashTable(int hValue){
	this->hashValue = hValue;
	hashTable = new HashTableEntry*[hashValue];
}

void HashTable::insertToTable(Node* nodeToAdd){
	if(HashTable::lookup(nodeToAdd->value) != NULL){
		return;
	}
	HashTableEntry* entryToAdd = new HashTableEntry(nodeToAdd);
	int index = HashTable::h(nodeToAdd->value);
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
		return -1;
	}
	else{
		int index = HashTable::h(i);
		for(HashTableEntry* entryToCheck = hashTable[index]; entryToCheck!= NULL; entryToCheck = entryToCheck->next){
			if(entryToCheck->entry->value == i){ // check if entry in array is the item to delete
				int heapIndex = entryToCheck->entry->heapIndex;
				if(entryToCheck == hashTable[i]){
					hashTable[i] = entryToCheck->next;
					delete entryToCheck;
					return heapIndex;
				} else {
					HashTableEntry* temp = entryToCheck->next;
					delete entryToCheck;
					entryToCheck = temp;
					return heapIndex;
				}
			}
		}

	}

	return -1;
}
