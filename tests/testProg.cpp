#include "prog1.h"
#include <iostream>
using namespace std;

int main(){
	Prog1* test = new Prog1();

	// insert 5
	// insert 2
	// insert 8
	// insert 3
	// delete 7
	// insert 5
	// delete 5
	// deleteMin
	// lookup 2

	test->insert(5);
	test->insert(2);
	test->insert(8);
	test->insert(3);
	test->deleteFromStructures(7);
	test->insert(5);
	test->deleteFromStructures(5);
	test->deleteMin();
	test->lookup(2);

}