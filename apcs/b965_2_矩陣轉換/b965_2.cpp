/**************************************************** /
*  apcs problem: 矩陣轉換
*  by: DavidChou
*  date: 2024/7/21
/****************************************************/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n,m, ops; //n rows, m columns, ops: number of operations
	cin >> n>>m>>ops;
	vector<vector<int>> matrix(n, vector<int>(m,0));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> matrix[i][j];
		}
	}
	int start_corner = 0, dir=0;
	// 0: top left, 1: top right, 2: bottom right, 3: bottom left
	for(int i=0; i<ops; i++){
		int op;
		cin >> op;
		if (op == 1) { // filp
			start_corner = 3 - start_corner;
		}
		else { // rotate
			start_corner += 1;
			start_corner %= 4;
			dir = ~dir;
		}
	}
	// output
	int x_start, y_start, x_dir, y_dir;
	if (start_corner == 0) {
		x_start = 0;
		y_start = 0;
		x_dir = 1;
		y_dir = 1;
	}
	else if (start_corner == 1) {
		x_start = m - 1;
		y_start = 0;
		x_dir = -1;
		y_dir = 1;
	}
	else if (start_corner == 2) {
		x_start = m - 1;
		y_start = n - 1;
		x_dir = -1;
		y_dir = -1;
	}
	else {
		x_start = 0;
		y_start = n - 1;
		x_dir = 1;
		y_dir = -1;
	}
	if (dir == 0) {
		cout<<n<<" "<<m<<"\n";
		for (int i = y_start, cnt_y = 0; cnt_y != n; i += y_dir, cnt_y += 1) {
			for (int j = x_start, cnt_x = 0; cnt_x != m; j += x_dir, cnt_x += 1) {
				cout << matrix[i][j] << " \n"[cnt_x==m-1];
			}
		}
	}
	else{
		cout<<m<<" "<<n<<"\n";
		for (int j = x_start, cnt_x = 0; cnt_x != m; j += x_dir, cnt_x += 1) {
			for (int i = y_start, cnt_y = 0; cnt_y != n; i += y_dir, cnt_y += 1) {
				cout << matrix[i][j] << " \n"[cnt_y==n-1];
			}
		}
	}
}