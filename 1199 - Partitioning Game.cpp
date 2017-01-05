#include <bits/stdc++.h>
#define mx 750011
#define mp make_pair
#define pb push_back
//#define int  long long
#define mod 1000000007
//#define inf 100000000
#define xx first
#define yy second
//#define N 3

using namespace std;

int n,m,cs,k,val;

int fx[]={-2,-2,1,-1};
int fy[]={1,-1,-2,-2};

int dp[10001];

vector<int>v;
bool rem[10001];

void precalc(){
    memset(dp,-1,sizeof(dp));
    dp[1]=0;
    dp[2]=0;
    for(int i=3;i<=10000;i++){
        memset(rem,0,sizeof(rem));
        for(int j=1;j< (i+1)/2 ;j++){
            if(j==i-j)continue;
            rem[ dp[j]^dp[i-j] ]=1;
        }
        int res=0;
        while(rem[ res ])res++;
        dp[i]=res;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t;
    precalc();
//    for(int i=1;i<20;i++){
//        cout<<dp[i]<<" ";
//    }
//    cout<<endl;
    cin>>t;
    int caseno=0;
    while(t--){
        cin>>n;
        int res=0;
        for(int i=0;i<n;i++){
            int p;
            cin>>p;
            res ^= dp[p];
        }
        cout<<"Case "<<++caseno<<": ";
        if(res)cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}
