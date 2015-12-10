#include <iostream>
using namespace std;

class node{
	public:
		int key;
		int val;
		node* next;
		node* pre;

		node(int k, int v){
			key = k;
			val = v;
			pre = NULL;
		}
};

//Move-To-Front(MTF): Upon a successful search, move the accessed
//item to the front of the list
class MTF{
	public:
		node* first;

		MTF(){
			first = NULL;
		}

		void Insert(int k, int v){
			node* n = new node(k,v);
			n->next = first;
			if(first) first->pre = n;
			first = n;
			cout<<"insert success"<<endl;
		}

		// using linear search Θ(n)
		int Search(int k){
			node* n = first;
			while(n && n->key != k){
				cout<<"a";
				n = n->next;
			}
			if(n){
				cout << "result: "<< n->val<<endl;
				if(n->pre) n->pre->next = n->next;
				else first = n->next;
				if(n->next) n->next->pre = n->pre;
				n->next = first;
				n->pre = NULL;
				first = n;
				return n->val;
			}else{
				cout << "key not found"<< endl;
			}
			return 0;
		}

		int Delete(int k){
			node* n = first;
			while(n && n->key != k){
				n = n->next;
			}
			if(n){
				if(n->pre){ // n have a previous item
					n->pre->next = n->next;
					delete n;
				}else{ // n is first item in the linked list
					first = n->next;
					delete n;
				}
				cout<< "delete success"<<endl;
			}else{
				cout << "key not found"<< endl;
			}
			return 0;
		}
		void print(){
			node* iterator = first;
			while(iterator){
				cout<< iterator->key <<" "<< iterator->val <<endl;
				iterator = iterator->next;
			}
		}
};

int main()
{
	cout<< "input shoud be :"<<endl;
	cout<< "insert <key> <value>"<<endl;
	cout<< "search <key>"<<endl;
	cout<< "delete <key>"<<endl;
	cout<< "print"<<endl;
	string cmd; // command from std input
	int k , v; //key and value
	MTF * mtf = new MTF();
	while (cin >> cmd){
		if(cmd == "insert"){
			cin >> k;
			cin >> v;
			mtf->Insert(k,v);
		}else if(cmd == "delete"){
			cin >> k;
			mtf->Delete(k);
		}else if (cmd == "search"){
			cin >> k; 
			mtf->Search(k);
		}else if (cmd == "print"){
			mtf->print();
		}
	}
}