#include <vector>
#include <iostream>
using namespace std;



//bubble sort: runtime O(n^2)
void bubble_sort(vector<int> & A){
	for(vector<int>::iterator i = A.begin() ; i != A.end(); ++i) {
		for(vector<int> ::iterator j = A.end()-1; j != A.begin(); --j) {
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