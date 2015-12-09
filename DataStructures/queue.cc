#include <iostream>
using namespace std;

// an implementation of queue using linked list

class node {
	public:
		int x;//sssss
		node * next;

		node(int n){	// ctor for node
			x = n; 
			next = NULL;
		}
};

class queue {
	public:
		node * first;

		void enqueue(node * n){
			node ** iterator = &first; // iterator is a pointer to a pointer of a node
			while (*iterator){  // Loop until the pointer to the node pointer is NULL
				iterator = &(*iterator)->next;
			}
			*iterator = n; // set the pointer that pointing to NULL points to n;
		}

		node * dequeue(){
			if( !first ){ 	// if first is NULL, return NULL
				cout<<"length of queue is 0, cannot call dequeue"<<endl;
				return NULL;
			}
			node * deququed_node = first;
			node * second_node = first->next;
			first = second_node;
			return deququed_node;
		}

};

int main(){
	queue * q= new queue();
	cout << "enqueue(1)" <<endl;
	q->enqueue(new node(1));
	cout << "enqueue(2)" <<endl;
	q->enqueue(new node(2));
	cout << "enqueue(3)" <<endl;
	q->enqueue(new node(3));
	cout << "enqueue(4)" <<endl;
	q->enqueue(new node(4));
	cout << "enqueue(5)" <<endl;
	q->enqueue(new node(5));
	cout << "enqueue(6)" <<endl;
	q->enqueue(new node(6));
	cout << "enqueue(7)" <<endl;
	q->enqueue(new node(7));
	cout << "dequeue 0: "<< q->dequeue()->x <<endl;
	cout << "dequeue 1: "<< q->dequeue()->x <<endl;
	cout << "dequeue 2: "<< q->dequeue()->x <<endl;
	cout << "dequeue 3: "<< q->dequeue()->x <<endl;
	cout << "enqueue(8)" <<endl;
	q->enqueue(new node(8));
	cout << "enqueue(9)" <<endl;
	q->enqueue(new node(9));
	cout << "dequeue 4: "<< q->dequeue()->x <<endl;
	cout << "dequeue 5: "<< q->dequeue()->x <<endl;
	cout << "dequeue 6: "<< q->dequeue()->x <<endl;
	cout << "dequeue 7: "<< q->dequeue()->x <<endl;
	cout << "dequeue 8: "<< q->dequeue()->x <<endl;
}
