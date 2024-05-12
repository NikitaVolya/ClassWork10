
#include <iostream>
#include "LinkedList.h"



int main()
{
	LinkedList<int> myList {5, 4, 2, 10};
	
	std::cout << myList << std::endl;

	myList.insert(8, 4);

	std::cout << myList << std::endl;
}


