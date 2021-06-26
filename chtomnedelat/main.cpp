#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"BinTree.h"
#include"menu.h"
//extern BinTree mytree;
int main()
{

	BinTree mytree;
	char choise;
	while ((choise = menu::choose()) != 'q')
	{
		switch (choise)
		{
		case 'a': menu::addpet(mytree); break;
		case'l': menu::showpets(mytree); break;
		case'f': menu::findpet(mytree); break;
		case'd':menu::droppet(mytree); break;
		case'n':menu::countpets(mytree); break;
		case'p':menu::loadfile(mytree); break;
		default: cout << ("Switching error"); break;
		}
	}
	//mytree.~BinTree();
	
	


	//menu::addpet(mytree);
	return 0;
}