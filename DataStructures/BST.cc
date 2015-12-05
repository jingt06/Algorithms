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
						delete this;
						return;
					}else{
						parent->right = left;
						delete this;
						return;
					}
				}else if(iterator->left == NULL){
					if(parent->left == this){
						parent->left = iterator;
						iterator->left = right;
						delete this;
						return;
					}else{
						parent->right = iterator;
						iterator->left = right;
						delete this;
						return;
					}
				}else{
					while(iterator->left){
						iterator = iterator->left;
					}
					iterator->parent->left = NULL;
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

};


int main(){
	Bst * bst = new Bst(0 , -4);
	bst->Insert(10,0);
	bst->Insert(-4,1);
	bst->Insert(6,2);
	bst->Insert(7,3);
	bst->Insert(12,4);
	bst->Insert(9,5);
	cout << "new Bst (0, -4)" <<endl;
	cout << "insert (10,0)" << endl;
	cout << "insert (-4,1)" << endl;
	cout << "insert (6,2)" << endl;
	cout << "insert (7,3)" << endl;
	cout << "insert (12,4)" << endl;
	cout << "insert (9,5)" << endl;
	cout << "serach -4" << endl;
	cout << "result: " << bst->Search(-4) << endl;
	cout << "serach 0" << endl;
	cout << "result: " << bst->Search(0) << endl;
	cout << "serach 13" << endl;
	bst->Search(13);
	cout << "delete 13" << endl;
	bst->Delete(13);
	cout << "delete 12" << endl;
	bst->Delete(12);
	cout << "Search 12" << endl;
	bst->Search(12);
	cout << "Delete 0" << endl;
	bst->Delete(0);
	cout<<"new root is "<<bst->key<<endl;

}







