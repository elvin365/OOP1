#pragma once

#include "string"

using namespace std;

struct Item
{
	string Name;
	string Kind;
	Item() :
		Name(),
		Kind()
	{
	}

	Item(string &name, string &kind):
		Name(name),
		Kind(kind)
	{
	}
	/*Item(string name = "", string kind = "")
	{
		Name = name;
		Kind = kind;
	}*/
	
};

inline bool operator==(const Item& left, const Item& right)
{
	return ((left.Kind == right.Kind) && (left.Name == right.Name));
}

inline bool operator<(const Item& left, const Item& right)
{
	if ((left.Name < right.Name) || ((left.Name == right.Name) && (left.Kind < right.Kind)))
		return true;
	return false;
}

inline bool operator>(const Item& left, const Item& right)
{
	if ((left.Name > right.Name) || ((left.Name == right.Name) && (left.Kind > right.Kind)))
		return true;
	return false;
}

/*ostream& operator << (std::ostream& out, const Item& obj)
{
	out << "Name: " << obj.Name << "\tKind: " << obj.Kind;
	return out;
}*/