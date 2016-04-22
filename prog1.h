#ifndef PROG1_H
#define PROG1_H

#include "hashTable.h"
#include "minHeap.h"

class Prog1{
 public:

  int h(int i){
    return i%hashValue;
  }
  
  void insert(int i);

  void lookup(int i);

  void deleteMin();

  void delete(int i);

  void print();


 private:

  int hashValue;
  HashTable hashTable;
  MinHeap minHeap;
};

#endif
