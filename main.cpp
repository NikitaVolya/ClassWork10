
#include <iostream>
#include "LinkedList.h"



int main()
{
	LinkedList<int> myList {5, 4, 2, 10};
	
	for (int i = 0; i < myList.getSize(); i++)
		std::cout << myList[i] << ", ";

	std::cout << std::endl;

	myList.remove();

	for (int i = 0; i < myList.getSize(); i++)
		std::cout << myList[i] << ", ";
}


