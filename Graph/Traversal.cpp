#include <bits/stdc++.h>
#define ii pair<int, int>
#define vii vector<ii>
#define vi vector<int>
#define vv vector<vi>
#define mp make_pair
#define loop(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int V, E; //declare the number of vertices and edges
vv AL(110);

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
	AL[b].push_back(a);
	sort_AL(b);
}

bool pernah[100];
vector<int> ans;
queue<int> temp;

void DFS(int v) {
	pernah[v] = true;
	
	ans.push_back(v);
	loop(i, 0, AL[v].size()) {
		if(!pernah[AL[v][i]]) DFS(AL[v][i]);
	}
}

void BFS(int v) {
	temp.push(v);
	ans.push_back(v);
	
	while(!temp.empty()) {
		int f = temp.front();
		pernah[f] = true;
			
		loop(i, 0, AL[f].size()) {
			if(!pernah[AL[f][i]]) {
				temp.push(AL[f][i]);
				pernah[AL[f][i]] = true;
				ans.push_back(AL[f][i]);
			}
		}
			
		temp.pop();
	}	
}

int main(){
	cin >> V >> E;
	
	//insert the edge between two vertex a and b
	loop(i, 0, E) {
		int a, b;
		cin >> a >> b;
		
		add_to_AL(a, b);
	}
	
	int a;
	cin >> a;
	BFS(a);
	loop(i, 0, ans.size()) {
		cout << ans[i];
		if(i != ans.size()-1) cout << " -> ";
		else cout << endl;
	}
}
