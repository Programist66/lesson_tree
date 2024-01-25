#include <iostream>
#include <string>
#include "Binaries_Tree.h"

using namespace std;

int main() 
{
	BinaryTree<int> numbers;
	for (int i = 0; i < 10; i++)
	{
		int y = rand() % 100;
		numbers.insert(y);
	}
	numbers.Print();
	numbers.remove(58);
	cout << "=========================" << endl;
	numbers.Print();
	return 0;
}