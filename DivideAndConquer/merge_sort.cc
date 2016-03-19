#include <vector>
#include <iostream>
using namespace std;


vector <int> Merge (vector<int> & A , vector<int> & B);

//merge_sort: runtime O(nlogn)
void merge_sort(vector<int> & A){
	int left = ( A.size() + 1 ) / 2; // size of left half of the original array
	int right = A.size() / 2; // size of right half of the original array
	if(A.size() == 1){
		return;
	}else{
		vector<int>::const_iterator begin1 = A.begin();
		vector<int>::const_iterator end1 = A.begin() + left;
		vector<int> first_half (begin1, end1); // first half of the array after partition
		vector<int>::const_iterator begin2 = A.begin() + left;
		vector<int>::const_iterator end2 = A.end();
		vector<int> second_half (begin2,end2); // second half of the array
		merge_sort(first_half);
		merge_sort(second_half);
		A.clear();
		A.reserve( first_half.size() + second_half.size() );
		A = Merge( first_half, second_half );
	}
}

//Merge ( vector A , Vector B) : merge two vecotors <int> and return one new vector
vector <int> Merge (vector<int> & A , vector<int> & B){
	vector<int> V;
	vector<int>::iterator a = A.begin(); // iterator for A
	vector<int>::iterator b = B.begin(); //              B
	while( a != A.end() || b != B.end() ){
		if ( a == A.end() ){
			V.push_back(*b);
			++b;
			continue;
		}else if ( b == B.end() || *a < *b ){
			V.push_back(*a);
			++a;
			continue;
		}
		if( *b <= *a ) {
			V.push_back(*b);
			++b;
			continue;
		} else {
			V.push_back(*a);
			++a;
			continue;
		}
	}
	return V;
}


int main() {
	int n; // input reads
	vector <int> input; // store input array in an vector <int>


	cout << "input the array need to sort "  << endl;
	while( cin >> n ) {
		input.push_back(n);
	}

	merge_sort(input);
	cout<<endl<< "sorted array: "<<endl;
	for(vector<int>::iterator it = input.begin(); it != input.end(); ++it) {
    	cout<< *it <<endl;
	}
}
