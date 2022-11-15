#include "DoublyLinkedList.hpp"

//********* class DNode
template <typename T>
DNode<T>::DNode():Node<T>(), prev(nullptr), next(nullptr){}

template <typename T>
DNode<T>::DNode(T v):Node<T>(v), prev(nullptr), next(nullptr){}

template <typename T>
DNode<T>::~DNode(){}

//********* class DoublyLinkedList
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList():root(nullptr), end(nullptr){}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){}

template <typename T>
void DoublyLinkedList<T>::Add(T& value){
    ++this->size;
    if (root==nullptr){
        root = new DNode<T>(value);
        end = root;
        return;
    }
    end->next = new DNode<T>(value);
    end->next->prev = end;
    end = end->next;
    return;
}

// add the specified element at the specified index
template <typename T>
void DoublyLinkedList<T>::Insert(T& value, int index){
    if(index>this->size)
        throw std::out_of_range("Index out of range");
    ++this->size;
    DNode<T>* newnode = new DNode<T>(value);
    if (index==0){
        newnode->next = root;
        root->prev = newnode;
        root = newnode;
    }
    else if (index == this->size-1){
        end->next = newnode;
        newnode->prev = end;
        end = end->next;
    }
    else if (index < (this->size>>1)){
        auto prev = root;
        for(int i=0;i<index-1;++i)            
            prev = prev->next;
        newnode->next = prev->next;
        newnode->prev = prev;
        newnode->next->prev = newnode;
        prev->next = newnode;
    }
    else{
        auto next = end;
        for(int i=0;i<this->size-2-index;++i)            
            next = next->prev;
        newnode->next = next;
        newnode->prev = next->prev;
        next->prev = newnode;
        newnode->prev->next = newnode;
    }
    return;
}

// get the element at the specified index
template <typename T>
T& DoublyLinkedList<T>::Get(int index){
    if (index>=this->size)
        throw std::out_of_range("Index out of range");
    if (index < (this->size>>1)){
        auto cur = root;
        for (int i=0;i<index;++i)
            cur = cur->next;
        return cur->value;
    }
    auto cur = end;
    for (int i=0;i<this->size-index-1;++i)
        cur = cur->prev;
    return cur->value;
}

// retrieve the index of the specified element (-1 if it does not exist in the list)
template <typename T>
int DoublyLinkedList<T>::IndexOf(T& value){
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
T& DoublyLinkedList<T>::Remove(int index){
    if (index>=this->size)
        throw std::out_of_range("Index out of range");
    --this->size;
    if (index==0){
        auto cur = root;
        root = root->next;
        root->prev = nullptr;
        return cur->value;
    }
    else if (index==this->size){
        auto cur = end;
        end = end->prev;
        end->next = nullptr;
        return cur->value;
    }
    else if (index < (this->size>>1)){
        auto prev = root;
        for (int i=0;i<index-1;++i)
            prev = prev->next;
        auto cur = prev->next;
        prev->next = prev->next->next;
        prev->next->prev = prev;
        return cur->value;
    }
    else{
        auto next = end;
        for (int i=0;i<this->size-1-index;++i)
            next = next->prev;
        auto cur = next->prev;
        next->prev = next->prev->prev;
        next->prev->next = next;
        return cur->value;
    }
}

// return an iterator on this list
template <typename T>
ListIterator<T> DoublyLinkedList<T>::Iterator(){
    return ListIterator<T>(root);
}

