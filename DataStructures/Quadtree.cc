#include <iostream>
#include <algorithm>    
#include <vector>     
using namespace std;  

class point {
public:
  int x;
  int y;
  point* NE;
  point* NW;
  point* SE;
  point* SW;

  point(int x, int y){
  	this->x = x;
  	this->y = y;
  	NE = NULL;
	NW = NULL;
	SE = NULL;
	SW = NULL;
  }
  point(const point* p){
  	x = p->x;
  	y = p->y;
  	NE = p->NE;
  	NW = p->NW;
  	SE = p->SE;
  	SW = p->SW;
  }
};

point * Quadtree(vector<point*> pts, int max_x, int min_x, int min_y , int max_y){ 
	int mid_x = (max_x + min_x) / 2;
	int mid_y = (max_y + min_y) / 2;
	if(pts.size() == 0){
		return NULL;
	}else if(pts.size()==1){
		return pts[0];
	}
	point * new_point = new point(-1,-1);
	vector <point*> NEv;
	vector <point*> NWv;
	vector <point*> SEv;
	vector <point*> SWv;
	for(std::vector<point*>::iterator it = pts.begin(); it != pts.end(); ++it) {
		point * copy = new point(*it);
	   	 if((*it)->x <= mid_x && (*it)->y >= mid_y){
	   	 	NWv.push_back(*it);
	   	 }else if((*it)->x <= mid_x){
	   	 	SWv.push_back(*it);
	   	 }else if((*it)->y >= mid_y){
	   	 	NEv.push_back(*it);
	   	 }else{
	   	 	SEv.push_back(*it);
	   	 }
	}
	if(NWv.size() == 0){
		new_point->NW = NULL;
	}else if(NWv.size() == 1){
		new_point->NW = NWv[0];
	}else{
		new_point->NW = Quadtree(NWv,min_x,mid_x,mid_y,max_y);
	}
	if(NEv.size() == 0){
		new_point->NE = NULL;
	}else if(NEv.size() == 1){
		new_point->NE = NEv[0];
	}else{
		new_point->NE = Quadtree(NEv,mid_x,max_x,mid_y,max_y);
	}
	if(SWv.size() == 0){
		new_point->SW = NULL;
	}else if(SWv.size() == 1){
		new_point->SW = SWv[0];
	}else{
		new_point->SW = Quadtree(SWv,min_x,mid_x,min_y,mid_y);
	}
	if(SEv.size() == 0){
		new_point->SE = NULL;
	}else if(SEv.size() == 1){
		new_point->SE = SEv[0];
	}else{
		new_point->SE = Quadtree(SWv,mid_x,max_x,min_y,mid_y);
	}
	return new_point;
}

void print(point* p){
	if(p->NE || p->SE || p->NW || p->SW){
		if(p->NE){
			print(p->NE);
		}
		if(p->SE){
			print(p->SE);
		}
		if(p->NW){
			print(p->NW);
		}
		if(p->SW){
			print(p->SW);
		}
	}else{
		cout<< p->x << " "<< p->y <<endl;
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
	int max_x, max_y,min_x,min_y;
	bool first = true; // if it is first iteration in the loop
	for (int i = 0; i < num; i++){
		cin >> x;
		cin >> y;
		if(first){
			min_x = x;
			max_x = x;
			min_y = y;
			max_y = y;
			first = false;
		}else{
			if(x > max_x){
				max_x = x;
			}
			if(x < min_x){
				min_x = x;
			}
			if(y > max_y){
				max_y = y;
			}
			if(y < min_y){
				min_y = y;
			}
		}
		point* p = new point(x,y);
		points.push_back(p);
	}
	point * root = Quadtree(points, max_x, min_x, min_y, max_y);
	print(root);
}