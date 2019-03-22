#pragma once
#include <iostream>
#include "Contract.h"

struct node
/*
	structure for the nodes used in the BST
*/
{
	Contract data; //the information
	node* left;    //pointer to the node to the left
	node* right;   //pointer to the node on the right
};

class Iterator
/*
	class Iterator
*/
{
private:
	node * first;	//first element in the BST (min)
	node* current;	//current element in the BST
	node* last;		//last element in the BST
	node* s;		//root of the BST
public:
	Iterator(node* first);
	bool hasNext();
	node* next();
	node* findParent();
};

class BST
/*
	class for implementing a binary search tree
*/
{
private:
	node* root;								//the root of the tree
	node* destroy(node* t);					//function that destroyes a node
	node* insert(Contract& x, node* t);		//function that inserts a new node in the BST
	node* findMin(node* t);                 //function that finds the min. value in the BST
	//node* findMax(node* t);
	node* remove(Contract& x, node* t);		//function that removes a node from the BST
	node* find(node* t, Contract& x);		//function that finds a node in the BST
	Iterator* it;							//iterator for the BST
public:
	friend class Iterator;
	BST();
	~BST();
	void insert(Contract& x);
	void remove(Contract& x);
	node* search(Contract& x);
	node* getRoot() { return this->root; }
	Iterator* iterator() { //function that returns an iterator for the BST
		this->it = new Iterator(this->root);
		return this->it;
	}
};


