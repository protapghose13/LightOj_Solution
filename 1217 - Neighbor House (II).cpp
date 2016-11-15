#include <bits/stdc++.h>
#define mx 44
#define pb push_back
#define mp make_pair
#define mod 100000007
#define xx first
#define yy second

using namespace std;

int n,m;
int dp[10011][2],ara[1011];

int call(int idx , bool flag){
    if(idx>=n)
        return 0;
    if(idx==n-1)
    {
        if(flag==0)return ara[idx];
        else return 0;
    }

    if(dp[idx][flag]!=-1)
        return dp[idx][flag];

    int res;
    if(idx==0){
        res = max( call(idx+1,flag),ara[idx]+call(idx+2,1) );
    }
    else{
        res = max( call(idx+1,flag),ara[idx]+call(idx+2,flag) );
    }
    return dp[idx][flag]=res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t;
    cin>>t;
    int caseno=0;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>ara[i];
        }
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<++caseno<<": "<<call(0,0)<<endl;
    }
    return 0;
}
