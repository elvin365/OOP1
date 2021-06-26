#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "BinTree.h"
#include <fstream>
#include <algorithm>

class menu
{
private:
	
	static void upp(string& str);
public:
	
	static void addpet(BinTree &mytree);
	static void showpets(BinTree &mytree);
	static void findpet(BinTree& mytree);
	static void countpets(BinTree& mytree);
	static void droppet(BinTree& mytree);
	static char choose();
	static void loadfile(BinTree& mytree);
};
void menu::upp(string& str)
{
	unsigned k = str.length();
	//std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	for (unsigned i = 0;i< k; i++)
	{
		str[i] = toupper(str[i]);
	}
	
}
void menu::addpet(BinTree &mytree)
{
	Item temp;
	cout << "Please enter name of pet: " << endl;
	//std:sin >> temp.Name;
	cin.ignore(32767, '\n');
	getline(std::cin, temp.Name);
	cout << "Please enter pet kind: " << endl;
	getline(std::cin, temp.Kind);
	upp(temp.Name);
	upp(temp.Kind);
	mytree.Add(temp);
}
void menu::showpets(BinTree &mytree)
{
	if (mytree.IsEmpty())
	{
		cerr << "No entries!";
	}
	else
		mytree.Traverse();

}
void menu::findpet(BinTree& mytree)
{

	Item temp;
	if (mytree.IsEmpty())
	{
		cerr << "No entries!";
		return;
	}

	cout << "Please enter name of pet: " << endl;
	//std:sin >> temp.Name;
	cin.ignore(32767, '\n');
	getline(std::cin, temp.Name);
	cout << "Please enter pet kind: " << endl;
	getline(std::cin, temp.Kind);
	upp(temp.Name);
	upp(temp.Kind);
	cout << temp.Name <<" "<< temp.Kind<<" ";
	if (mytree.In(temp))
	{
		cout << "is a member!" << endl;
	}
	else
		cout << "is not a member!" << endl;

}
void menu::countpets(BinTree& mytree)
{
	cout << "There are "<<mytree.Size()<<" pets"<<endl;
}
void menu::droppet(BinTree& mytree)
{
	Item temp;
	if (mytree.IsEmpty())
	{
		cerr << "No entries!";
		return;
	}

	cout << "Please enter name of pet you wish to delete: " << endl;
	//std:sin >> temp.Name;
	cin.ignore(32767, '\n');
	getline(std::cin, temp.Name);
	cout << "Please enter pet kind: " << endl;
	getline(std::cin, temp.Kind);
	upp(temp.Name);
	upp(temp.Kind);
	cout << temp.Name << " "<< temp.Kind;
	if (mytree.Delete(temp))
	{
		cout << " is deleted from the club"<<endl;
	}
	else
		cout << " is not a member"<< endl;


}

char menu::choose()
{
	char ch;
	cout << "Nerfville Pet Club Membership Program"<<endl;
	cout << "Enter the letter corresponding to your choice:" << endl;
	cout << "a) add a pet          l) show list of pets" << endl;
	cout << "n) number of pets     f) find pets" << endl;
	cout << "d) delete a pet       q) quit" << endl;
	cout << "p)load from file" << endl;

	string letters = "alrfndq";
	while (1)
	{
		cin >> ch;
		//cin.ignore(32767, '\n');
		ch = tolower(ch);
		if (!(letters.find_first_of(ch, 1)))
		{
			cerr << "Please enter an a,l,n,f,d,q";
		}
		else
			break;
	}
	if (ch == EOF)
		ch = 'q';
	
	return ch;
}

void menu::loadfile(BinTree& mytree)
{
	string str;
	char* forstr;
	Item temp;
	ifstream myfile ("C:\\Users\\Elvin\\source\\repos\\chtomnedelat1\\petsdata.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, str,'\n'))
		{
			char *cstr = new char[str.length() + 1];
			strcpy(cstr, str.c_str());
			// do stuff
			forstr = strtok(cstr, " ");
			while (forstr)
			{
				if (temp.Name != "\0")
				{
					temp.Kind = forstr;

				}
				if (temp.Name=="\0")
				{
					temp.Name = forstr;
				}
				
				forstr = strtok(NULL, " ");
			}
			upp(temp.Name);
			upp(temp.Kind);
			mytree.Add(temp);
			temp.Kind.clear();
			temp.Name.clear();
			delete[] cstr;
		}

		myfile.close();
	}
}
