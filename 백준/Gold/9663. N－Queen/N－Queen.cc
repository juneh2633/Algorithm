#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <queue>
#include <utility>
#include <map>
#include <stack>
using namespace std;
int n;
int ans = 0;
int col[17] = { 0, };
bool check(int depth) {
	for (int i = 0; i < depth; i++) {
		if (col[i] == col[depth]||depth-i==abs(col[i]-col[depth])) {
			return false;
		}
	}
	return true;
}

void solution(int depth) {
	if (depth == n) {
		ans++;
	}
	for (int i = 0; i < n; i++) {
		col[depth] = i;
		if (check(depth))solution(depth+1);

	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	solution(0);
	cout << ans;
	
}