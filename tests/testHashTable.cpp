#include "hashTable.h"
#include <iostream>


int main(){
HashTable* test = new HashTable(6);

Node* add = new Node(7,0,0);
Node* add1 = new Node(7,0,0);
Node* add2 = new Node(13,0,0);
test->insertToTable(add);
test->insertToTable(add2);

test->deleteFromTable(13);
test->deleteFromTable(19);
test->deleteFromTable(13);

test->lookup(7);
test->lookup(13);
test->lookup(4);

return 0;
}
