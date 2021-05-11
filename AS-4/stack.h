#include <string>
using namespace std;
#ifndef H_STACK
#define H_STACK

class treeNode{
    private:
    char data;
    treeNode* left;
    treeNode* right;
    friend class expression;

};

template<class t>
class Stack;
template<class t>
class node{
	t data;
	node<t>* next;
	friend class Stack<t>;
};

template<class t>
class Stack{
    public:
	node<t>* top;
    Stack();
    void push(t info);
    void pop();
    bool isEmpty();
    t isTop();
};

#endif 