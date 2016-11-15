#include <bits/stdc++.h>
#define mx 1001
#define pb push_back
//#define int long long
#define mod 100000007

using namespace std;

vector<int>vec[mx];
int n,m;
int dp2[mx],dp1[mx];
bool vis[mx];

void dfs(int node,int par){
    int sum1=0,sum2=0;
    vis[node]=1;
    int sz=vec[node].size();
    for(int i=0;i<sz;i++){
        int v=vec[node][i];
        if(v==par || vis[v])continue;
        dfs(v,node);
        sum1 += dp2[v];
        sum2 += max(dp1[v],dp2[v]);
    }
    dp1[node] = 1+sum1;
    dp2[node] = sum2;
   // cout<<node<<" "<<par<<" "<<dp1[node]<<" "<<dp2[node]<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t;
    cin>>t;
    int caseno=0;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            vec[u].pb(v);
            vec[v].pb(u);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                dfs(i,-1);
                ans += max(dp1[i],dp2[i]);
            }
        }
        cout<<"Case "<<++caseno<<": "<<ans<<endl;
        for(int i=0;i<mx;i++)vec[i].clear();
        memset(vis,0,sizeof(vis));
    }
    return 0;
}
