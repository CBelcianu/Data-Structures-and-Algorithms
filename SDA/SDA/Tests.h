#pragma once
#include "BST.h"
#include "BST.h"
#include "SortedSet.h"
#include <assert.h>
class Tests
/*
	class for running tests
*/
{
public:
	Tests();
	~Tests();
	static void testContract(); //function that tests the Contract class
	static void testBST();		//function that tests the BST class
	static void testSortedSet();//function that tests the SortedSet class
	static void testAll();		//function that runs all the tests
};

