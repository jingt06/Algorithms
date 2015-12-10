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

//Transpose: Upon a successful search, swap the accessed item with the
//item immediately preceding it
class TSS{
	public:
		node* first;

		TSS(){
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
				n = n->next;
			}
			if(n){
				cout << "result: "<< n->val<<endl;
				
				
				if(n->pre){
					if(n->pre->pre){ // switch with previous item
						node * pre_node = n->pre;
						pre_node->next = n->next;
						n->pre = n->pre->pre;
						pre_node->pre->next = n;
						pre_node->pre = n;
						if(n->next) n->next->pre = pre_node;
						n->next = pre_node;
					}else{//swith with first element
						n->pre->next = n->next;
						if(n->next) n->next->pre = n->pre;
						n->next = first;
						first = n;
						n->pre = NULL;
					}
				}else{
					//already at first, do nothing
				}
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
	TSS * tss = new TSS();
	while (cin >> cmd){
		if(cmd == "insert"){
			cin >> k;
			cin >> v;
			tss->Insert(k,v);
		}else if(cmd == "delete"){
			cin >> k;
			tss->Delete(k);
		}else if (cmd == "search"){
			cin >> k; 
			tss->Search(k);
		}else if (cmd == "print"){
			tss->print();
		}
	}
}