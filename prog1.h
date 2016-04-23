#ifndef PROG1_H
#define PROG1_H

#include "hashTable.h"
#include "minHeap.h"

class Prog1{
 public:

  Prog1();

  int h(int i){
    return i%hashValue;
  }
  
  void insert(int i);

  void lookup(int i);

  void deleteMin();

  void deleteFromStructures(int i);

  void print();

 private:

  int hashValue;
  HashTable* hashTable;
  MinHeap* minHeap;
};

#endif
