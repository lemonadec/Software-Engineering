#include "LinkedList.hpp"
#include <stdexcept>

//********* class Node
template <typename T>
Node<T>::Node():next(nullptr){}

template <typename T>
Node<T>::Node(T v):value(v), next(nullptr){}

template <typename T>
Node<T>::~Node(){}

//********* class LinkedList
template <typename T>
LinkedList<T>::LinkedList():root(nullptr), end(nullptr), size(0){}

template <typename T>
LinkedList<T>::~LinkedList(){}

template <typename T>
void LinkedList<T>::Add(T& value){
    ++size;
    if (root==nullptr){
        root = new Node<T>(value);
        end = root;
        return;
    }
    end->next = new Node<T>(value);
    end = end->next;
    return;
}

// add the specified element at the specified index
template <typename T>
void LinkedList<T>::Insert(T& value, int index){
    if(index>size)
        throw std::out_of_range("Index out of range");
    ++size;
    Node<T>* newnode = new Node<T>(value);
    if (index==0){
        newnode->next = root;
        root = newnode;
        return;
    }
    auto prev = root;
    for(int i=0;i<index-1;++i)            
        prev = prev->next;
    newnode->next = prev->next;
    prev->next = newnode;
    return;
}

// get the element at the specified index
template <typename T>
T& LinkedList<T>::Get(int index){
    if (index>=size)
        throw std::out_of_range("Index out of range");
    auto cur = root;
    for (int i=0;i<index;++i)
        cur = cur->next;
    return cur->value;
}

// retrieve the index of the specified element (-1 if it does not exist in the list)
template <typename T>
int LinkedList<T>::IndexOf(T& value){
    auto cur = root;
    int cnt = 0;
    while(cur){
        if (cur->value == value)
            return cnt;
        ++cnt;
        cur = cur->next;
    }
    return -1;
}

// remove the element at the specified index and return it
template <typename T>
T& LinkedList<T>::Remove(int index){
    if (index>=size)
        throw std::out_of_range("Index out of range");
    --size;
    if (index==0){
        auto cur = root;
        root = root->next;
        return cur->value;
    }
    auto prev = root;
    for (int i=0;i<index-1;++i)
        prev = prev->next;
    auto cur = prev->next;
    prev->next = prev->next->next;
    return cur->value;
}

// return an iterator on this list
template <typename T>
ListIterator<T> LinkedList<T>::Iterator(){
    return ListIterator<T>(root);
}

// return the size of the list
template <typename T>
int LinkedList<T>::Size(){
    return size;
}

//********* class ListIterator
template <typename T>
ListIterator<T>::ListIterator():it(nullptr){}

template <typename T>
ListIterator<T>::ListIterator(Node<T>* n):it(n){}

template <typename T>
ListIterator<T>::~ListIterator(){}

// return whether there is another element to return in this iterator
template <typename T>
bool ListIterator<T>::HasNext(){
    return it != nullptr;
}

// return the next element in this iterator
template <typename T>
T& ListIterator<T>::Next(){
    if (!it)
        throw std::out_of_range("There is no next iterator");
    T& ans = it->value;
    it = it->next;
    return ans;
}