#include <bits/stdc++.h>
#define mx 10001
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define xx first
#define yy second
#define inf 1000000000
//#define int long long

using namespace std;

int n,m,par[mx],k,ans;
bool vis[mx];
vector<pair<int,pair<int,int> > >vec;
vector<int>graph[mx];


int find(int r){
    if(par[r]==r)return r;
    return par[r]=find(par[r]);
}

void mst(){
    sort(vec.begin(),vec.end());
    int sz=vec.size();
    int f=0;
    for(int i=0;i<sz;i++){
        int u=vec[i].yy.xx;
        int v=vec[i].yy.yy;
        int w=vec[i].xx;
        int p=find(u);
        int q=find(v);
        if(p!=q){
            f++;
            par[p]=q;
            graph[u].pb(v);
            graph[v].pb(u);
            ans+=w;
            if(f==n-1){
                return;
            }
        }
    }
}

void dfs(int node,int pr){
    vis[node]=1;
    int sz=graph[node].size();
    for(int i=0;i<sz;i++){
        int v=graph[node][i];
        if(vis[v]||v==pr)continue;
        dfs(v,node);
    }
}


void clr(){
    for(int i=0;i<mx;i++){
        par[i]=i;
        vis[i]=0;
        graph[i].clear();
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
        cin>>n>>m>>k;
        ans=0;
        for(int i=0;i<m;i++){
            int u,v,p;
            cin>>u>>v>>p;
            if(p>=k)continue;
            vec.pb(mp(p,mp(u,v)));
        }
        cout<<"Case "<<++caseno<<": ";
        mst();
        int tt=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                ans+=k;
                tt++;
                dfs(i,-1);
            }
        }
        cout<<ans<<" "<<tt<<endl;
    }


    return 0;
}
