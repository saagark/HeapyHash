#include "minHeap.h"
#include <iostream>


int main(){
MinHeap* test = new MinHeap(6);

Node* add = new Node(7,0,0);
Node* add1 = new Node(7,0,0);
Node* add2 = new Node(13,0,0);
Node* add3 = new Node(13,0,0);
Node* add4 = new Node(15,0,0);
Node* add5 = new Node(20,0,0);
Node* add6 = new Node(4,0,0);
Node* add7 = new Node(6,0,0);
test->insertToHeap(add);
test->insertToHeap(add2);
// test->insertToTable(add3);
test->insertToHeap(add4);
test->insertToHeap(add5);
test->insertToHeap(add6);
// test->insertToTable(add7);
test->printTable();

test->deleteFromHeap(2);
test->printTable();

return 0;
}