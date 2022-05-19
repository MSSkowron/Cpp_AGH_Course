//
// Created by mateuszskowron on 5/5/22.
//

#ifndef ZAD5MYLISTANDSORTING_DLASTUDENTOW_MYLIST_H
#define ZAD5MYLISTANDSORTING_DLASTUDENTOW_MYLIST_H

#include <iostream>
#include <stdlib.h>
#include <memory>

template <class T>
class MyList {
public:
    typedef T value_type;
    MyList(): head{nullptr} {};
    ~MyList(){
        while(head){
            Node* toRemove = head;
            head = head->next;
            delete toRemove;
        }
    };
    MyList(const MyList&) = delete;
    MyList & operator=(const MyList&) = delete;

    void push_front(T newElem){
        if(!head){
            head = new Node(newElem);
        }
        else {
            Node* newNode = new Node(newElem);
            newNode->next = head;
            head = newNode;
        }
    }
    T pop_front(){
        if(!head){
            throw std::out_of_range("List is empty");
        }
        else {
            T res = head->value;
            Node* toRemove = head;
            head = head->next;
            delete toRemove;
            return res;
        }
    }
    T front(){
        if(!head){
            throw std::out_of_range("List is empty");
        }
        else {
            return head->value;
        }
    }
    [[nodiscard]] int size() const{
        Node* node = this->head;
        if(!node){
            return 0;
        }
        int res = 0;
        while(node) {
            res++;
            node = node->next;
        }
        return res;
    }
    void remove(T value){
        Node* prev = nullptr;
        Node* curr = head;

        while(curr!=nullptr){
            if(curr->value == value){
                Node* toRemove = curr;
                if(prev == nullptr){
                    head = head->next;
                    curr = head;
                }
                else {
                    prev->next = curr->next;
                    curr = curr->next;
                }
                delete toRemove;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    class Node {
    public:
        T value;
        Node* next;
        explicit Node(T t): value{t}, next{nullptr} {}
        Node(): value{}, next{nullptr} {}
    };

    class iterator: public std::iterator<std::forward_iterator_tag,int> {
    private:
        Node* node;
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type  = T;
        using pointer = Node*;
        using reference = Node&;
        iterator(): node(nullptr) {};
        iterator(Node* n): node(n) {};
        iterator& operator++() {
            if(node != nullptr){
                    node = node->next;
            }
            return *this;
        }
        iterator operator++(int){
            iterator tmp = *this;
            ++*this;
            return tmp;
        }
        bool operator!=(const iterator& iter) const {
            return this->node != iter.node;
        }
        T& operator*() const {
            return node->value;
        }
    };

    iterator begin() const {return iterator{head};}
    iterator end() const {return iterator{nullptr};} // Is it right?

    friend std::ostream& operator<<(std::ostream& os, const MyList& myList){
        for(auto iter = myList.begin(); iter != myList.end(); ++iter) {
            os << *iter << ", ";
        }
        return os;
    }

protected:
    Node* head;
};
#endif //ZAD5MYLISTANDSORTING_DLASTUDENTOW_MYLIST_H