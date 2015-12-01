#include <iostream>
#include <vector>
using namespace std;

//implemented Max Heap

class Max_heap {
	public:
		vector<int> heap;

		void bubble_down(int i){
			int size = heap.size();
			while(i < size/2){
				int left = 2*i + 1;
				int right = 2*i + 2 == size ? 2*i + 1 : 2*i + 2;
				int larger_children;
				if(heap[left] >= heap[right]){
					larger_children = left;
				}else{
					larger_children = right;
				}
				if(heap[larger_children] > heap[i]){
					int tmp = heap[i];
					heap[i] = heap[larger_children];
					heap[larger_children] = tmp;
					i = larger_children;
				}else{
					break;
				}
			}
		}

		void heapify(){
			int n = heap.size()-1;
			for(int i = n/2 ;i >= 0; i--){
				bubble_down(i);
			}
		}

		Max_heap(vector<int> input){
			heap = input;
			heapify();
		}
};



int main(){
	cout << "please input a sequence of integers" << endl;
	vector<int> items;
	int input;
	while( cin>>input ){
		items.push_back(input);
	}
	Max_heap * mh = new Max_heap(items);
	cout<<endl<< "Heapified Result"<<endl;
	for(int i=0; i<mh->heap.size(); i++){
		cout<< mh->heap	[i] <<endl;
	}
}
