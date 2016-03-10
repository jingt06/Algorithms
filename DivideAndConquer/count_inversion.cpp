#include <vector>
#include <iostream>
using namespace std;

long int Count_Inversion(std::vector<int> & arr, vector<int>::iterator begin, std::vector<int>::iterator end);
long int Merge(std::vector<int> & arr,vector<int>::iterator b,vector<int>::iterator m1,vector<int>::iterator m2,vector<int>::iterator e);

int main(){
	long int num;
	vector<int> arr;
	while(cin>>num){
		arr.push_back(num);
	}
	cout<<Count_Inversion(arr, arr.begin(), arr.end())<<endl;
}


long int Count_Inversion(std::vector<int> & arr, vector<int>::iterator begin, std::vector<int>::iterator end){
	long int l = end - begin;
	if(l <= 1){
		return 0;
	}
	long int s1 = Count_Inversion(arr, begin, begin + l/2);
	long int s2 = Count_Inversion(arr, begin + l/2, end);
	long int s3 = Merge(arr, begin, begin+l/2, begin+l/2, end);
	return s1+s2+s3;
}

long int Merge(std::vector<int> & arr,vector<int>::iterator b1,vector<int>::iterator e1,vector<int>::iterator b2,vector<int>::iterator e2){
	vector<int>:: iterator start = b1;
	vector<int> new_arr;
	long int count = 0;
	while (b1 != e1 || b2 != e2){
		if(b1 != e1 && b2 != e2){
			if(*b1 > *b2){
				new_arr.push_back(*b2);
				count = count + (e1-b1) ;
				++b2;
			}else{
				new_arr.push_back(*b1);
				++b1;
			}
		}else if(b1 != e1){
			new_arr.push_back(*b1);
			++b1;
		}else if(b2 != e2){
			new_arr.push_back(*b2);
			++b2;
		}
	}
	for(int i = 0; i < e2 - start; i++){
		*(start+i) = new_arr[i];
	}
	return count;
}