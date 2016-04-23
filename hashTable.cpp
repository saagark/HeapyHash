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
		for(HashTableEntry* entryToCheck = hashTable[index]; entryToCheck->next != NULL; entryToCheck = entryToCheck->next){
			if(entryToCheck->next->entry->value == i){ // check if next in array is the item to delete
				int heapIndex = entryToCheck->next->entry->heapIndex;
				HashTableEntry* temp = entryToCheck->next->next;
				delete entryToCheck->next;
				entryToCheck->next = temp;
				return heapIndex;
			}
		}

	}
	return -1;
}