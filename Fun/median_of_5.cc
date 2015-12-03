using namespace std;

void swap(int & a, int & b){
	int tmp = a;
	a = b;
	b = tmp;
}

//the worst case comparision is minimun, which is 6 times
int median_of_5 ( int a , int b , int c , int d , int e){
	if(b < a)        
		swap(a, b);        // a < b
	if(d < c)
		swap(c, d);        // a < b , c < d
	if(c < a){
		swap(c, a);
		swap(b, d);        // a < b , a < c , c < d
	}
	swap(a,e);             // a , b , c < d ( e out )
	if(b < a)
		swap(a, b);        // a < b , c < d
	if(c < a){
		swap(c, a);
		swap(b, d);        // a < b , c < d , a < c ( a out )
	}                            // c < d, b
	if(b < c){
		return b; 
	}else{
		return c;
	}
}