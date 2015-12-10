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

// Ordered Array using Dynamic array:
//      Θ(n) insert delete;
//      Θ(logn) search;
class Dynamic_Array{
	public:
		KVP ** arr;
		int size;
		int max_size;

		Dynamic_Array(){
			arr = new KVP * [4];
			size = 0;
			max_size = 4;
		}
		// Binary Search , runtime is Θ(logn) 
		int Search(int k){
			int front = 0;
			int end = size - 1;
			int mid = front + ((k - arr[front]->key)/(arr[end]->key - arr[front]->key)) *  (end - front);
			while(end >= front){
				if(arr[mid]->key == k){
					cout<< "result:" << arr[mid]->val <<endl;
					return arr[mid]->val;
				}else if(end == front){
					cout<< "key not found"<<endl;
					return 0;
				}else if(arr[mid]->key > k){
					end = mid-1;
				}else if(arr[mid]->key < k){
					front = mid+1;
				}
				mid = front + ((k - arr[front]->key)/(arr[end]->key - arr[front]->key)) *  (end - front);
			}
			return 0;
		}

		void Insert(int k, int v){
			int new_max_size = max_size;
			if(size == max_size){
				new_max_size = max_size * 2;
			}
			KVP ** new_arr = new KVP *[new_max_size];
			int i = 0;
			while(i < size){
				if(arr[i]->key == k){
					cout<<"duplicate key, insert fail"<<endl;
					delete new_arr;
					return;
				}else if(arr[i]->key > k){
					break;
				}else{
					new_arr[i] = arr[i];
				}
				++i;
			}
			new_arr[i] = new KVP(k,v);
			i = i + 1;
			size = size + 1;
			max_size = new_max_size;
			while(i < size){
				new_arr[i] = arr[i-1];
				++i;
			}
			delete arr;
			arr = new_arr;
			cout<< "insert success"<<endl;
		}
		void Delete(int k){
			bool found = false;
			int i = 0;
			while(i < size){
				if(arr[i]->key < k){
				}else if(arr[i]->key > k){
					if(!found){
						cout<<"key not found, delete fail"<<endl;
						return;
					}else{
						arr[i]=arr[i+1];
					}
				}else{
					arr[i] = arr[i+1];
					found = true;
				}
				++i;
			}
			--size;
			cout<< "delete success"<<endl;
		}

		void print(){
			for (int i = 0; i < size; ++i)
			{
				cout<< arr[i]->key << " " << arr[i]->val << endl;
			}
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
	Dynamic_Array * arr = new Dynamic_Array();
	while (cin >> cmd){
		if(cmd == "insert"){
			cin >> k;
			cin >> v;
			arr->Insert(k,v);
		}else if(cmd == "delete"){
			cin >> k;
			arr->Delete(k);
		}else if (cmd == "search"){
			cin >> k; 
			arr->Search(k);
		}else if (cmd == "print"){
			arr->print();
		}

	}
}