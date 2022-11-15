#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

template <typename T>
class Node;

template <typename T>
class LinkedList;

template <typename T>
class ListIterator;

template <typename T>
class Node {
public:
	T value;
	Node* next;
	Node();
	Node(T v);
	virtual ~Node();
	T& get();
};

template <typename T>
class LinkedList {
protected:
	Node<T>* root;
	Node<T>* end;
	int size;
public:
	LinkedList();
	virtual ~LinkedList();

	// add the specified element at the end of the list
	void Add(T& value);

	// add the specified element at the specified index
	void Insert(T& value, int index);

	// get the element at the specified index
	T& Get(int index);

	// retrieve the index of the specified element (-1 if it does not exist in the list)
	int IndexOf(T& value);

	// remove the element at the specified index and return it
	T& Remove(int index);

	// return an iterator on this list
	ListIterator<T> Iterator();

	// return the size of the list
	int Size();
};

template <typename T>
class ListIterator {
protected:
	Node<T>* it;
public:
	ListIterator();
	ListIterator(Node<T>* n);
	virtual ~ListIterator();

	// return whether there is another element to return in this iterator
	bool HasNext();

	// return the next element in this iterator
	T& Next();
};
#include "LinkedList.cpp"

#endif

