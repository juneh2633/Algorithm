#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int n;
int ij[22][22];
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};
int sum[5];

int ans = 9999999;
int checkArea[22][22];

int solution(int targetI, int targetJ, int d, int dd) {
    vector<int> sum(5, 0);

    // r,c == i ,j x =targetI, y = targetJ
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int area = 4;
            if (i <= targetI + d && j <= targetJ) {
                // i-targetI= -(j-targetJ)
                if (i + j < targetI + targetJ) {
                    area = 0;
                }
            }
            if (i <= targetI + dd && targetJ < j) {
                // i-targetI=(j-targetJ)
                if (i - j < targetI - targetJ) {
                    area = 1;
                }
            }
            if (targetI + d <= i && j < targetJ - d + dd) {
                // i-(targetI+d)=j-(targetJ-d)
                if (i - j > targetI - targetJ + 2 * d) {
                    area = 2;
                }
            }
            if (targetI + dd < i && targetJ - d + dd <= j) {
                // i- (targetI+d+dd)=-( j - (targetJ-d+dd))
                if (i + j > targetI + targetJ + 2 * dd) {
                    area = 3;
                }
            }
            sum[area] += ij[i][j];
            checkArea[i][j] = area;
        }
    }
    sort(sum.begin(), sum.end());
    return sum[4] - sum[0];
}

void findBoundary() {
    for (int i = 2; i < n; i++) {
        for (int j = 2; j < n; j++) {
            // 시작 ij잡기

            for (int d = 1; d < n; d++) {
                for (int dd = 1; dd < n; dd++) {
                    if (j + dd > n || j - d < 1) {
                        continue;
                    }
                    if (i + dd > n || i + d > n) {
                        continue;
                    }

                    ans = min(ans, solution(i, j, d, dd));
                }
            }
        }
    }
    cout << ans;
}

void debug() {
    n = 7;
    memset(checkArea, 0, sizeof(checkArea));
    solution(2, 5, 3, 2);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << checkArea[i][j];
        }
        cout << '\n';
    }
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> ij[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    findBoundary();
}
