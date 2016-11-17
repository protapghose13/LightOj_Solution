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

bool network[650][650];
bool gone[25][25];
string s[25];
int ara[25][25];
int src,des;
int par[650];
bool vis[650];
int n;
int human;

bool issafe(int x,int y){
    return (  x>=0 && x<n && y>=0 && y<n && s[x][y]!='#' );
}

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

void bfs(int s1,int s2,int dis){
    queue<pair<pp,int> >myqueue;
    myqueue.push(mp(mp(s1,s2),0));
    memset(gone,0,sizeof(gone));
    gone[s1][s2]=1;
    while(!myqueue.empty()){
        int u=myqueue.front().xx.xx;
        int v=myqueue.front().xx.yy;
        int d=myqueue.front().yy;
        myqueue.pop();
        for(int i=0;i<4;i++){
            int x=u+fx[i];
            int y=v+fy[i];
            if( issafe(x,y) && gone[x][y]==0){
                gone[x][y]=1;
                myqueue.push(mp(mp(x,y),d+1));
                if(s[x][y]=='G'&&((d+1)*2+2)<=dis ){
                    network[ ara[x][y] ][ ara[s1][s2] ]=1;
                }
            }
        }
    }
}

void make_network(int dis){
    memset(network,0,sizeof(network));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j]=='H'){
                network[ ara[i][j] ][des]=1;
                bfs(i,j,dis);
            }
            if(s[i][j]=='G'){
                network[src][ ara[i][j] ]=1;
            }
        }
    }
}

int find_flow(){
    int temp=0;
    while(1){
        memset(par,0,sizeof(par));
        memset(vis,0,sizeof(vis));
        global=0;
        dfs(src);
        if(global==0)break;
        temp++;
        int u=des;
        while(par[u]!=u){
            int v=par[u];
            network[v][u]=0;
            network[u][v]=1;
            u=v;
        }
    }
    return temp;
}

int solve(){
    int low=0;
    int high=des;
    while(high-low>4){
        int mid=(low+high)>>1;
        make_network(mid);
        int p=find_flow();
        if(p==human) high=mid;
        else low=mid;
    }
    for(int i=low;i<=high;i++){
        make_network(i);
        int p=find_flow();
        if(p==human)return i;
    }
    return -1;
}

 main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(false);
//    cout.tie(false);

//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);



    int t;
    int k=1;
    for(int i=0;i<25;i++){
        for(int j=0;j<25;j++){
            ara[i][j]=k++;
        }
    }
    scanf("%d",&t);
    int caseno=0;
    src=0;
    des=626;
    while(t--){

        memset(network,0,sizeof(network));

        scanf("%d",&n);
        human=0;
        for(int i=0;i<n;i++){
            cin>>s[i];
            for(int j=0;j<n;j++){
                if(s[i][j]=='H')
                    human++;
            }
        }

        int res=solve();
        if(res==-1)
            printf("Case %d: Vuter Dol Kupokat\n",++caseno );
        else
            printf("Case %d: %d\n",++caseno,res );
    }
    return 0;
}
