#include <iostream>
using namespace std;


class Bst { // Binary search tree
	public:
		int key;
		int val;
		Bst * right;
		Bst * left;
		Bst * parent;

		Bst (int k,int v, Bst * p = NULL, Bst * l = NULL, Bst * r = NULL){	// ctor for node
			key = k; 
			val = v;
			parent = p;
			right = r;
			left = l;
		}

		void Insert(int k, int v){
			if(k > key){
				if(right == NULL){
					right = new Bst(k,v,this);
				}else{
					right->Insert(k,v);
				}
			}else if (k < key){
				if(left == NULL){
					left = new Bst(k,v,this);
				}else{
					left->Insert(k,v);
				}
			}else{
				cout << "dupilicate keys, insert fail" << endl;
				return;
			}
		}

		int Search(int k){
			if(key == k){
				cout<< "result: "<<val<<endl;
				return val;
			}else if(k > key){
				if(right == NULL){
					cout<< "serach not found" << endl;
					return -1;
				}else{
					return right->Search(k);
				}
			}else if (k < key){
				if(left == NULL){
					cout<< "serach not found" << endl;
					return -1;		
				}else{
					return left->Search(k);
				}
			}
			return 0;
		}

		void Delete(int k){
			if(key == k){
				//find inorder successor of the node
				Bst * iterator = right;
				if(iterator == NULL){
					if(parent->left == this){
						parent->left = left;
						if(left) left->parent = parent;
						delete this;
						return;
					}else{
						parent->right = left;
						if(left) left->parent = parent;
						delete this;
						return;
					}
				}else if(iterator->left == NULL){
					if(parent->left == this){
						parent->left = iterator;
						iterator->left = right;
						if(right) right->parent = iterator;
						iterator->parent = parent;
						delete this;
						return;
					}else{
						parent->right = iterator;
						iterator->left = right;
						if(right) right->parent = iterator;
						iterator->parent = parent;
						delete this;
						return;
					}
				}else{
					while(iterator->left){
						iterator = iterator->left;
					}
					iterator->parent->left = iterator->right;
					this->key = iterator->key;
					this->val = iterator->val;
					delete iterator;
				}
			}else if(k > key){
				if(right == NULL){
					cout<< "delete not found" << endl;
					return;
				}else{
					return right->Delete(k);
				}
			}else if (k < key){
				if(left == NULL){
					cout<< "delete not found" << endl;
					return;		
				}else{
					return left->Delete(k);
				}
			}
		}

		void print(){
			print_rec(0);
		}
		void print_rec(int n){

			string space(n, ' ');
			n++;
			if(left) left->print_rec(n);
			cout<< space << key << " " << val << endl;
			if(right) right->print_rec(n);
		}
};

	//Running time: O(log n + k), k: number of reported items
void Range_Search(Bst* T, int k1, int k2){
	if(!T){
		return;
	}
	if(T->key < k1){
		Range_Search(T->right,k1,k2);
	}
	if(T->key > k2){
		Range_Search(T->left,k1,k2);
	}
	if(T->key >= k1 && T->key <= k2){
		Range_Search(T->left,k1,k2);
		cout<<T->key<< " " << T->val<<endl;
		Range_Search(T->right,k1,k2);
	}
}


int main(){
	cout<< "input shoud be :"<<endl;
	cout<< "insert <key> <value>"<<endl;
	cout<< "search <key>"<<endl;
	cout<< "delete <key>"<<endl;
	cout<< "range <lower_bound> <upper_boudn>"<<endl;
	string cmd; // command from std input
	int k , v; //key and value
	Bst * bst = NULL;
	while (cin >> cmd){
		if(cmd == "insert"){
			cin >> k;
			cin >> v;
			if(!bst){
				bst = new Bst(k,v);
				continue;
			}else{
				bst->Insert(k,v);
			}
		}else if(cmd == "delete"){
			cin >> k;
			if(bst) bst->Delete(k);
		}else if (cmd == "search"){
			cin >> k; 
			if(bst) bst->Search(k);
		}else if (cmd == "print"){
			if(bst) bst->print();
		}else if (cmd == "range"){
			cin>>k;
			cin>>v;
			Range_Search(bst,k,v);
		}

	}

}







