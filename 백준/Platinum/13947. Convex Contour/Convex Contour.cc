#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
double pi=3.14159265;
int n;
string s;
double ans;
double Ho[20]={0,1.0091418,2.0045075,3.0029975,4.0022462,5.0017962,6.0014965,7.0012826,8.0011221,9.0009974,10.0008976,11.0008160,12.0007480,13.0006904,14.0006411,15.0005984,16.0005610,17.0005280,18.0004986,19.0004724};
double S[20]={0,4.5176381,6.5059712,8.5035873,10.5025632,12.5019939,14.5016315,16.5013806,18.5011965,20.5010558,22.5009446,24.5008547,26.5007804,28.5007179,30.5006648,32.5006189,34.5005790,36.5005439,38.5005128,40.5004851};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>s;
    if(n==1){
        if(s=="T")ans=3;
        else if(s=="C")ans=pi;
        else 
            ans=4;
        cout<<fixed;cout.precision(6);cout<<ans;
        return 0;
    }
    ans=0.0;
    int i=0;
    if(s[0]=='T'){
        while(i<n&&s[i]=='T')i++;
        if(i==n){
            ans=2*n+1;
            cout<<fixed;cout.precision(6);cout<<ans;
            return 0;
        }
        else{
            if(s[i]=='C')ans=Ho[i]+2.5+i;
            else if(s[i]=='S')ans=S[i];
        }
    }
    else if(s[0]=='C'){
        i=1;ans=pi*0.5+2+1;
    }
    else{
        i=1;ans=5;
    }
    int j=0;
    if(s[n-1]=='T'){

        while(i<=n-1-j&&s[n-1-j]=='T')j++;

        if(s[n-1-j]=='C')ans+=Ho[j]+2.5+j;
        else if(s[n-1-j]=='S')ans+=S[j];

    }
    else if(s[n-1]=='C'){
        j=1;ans+=pi*0.5+3;
    }
    else{
        j=1;ans+=5;
    }    
    if(n-1-j==i)ans-=2;
    else if(n-1-j==i+1)i=1;
    else 
        ans+=(n-1-j-i-1)*2;
    cout<<fixed;cout.precision(7);cout<<ans;
}   