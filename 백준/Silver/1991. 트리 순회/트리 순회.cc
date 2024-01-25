#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstring>
#include <math.h>
#include <stack>
#include <iomanip>
#include <queue>
#include <utility>
#include <map>
typedef long long ll;
using namespace std;
int tree[33][3];
void preorder(int N){
    if(N<0)return;
    cout<<(char)(N+'A');
    preorder(tree[N][0]);
    preorder(tree[N][1]);
}
void inorder(int N){
    if(N<0)return;
 
    inorder(tree[N][0]);
    cout<<(char)(N+'A'); 
    inorder(tree[N][1]);
}
void postorder(int N){
    if(N<0)return;
    
    postorder(tree[N][0]);
    postorder(tree[N][1]);
    cout<<(char)(N+'A');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char a,b,c;
        cin>>a>>b>>c;
        if(b!='.')tree[a-'A'][0]=b-'A';
        else tree[a-'A'][0]=-1;
        if(c!='.')tree[a-'A'][1]=c-'A';
        else tree[a-'A'][1]=-1;
    }
    preorder(0);
    cout<<'\n';
    inorder(0);
    cout<<'\n';
    postorder(0);
}

