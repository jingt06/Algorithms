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

// Dictionary ADT using linkedd list:
//      Θ(1) insert;
//      Θ(n) search and delete
class Dict{
	public:
		node* first;

		Dict(){
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
};

int main()
{
	cout<< "input shoud be :"<<endl;
	cout<< "insert <key> <value>"<<endl;
	cout<< "search <key>"<<endl;
	cout<< "delete <key>"<<endl;
	string cmd; // command from std input
	int k , v; //key and value
	Dict * dict = new Dict();
	while (cin >> cmd){
		if(cmd == "insert"){
			cin >> k;
			cin >> v;
			dict->Insert(k,v);
		}else if(cmd == "delete"){
			cin >> k;
			dict->Delete(k);
		}else if (cmd == "search"){
			cin >> k; 
			dict->Search(k);
		}
	}
}