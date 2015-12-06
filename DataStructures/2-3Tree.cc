#include <iostream>
using namespace std;
class tree23;
void swap(int & a , int & b);
bool Insert(tree23 * & node, int k , int v);
void promote(tree23 * & p, tree23 * & node , int  k , int v );


class tree23 { // Binary search tree
	public:
		int key1;
		int key2;
		int val1;
		int val2;
		bool full;	
		tree23 * right;
		tree23 * mid;
		tree23 * left;
		tree23 * parent;

		tree23(int k, int v , tree23 * p = NULL){
			full = false;
			key1 = k;
			val1 = v;
			right = mid = left = NULL;
			parent = p;
		}
		tree23(int k1, int v1 , int k2, int v2, tree23 * p = NULL){
			full = true;
			key1 = k1;
			val1 = v1;
			key2 = k2;
			val2 = v2;
			right = mid = left = NULL;
			parent = p;
		}
		void print(){
			print_rec(0);
		}
		void print_rec(int n){

			string space(n, ' ');
			n++;
			if(left) left->print_rec(n);
			cout<< space << key1 << " " << val1 << endl;
			if(mid) mid->print_rec(n);
			if(full){
				cout<< space << key2 << " " << val2 << endl;
				if(right) right->print_rec(n);
			}
		}
};



bool Insert(tree23 * & node, int k , int v){
	if(!node->full && !node->left ){ // node is not full and node is a leaf
		if (k > node-> key1){
			node->key2 = k;
			node->val2 = v;
		} else if (k < node->key1 ){
			node->key2 = node->key1;
			node->val2 = node->val1;
			node->key1 = k;
			node->val1 = v;
		}else{
			cout<< "duplicate key, insert fail"<<endl;
			return false;
		}
		node->full = true;
		return true;
	}else if(node->left){ // node is not a leaf
		if(k < node->key1 ){
			Insert(node->left, k , v);
		}else if( k == node->key1 ){
			cout<< "duplicate key, insert fail"<<endl;
			return false;
		}else if( k > node->key1 && (!node->full || (node->full &&  k < node->key2))){
			Insert(node->mid, k , v);
		}else if( k == node->key2){
			cout<< "duplicate key, insert fail"<<endl;
			return false;
		}else{
			Insert(node->right,k,v);
		}
	}else{ // node is a leaf and full
		if(k >= node->key2){ // key1 <= key2 <= k,   key2 shoud be promoted
			swap(node->key2,k);
			swap(node->val2,v);
		}else if (k < node->key1 ){ // k < key1 <= key2, key1 should be promoted
			swap(node->key1,k);
			swap(node->val1,v);
		}
		promote(node->parent, node , k , v);
		return true;
	}
	return false;
}

void promote(tree23 * & p, tree23 * & node , int  k , int v ){
	if(!p){ // node is root, ( parent is NULL )
		tree23 * newroot = new tree23(k,v);
		newroot->left = new tree23(node->key1, node->val1, newroot);
		newroot->mid = new tree23(node->key2, node->val2, newroot);
		node = newroot;
	}
}



void swap ( int & a , int & b ){
	int tmp = a;
	a = b;
	b = tmp;
}



int main(){
	tree23 * tree = new tree23 (0, 0);
	Insert(tree, 1 ,3);
	Insert(tree, 2 ,4);
	tree->print();
}