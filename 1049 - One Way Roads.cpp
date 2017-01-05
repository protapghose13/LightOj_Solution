#include <bits/stdc++.h>
#define mx 20011
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define xx first
#define yy second
//#define int long long
#define SIZE 100011
#define ll long long

using namespace std;

const int inf=1000000000;

int fx[]={1,1,2,2,-1,-1,-2,-2};
int fy[]={2,-2,1,-1,2,-2,1,-1};


int n,m;
vector<int>vec[101];
int vis[101];
int dir[101][101];
int cnt1,cnt2;

void dfs(int node,int src,int par){
    vis[node]=1;
    for(int i=0;i<vec[node].size();i++){
        int v=vec[node][i];
        if(v==par)continue;
        if(v==src){
            if(dir[node][v]==0)
                cnt1+=dir[v][node];
        }
        if(vis[v]==0){
            if(dir[node][v]==0)
                cnt1+=dir[v][node];
            dfs(v,src,node);
        }
    }
}

void clr(){
    cnt1=0,cnt2=0;
    memset(dir,0,sizeof(dir));
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=100;i++)vec[i].clear();
}

int main()
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
            int u,v,w;
            cin>>u>>v>>w;
            cnt2+=w;
            dir[u][v]=w;
            vec[u].pb(v);
            vec[v].pb(u);
        }
        dfs(1,1,-1);
        cout<<"Case "<<++caseno<<": " << min(cnt2-cnt1,cnt1) <<endl;
    }
    return 0;
}
