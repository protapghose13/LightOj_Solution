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

bool network[811][811];
string s[21];
pp ara[21][21];
int src,des;
int par[811];
bool vis[811];
int n,m;


bool global;
void dfs(int node){
    if(node==des)global=1;
    if(global)return;
    vis[node]=1;
    for(int i=0;i<=des;i++){
        if(network[node][i] && vis[i]==0){
            par[i]=node;
            dfs(i);
        }
    }
}

bool issafe(int x,int y){
    return (  x>=0 && x<n && y>=0 && y<m );
}

 main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(false);
//    cout.tie(false);

//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);



    int t;
    int k=1;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            ara[i][j]=mp(k,k+400);
            k++;
        }
    }
    scanf("%d",&t);
    int caseno=0;
    src=0;
    des=801;
    while(t--){

        memset(network,0,sizeof(network));

        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            cin>>s[i];
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j]=='*'){
                    cnt++;
                    network[src][ara[i][j].xx]=1;
                    network[ara[i][j].yy][des]=1;
                    for(k=0;k<4;k++){
                        int p=i+fx[k];
                        int q=j+fy[k];
                        if( issafe(p,q) && s[p][q]=='*' ){
                            network[ ara[i][j].xx ][ ara[p][q].yy  ]=1;
                        }
                    }
                }
            }
        }


        int ans=0;
        while(1){
            memset(par,0,sizeof(par));
            memset(vis,0,sizeof(vis));
            global=0;
            dfs(src);
            if(global==0)break;
            ans++;
            int u=des;
            while(par[u]!=u){
                int v=par[u];
                network[v][u]=0;
                network[u][v]=1;
                u=v;
            }
        }

        printf("Case %d: %d\n",++caseno,cnt-ans/2);
    }
    return 0;
}
