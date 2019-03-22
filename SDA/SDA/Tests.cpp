#include "Tests.h"



Tests::Tests()
{
}


Tests::~Tests()
{
}

void Tests::testContract()
{
	Contract c{ 2,"Neuer" };
	assert(c.getDays() == 2);
	assert(c.getPlayer() == "Neuer");
	c.sim(1);
	assert(c.getDays() == 1);
}

void Tests::testBST()
{
	BST myBst;
	Contract c1{ 6,"Neuer" };
	Contract c2{ 3,"Abc" };
	Contract c3{ 5,"Xyz" };
	Contract c4{ 9,"Xyz" };
	Contract c5{ 8,"Xyz" };
	Contract c6{ 10,"Xyz" };
	myBst.insert(c1);
	myBst.insert(c2);
	myBst.insert(c3);
	myBst.insert(c4);
	myBst.insert(c5);
	assert(myBst.getRoot()->data.getDays() == c1.getDays());
	assert(myBst.search(c2)->data.getDays() == c2.getDays());
	assert(myBst.search(c4)->data.getDays() == c4.getDays());
	myBst.remove(c1);
	assert(myBst.getRoot()->data.getDays() == c5.getDays());
	myBst.remove(c3);
	myBst.remove(c6);
	myBst.remove(c5);
	myBst.remove(c4);
}

void Tests::testSortedSet()
{
	SortedSet set;
	Contract c1{ 6,"Neuer" };
	Contract c2{ 3,"Abc" };
	Contract c3{ 5,"Xyz" };
	Contract c4{ 9,"Xyz" };
	Contract c5{ 8,"Xyz" };
	Contract c6{ 10,"Xyz" };
	set.insertSS(c1);
	set.insertSS(c2);
	set.insertSS(c3);
	set.insertSS(c4);
	set.insertSS(c5);
	set.insertSS(c6);
	assert(set.getSize() == 6);
	set.removeSS(c1);
	set.removeSS(c3);
	assert(set.getSize() == 4);
	assert(set.searchSS(c5)->data.getDays() == c5.getDays());
	Iterator* it = set.iter();
	assert(it->next()->data.getDays() == c2.getDays());
	assert(it->next()->data.getDays() == c5.getDays());
	assert(it->hasNext() == 1);
	it->next();
	it->next();
	assert(it->hasNext()==0);
	assert(it->next()->data.getDays() == c2.getDays());

	SortedSet ss;
	Contract d1{ 9,"Player 1" };
	Contract d2{ 3,"Player 2" };
	Contract d3{ 4,"Player 3" };
	Contract d4{ 2,"Player 4" };
	Contract d5{ 15,"Player 5" };
	Contract d6{ 18,"Player 6" };
	Contract d7{ 11,"Player 7" };
	ss.insertSS(d1);
	ss.insertSS(d2);
	ss.insertSS(d3);
	ss.insertSS(d4);
	ss.insertSS(d5);
	ss.insertSS(d6);
	ss.insertSS(d7);
	Iterator* j = ss.iter();
	for (int i = 0; i < ss.getSize(); i++)
	{
		node* c = j->next();
		c->data.sim(6);
	}
	for (int i = 0; i < ss.getSize(); i++)
	{
		node* c = j->next();
		//Contract ct{ c->data.getDays() + s,c->data.getPlayer() };
		if (c->data.getDays() <= 0) {
			ss.removeSS(c->data);
			j = ss.iter();
		}
	}
	for (int i = 0; i < ss.getSize(); i++)
	{
		node* c = j->next();
		c->data.sim(6);
	}
	for (int i = 0; i < ss.getSize(); i++)
	{
		node* c = j->next();
		//Contract ct{ c->data.getDays() + s,c->data.getPlayer() };
		if (c->data.getDays() <= 0) {
			ss.removeSS(c->data);
			j = ss.iter();
		}
	}
	assert(ss.getSize() == 2);
}

void Tests::testAll()
{
	testContract();
	testBST();
	testSortedSet();
}
