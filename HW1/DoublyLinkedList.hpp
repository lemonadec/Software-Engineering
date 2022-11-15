#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include "LinkedList.hpp"

template <typename T>
class DNode;

template <typename T>
class DoublyLinkedList;


template <typename T>
class DNode : public Node<T>{
public:
    DNode* prev;
    DNode* next;
    DNode();
	DNode(T v);
    virtual ~DNode();
};

template <typename T>
class DoublyLinkedList : public LinkedList<T>{
protected:
    DNode<T>* root;
	DNode<T>* end;
public:
	DoublyLinkedList();
	virtual ~DoublyLinkedList();

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
};

#include "DoublyLinkedList.cpp"

#endif

