#pragma once

#include <iostream>

template <typename T>
struct Node
{
	T value;
	Node<T>* next;
};

template <typename T>
class LinkedList
{
private:
	Node<T>* head;
	size_t size;
public:
	LinkedList() : head(nullptr), size(0) {};
	LinkedList(const std::initializer_list<T>& elements);
	~LinkedList();

	void addfirst(T value);
	void remove();

	size_t getSize() const { return size; };

	T& getElement(int index) const;
	T& operator[](int);
	const T& operator[](int) const;
};

template<typename T>
inline LinkedList<T>::LinkedList(const std::initializer_list<T>& elements) : LinkedList()
{
	for (const T* element = elements.end() - 1; element != elements.begin() - 1; element--)
		addfirst(*element);
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* pointer = head;
	while (pointer != nullptr)
	{
		Node<T>* tmp = pointer->next;
		delete pointer;
		pointer = tmp;
	}
}

template<typename T>
void LinkedList<T>::addfirst(T value)
{
	head = new Node<T>{ value, head };
	size++;
}

template<typename T>
inline void LinkedList<T>::remove()
{
	if (!head)
		return;

	Node<T>* tmp = head;
	head = head->next;

	delete tmp;
	size--;
}

template<typename T>
inline T& LinkedList<T>::getElement(int index) const
{
	if (index < 0 || index >= size)
		throw std::out_of_range("Invalid index");

	Node<T>* pointer = head;
	while (index-- > 0)
		pointer = pointer->next;
	return pointer->value;
}

template<typename T>
inline T& LinkedList<T>::operator[](int index)
{
	return getElement(index);
}

template<typename T>
inline const T& LinkedList<T>::operator[](int index) const
{
	return getElement(index);
}
