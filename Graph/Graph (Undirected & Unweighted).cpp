#include <bits/stdc++.h>
#define ii pair<int, int>
#define vii vector<ii>
#define vi vector<int>
#define vv vector<vi>
#define mp make_pair
#define loop(i, a, b) for(int i = 0; i < b; i++)
using namespace std;

int AM[110][110];
vv AL(110);
vector<ii> EL;

void add_to_AM(int V1, int V2);
void add_to_AL(int a, int b);
void add_to_EL(int a, int b);
void print_AM(int V);
void print_AL(int V);
void print_EL(int E);

int main(){
	int V, E;
	cin >> V >> E;
	
	loop(i, 0, E) {
		int a, b;
		cin >> a >> b;
		
		add_to_AM(a, b);
		add_to_AL(a, b);
		add_to_EL(a, b);
	}
	
	print_AM(V);
	print_AL(V);
	print_EL(E);
}

void add_to_AM(int a, int b) {
	AM[a][b] = 1;
	AM[b][a] = 1;
}

void add_to_AL(int a, int b) {
	AL[a].push_back(b);
	AL[b].push_back(a);
}

void add_to_EL(int a, int b) {
	EL.push_back(mp(a,b));
	EL.push_back(mp(b,a));
}

void print_AM(int V) {
	cout << "\nAM :\n";
	loop(i, 1, V) {
		loop(j, 1, V) {
			cout << AM[i][j] << " ";
		}
		cout << endl;
	}
} 

void print_AL(int V) {
	cout << "\nAL :\n"; 
	loop(i, 0, V) {
		cout << i << ": ";
		loop(j, 0, AL[i].size()) {
			 cout << AL[i][j] << " ";
		}
		cout << endl;
	}
}

void print_EL(int E) {
	cout << "\nEL :\n"; 
	loop(i, 0, 2*E) {
		cout << EL[i].first << " " << EL[i].second << endl;
	}
}
