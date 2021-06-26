#include "BinTree.h"

BinTree::BinTree()
{
	root = NULL;
	size = 0;
}

BinTree::~BinTree()
{
	/*if (root != NULL)
	{
		InOrder(root->Left);
		InOrder(root->Right);
		root->~Node();
	}
	root = NULL;
	size = 0;*/
	if (root != NULL)
	{
		PostOrdertoDelete(root);
	}
	//delete root;
	root = NULL;
	size =0;
}

bool BinTree::IsEmpty()
{
	return root == NULL;
}

bool BinTree::IsFull()
{
	return size == MAXITEMS;
}

const int BinTree::Size() const
{
	return size;
}

bool BinTree::Add(Item data)
{
	Node* new_node;

	if (IsFull())
	{
		cerr << "Tree is full" << endl;
		return false;
	}
	if (SeekItem(data).second)
	{
		cerr << "Attempted to add duplicate item" << endl;
		return false;
	}

	new_node = new Node(data);

	if (!new_node)
	{
		cerr << "Couldn't create node" << endl;
		return false;
	}

	++size;

	if (!root)
		root = new_node;
	else
		AddNode(root, new_node);
	return true;
}

bool BinTree::In(Item data)
{
	return SeekItem(data).second;
}

bool BinTree::Delete(Item data)
{
	pair<Node*, Node*> look = SeekItem(data);
	if (!look.second)
	{
		return false;
	}
	else if (!look.first)
	{
		DeleteNode(root);
	}
	else if (look.first->Left == look.second)
	{
		DeleteNode(look.first->Left);
	}
	else
	{
		DeleteNode(look.first->Right);
	}
	size--;
	return 1;
}

void BinTree::Traverse()
{
	InOrder(root);
}

pair<Node*, Node*> BinTree::SeekItem(Item data)
{
	//pair<Node*, Node*> look = make_pair((Node*)NULL, root);
	//look.first - parent
	//look.second - child
	pair <Node*, Node*> look((Node*)NULL, root);
	if (!look.second)
		return look;

	for (; look.second;)
	{
		if (look.second->Data > data)
		{
			look.first = look.second;
			look.second = look.first->Left;
		}
		else if (look.second->Data < data)
		{
			look.first = look.second;
			look.second = look.first->Right;
		}
		else
			break;
	}
	return look;
}

void BinTree::AddNode(Node *&cur, Node* new_node)
{
	if (!cur)
	{
		cur = new_node;
		return;
	}
	if (cur->Data > new_node->Data)
		AddNode(cur->Left, new_node);
	else
		AddNode(cur->Right, new_node);
}

void BinTree::DeleteNode(Node*& cur)
{
	Node* temp = cur;
	if (!cur->Left)
	{
		cur = cur->Right;
	}
	else if (!cur->Right)
	{
		cur = cur->Left;
	}
	else
	{
		for (temp = cur->Left; temp->Right; temp = temp->Right);
		temp->Right = cur->Right;
		temp = cur;
		cur = cur->Left;
	}
	delete temp;
}

void BinTree::InOrder(Node* obj)
{
	if (obj)
	{
		InOrder(obj->Left);
		cout << obj->Data.Name<<" ";
		cout << obj->Data.Kind << endl;
		InOrder(obj->Right);
	}
}
void BinTree::PostOrdertoDelete(Node* obj)
{
	//Node* pright;
	if (obj)
	{
		//pright = obj->Right;
		PostOrdertoDelete(obj->Left);
		PostOrdertoDelete(obj->Right);
		delete obj;
	}
}