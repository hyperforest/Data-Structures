#include <bits/stdc++.h>
#define ii pair<int, int>
#define pii pair<ii, int>
#define vii vector<ii>
#define vi vector<int>
#define vv vector<vii>
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
	
	Because the graph is undirected, insertion of an edge of A-B implies that B-A also get inserted.
	And because the graph is weighted, if there's an edge between two vertices A and B, the value of
	AM[A][B] will change to its weight (probably 0 or negative). Otherwise, it equals to INT_MAX in C++.
*/

int AM[110][110];
vv AL(110);
vector<pii> EL;

void init(int V);
void add_to_AM(int a, int b, int w);
void sort_AL(int V);
void add_to_AL(int a, int b, int w);
void sort_EL();
void add_to_EL(int a, int b, int w);
void print_AM(int V);
void print_AL(int V);
void print_EL();

int main(){
	int V, E; //declare the number of vertices and edges
	cin >> V >> E;
	
	//initialize AM with INT_MAX
	init(V);
	
	//insert the edge between two vertex a and b, and weight of w
	loop(i, 0, E) {
		int a, b, w;
		cin >> a >> b >> w;
		
		add_to_AM(a, b, w);
		add_to_AL(a, b, w);
		add_to_EL(a, b, w);
	}
	
	print_AM(V);
	print_AL(V);
	print_EL();
}

void init(int V) {
	loop(i, 0, V) {
		loop(j, 0, V) {
			AM[i][j] = INT_MAX;
		}
	}
}

void add_to_AM(int a, int b, int w) {
	AM[a][b] = w;
	AM[b][a] = w;
}

void sort_AL(int V) {
	int pos = AL[V].size()-1;
	
	ii temp = AL[V][pos];
	while(pos >= 1 and AL[V][pos-1].first > temp.first) {
		AL[V][pos] = AL[V][pos-1];
		pos--;
	}
	AL[V][pos] = temp;
}

void add_to_AL(int a, int b, int w) {
	AL[a].push_back(mp(b, w));
	sort_AL(a);
	AL[b].push_back(mp(a, w));
	sort_AL(b);
}

void sort_EL() {
	int pos = EL.size()-1;
	
	pii temp = EL[pos];
	while(pos >= 1 and EL[pos-1].first.first > temp.first.first) {
		EL[pos] = EL[pos-1];
		pos--;
	}
	EL[pos] = temp;
	
	temp = EL[pos];
	while(	pos >= 1 and 
			EL[pos-1].first.second > temp.first.second and 
			EL[pos-1].first.first == temp.first.first
		 ) 
	{
		EL[pos] = EL[pos-1];
		pos--;
	}
	EL[pos] = temp;
}

void add_to_EL(int a, int b, int w) {
	EL.push_back(mp(mp(a,b),w));
	sort_EL();
	EL.push_back(mp(mp(b,a),w));
	sort_EL();
}

void print_AM(int V) {
	cout << "\nAM :\n";
	loop(i, 0, V) {
		loop(j, 0, V) {
			if(AM[i][j] != INT_MAX) cout << AM[i][j] << " ";
			else cout << "inf ";
		}
		cout << endl;
	}
}

void print_AL(int V) {
	cout << "\nAL :\n"; 
	loop(i, 0, V) {
		cout << i << ": ";
		loop(j, 0, AL[i].size()) {
			//print the adjacent vertex and its weight respectively
			cout << AL[i][j].first << ";" << AL[i][j].second << " ";
		}
		cout << endl;
	}
}

void print_EL() {
	cout << "\nEL :\n"; 
	loop(i, 0, EL.size()) {
		//print vertices that connected by the edge and its weight repsectively
		cout << EL[i].first.first << " " << EL[i].first.second << " " << EL[i].second << endl;
	}
}
