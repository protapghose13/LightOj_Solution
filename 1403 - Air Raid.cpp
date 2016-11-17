#include <bits/stdc++.h>
#define mx 200011
#define pb push_back
#define mp make_pair
#define mod 100000007
#define xx first
#define yy second
//#define int long long
#define inf 20000000000000009

using namespace std;

typedef pair<int,int> pp;

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};

int n, m;
int network[1010][1010];
int vis[1010];
int match[1010];
vector<int> graph[1010];

int dfs(int u)
{
    int i;
    for (i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(vis[v] == 0 && network[u][v] == 1){
            vis[v] = 1;
            if (match[v] == 0 || dfs(match[v])){
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}



int solve(){
    int temp=0;
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i)){
            temp++;
        }
    }
    return temp;
}

 main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(false);
//    cout.tie(false);

//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int t;
    scanf("%d",&t);
    int caseno=0;
    while(t--){

        memset(network,0,sizeof(network));
        memset(match,0,sizeof(match));

        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            network[u][v]=1;
            graph[u].pb(v);
        }
        printf("Case %d: %d\n",++caseno, n-solve() );
        for(int i=0;i<1001;i++)graph[i].clear();
    }
    return 0;
}
