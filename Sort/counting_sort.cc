#include <vector>
#include <iostream>
using namespace std;

// counting_sort , runtime Θ(n + max)
void counting_sort(vector<int> & A, int max){
	int * Count = new int [max];
	for(vector<int>::iterator i = A.begin(); i != A.end(); ++i) {
		++Count[*i];
	}
	for(int i = 1 ; i < max ; ++i) {
		Count[i] = Count[i] + Count[i-1];
	}
	vector<int> copy = A;
	for(int i = A.size()-1 ; i >= 0 ; --i){
		--Count[copy[i]];
		A[Count[copy[i]]] = copy[i];
	}
}


int main() {
	int n; // input reads
	int max = 0; //keep track the value of maximun number during input.
	vector <int> input; // store input array in an vector <int>
	cout << "input the array ( positive number only ) need to sort "  << endl;
	while( cin >> n ) {
		input.push_back(n);
		if(max < n){
			max = n;
		}
	}
	max++;
	counting_sort(input,max);
	cout<<endl<< "sorted array: "<<endl;
	for(vector<int>::iterator it = input.begin(); it != input.end(); ++it) {
    	cout<< *it <<endl;
	}
}