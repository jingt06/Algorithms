#include <vector>
#include <iostream>
using namespace std;


vector <int> Merge (vector<int> & A , vector<int> & B);

//merge_sort: runtime O(nlogn)
void selection_sort(vector<int> & A){
	vector<int>::iterator min; // points to max number in the current loop
	for(vector<int>::iterator i = A.begin(); i != A.end(); ++i) {
		min = i;
		for(vector<int> ::iterator j = i; j != A.end(); ++j) {
    		if(*j < *min){
    			min = j;
    		}
		}
		int tmp = *i;
		*i = *min;
		*min = tmp;
	}
}


int main() {
	int n; // input reads
	vector <int> input; // store input array in an vector <int>


	cout << "input the array need to sort "  << endl;
	while( cin >> n ) {
		input.push_back(n);
	}

	selection_sort(input);
	cout<<endl<< "sorted array: "<<endl;
	for(vector<int>::iterator it = input.begin(); it != input.end(); ++it) {
    	cout<< *it <<endl;
	}
}