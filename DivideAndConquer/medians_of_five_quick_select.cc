#include <vector>
#include <iostream>
using namespace std;

int partition(vector <int> & A, int p);
int choose_pivot(vector <int> & A); // choose pivot using mediam of five
void swap(int & a, int & b);

// quick select, implemented using "medians of five" 
// (invented by Tarjan in 1973)
// worst case expected rumtime is O(n)
int quick_select(vector <int> & A, int k){
	int p = choose_pivot(A); // pivot
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

int choose_pivot(vector<int> & A){
	int m = A.size() / 5 - 1;
	if( m <= 0 ){
		return 0;
	}
	for (int i = 0; i < m; ++i) {
		int a = 5 * i ;			    
		int b = 5 * i + 1 ;   
		int c = 5 * i + 2 ;
		int d = 5 * i + 3 ;
		int e = 5 * i + 4 ;
		// algorithm for compute medium of 5
		// the maximun comparsion is 6.
		if(A[b] < A[a])        
			swap(A[a], A[b]);        // a < b
		if(A[d] < A[c])
			swap(A[c], A[d]);        // a < b , c < d
		if(A[c] < A[a]){
			swap(A[c], A[a]);
			swap(A[b], A[d]);        // a < b , a < c , c < d
		}
		swap(A[a],A[e]);             // a , b , c < d ( e out )
		if(A[b] < A[a])
			swap(A[a], A[b]);        // a < b , c < d
		if(A[c] < A[a]){
			swap(A[c], A[a]);
			swap(A[b], A[d]);        // a < b , c < d , a < c ( a out )
		}                            // c < d, b
		if(A[b] < A[c]){
			swap(A[b], A[i]); 
		}else{
			swap(A[c], A[i]);
		}
	}
	vector<int>::const_iterator begin = A.begin();
	vector<int>::const_iterator end = A.begin() + m;
	vector<int> Arr(begin,end);
	return quick_select(Arr, m/2);
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