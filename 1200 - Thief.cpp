#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define mx 61
#define xx first
#define yy second
#define int long long

using namespace std;

const int inf=1000000000000;


struct node{
    int p,c,w;
};
node arr[101];
int N,W;
int dp[101][10001];

int call(int id,int weight){
    if(id==N)
        return 0;

    if(dp[id][weight]!=-1)
        return dp[id][weight];

    int res=0;
    if(weight-arr[id].w>=0)
        res = max(res,arr[id].p+call(id,weight-arr[id].w));
    res = max(res,call(id+1,weight));

    return dp[id][weight]=res;
}


main(){
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t;
    cin>>t;
    int caseno=0;
    while(t--){
        cin>>N>>W;
        for(int i=0;i<N;i++){
            cin>>arr[i].p>>arr[i].c>>arr[i].w;
            W-=(arr[i].c*arr[i].w);
        }
        cout<<"Case "<<++caseno<<": ";
        memset(dp,-1,sizeof(dp));
        if(W<0)cout<<"Impossible"<<endl;
        else cout<<call(0,W)<<endl;
    }
    return 0;
}
