#include <iostream>
using namespace std;
class tree23;
void swap(int & a , int & b);
tree23 * Insert(tree23 * & node, int k , int v);
tree23 * promote(tree23 * & p, tree23 * & node , tree23 * & left, tree23 * & right , int  k , int v );


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

tree23 * getroot(tree23 * node){
	if (node->parent){
		node = node->parent;
	}
	return node;
}


tree23 * Insert_rec(tree23 * & root, tree23 * & node, int k , int v){
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
			return getroot(node);
		}
		node->full = true;
		return getroot(node);;
	}else if(node->left){ // node is not a leaf
		if(k < node->key1 ){
			return Insert_rec(root, node->left, k , v);
		}else if( k == node->key1 ){
			cout<< "duplicate key, insert fail"<<endl;
			return getroot(node);;
		}else if( k > node->key1 && (!node->full || (node->full &&  k < node->key2))){
			return Insert_rec(root, node->mid, k , v);
		}else if( k == node->key2){
			cout<< "duplicate key, insert fail"<<endl;
			return getroot(node);
		}else{
			return Insert_rec(root, node->right,k,v);
		}
	}else{ // node is a leaf and full
		if(k >= node->key2){ // key1 <= key2 <= k,   key2 shoud be promoted
			swap(node->key2,k);
			swap(node->val2,v);
		}else if (k < node->key1 ){ // k < key1 <= key2, key1 should be promoted
			swap(node->key1,k);
			swap(node->val1,v);
		}
		tree23 * left = new tree23(node->key1, node->val1,node->parent);
		tree23 * right = new tree23(node->key2, node->val2,node->parent);
		return getroot(promote(node->parent, node, left , right , k , v));
	}
	return node;
}

tree23 * Insert (tree23 * & root, int k , int v ){
	return Insert_rec(root,root,k,v);
}

tree23 * promote(tree23 * & p, tree23 * & node , tree23 * & left , tree23 * & right , int  k , int v ){
	if(!p){ // node is root, ( parent is NULL )
		tree23 * newroot = new tree23(k,v);
		newroot->left = left;
		newroot->mid = right;
		left->parent = newroot;
		right->parent = newroot;
		delete node;
		return newroot;
	}else{ // node is not root
		if(p->full) { // parent is full , need to promote again
			//cout<<k << " "  <<v <<endl;//debug
			//cout<< left->key1 <<endl;//debug
			//cout<< right->key1 <<endl;//debug
			//p->print();
			if(k >= p->key2){ // key1 <= key2 <= k,   key2 shoud be promoted
				swap(p->key2,k);
				swap(p->val2,v);
			}else if (k < p->key1 ){ // k < key1 <= key2, key1 should be promoted
				swap(p->key1,k);
				swap(p->val1,v);
			}
			tree23 * new_left = new tree23(p->key1, p->val1,p->parent);
			tree23 * new_right = new tree23(p->key2, p->val2,p->parent);
			if(node == p->left){
				new_left->left = left;
				new_left->mid = right;
				new_right->left = p->mid;
				new_right->mid = p->right;
			}else if ( node == p->mid ){
				new_left->left = p->left;
				new_left->mid = left;
				new_right->left = right;
				new_right->mid = p->right;
			}else if ( node == p->right ){
				new_left->left = p->left;
				new_left->mid = p->mid;
				new_right->left = left;
				new_right->mid = right;
			}
			node = p;
			return promote(node->parent, node, new_left , new_right , k , v);
		}else{ // parent is not full
			p->full = true;
			if(k > p->key1){ 
				p->key2 = k;
				p->val2 = v;
				p->mid = left;
				p->right = right;
			}else{
				p->key2 = p->key1;
				p->val2 = p->val1;
				p->key1 = k;
				p->val1 = v;
				p->right = p->mid;
				p->mid = right;
				p->left = left;
			}
			return p;
		}
	}
}



void swap ( int & a , int & b ){
	int tmp = a;
	a = b;
	b = tmp;
}



int main(){
	tree23 * tree = new tree23 (0, 0);
	tree = Insert(tree, 1 ,3);
	tree = Insert(tree, 2 ,4);
	tree = Insert(tree, 3 ,5);
	tree = Insert(tree, 4 ,15);
	cout<<endl;
	tree->print();
	tree = Insert(tree, 5 ,15);
	tree->print();
	tree = Insert(tree, 6 ,115);
	cout<<endl;
	tree->print();
	Insert(tree, 7 ,100);
	cout<<endl;
	tree->print();
	Insert(tree, 9,100);
	cout<<endl;
	tree->print();
}