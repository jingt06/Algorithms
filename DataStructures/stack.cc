#include <iostream>
using namespace std;

// an implementation of stack using linked list

class node {
	public:
		int x;
		node * next;

		node(int n){	// ctor for node
			x = n; 
			next = NULL;
		}
};

class stack {
	public:
		node * first;

		node * pop(){
			if( !first ){ 	// if first is NULL, just return NULL
				cout<<"length of stack is 0, cannot call pop"<<endl;
				return NULL;
			}
			node * poped_node = first;
			node * second_node = first->next;
			first = second_node;
			return poped_node;
		}

		void push(node* n){
			n->next = first;
			first = n;
		}

};

int main(){
	stack * s= new stack();
	cout << "push(1)" <<endl;
	s->push(new node(1));
	cout << "push(2)" <<endl;
	s->push(new node(2));
	cout << "push(3)" <<endl;
	s->push(new node(3));
	cout << "push(4)" <<endl;
	s->push(new node(4));
	cout << "push(5)" <<endl;
	s->push(new node(5));
	cout << "push(6)" <<endl;
	s->push(new node(6));
	cout << "push(7)" <<endl;
	s->push(new node(7));
	cout << "pop 0: "<< s->pop()->x <<endl;
	cout << "pop 1: "<< s->pop()->x <<endl;
	cout << "pop 2: "<< s->pop()->x <<endl;
	cout << "pop 3: "<< s->pop()->x <<endl;
	cout << "pop 4: "<< s->pop()->x <<endl;
	cout << "pop 5: "<< s->pop()->x <<endl;
	cout << "pop 6: "<< s->pop()->x <<endl;
}