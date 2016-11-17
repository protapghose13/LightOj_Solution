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

vector<pair<pair<int,int>,int> >vec,vec1;
bool network[111][111],vis[111];
int src,des;
int par[111];
int n,m;

int bfs(){
    queue<int>myq;
    myq.push(src);
    par[src]=src;
    memset(vis,0,sizeof(vis));
    vis[src]=1;
    while(!myq.empty()){
        int u=myq.front();
        myq.pop();
        for(int i=0;i<=des;i++){
            if(vis[i]==0 && network[u][i]){
                myq.push(i);
                vis[i]=1;
                par[i]=u;
                if(i==des)return 1;
            }
        }
    }
    return 0;
}


void clr(){
    vec.clear();
    vec1.clear();
    memset(network,0 , sizeof(network));
}

 main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(false);
//    cout.tie(false);


    int t;
    scanf("%d",&t);
    int caseno=0;
    while(t--){
        clr();
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            vec.pb(mp(mp(u,v),w));
        }
        for(int i=0;i<m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            vec1.pb(mp(mp(u,v),w));
        }
        src=0;
        des=105;
        for(int i=0;i<n;i++){
            network[0][i+1]=1;
            int p=vec[i].xx.xx;
            int q=vec[i].xx.yy;
            int r=vec[i].yy;
            for(int j=0;j<m;j++){
                network[j+1+n][105]=1;
                int u=vec1[j].xx.xx;
                int v=vec1[j].xx.yy;
                int w=vec1[j].yy;

                if(  abs(u-p)<=12  && abs(v-q)<=5 && w==r ){
                    network[i+1][j+1+n]=1;
                }

            }
        }

        int ans=0;
        while(1){
            memset(par,-1,sizeof(par));
            int p=bfs();
            if(p==0)break;
            ans++;
            int u=des;
            while(par[u]!=u){
                int v=par[u];
                network[v][u]=0;
                network[u][v]=1;
                u=v;
            }
        }

        printf("Case %d: %d\n",++caseno,ans);
    }
    return 0;
}
