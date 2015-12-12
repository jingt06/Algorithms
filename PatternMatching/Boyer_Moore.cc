#include <iostream>
#include <map>
#include <algorithm> 
using namespace std;

map<char,int> Last_Occ(string);
int * Suffix_Arr(string);


map<char,int> Last_Occ(string P){
	map<char,int> last_occ;
	for(int i = P.length()-1; i>=0; i--){
		if(last_occ.find(P[i]) == last_occ.end()){
			last_occ.insert(pair<char,int>(P[i], i));
		}
	}
	return last_occ;
}

int* Suffix_Arr(string P){
	int * suffix_arr = new int [P.length()];
	for(int i = 0; i < P.length(); ++i){
		bool match = true;
		for(int j = 1 ; j < P.length(); ++j){ // j is the number shift to right
			if(j > i || P[i] != P[i-j]){
				match = true;
				for( int m = 0; j+m < P.length(); ++m ){
					if(j+m>i && P[j+m] != P[m]){
						match = false;
						break;
					}
				}
			}else{
				match = false;
			}
			if(match){
				suffix_arr[i]=i-j;
				break;
			}
		}
		if(!match){
			suffix_arr[i] = i - P.length();
		}
	}
	return suffix_arr;
}

int getL(map<char,int> L, char c){
	if(L.find(c) == L.end()) return -1;
	else return L[c];
}

int boyer_moore(string T, string P){
	map<char,int> L = Last_Occ(P);
	int * S = Suffix_Arr(P);
	int n = T.length();
	int m = P.length();
	int i = m - 1;
	int j = m - 1;
	while(i < n && j >= 0){
		if(T[i] == P[j]){
			--i;
			--j;
		}else{
			i = i + m - 1 - min(getL(L,T[i]),S[j]);
			j = m - 1;
		}
	}
	if(j == -1) return i + 1;
	else return -1;
}

int main(){
	string Text;
	string Pattern;
	cout << "Input the Text and press enter" <<endl;
	getline(cin,Text);
	cout << "Input the Pattern and press enter" <<endl;
	getline(cin,Pattern);
	cout << boyer_moore(Text,Pattern)<<endl;
}