#include <iostream>
#include <algorithm>    
#include <vector>     
using namespace std;  

class point {
public:
  int x;
  int y;
  point* right;
  point* left;
  point* y_Bst;

  point(int x, int y){
  	this->x = x;
  	this->y = y;
  	right = NULL;
  	left = NULL;
  	y_Bst = NULL;
  }
};

bool sort_x(point * x, point * y){
	return x->x < y->x;
}
bool sort_y(point * x, point * y){
	return x->y < y->y;
}

// return a kd tree Runtime: Θ(n log n)
point * Range_Tree(vector<point*> pts, bool x_bst){ 
	if(pts.size() == 0){
		return NULL;
	}
	if(pts.size() == 1){
		return pts[0];
	}
	if(x_bst){
		int mid = pts.size() / 2;
		sort (pts.begin(), pts.end(), sort_x);
		vector<point*>::const_iterator mid_end = pts.begin()+mid;
		vector<point*>::const_iterator mid_start = pts.end()-mid+(1-pts.size()%2);
		vector<point*>::const_iterator begin = pts.begin();
		vector<point*>::const_iterator end = pts.end();
		vector<point*> first (begin, mid_end);
		vector<point*> last (mid_start,end);
		pts[mid]->left = Range_Tree(first,true);
		pts[mid]->right = Range_Tree(last,true);
		pts[mid]->y_Bst = Range_Tree(pts,false);
		return pts[mid];

	}else{
		int mid = pts.size() / 2;
		sort (pts.begin(), pts.end(), sort_y);
		vector<point*>::const_iterator mid_end = pts.begin()+mid;
		vector<point*>::const_iterator mid_start = pts.end()-mid+(1-pts.size()%2);
		vector<point*>::const_iterator begin = pts.begin();
		vector<point*>::const_iterator end = pts.end();
		vector<point*> first (begin, mid_end);
		vector<point*> last (mid_start,end);
		pts[mid]->left = Range_Tree(first,false);
		pts[mid]->right = Range_Tree(last,false);
		return pts[mid];
	}
}


int main()
{
	string line;
	int num,x,y;
	cout<< "input the total number of points: "<<endl;
	cin >> num;
	vector <point*> points;
	cout<< "than give "<< num <<" points (x,y) on each lines"<<endl;
	for (int i = 0; i < num; i++){
		cin >> x;
		cin >> y;
		point* p = new point(x,y);
		points.push_back(p);
	}
	point* range_tree = Range_Tree(points, true);
	/*cout<< "range <x_upper_bound> <x_lower_bound> <y_upper_bound> <y_lower_bound>"<<endl;
	string cmd;
	while(cin >> cmd){
		int x_up;
		int x_low;
		int y_up;
		int y_low;
		if(cmd == "range"){
			cin>>x_up;
			cin>>x_low;
			cin>>y_up
			cin>>y_low;
			Range_Search(range_tree,x_up,x_low,y_up,y_low);
		}
	}*/
}