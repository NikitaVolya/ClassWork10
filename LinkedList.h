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

	T* find(const T& value);

	void appfirst(const T& value);
	void append(const T& value);

	void insertAfter(const T& value, int index);

	void remove(); 
	void removeAfter(int index);

	size_t getSize() const { return size; };

	T& getElement(int index) const;
	T& operator[](int);
	const T& operator[](int) const;

	void print(std::ostream& out) const;
	friend std::ostream& operator<<(std::ostream& out, const LinkedList& lst)
	{
		lst.print(out);
		return out;
	}
};

template<typename T>
inline LinkedList<T>::LinkedList(const std::initializer_list<T>& elements) : LinkedList()
{
	for (const T* element = elements.end() - 1; element != elements.begin() - 1; element--)
		appfirst(*element);
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
inline T* LinkedList<T>::find(const T& value)
{
	Node<T>* tmp = head;
	while (tmp)
	{
		if (tmp->value == value)
			return &tmp->value;
		tmp = tmp->next;
	}
	return nullptr;
}

template<typename T>
void LinkedList<T>::appfirst(const T& value)
{
	head = new Node<T>{ value, head };
	size++;
}

template<typename T>
inline void LinkedList<T>::append(const T& value)
{
	Node<T>* pointer = head;
	while (pointer->next)
		pointer = pointer->next;

	pointer->next = new Node<T>{ value, nullptr };
	size++;
}

template<typename T>
inline void LinkedList<T>::insertAfter(const T& value, int index)
{
	if (index < 0 || index >= size)
		throw std::out_of_range("Invalid index");

	Node<T>* pointer = head;
	while (index-- > 0)
		pointer = pointer->next;
	
	Node<T>* newNode = new Node<T>{ value, pointer->next };
	pointer->next = newNode;
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
inline void LinkedList<T>::removeAfter(int index)
{
	if (index < 0 || index >= size)
		throw std::out_of_range("Invalid index");

	Node<T>* pointer = head;
	while (index-- > 0)
		pointer = pointer->next;

	Node<T>* tmp = pointer->next;
	if (tmp)
	{
		if (!tmp->next)
		{
			pointer->next = nullptr;
			delete tmp;
		}
		else
		{
			pointer->next = tmp->next;
			delete tmp;
		}
		size--;
	}
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

template<typename T>
inline void LinkedList<T>::print(std::ostream& out) const
{
	out << "[ ";
	Node<T>* tmp = head;
	while (tmp)
	{
		out << tmp->value;
		if (tmp->next)
			out << ", ";
		tmp = tmp->next;
	}
	out << " ]";
}
