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

  point(int x, int y){
  	this->x = x;
  	this->y = y;
  	right = NULL;
  	left = NULL;
  }
};

bool sort_x(point * x, point * y){
	return x->x < y->x;
}
bool sort_y(point * x, point * y){
	return x->y < y->y;
}

// return a kd tree Runtime: Θ(n log n)
point * kd_tree(vector<point*> pts, bool x_coor){ 
	if(pts.size() == 0){
		return NULL;
	}
	if(pts.size() == 1){
		cout<<pts[0]->x<<" "<<pts[0]->y<<" ";
		return pts[0];
	}
	if(x_coor){
		int mid = pts.size() / 2;
		sort (pts.begin(), pts.end(), sort_x);
		vector<point*>::const_iterator mid_end = pts.begin()+mid;
		vector<point*>::const_iterator mid_start = pts.end()-mid+(1-pts.size()%2);
		vector<point*>::const_iterator begin = pts.begin();
		vector<point*>::const_iterator end = pts.end();
		vector<point*> first (begin, mid_end);
		vector<point*> last (mid_start,end);
		pts[mid]->left = kd_tree(first,false);
		cout<< (pts[mid]->x) <<" "<< (pts[mid]->y) << " ";
		pts[mid]->right = kd_tree(last,false);
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
		pts[mid]->left = kd_tree(first,true);
		cout<<pts[mid]->x<<" "<<pts[mid]->y<< " ";
		pts[mid]->right = kd_tree(last,true);
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
	cout<< "result: " <<endl;
	kd_tree(points, true);
}