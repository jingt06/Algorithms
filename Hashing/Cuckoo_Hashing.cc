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

int func1(int k){
	return k % 11;
}

int func2(int k){
	return k / 11;
}

void swap(KVP * & a , KVP * & b){
	KVP * tmp = a;
	a = b;
	b = tmp;
}

// hashing function 1 is f(x) = x % 11
// hashing function 2 is f(x) = x / 11
class Cuckoo_Hashing{
	KVP ** h; // hash 1 length of 10
public:
	Cuckoo_Hashing(){
		h = new KVP * [11];
		for(int i = 0 ; i < 11 ; i++){ 
			h[i] = NULL; // set all KVP to NULL
		}
	}

	void Insert(int k , int v){
		if((h[func1(k)] && h[func1(k)]->key == k) || (h[func2(k)] && h[func2(k)]->key == k)){
			cout << k << " is already inserted in the hash table" <<endl;
			return;
		}
		KVP * x = new KVP(k,v);
		int i = func1(x->key);
		for(int j = 0; j < 10 ; ++j){
			swap(x, h[i]);
			if(!x){
				cout << "insert success" <<endl;
				return;
			}
			if(i == func1(x->key)){
				i = func2(x->key);
			}else{
				i = func2(x->key);
			}
		}
		cout << "insert fail, need to extend hash table"<<endl;
		return;
	}
	void Delete(int k){
		if(h[func1(k)] && h[func1(k)]->key == k){
			delete h[func1(k)];
			h[func1(k)] = NULL;
			cout<<"delete success" <<endl;
			return;
		}else if(h[func2(k)] && h[func2(k)]->key == k){
			delete h[func2(k)];
			cout<<"delete success" <<endl;
			h[func2(k)] = NULL;
			return;
		}else{
			cout << "key not found" <<endl;
			return;
		}
	}
	void Search(int k){
		if(h[func1(k)] && h[func1(k)]->key == k){
			cout << "value at " << k << " is " << h[func1(k)]->val <<endl;
			return;
		}else if(h[func2(k)] && h[func2(k)]->key == k){
			cout << "value at " << k << " is " << h[func2(k)]->val <<endl;
			return;
		}else{
			cout << "key not found" <<endl;
			return;
		}
	}

	void Print(){
		for(int i = 0 ; i < 11 ; ++i){
			if(h[i])
				cout << i << " " << h[i]->key << " " << h[i]->val <<endl;
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
	Cuckoo_Hashing * hashing = new Cuckoo_Hashing();
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
