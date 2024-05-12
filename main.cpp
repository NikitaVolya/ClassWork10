
#include <iostream>
#include "LinkedList.h"



int main()
{
	LinkedList<int> myList {5, 4, 2, 10};
	
	std::cout << myList << std::endl;

	int* val = myList.find(4);
	*val = 2;

	myList.remove();

	std::cout << myList << std::endl;

	std::cout << (myList.find(11) == nullptr ? "is nullptr" : "is not nullptr");
}


