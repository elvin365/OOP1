#pragma once

#include "item.h"

using namespace std;

struct Node
{
	Node* Left;
	Node* Right;
	Item Data;

	Node(Item data, Node* left=nullptr, Node* right=nullptr):Data(data)
	{
		Data = data;
		Left = left;
		Right = right;


	}
	Node(const Node& source)//copy
	{
		Data = source.Data;
		if (Left)
		{
			Left = source.Left;
		}
		if (Right)
		{
			Right = source.Right;
		}
		Data = source.Data;
	}
	/*~Node()
	{
		
		/*if (Left)
		{
			delete Left;
			Left = NULL;
		}
		if (Right)
		{
			delete Right;
			Right = NULL;
		}
		//delete this;
	}*/

};