#include <iostream>
using namespace std;

int max_subarray(int* arr, int s, int t){
	if (s == t){
		return arr[s];
	}
	int mid = (t+s)/2;
	int l = max_subarray(arr,s,mid);
	int r = max_subarray(arr,mid+1,t);
	int m = arr[mid] + arr[mid+1];
	int curr = m;
	for (int i = mid+2; i <= t; ++i)
	{
		curr += arr[i];
		if(curr>m)
			m = curr;
	}
	curr = m;
	for(int i = mid-1; i>=0 ; --i){
		curr += arr[i];
		if(curr>m) 
			m = curr;
	}
	if(m>r){
		if(m>l){
			return m;
		}else{
			return l;
		}
	}else{
		if(r>l){
			return r;
		}else{
			return l;
		}
	}
}

int main(){
	int n;
	cout<< "the number of input:";
	cin>>n;
	int* arr =new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	cout << max_subarray(arr,0,n-1);
}