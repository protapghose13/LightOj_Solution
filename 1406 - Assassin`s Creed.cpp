#include <bits/stdc++.h>
#define mx 30011
#define pb push_back
//#define int long long
#define mod 100000007

using namespace std;

int visited[16][1<<16];
int visarea[1<<16];
vector<int>vec[16];
int dp[1<<16];

void dfs(int node,int mask){
    visited[node][mask]=1;
    visarea[mask]=1;
    int sz=vec[node].size();
    for(int i=0;i<sz;i++){
        int v=vec[node][i];
        if( visited[v][mask|(1<<v)]==0){
            dfs(v, mask|(1<<v) );
        }
    }
}

int call(int mask){
    if(mask==0)
        return 0;

    if(dp[mask]!=-1)
        return dp[mask];

    int res=20;
    for(int i=mask ; i>0 ; i = mask&(i-1) ){
        if(visarea[i]){
            res = min(res,1+call(mask^i));
        }
    }
    return dp[mask]=res;
}

void clr(int n){
    for(int i=0;i<n;i++){
        vec[i].clear();
    }
    memset(visarea,0,sizeof(visarea));
    memset(visited,0,sizeof(visited));
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);

    int t;
    cin>>t;
    int caseno=0;
    while(t--){
        int n,m;
        cin>>n>>m;
        clr(n);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            vec[u].pb(v);
        }
        for(int i=0;i<n;i++){
            dfs(i,(1<<i));
        }
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<++caseno<<": "<<call((1<<n)-1)<<endl;
    }
}
