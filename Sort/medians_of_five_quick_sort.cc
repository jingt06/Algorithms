#include <vector>
#include <iostream>
using namespace std;

int partition(vector <int> & A, int p);
int quick_select(vector <int> & A, int k);
int choose_pivot(vector<int> & A);

//medians of 5 quick sort worst case Θ(nlogn)
void quick_sort(vector <int> & A){
	if(A.size() <= 1){
		return;
	}
	int p = choose_pivot(A); // pivot
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
