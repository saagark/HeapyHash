#ifndef PROG1_H
#define PROG1_H

#include<"structures.h">

class Prog1{
 public:

  int h(int i){
    return i%hashValue;
  }
  
  void insert(int i);

  int lookup(int i);

  void deleteMin();

  void delete(int i);

  void print();


 private:

  int hashValue;
  HashTableEntry** hashTable;
  Node** minHeap;
};

#endif
