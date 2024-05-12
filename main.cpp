
#include <iostream>
#include "LinkedList.h"



int main()
{
	LinkedList<int> myList {5, 4, 2, 10};
	
	std::cout << myList << std::endl;

	myList.insertAfter(8, 0);

	std::cout << myList << std::endl;

	myList.removeAfter(3);
	myList.remove();
	myList.remove();

	std::cout << myList << std::endl;
}


