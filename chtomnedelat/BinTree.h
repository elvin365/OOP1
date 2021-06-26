#pragma once
#include "iostream"
#include "item.h"
#include "Node.h"
#include"string"
#define MAXITEMS 10

using namespace std;

class BinTree
{
public:
	BinTree();

	~BinTree();

	bool IsEmpty();
	bool IsFull();
	const int Size() const;

	bool Add(Item data);
	bool In(Item data);
	bool Delete(Item data);
	void Traverse();

private:
	int size;
	Node* root;

	pair<Node*, Node*> SeekItem(Item data);
	void AddNode(Node *&cur, Node* new_node);
	void DeleteNode(Node*& cur);
	void InOrder(Node* obj);
	void PostOrdertoDelete(Node* obj);

};

