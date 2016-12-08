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


int n,m,k,d,dis[mx][11];
vector<pair<int,int> >vec[mx],vec1[mx];

struct node{
    int u,w,id;
    node(){}
    node(int a,int b,int c){
        u=a,w=b,id=c;
    }
    bool operator < (const node &p) const{
        return w>p.w;
    }
};

int dijkstra(){
    priority_queue<node>pq;
    pq.push(node(0,0,0));
    dis[0][0]=0;
    int ans=INT_MAX;
    while(!pq.empty()){
        node pro=pq.top();
        pq.pop();
        int from=pro.u;
        int w=pro.w;
        if(from==n-1)return w;
        int val=pro.id;
        for(int i=0;i<vec[from].size();i++){
            int to=vec[from][i].xx;
            int cst=vec[from][i].yy;
            if(dis[to][val]>dis[from][val]+cst){
                dis[to][val]=dis[from][val]+cst;
                pq.push(node(to,dis[to][val],val));
            //    if(to==n-1)ans=min(ans,dis[to][val]);
            }
        }
        for(int i=0;i<vec1[from].size();i++){
            int to=vec1[from][i].xx;
            int cst=vec1[from][i].yy;
            if(dis[to][val+1]>dis[from][val]+cst && val+1<=d){
                dis[to][val+1]=dis[from][val]+cst;
                pq.push(node(to,dis[to][val+1],val+1));
              //  if(to==n-1)ans=min(ans,dis[to][val+1]);
            }
        }
    }
    return ans;
}

void clr(){
    for(int i=0;i<mx;i++){
        vec[i].clear();
        vec1[i].clear();
        for(int j=0;j<11;j++){
            dis[i][j]=inf;
        }
    }
}

int main()
{
//    freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);

//    ios_base::sync_with_stdio(false);
//    cin.tie(false);
//    cout.tie(false);

    int t,caseno=0;
    scanf("%d",&t);
    while(t--){
        clr();
        scanf("%d%d%d%d",&n,&m,&k,&d);
        for(int i=0;i<m;i++){
            int u,v,p;
            scanf("%d%d%d",&u,&v,&p);
            vec[u].pb(mp(v,p));
        }
        for(int i=0;i<k;i++){
            int u,v,p;
            scanf("%d%d%d",&u,&v,&p);
            vec1[u].pb(mp(v,p));
        }
        printf("Case %d: ",++caseno);
        int ret=dijkstra();
        if(ret==INT_MAX)cout<<"Impossible"<<endl;
        else cout<<ret<<endl;
    }
    return 0;
}
