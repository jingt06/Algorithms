#include <iostream>
using namespace std;

int * FailureArray(string);

// Knuth-Morris-Pratt algorithm (1977)
int KMP(string T, string P){
	int * F = FailureArray(P);
	int n = T.length();
	int m = P.length();
	int i = 0;
	int j = 0;
	while(i < n){
		if(T[i] == P[j]){
			if(j == m - 1){
				return i - j;
			}else{
				++i;
				++j;
			}
		}else{
			if(j > 0){
				j = F[j - 1];
			}else{
				++i;
			}
		}
	}
	return -1;
}

int * FailureArray(string P){
	int * F = new int [P.length()];
	int m = P.length();
	int i = 1;
	int j = 0;
	F[0] = 0;
	while (i < m){
		if(P[i] == P[j]){
			F[i] = j + 1;
			++i;
			++j;
		}else if(j > 0){
			j = F[j - 1];
		}else{
			F[i] = 0;
			++i;
		}
	}
	return F;
}

int main(){
	string Text;
	string Pattern;
	cout << "Input the Text and press enter" <<endl;
	getline(cin,Text);
	cout << "Input the Pattern and press enter" <<endl;
	getline(cin,Pattern);
	cout << KMP(Text,Pattern) << endl;
}