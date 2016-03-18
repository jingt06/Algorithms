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

class block { // block is size of 4
public:
	KVP ** kvps;
	int look_ahead;
	int size;
	block(){
		kvps = new KVP [4];
		size = 0;
	}
};

class hash {
public:
	blocks ** 
}