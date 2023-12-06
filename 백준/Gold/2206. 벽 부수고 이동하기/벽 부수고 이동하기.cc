#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int ij[1111][1111][2];

int n, m;
struct cor{
    int i;
    int j;
    bool power;
    int weight;
};
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
void solution(){
    queue<cor> q;
    q.push({0, 0, 0, 1});
    while(!q.empty()){
        cor c = q.front();
        q.pop();
        
        //cout<<"@@"<<c.i<<" "<<c.j<<'\n';
        if (c.i == n - 1 && c.j == m - 1){
            cout << c.weight;
            return;
        }
        for (int d = 0; d < 4;d++){
            int ii = c.i + di[d];
            int jj = c.j + dj[d];
            if(ii<0||jj<0||ii>=n||jj>=m){
                continue;
            }
            if(c.power==1){
                if(ij[ii][jj][1]==0){
                    q.push({ii, jj, 1, c.weight + 1});
                    ij[ii][jj][1]=2;
                }

            }
            else if(c.power==0){
                if(ij[ii][jj][0]==0){
                    q.push({ii, jj, 0, c.weight + 1});
                    ij[ii][jj][0]=2;
                }    
                else if(ij[ii][jj][0]==1){
                    q.push({ii, jj, 1, c.weight + 1});
                    ij[ii][jj][1]=2;
                }
            }
        }
    }
    cout << "-1";
    return;
}

int main(){

    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            char ch;
            cin >> ch;
            ij[i][j][0]=ch-'0';
            ij[i][j][1]=ch-'0';
        }
    }
    solution();
}

