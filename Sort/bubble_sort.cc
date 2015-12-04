#include <vector>
#include <iostream>
using namespace std;


vector <int> Merge (vector<int> & A , vector<int> & B);

//selection sort: runtime O(n^2)
void bubble_sort(vector<int> & A){
	vector<int>::iterator min; // points to max number in the current loop
	for(vector<int>::iterator i = A.begin()+1 ; i != A.end(); ++i) {
		min = i;
		for(vector<int> ::iterator j = i; j != A.begin(); --j) {
    		if(*(j - 1) > *j){
				int tmp = *(j-1);
				*(j - 1) = *j;
				*j = tmp;  
	  		}
		}
	}
}


int main() {
	int n; // input reads
	vector <int> input; // store input array in an vector <int>


	cout << "input the array need to sort "  << endl;
	while( cin >> n ) {
		input.push_back(n);
	}

	bubble_sort(input);
	cout<<endl<< "sorted array: "<<endl;
	for(vector<int>::iterator it = input.begin(); it != input.end(); ++it) {
    	cout<< *it <<endl;
	}
}