#include <vector>
#include <iostream>
#include <math.h> 
using namespace std;

void counting_sort(vector<int> & A, int max, int key);

// radix sort , runtime Θ(d(n+k))
void radix_sort(vector<int> & A, int d, int k){
	for(int i=0;i < d ; ++i){
		counting_sort(A,k,i);
	}
}

void counting_sort(vector<int> & A, int max, int key){
	int * Count = new int [max];
	memset(Count,0,max);
	for(vector<int>::iterator i = A.begin(); i != A.end(); ++i) {
		++Count[(int)(*i % (int)(pow(10, (key + 1)))) / (int)(pow(10, key))]; 
	}
	for(int i = 1 ; i < max ; ++i) {
		Count[i] = Count[i] + Count[i-1];
	}
	vector<int> copy = A;
	for(int i = A.size()-1 ; i >= 0 ; --i){
		int k = (int)(copy[i] % (int)(pow(10, (key + 1)))) / (int)(pow(10, key));
		--Count[k];
		A[Count[k]] = copy[i];
	}
}


int main() {
	int n; // input reads
	int max_digit = 0; //keep track the value of maximun digits of a number during input.
	vector <int> input; // store input array in an vector <int>
	cout << "input the array ( positive number only ) need to sort "  << endl;
	while( cin >> n ) {
		input.push_back(n);
		if(max_digit < floor(log10(n))){
			max_digit = floor(log10(n));
		}
	}
	max_digit++;
	radix_sort(input,max_digit,10); // k is 10
	cout<<endl<< "sorted array: "<<endl;
	for(vector<int>::iterator it = input.begin(); it != input.end(); ++it) {
    	cout<< *it <<endl;
	}
}