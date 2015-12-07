#include <iostream>
using namespace std;

class KVP{ // key value pair
public:
	int key;
	int val;
	bool deleted;
	KVP(int k, int v){
		key = k ;
		val = v ;
		deleted = false;
	}
};

class Hashing{
	KVP ** kvps; // length of 10;
public:
	Hashing(){
		kvps = new KVP * [11];
		for(int i = 0 ; i < 11 ; i++){ 
			kvps[i] = NULL; // set all KVP to NULL
		}
	}

	void Insert(int k , int v){
		int key = k % 11;
		int count = 0;
		while( kvps[key] && (!kvps[key]->deleted || kvps[key]->key != k)){ 
			// loop until find a slot that is NULL or is deleted or have the right key
			count++;
			key = (k + count) % 11;
			if(count == 11){
				cout << "hash table full, insert fail" << endl;
				return;
			}
		}
		if(kvps[key]) {
			if(kvps[key]->key == k && !kvps[key]->deleted)
				cout << "key of " << k << " already exists, update value" << endl;
			else 
				cout<< "insert success" <<endl;
			delete kvps[key];
			kvps[key] = new KVP(k,v);
			return;
		}else if(!kvps[key]){
			kvps[key] = new KVP(k,v);
			cout<< "insert success" <<endl;
			return;
		}
	}
	void Delete(int k){
		int key = k % 11;
		int count = 0;
		while( kvps[key] && kvps[key]->key != k){ 
			// loop until find a NULL slot or have the right key
			count++;
			key = (k + count) % 11;
			if(count == 11){
				cout << "key not found , delete fail" << endl;
				return;
			}
		}
		
		if(kvps[key]) {
			if(kvps[key]->key == k){
				kvps[key]->deleted = true;
				cout<< "delete success"<<endl;
			}
			return;
		} else if(!kvps[key]){
			cout<< "key not found , delete fail" <<endl;
			return;
		}
	}

	void Search(int k){
		int key = k % 11;
		int count = 0;
		while( kvps[key] && (kvps[key]->key != k || !kvps[key]->deleted)){ 
			// loop until find a NULL slot or have the right key
			count++;
			key = (k + count) % 11;
			if(count == 11){
				cout << "hash table full, insert fail" << endl;
				return;
			}
		}
		
		if(kvps[key]) {
			if(kvps[key]->key == k && !kvps[key]->deleted)
				cout << "key of " << k << " have value " << kvps[key]->val << endl;
			else 
				cout<< "search fail, key not found" <<endl;
			return;
		} else if(!kvps[key]){
			cout<< "search fail, key not found" <<endl;
			return;
		}
	}
	void Print(){
		for(int i = 0 ; i < 11 ; ++i){
			if(kvps[i] && kvps[i]->deleted)
				cout << i << " " << kvps[i]->key << " " << kvps[i]->val << " deleted" <<endl;
			else if(kvps[i])
				cout << i << " " << kvps[i]->key << " " << kvps[i]->val <<endl;
			else 
				cout << i <<endl;
		}
	}
};

int main()
{
	cout<< "input shoud be :"<<endl;
	cout<< "insert <key> <value>"<<endl;
	cout<< "search <key>"<<endl;
	cout<< "delete <key>"<<endl;
	cout<< "print" <<endl;
	cout<< "key must between 0 and 99"<<endl;
	string cmd; // command from std input
	int k , v; // key and value
	Hashing * hashing = new Hashing();
	while (cin >> cmd){
		if(cmd == "insert"){
			cin >> k;
			cin >> v;
			hashing->Insert(k,v);
		}else if(cmd == "delete"){
			cin >> k;
			hashing->Delete(k);
		}else if (cmd == "search"){
			cin >> k; 
			hashing->Search(k);
		}else if (cmd == "print"){
			hashing->Print();
		}
	}
}