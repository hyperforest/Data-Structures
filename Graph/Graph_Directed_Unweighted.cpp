#include <bits/stdc++.h>
#define ii pair<int, int>
#define vii vector<ii>
#define vi vector<int>
#define vv vector<vi>
#define mp make_pair
#define loop(i, a, b) for(int i = a; i < b; i++)
using namespace std;

/*
	Created by : Rimba Erlangga, 2017
	
	This program contains code for representating undirected and unweighted graph
	in its adjacency matrix (AM), adjacency list (AL), and edge list (EL) representation.
	The graph is considered to be simple graph. The vertices is indexed from 0.
	
	The AL for each vertex is automatically sorted by index of another vertex it is adjacent with
	when we insert new edge, and the EL also automatically sorted by index of its vertex.
	If edge A-B is contained in the EL, then there is a direct way from vertex A to vertex B.
	
	Because the graph is directed, insertion of an edge of A-B does not imply that B-A also get inserted.
	And because the graph is unweighted, if there's an edge between two vertices A and B, the value of
	AM[A][B] will change to 1. Otherwise, it will be 0.
*/

int AM[110][110];
vv AL(110);
vector<ii> EL;

void add_to_AM(int a, int b);
void sort_AL(int V);
void add_to_AL(int a, int b);
void sort_EL();
void add_to_EL(int a, int b);
void print_AM(int V);
void print_AL(int V);
void print_EL();

int main(){
	int V, E; //declare the number of vertices and edges
	cin >> V >> E;
	
	//insert the edge between two vertex a and b
	loop(i, 0, E) {
		int a, b;
		cin >> a >> b;
		
		add_to_AM(a, b);
		add_to_AL(a, b);
		add_to_EL(a, b);
	}
	
	print_AM(V);
	print_AL(V);
	print_EL();
}

void add_to_AM(int a, int b) {
	AM[a][b] = 1;
}

void sort_AL(int V) {
	int pos = AL[V].size()-1;
	
	int temp = AL[V][pos];
	while(pos >= 1 and AL[V][pos-1] > temp) {
		AL[V][pos] = AL[V][pos-1];
		pos--;
	}
	AL[V][pos] = temp;
}

void add_to_AL(int a, int b) {
	AL[a].push_back(b);
	sort_AL(a);
}

void sort_EL() {
	int pos = EL.size()-1;
	
	ii temp = EL[pos];
	while(pos >= 1 and EL[pos-1].first > temp.first) {
		EL[pos] = EL[pos-1];
		pos--;
	}
	EL[pos] = temp;
	
	temp = EL[pos];
	while(	pos >= 1 and 
			EL[pos-1].second > temp.second and 
			EL[pos-1].first == temp.first
		 )
	{
		EL[pos] = EL[pos-1];
		pos--;
	}
	EL[pos] = temp;
}

void add_to_EL(int a, int b) {
	EL.push_back(mp(a,b));
	sort_EL();
}

void print_AM(int V) {
	cout << "\nAM :\n";
	loop(i, 0, V) {
		loop(j, 0, V) {
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

void print_EL() {
	cout << "\nEL :\n"; 
	loop(i, 0, EL.size()) {
		cout << EL[i].first << " " << EL[i].second << endl;
	}
}
