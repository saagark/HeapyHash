#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "structures.h"

class HashTable{

	private:
		int hashValue;
		HashTableEntry** hashTable;


	public:
		HashTable(int hValue);

		int h(int i){
			return i % hashValue;
		}

		int deleteFromTable(int i);

		void insertToTable(Node* nodeToAdd);

		Node* lookup(int i);


};

#endif