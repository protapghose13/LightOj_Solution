#include <bits/stdc++.h>
#define mx 1000001
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define xx first
#define yy second
#define inf 1000000000
//#define int long long

using namespace std;

int n,m,ans[500],par[500];
vector<pair<int,pair<int,int> > >vec;
vector<int>graph[500],cost[500];
bool vis[500];

void dfs(int node,int pr){
    vis[node]=1;
    for(int i=0;i<graph[node].size();i++){
        int v=graph[node][i];
        if( vis[v] || v==pr )continue;
        ans[v]=max(ans[node],cost[node][i]);
        dfs(v,node);
    }
}

int find(int r){
    if(par[r]==r)return r;
    return par[r]=find(par[r]);
}

void mst(){
    sort(vec.begin(),vec.end());
    int sz=vec.size();
    for(int i=0;i<sz;i++){
        int u=vec[i].yy.xx;
        int v=vec[i].yy.yy;
        int w=vec[i].xx;
        int p=find(u);
        int q=find(v);
        if(p!=q){
            par[p]=q;
            graph[u].pb(v);
            graph[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
        }
    }
}


void clr(){
    for(int i=0;i<500;i++){
        graph[i].clear();
        cost[i].clear();
        par[i]=i;
        ans[i]=inf;
        vis[i]=0;
    }
    vec.clear();
}

int main()
{
//    freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t,caseno=0;
    cin>>t;
    while(t--){
        clr();
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            vec.pb(mp(w,mp(u,v)));
        }
        int p;
        cin>>p;
        mst();
        ans[p]=0;
        dfs(p,-1);
        cout<<"Case "<<++caseno<<":"<<endl;
        for(int i=0;i<n;i++){
            if(ans[i]==inf)cout<<"Impossible"<<endl;
            else cout<<ans[i]<<endl;
        }
    }


    return 0;
}
