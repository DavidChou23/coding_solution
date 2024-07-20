/**************************************************** /
*  apcs problem: 成績指標
*  by: DavidChou
*  date: 2024/7/21
/****************************************************/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> score(n);
	for(int i = 0; i < n; i++) {
		cin >> score[i];
	}

	sort(score.begin(), score.end());
	for (int i = 0; i < n; i++) {
		cout << score[i] << " \n"[i == n - 1];
	}
	int idx = lower_bound(score.begin(), score.end(), 60) - score.begin();
	if (idx == 0) {
		cout << "best case\n";
	} else {
		cout << score[idx-1] << "\n";
	}
	if (idx == n) {
		cout << "worst case\n";
	} else {
		cout << score[idx] << "\n";
	}
}