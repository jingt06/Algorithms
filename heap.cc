#include <iostream>
#include <vector>
using namespace std;

//implemented Max Heap

class Max_heap {
	public:
		vector<int> heap;

		Max_heap(vector<int> input){ // ctor for Max_heap
			heap = input;
			heapify();
		}

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

		void bubble_up(int i){
			while(i!=0 && heap[(i-1)/2] < heap[i]){
				int tmp = heap[i];
				heap[i] = heap[(i-1)/2];
				heap[(i-1)/2] = tmp;
				i = (i-1)/2;
			}
		}

		void heapify(){
			int n = heap.size()-1;
			for(int i = n/2 ;i >= 0; i--){
				bubble_down(i);
			}
		}

		void insert(int i){
			heap.push_back(i);
			bubble_up(heap.size()-1);	
		}

		int delete_max(){
			int size = heap.size();
			int max = heap[0];
			heap[0] = heap[size-1];
			heap[size-1] = max;
			heap.pop_back();
			bubble_down(0);
			return max;
		}
};



int main(){
	cout << "please input a sequence of integers" << endl;
	vector<int> items;
	int input;
	while( cin>>input ){
		items.push_back(input);
	}
	Max_heap * max_heap = new Max_heap(items);
	cout<<endl<< "Heapified Result"<<endl;
	for(int i=0; i<max_heap->heap.size(); i++){
		cout<< max_heap->heap	[i] <<endl;
	}
	cout<<"heap insert(100)"<<endl;
	max_heap->insert(100);	
	cout<<"heap insert(0)"<<endl;
	max_heap->insert(0);	
	cout<<"heap insert(-100)"<<endl;
	max_heap->insert(-100);	
	cout<<endl<< "Result after heap insert"<<endl;
	for(int i=0; i<max_heap->heap.size(); i++){
		cout<< max_heap->heap	[i] <<endl;
	}
	cout<<endl<< "Heap Sort Result"<<endl;
	while(max_heap->heap.size()!=0){
		cout<< max_heap->delete_max()<<endl;
	}
}
