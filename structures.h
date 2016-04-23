#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <cstdlib>  


struct Node{
    Node(int value, int heapIndex, int hashIndex){
      this->value = value;
      this->heapIndex = heapIndex;
      this->hashIndex = hashIndex;
    }

    int value;
    int heapIndex;
    int hashIndex;

    void setHeapIndex(int index){
      heapIndex = index;
    }
  };

  struct HashTableEntry{
    HashTableEntry(Node* node){
      entry = node;
      next = NULL;
    }

    Node* entry;
    HashTableEntry* next;
  
    void setNext(HashTableEntry* node){
      next = node;
    }

    ~HashTableEntry(){
    	delete entry;
    }
  };

#endif