#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "tree.h"
#include <time.h>

using namespace std;

int randnum(Tree<int>& mytree)
{
	int number;
	int xran;
	cout << "How many number do you want to insert : ";
	cin >> xran;
	for (int i = 0; i < xran; i++)
	{
		number = rand() % 100 + 1;
		cout << number << "     --------Number" << i + 1 << endl;
		mytree.insert(number);
	}
	return 0;
}

void search(Tree<int> &mytree)
{
	int findnum;
	cout << "Enter the number Your want to find :";
	cin >> findnum;
	mytree.search(mytree.root, findnum);
}

void main() {
	srand(time(NULL));  
	Tree<int> mytree;
	randnum(mytree);
	mytree.inorder();
	cout << endl << "Height of this tree is : " << mytree.getheight() << endl;

	search(mytree);

}
