#include <iostream>
using namespace std;


class AVLtree { // Binary search tree
	public:
		int key;
		int val;
		int height;
		int balance_factor; // balance factor = height(R) - height(L)
		AVLtree * right;
		AVLtree * left;
		AVLtree * parent;

		AVLtree (int k,int v, AVLtree * p = NULL, AVLtree * l = NULL, AVLtree * r = NULL){	// ctor for node
			key = k; 
			val = v;
			parent = p;
			right = r;
			left = l;
			balance_factor = 0;
			height = 0;
		}

		void rec_insert(int k, int v){
			if(k > key){ // if k is greater tha key , recursion on the right node
				if(right == NULL){
					right = new AVLtree(k,v,this);
				}else{
					right->rec_insert(k,v);
				}
			}else if (k < key){ // if k is less tha key , recursion on the left node
				if(left == NULL){
					left = new AVLtree(k,v,this);
				}else{
					left->rec_insert(k,v);
				}
			}else{
				cout << "dupilicate keys, insert fail" << endl;
				return;
			}
		}

		int Search(int k){
			if(key == k){ // if k equals to key , then KVP found
				return val;
			}else if(k > key){ // if k is greater tha key , recursion on the right node
				if(right == NULL){
					cout<< "serach not found" << endl;
					return -1;
				}else{
					return right->Search(k);
				}
			}else if (k < key){ // if k is less tha key , recursion on the left node
				if(left == NULL){
					cout<< "serach not found" << endl;
					return -1;		
				}else{
					return left->Search(k);
				}
			}
			return 0;
		}


		void Delete_rec(int k){
			if(key == k){
				// find inorder successor of the node
				// and swap with the deleted node
				AVLtree * iterator = right;
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
					right->Delete_rec(k);
				}
			}else if (k < key){
				if(left == NULL){
					cout<< "delete not found" << endl;
					return;		
				}else{
					left->Delete_rec(k);
				}
			}
		}

		void print(){
			print_rec(0);
		}

		void print_rec(int n){
			string space(n*2, ' ');
			n++;
			if(left) left->print_rec(n);
			cout<< space << "(" <<key << ", " << val << ") height: " << height << "(" << balance_factor << ")" << endl;
			if(right) right->print_rec(n);
		}
};

AVLtree * rotate_right(AVLtree * avl) {
	AVLtree * newroot = avl->left;
	avl->left = newroot->right;
	newroot->right = avl;
	newroot->parent = avl->parent;
	if(newroot->left) newroot->left->parent = newroot;
	if(newroot->right) newroot->right->parent = newroot;
	return newroot;
}

AVLtree * rotate_left(AVLtree * avl) {
	AVLtree * newroot = avl->right;
	avl->right = newroot->left;
	newroot->left = avl;
	newroot->parent = avl->parent;
	if(newroot->left) newroot->left->parent = newroot;
	if(newroot->right) newroot->right->parent = newroot;
	return newroot;
}

int fix(AVLtree * & avl){
	AVLtree * right = avl->right;
	AVLtree * left = avl->left;
	int right_height = right ? fix(right) : -1 ;
	int left_height = left ? fix(left) : -1 ;
	avl->height = right_height > left_height ? right_height + 1 :  left_height + 1;
	avl->balance_factor = right_height - left_height;
	if(! (-1 <= avl->balance_factor && avl->balance_factor <= 1)){
		if(avl->balance_factor == -2){
			if(left && left->balance_factor == 1){
				avl->left = rotate_left(avl->left);
			}
			avl = rotate_right(avl);
		}else if(avl->balance_factor == 2){
			if(right && right->balance_factor == -1){
				avl->right = rotate_right(avl->right);
			}
			avl = rotate_left(avl);
		}
		right = avl->right;
		left = avl->left;
		right_height = right ? fix(right) : -1 ;
		left_height = left ? fix(left) : -1 ;
		avl->height = right_height > left_height ? right_height + 1 :  left_height + 1;
		avl->balance_factor = right_height - left_height;
	}
	return avl->height;
}

void AVL_Delete(AVLtree * & avl, int k){
	avl->Delete_rec(k);
	fix(avl);
}

void AVL_Insert(AVLtree * & avl, int k, int v){
	avl->rec_insert(k , v);
	fix(avl);
}



int main(){
	AVLtree * avl = new AVLtree(0 , -4);
	AVL_Insert(avl, 10,0);
	AVL_Insert(avl, 4,1);
	AVL_Insert(avl, 6,2);
	AVL_Insert(avl, 7,3);
	AVL_Insert(avl, 12,4);
	AVL_Insert(avl, 9,5);
	cout << "new AVLtree (0, -4)" <<endl;
	cout << "insert (10,0)" << endl;
	cout << "insert (-4,1)" << endl;
	cout << "insert (6,2)" << endl;
	cout << "insert (7,3)" << endl;
	cout << "insert (12,4)" << endl;
	cout << "insert (9,5)" << endl;
	avl->print();
	cout << "Delete 12" << endl;
	AVL_Delete(avl, 12);	
	cout << "Delete 0" << endl;
	AVL_Delete(avl, 0);
	avl->print();
}

