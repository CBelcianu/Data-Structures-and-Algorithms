#include "BST.h"

node* BST::destroy(node* t)
/*
	function that destoryes a node
	input: node* t
	output: -
*/
{
	if (t == nullptr)	//the case in which the BST is empty
		return nullptr;
	else                //the case in which the BST is not empty
	{
		destroy(t->left);
		destroy(t->right);
		delete t;		//we destroy recursively every node of the BST
	}
	return nullptr;
}

node* BST::insert(Contract& x, node* t)
/*
	function that inserts a node
	input: node* t
	output: -
*/
{
	if (t ==nullptr) //the case in which the BST is empty and the added node is the first added, so this node becomes the root of the BST
	{
		t = new node;
		t->data = x;
		t->left = t->right = nullptr;
	}
	else if (x.getDays() < t->data.getDays()) //the case in which the BST already has elements and the information from the node that we want to add is less than the one in root
		t->left = insert(x, t->left);
	else if (x.getDays() > t->data.getDays()) //the case in which the information from the node that we want to add is grater that the one in root
		t->right = insert(x, t->right);
	return t;
}

node* BST::findMin(node* t)
/*
	function that find the min val
	input: node* t
	output: -
*/
{
	if (t == nullptr)	//the case in which the BST is empty
		return nullptr;
	else if (t->left == nullptr)	//if the root has no left child that means that the root is the minimum value in the BST
		return t;
	else
		return findMin(t->left);	//if the root has a left child, we go on shearching further
}
/*
node* BST::findMax(node* t)
{
	if (t == NULL)
		return NULL;
	else if (t->right == NULL)
		return t;
	else
		return findMax(t->right);
}
*/

node* BST::remove(Contract& x, node* t)
/*
	function that removes a node
	input: Contract& x, node* t
	output: -
*/
{
	
	node* temp;
	if (t == nullptr)	//the case in which the BST is empty
		return nullptr;
	else if (x.getDays() < t->data.getDays()) //the case in which we want to remove a node that smaller than the root
		t->left = remove(x, t->left);
	else if (x.getDays() > t->data.getDays()) //the case in which we want to remove a node that grater than the root
		t->right = remove(x, t->right);
	else if (t->left && t->right)
	{
		temp = findMin(t->right);
		t->data = temp->data;
		t->right = remove(t->data, t->right);
	}
	else //the case in which we want to remove the root ( in this case we have to assign the root another node from the BST such that it keeps the characteristics of a BST
	{
		temp = t;
		if (t->left == nullptr)
			t = t->right;
		else if (t->right == nullptr)
			t = t->left;
		delete temp;
	}
	return t;
}

node* BST::find(node* t, Contract& x)
/*
	function that searches and returns node
	input: Contract& x, node* t
	output: -
*/
{
	if (t == nullptr) // the case in which the BST is empty
		return nullptr;
	else if (x.getDays() < t->data.getDays())	//the node that we want to find is smaller that the root
		return find(t->left, x);
	else if (x.getDays() > t->data.getDays())	//the node that we want to find is grater that the root
		return find(t->right, x);
	else
		return t;
}

BST::BST() //constructor for the class BST
{
	this->root = nullptr; //the BST is empty so the root has no data and points to nothing
}


BST::~BST() //destructor for the class BST
{
	this->root = destroy(this->root); //call the destroy function that deletes the nodes recursively
}

void BST::insert(Contract& x)
/*
	function that inserts a contract
	input: Contract& x
	output: -
*/
{
	this->root = this->insert(x, this->root);
}

void BST::remove(Contract& x)
/*
	function that removes a contract
	input: Contract& x
	output: -
*/
{
	this->root = this->remove(x, this->root);
}

node* BST::search(Contract& x)
/*
	function that searches for a contract in the BST and returns the node containing that contract
	input: Contract& x
	output: node*
*/
{
	//this->root = this->find(this->root, x);
	return this->find(this->root, x);
}

Iterator::Iterator(node * first)
/*
	constructor for the iterator class
*/
{
	if (first == nullptr) //the case in which the BST is empty so we can't iterate through it
		return;
	this->first = first;
	this->current = first;
	this->last = first;

	while (last != nullptr && last->right != nullptr) //we search for the max value
		last = last->right;
	while (current != nullptr && current->left != nullptr) //we search for the min value
		current = current->left;
	s = current; //we keep the minvalue sorted
}

bool Iterator::hasNext()
/*
	function that verifies if the current node "has a next node"
	in other words, it verifies if the next node is valid or not
	input:
	output: true, if the next node is valid, false otherwise
*/
{
	return current != nullptr && current->data.getDays() <= last->data.getDays();
}

node* Iterator::next()
/*
	function that returns the current node and jumps to the next one ( current<-next )
	input: -
	output: node*
*/
{
	if (current != nullptr)
	{
		node* rst = current;
		//the current node has a right child so that node is the next
		if (current->right != nullptr)
		{
			current = current->right;
			while (current->left != nullptr)
			{
				current = current->left;
			}
		}
		else 
		{
		//the urrent node does not have a right child so we have to find the parent of the current node
			current = findParent();
		}
		return rst;
	}
	else //the case in which we are on the last element, so we will move the current on the first ( that's why we stored the min value )
	{
		node* rst = s;
		current = s;
		//the current node has a right child so that node is the next
		if (current->right != nullptr)
		{
			current = current->right;
			while (current->left != nullptr)
			{
				current = current->left;
			}
		}
		else
		{
		//the urrent node does not have a right child so we have to find the parent of the current node
			current = findParent();
		}
		return rst;
	}
	
}

node * Iterator::findParent()
/*
	function that finds the parent of the current node
	input: -
	output: node* (nullptr if it has no parent)
*/
{
	node* node1 = first;
	node* parent = nullptr;
	int x = current->data.getDays();
	if (x == last->data.getDays()) 
	{ 
		//this node is the greatest node in the BST
		return nullptr;
	}
	while (node1 != nullptr) 
	{
		if (x < node1->data.getDays())
		{
			parent = node1;
			node1 = node1->left;
		}
		else if (x > node1->data.getDays())
		{
			node1 = node1->right;
		}
		else 
		{
		//node1 == current
			break;
		}
	}
	return parent;
}
