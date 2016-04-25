#include "prog1.h"
#include <iostream>
#include <sstream>
using namespace std;


Prog1* prog1;

void executeFunction(string word, int param){
	if(word == "insert"){
		prog1->insert(param);
	} else if(word == "delete"){
		prog1->deleteFromStructures(param);
	} else if(word == "deleteMin"){
		prog1->deleteMin();
	} else if(word == "lookup"){
		prog1->lookup(param);
	} else if(word == "print"){
		prog1->print();
	}
}


void parseString(string instruction){
	istringstream iss(instruction);

	string word;
	int param;
	iss >> word;
	iss >> param;
	executeFunction(word, param);
}

int main(){

	int tableSize;
	cin >> tableSize;
	
	prog1 = new Prog1(tableSize);
	
	int numInstr;
	cin >> numInstr;
	string line;
	
	getline(cin, line);// this is an empty line that is remaining from line 2 read above

	for (int i = 0; i < numInstr; i++) {
		getline(cin, line);
        parseString(line);
    }

    return 0;
}