#include <iostream>
using namespace std;

int BrutefoucePM(string T, string P){
	bool match;
	int n = T.length();
	int m = P.length();
	for (int i = 0; i <= n - m; ++i) {
		match = true;
		int j = 0;
		while(j < m && match){
			if(T[i+j] == P[j]){
				++j;
			}else{
				match = false;
			}
		}
		if(match){
			return i;
		}
	}
	return -1;
}

int main(){
	string Text;
	string Pattern;
	cout << "Input the Text and press enter" <<endl;
	getline(cin,Text);
	cout << "Input the Pattern and press enter" <<endl;
	getline(cin,Pattern);

	cout << BrutefoucePM(Text,Pattern) << endl;
}