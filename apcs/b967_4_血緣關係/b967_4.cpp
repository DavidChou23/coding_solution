/**************************************************** /
*  apcs problem: 血緣關係
*  by: DavidChou
*  date: 2024/7/20
/****************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n; //read number of nodes

	vector<vector<int>> nodes(n); //index: id, value: neighbor
	vector<int> visited(n, 0);
	int longest_dist = -1;

	//read input
	while (!cin.eof()) { //read until EOF
		int a, b;
		cin >> a >> b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}

	int start = 0;
	//search first leaf nodes
	for (int i = 0; i < n; i++) {
		if (nodes[i].size() == 1) {
			start = i;
			break;
		}
	}
	
	int tmp_dist = 0;
	//search longest distance with BFS
	while (longest_dist != tmp_dist) {
		longest_dist = max(longest_dist, tmp_dist);
		visited.assign(n, 0);
		vector<int> dist(n, 0);
		queue<int> q;
		q.push(start);
		visited[start] = 1;
		tmp_dist = 0;

		while (!q.empty()) {
			int cur = q.front();

			for (int next : nodes[cur]) {
				if (visited[next] == 0) {
					visited[next] = 1;
					dist[next] = dist[cur] + 1;
					q.push(next);
				}
			}
			visited[cur] = 2;
			tmp_dist = dist[cur];
			if (q.size() == 1) {
				start = q.front();
			}
			q.pop();
		}
	}
	std::cout << longest_dist << "\n";
}