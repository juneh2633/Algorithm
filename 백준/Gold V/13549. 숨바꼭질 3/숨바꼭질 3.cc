#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
int MAX_INT = 100001;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    queue<int> q;
    vector<int> dp(MAX_INT, MAX_INT);
    q.push(n);
    dp[n] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if (cur == k){
            cout << dp[cur];
            return 0;
        }
        if(cur*2<MAX_INT&&dp[cur*2]>dp[cur]){
            dp[cur * 2] = dp[cur];
            q.push(cur * 2);
        }
        if(cur+1<MAX_INT&&dp[cur+1]>dp[cur]+1){
            dp[cur + 1] = dp[cur] + 1;
            q.push(cur + 1);
        }
        if(cur - 1 >= 0&&dp[cur-1]>dp[cur]+1){
            dp[cur - 1] = dp[cur] + 1;
            q.push(cur - 1);
        }
    }
    return 0;
}