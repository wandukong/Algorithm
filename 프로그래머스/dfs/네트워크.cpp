#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
int check[201];

void dfs(int v) {
	check[v] = 1;
	for (int i = 0; i < adj[v].size(); i++) 
		if (!check[adj[v][i]]) dfs(adj[v][i]);
}

int main() {
	int answer = 0;
	int n = 3;
	vector<vector<int>> computers = { {1, 1, 0}, {1, 1, 1},{0, 1, 1} };
	
	adj.resize(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			else if (computers[i][j])
				adj[i].push_back(j);
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			dfs(i);
			answer++;
		}
	}
	printf("%d", answer);

	return 0;
}