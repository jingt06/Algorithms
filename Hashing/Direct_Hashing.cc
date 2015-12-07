#include <iostream>
using namespace std;

class KVP{ // key value pair
public:
	int key;
	int val;
	KVP(int k, int v){
		key = k ;
		val = v ;
	}
};

class Hashing{
	KVP ** kvps; // length of 100;
public:
	Hashing(){
		kvps = new KVP * [100];
		for(int i = 0 ; i < 100 ; i++){ 
			kvps[i] = NULL; // set all KVP to NULL
		}
	}

	void Insert(int k , int v){
		if(k < 0 || k >= 100){
			cout << "invalid  key, insert fail "<<endl;
			return;
		}else if(!kvps[k]){
			kvps[k] = new KVP(k,v);
			cout<<"insert success"<<endl;
		}else {
			cout << "hash at "<< k << " is not empty ,update value"<<endl;
			kvps[k]->val = v;
		}
	}
	void Delete(int k){
		if(k < 0 || k >= 100){
			cout << "invalid  key, delete fail "<<endl;
			return;
		}else if(!kvps[k]){
			cout<<"hast at " << k <<" is empty, delete fail"<<endl;
		}else {
			delete kvps[k];
			kvps[k] = NULL;
			cout << "delete success"<<endl;
		}
	}
	void Search(int k){
		if(k < 0 || k >= 100){
			cout << "invalid  key, delete fail "<<endl;
			return;
		}else if(!kvps[k]){
			cout<<"hast at " << k <<" is empty, search fail"<<endl;
		}else {
			cout << "hashing at "<< k << " is " << kvps[k]->val <<endl;
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