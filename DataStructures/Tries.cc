#include <iostream>
using namespace std;
class node;
void Insert_rec(node*& , int , int ,int );
void Search_rec(node*& , int ,int );

class node{
public:
	int key;
	int val;
	bool leaf;
	node** kids; 
	node(int k ,int v, bool l){
		key = k;
		val = v;
		kids = new node* [2];
		kids[0] = NULL;
		kids[1] = NULL;
		leaf = l;
	}
};

void Insert(node*& root, int k , int v){
	Insert_rec(root, k, v, k);
}

void Insert_rec(node*& n, int k , int v,int acc){
	if(acc == 0){
		if(n){
			cout<<"insert fail"<<endl;
		}else{
			n = new node(k,v,true);
			cout<<"insert succeess" <<endl;
		}
	}else{
		if(n && n->leaf){
			cout<<"insert fail"<<endl;
			return;
		}else if(n){
			int bit = acc%2;
			Insert_rec(n->kids[bit],k,v,acc/2);
		}else{
			n = new node(-1,-1,false);
			int bit = acc%2;
			Insert_rec(n->kids[bit],k,v,acc/2);
		}
	}
}

void Search(node* n, int k){
	Search_rec(n, k, k);
}

void Search_rec(node*& n, int k ,int acc){
	if(acc == 0){
		if(n){
			if(k==n->key){
				cout<<"result: "<< n->val <<endl;
			}else{
				cout<<"key not found" <<endl;
			}
			return;
		}else{
			cout<<"key not found" <<endl;
			return;
		}
	}else{
		if(n){
			int bit = acc%2;
			Search_rec(n->kids[bit],k,acc/2);
		}else{
			cout<<"key not found" <<endl;
			return;
		}
	}
}

void print(node* n){
	if(!n) return;
	if(n->leaf){
		cout<< n->key << " " << n->val<<endl;
	}else{
		if(n->kids[0])
			print(n->kids[0]);
		if(n->kids[1])
			print(n->kids[1]);
	}
}


int main(){
	cout<< "input shoud be :"<<endl;
	cout<< "insert <key> <value>"<<endl;
	cout<< "search <key>"<<endl;
	cout<< "delete <key>"<<endl;
	string cmd; // command from std input
	int k , v; //key and value
	node * trie = NULL;
	while (cin >> cmd){
		if(cmd == "insert"){
			cin>>k;
			cin>>v;
			Insert(trie,k,v);
		}else if (cmd == "search"){
			cin >> k; 
			Search(trie,k);
		}else if (cmd == "print"){
			print(trie);
		}
	}
}

