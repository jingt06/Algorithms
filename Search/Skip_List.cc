#include <iostream>
#include <stdlib.h>    
#include <time.h>      
using namespace std;

int toss();

class node{ // key value pair
public:
	int key;
	int val;
	bool bound;
	node* next;
	node* down;
	node* pre;
	node(int k, int v, node* n = NULL){
		key = k ;
		val = v ;
		bound = false;
		next = n;
		down = NULL;
		pre = NULL;
	}
	node(bool b){
		bound = b;
		next = NULL;
		down = NULL;
		pre = NULL;
	}
};

class Skip_List{ // a Skip list with maximun height 4
public:
	node* S3;
	node* S2;
	node* S1;
	node* S0;

	Skip_List(){
		S0 = new node(true);
		S1 = new node(true);
		S2 = new node(true);
		S3 = new node(true);
		S3->down = S2;
		S2->down = S1;
		S1->down = S0;
	}
	void Insert(int k, int v){
		node* iterator = S3;
		node* S1_insert = NULL;
		node* S2_insert = NULL;
		node* S3_insert = NULL;
		while((iterator->next &&  (k >= iterator->next->key || iterator->bound)) || iterator->down){
			if(iterator->next &&  k >= iterator->next->key){
				iterator = iterator->next;
			}else if(iterator->down){
				if(!S3_insert){
					S3_insert = iterator;
				}else if(!S2_insert){
					S2_insert = iterator;
				}else if(!S1_insert){
					S1_insert = iterator;
				}
				iterator = iterator->down;
			}else if(iterator->bound && !iterator->down){
				break;
			}
		}
		if(iterator->key == k){
			cout<<"duplicate key, insert fail"<<endl;
			return;
		}
		node* new_node = new node(k,v,iterator->next);
		node* pre_node = new_node;
		if(iterator->next) iterator->next->pre = new_node;
		new_node->pre = iterator;
		iterator->next = new_node;
		int n = toss();
		if(n >= 1){
			new_node = new node(k,v,S1_insert->next);
			if(S1_insert->next) S1_insert->next->pre = new_node;
			new_node->pre = S1_insert;
			S1_insert->next = new_node;
			new_node->down = pre_node;
			pre_node = new_node;
		}
		if(n >= 2){
			new_node = new node(k,v,S2_insert->next);
			if(S2_insert->next) S2_insert->next->pre = new_node;
			new_node->pre = S2_insert;
			S2_insert->next = new_node;
			new_node->down = pre_node;
			pre_node = new_node;
		}
		if(n >= 3){
			new_node = new node(k,v,S3_insert->next);
			if(S3_insert->next) S3_insert->next->pre = new_node;
			new_node->pre = S3_insert;
			S3_insert->next = new_node;
			new_node->down = pre_node;
			pre_node = new_node;
		}
		cout<<"insert success"<<endl;
	}
	void Search(int k){
		node* iterator = S3;
		while((iterator->next && k >= iterator->next->key) || iterator->down){
			if(iterator->next &&  k >= iterator->next->key){
				iterator = iterator->next;
			}else if(iterator->down){
				iterator = iterator->down;
			}
		}
		if(iterator->key == k){
			cout<<"result: "<< iterator->val <<endl;
		}else{
			cout<<"key not found, search fail"<<endl;
		}
	}
	void Delete(int k){
		node* iterator = S3;
		while((iterator->next && k >= iterator->next->key) || iterator->down){
			if(iterator->key == k && !iterator->bound){
				break;
			}else if(iterator->next &&  k >= iterator->next->key){
				iterator = iterator->next;
			}else if(iterator->down){
				iterator = iterator->down;
			}
		}
		if(iterator->key != k || iterator->bound){
			cout<<"key not found, delete fail"<<endl;
			return;
		}else{
			while(iterator){
				if(iterator->next){
					iterator->next->pre = iterator->pre;
				}
				iterator->pre->next = iterator->next;
				node* down_node = iterator->down;
				delete iterator;
				iterator = down_node;
			}
		}
	}

	void print(){
		node* iterator = S3;
		while(iterator){
			cout<< iterator->key<< " ";
			iterator = iterator->next;
		}
		cout<<endl;
		iterator = S2;
		while(iterator){
			cout<< iterator->key<< " ";
			iterator = iterator->next;
		}
		cout<<endl;
		iterator = S1;
		while(iterator){
			cout<< iterator->key<< " ";
			iterator = iterator->next;
		}
		cout<<endl;
		iterator = S0;
		while(iterator){
			cout<< iterator->key<< " ";
			iterator = iterator->next;
		}
		cout<<endl;
	}
};

int toss(){
	int count = 0;
	while(rand() % 2 == 1){
		++count;
	}
	if(count > 3) count = 3;
	return count; 
}

int main()
{
	srand(time(NULL));
	cout<< "input shoud be :"<<endl;
	cout<< "insert <key> <value>"<<endl;
	cout<< "search <key>"<<endl;
	cout<< "delete <key>"<<endl;
	cout<< "print"<<endl;
	string cmd; // command from std input
	int k , v; //key and value
	Skip_List * skip_list = new Skip_List();
	while (cin >> cmd){
		if(cmd == "insert"){
			cin >> k;
			cin >> v;
			skip_list->Insert(k,v);
		}else if (cmd == "search"){
			cin >> k; 
			skip_list->Search(k);
		}else if (cmd == "delete"){
			cin >> k; 
			skip_list->Delete(k);
		}else if (cmd == "print"){
			skip_list->print();
		}

	}
}