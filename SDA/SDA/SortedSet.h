#pragma once
#include "BST.h"
class SortedSet
{
private:
	BST contracts;		//the date stored in the set
	int size=0;			//the size of the set
public:
	SortedSet() {}		//defaault constructor
	void insertSS(Contract& t) { this->contracts.insert(t); this->size++; }	//function that inserts a contract in the set and increments the size
																			//input: Contract& t
																			//output: -

	void removeSS(Contract& t) { this->contracts.remove(t); this->size--; }	//function that removes a contract from the set and decrements the size
																			//input: Contract& t
																			//output: -
	
	node* searchSS(Contract& t) { return this->contracts.search(t); }		//function that searches fro contract in the set and returns a pointer to the node that contains that contract
																			//input: Contract& t
																			//output: node *
	//BST getAll() { return contracts; }
	int getSize() { return size; }											//function that returns the size of the set
																			//input: -
																			//output: int

	Iterator* iter() { return contracts.iterator(); }						//function that returns an iterator for the set
																			//input: -
																			//output: Iterator
	~SortedSet() {}		//destructor
};
