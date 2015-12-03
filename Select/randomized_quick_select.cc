#include <vector>
#include <iostream>
#include <stdlib.h>     
#include <time.h>       
using namespace std;

int partition(vector <int> & A, int p);
void swap(int & a, int & b);

// quick select, select A[0] as pivot, Runtime is ϴ(n) 
int quick_select(vector <int> & A, int k){
	int p = rand()% A.size(); // pivot
	int i = partition(A,p);

	if ( i == k ){
		return A[i];
	} else if ( i > k ){
		vector<int>::const_iterator begin = A.begin();
		vector<int>::const_iterator end = A.begin() + i;
		vector<int> new_A (begin, end);
		return quick_select(new_A,k);
	} else if ( i < k ){
		vector<int>::const_iterator begin = A.begin() + i + 1;
		vector<int>::const_iterator end = A.end();
		vector<int> new_A (begin,end);
		return quick_select(new_A,k-i-1);
	}
	return 0;
}

int partition(vector <int> & A, int p){
	int n = A.size(); // n is the size of the given array
	swap(A[0], A[p]);
	int i = 1;
	int j = n - 1;
	while(true){
		while(1 < n && A[i] <= A[0]){
			++i;
		}
		while(j>=1 && A[j] > A[0]){
			--j;
		}
		if( j < i ) break;
		else swap(A[i],A[j]);
	}
	swap(A[0], A[j]);
	return j;
}

void swap(int & a, int & b){
	int tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int size; // size of the input array
	int n; // input reads
	int k; // the position to select
	vector <int> input; // store input array in an vector <int>
	srand (time(NULL));

	cout << "input the size of the array: ";
	cin >> size;
	cout << "input the array of size " << size << endl;
	for (int i = 0; i < size; ++i)
	{
		cin >> n;
		input.push_back(n);
	}
	cout << "input a valid position you want to select" << endl;
	cin >> k;
	while(k < 0 || k >= size){
		cout << "k is not a valid select, input another number" <<endl;
		cin >> k;
	}
	int result = quick_select(input,k);
	cout<<endl<< "the number at position " << k << " is " << result<<endl;

}