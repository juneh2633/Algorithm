#include <bits/stdc++.h>
using namespace std;
int n, m;
char ij[35][35];
int yx[13][13];
int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };

bool check_area(int i, int j) {
	if (i < 0 || i >= n)return 0;
	if (j < 0 || j >= m)return 0;
	return 1;
}

char sqtr[6][3][3] = {
	{{'.','.','.'}, {'.','.','.'}, {'.','.','.'}},
	{{'#','#','#'}, {'#','#','#'}, {'#','#','#'}},
	{{'#','.','.'}, {'#','#','.'}, {'#','#','#'}},
	{{'#','#','#'}, {'.','#','#'}, {'.','.','#'}},
	{{'#','#','#'}, {'#','#','.'}, {'#','.','.'}},
	{{'.','.','#'}, {'.','#','#'}, {'#','#','#'}}
};
int classification(int i, int j) {
	bool t = 0;
	for (int k = 0; k < 6; k++) {
		t = 0;
		for (int y = 0; y < 3; y++) {

			for (int x = 0; x < 3; x++) {
				if (x == 1 && y == 1)continue;
				if (ij[i + y][j + x] != sqtr[k][y][x]) {
					t = 1;
					break;
				}

			}
			if (t == 1)break;
		}
		if (t == 0)return k;
	}
}
void sqcheck(int i, int j) {
	int t = classification(i, j);

	if (t == 1) {
		if (ij[i + 1][j + 1] - '0' >= 0) {
			t = ij[i + 1][j + 1] - '0' + 10;
		}
		yx[i / 3][j / 3] = t;
	}
	else yx[i / 3][j / 3] = t;

}

bool check_num_true(int i, int j) {
	int t = yx[i][j] - 10;

	int cnt = 0;
	for (int k = 0; k < 4; k++) {
		int ii = di[k] + i;
		int jj = dj[k] + j;
		if (!check_area(ii, jj))continue;
		if (yx[ii][jj] >= 2 && yx[ii][jj] < 10)cnt++;
	}
	yx[i][j] = 1;
	if (cnt == t)return 1;
	else return 0;
}
bool bfs(int i, int j) {
	queue<pair<int, int>>q;
	q.push({ i,j });

	while (!q.empty()) {
		int ki = q.front().first;
		int kj = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ni = di[k] + ki;
			int nj = dj[k] + kj;
			if (yx[ni][nj] == -1)continue;
			else if (yx[ni][nj] != 0)return 0;
			yx[ni][nj] = -1;
			q.push({ ni,nj });
		}
	}
	return 1;
}

bool check_rectangle_sq(int i, int j) {
	yx[i][j] = -2;
	int a = i + 1;
	while (a < n && yx[a][j] == 0) {
		yx[a][j] = -2;
		a++;
	}
	a--;

	if (a + 1 < n) {
		if (yx[a + 1][j] == -2)return 0;
	}


	int b = i - 1;
	while (b >= 0 && yx[b][j] == 0) {
		yx[b][j] = -2;
		b--;
	}
	b++;
	
	if (b - 1 >= 0) {
		if (yx[b - 1][j] == -2)return 0;
	}
	int c = j + 1;
	while (c < m && yx[i][c] == 0) {
		yx[i][c] = -2;
		c++;
	}
	c--;

	if (c + 1 < m) {
		if (yx[i][c + 1] == -2)return 0;
	}

	int d = j - 1;
	while (d >= 0 && yx[i][d] == 0) {
		yx[i][d] = -2;
		d--;
	}
	d++;

	if (d - 1 >= 0) {
		if (yx[i][d - 1] == -2)return 0;
	}
	for (int y = b; y <= a; y++) {
		for (int x = d; x <= c; x++) {
			if (yx[y][x] == -2)continue;
			if (yx[y][x] != 0) {
				return 0;
			}
			yx[y][x] = -2;
		}
	}

	
	return 1;
}
bool check_rectangle_tr(int i, int j) {
	if (!check_area(i, j + 1) || yx[i][j + 1] != 3)return 0;
	yx[i][j] = -1;
	int ii = i + 1;
	int jj = j - 1;
	while (check_area(ii, jj) && yx[ii][jj] == 4) {
		yx[ii][jj] = -1;
		ii++;
		jj--;
	}
	ii--;
	jj++;


	if (yx[ii + 1][jj] != 2) {
		return 0;
	}
	yx[ii + 1][jj] = -1;

	int iii = ii + 2;
	int jjj = jj + 1;

	while (check_area(iii, jjj) && yx[iii][jjj] == 2) {
		yx[iii][jjj] = -1;
		iii++;
		jjj++;
	}
	iii--;
	jjj--;

	if (yx[iii][jjj + 1] != 5) {
		return 0;
	}
	yx[iii][jjj + 1] = -1;

	int ki = iii - 1;
	int kj = jjj + 2;
	while (check_area(ki, kj) && yx[ki][kj] == 5) {
		yx[ki][kj] = -1;
		ki--;
		kj++;
	}
	ki++;
	kj--;


	if (yx[ki - 1][kj] != 3) {
		return 0;
	}
	yx[ki - 1][kj] = -1;

	int kki = ki - 2;
	int kkj = kj - 1;
	while (check_area(kki, kkj) && yx[kki][kkj] == 3) {
		yx[kki][kkj] = -1;
		kki--;
		kkj--;
	}
	kki++;
	kkj++;


	if (i != kki || j + 1 != kkj)return 0;

	if (i + 1 == ki&&iii==ki)return 1;

	if (yx[i + 1][j] != -1) {
		if (yx[i + 1][j] == 1)return 0;
		if (bfs(i + 1, j) == 0) {

			return 0;
		}

	}
	else {
		if (yx[i + 1][j+1] == 1)return 0;
		if (bfs(i + 1, j + 1) == 0) {

			return 0;
		}
	}


	return 1;



}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	bool ans = 1;
	for (int i = 0; i < n * 3; i++) {
		for (int j = 0; j < m * 3; j++) {
			cin >> ij[i][j];
		}
	}
	for (int i = 0; i < n * 3; i = i + 3) {
		for (int j = 0; j < m * 3; j = j + 3) {
			sqcheck(i, j);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (yx[i][j] >= 10) {
				if (!check_num_true(i, j))ans = 0;
			}
		}
	}
	if (ans == 0) {

		cout << "NO";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (yx[i][j] < 0)continue;
			else if (yx[i][j] == 1)continue;
			else if (yx[i][j] == 0) {
				if (!check_rectangle_sq(i, j)) {
					cout << "NO";			
					return 0;
				}
			}
			else if (yx[i][j] == 4) {
				if (!check_rectangle_tr(i, j)) {
					cout << "NO";

					return 0;
				}
			}
			else {
				cout << "NO";

				return 0;
			}
		}
	}
	
	cout << "YES";
	
}