#include <iostream>
using namespace std;

class KVP{ // key value pare
public:
	int key;
	int val;
	KVP * next;
	KVP(int k, int v, KVP * n = NULL){
		key = k ;
		val = v ;
		next = n ;
	}
};

class Hashing{
	KVP ** kvps; // length of 100;
public:
	Hashing(){
		kvps = new KVP * [11]; // hashing function is x % 11
		for(int i = 0 ; i < 100 ; i++){ 
			kvps[i] = NULL; // set all KVP to NULL
		}
	}

	void Insert(int k , int v){
		int key = k % 11;
		if(!kvps[key]){
			kvps[key] = new KVP(k,v);
			cout<<"insert success"<<endl;
		}else {
			KVP * iterator = kvps[key];
			while(iterator && iterator->key != k){
				iterator = iterator->next;
			}
			if(!iterator){
				KVP * newKvp = new KVP (k,v, kvps[key]);	
				kvps[key] = newKvp;
				cout<<"insert success"<<endl;
			}else{
				cout << "hashing at "<< k << " is not empty,  update value" <<endl;
				iterator->val = v;
			}
			
			
		}
	}
	void Delete(int k){
		int key = k % 11;
		if(!kvps[key]){
			cout<<"hast at " << k <<" is empty, delete fail"<<endl;
		}else {
			KVP * iterator = kvps[key];
			KVP * pre_iterator ;
			while(iterator && iterator->key != k){
				pre_iterator = iterator;
				iterator = iterator->next;
			}
			if(!iterator){
				cout<<"hash of key " << k <<" not found, delete fail"<<endl;
			}else{
				pre_iterator->next = iterator->next;
				delete iterator;
				cout<<"delete success"<<endl;
			}
		}
	}
	void Search(int k){
		int key = k % 11;
		if(!kvps[key]){
			cout<<"hast at " << k <<" is empty, search fail"<<endl;
		}else {
			KVP * iterator = kvps[key];
			while(iterator && iterator->key != k){
				iterator = iterator->next;
			}
			if(!iterator){
				cout<<"hash of key " << k <<" not found, search fail"<<endl;
			}else{
				cout << "hashing at "<< k << " is " << iterator->val <<endl;
			}
		}
	}
};

int main()
{
	cout<< "input shoud be :"<<endl;
	cout<< "insert <key> <value>"<<endl;
	cout<< "search <key>"<<endl;
	cout<< "delete <key>"<<endl;
	cout<< "key must between 0 and 99"<<endl;
	string cmd; // command from std input
	int k , v; //key and value
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
		}
	}
}