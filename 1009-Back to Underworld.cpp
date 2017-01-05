#include <bits/stdc++.h>
#define mx 20011
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define xx first
#define yy second
#define inf 1000000000000000
//#define int long long
#define SIZE 100011
#define ll long long

using namespace std;

vector<int>vec[mx];
int vis[mx],n;
int cnt1,cnt2;

void dfs(int node){
    for(int i=0;i<vec[node].size();i++){
        int v=vec[node][i];
        if(vis[v])continue;
        if(vis[node]==1)vis[v]=2,cnt2++;
        else vis[v]=1,cnt1++;
        dfs(v);
    }
}

void clr(){
    for(int i=0;i<mx;i++){
        vec[i].clear();
        vis[i]=0;
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t,caseno=0;
    cin>>t;
    while(t--){
        cin>>n;
        clr();
        for(int i=0;i<n;i++){
            int u,v;
            cin>>u>>v;
            vec[u].pb(v);
            vec[v].pb(u);
        }
        int ans=0;
        for(int i=1;i<=mx;i++){
            if(vis[i]==0){
                vis[i]=1;
                cnt1=1,cnt2=0;
                dfs(i);
                if(cnt2)ans+=max(cnt2,cnt1);
            }
        }
        cout<<"Case "<<++caseno<<": "<<ans<<endl;
    }
    return 0;
}
