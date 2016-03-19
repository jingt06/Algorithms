#include <vector>
#include <iostream>
using namespace std;

int partition(vector <int> & A, int p);

//quick_sort of average case nlogn
void quick_sort(vector <int> & A){
	if(A.size() <= 1){
		return;
	}
	int p = 0; // pivot
	int i = partition(A,p);
	int n = A[i];
	vector<int>::const_iterator begin1 = A.begin();
	vector<int>::const_iterator end1 = A.begin() + i;
	vector<int> first_half (begin1, end1); // first half of the array after partition
	vector<int>::const_iterator begin2 = A.begin() + i + 1;
	vector<int>::const_iterator end2 = A.end();
	vector<int> second_half (begin2,end2); // second half of the array
	quick_sort(first_half);
	quick_sort(second_half);
	A.clear();
	A.reserve( first_half.size() + second_half.size() );
	A.insert( A.end(), first_half.begin(), first_half.end()); 
	A.push_back(n);    // new A is sorted first_half + n + sorted second_half
	A.insert( A.end(), second_half.begin(), second_half.end());
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

int main() {
	int n; // input reads
	vector <int> input; // store input array in an vector <int>


	cout << "input the array need to sort "  << endl;
	while( cin >> n ) {
		input.push_back(n);
	}

	quick_sort(input);
	cout<<endl<< "sorted array: "<<endl;
	for(vector<int>::iterator it = input.begin(); it != input.end(); ++it) {
    	cout<< *it <<endl;
	}
}



