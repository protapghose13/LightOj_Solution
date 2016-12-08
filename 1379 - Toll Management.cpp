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


int n,m,s,t,p,dis1[mx],dis2[mx];
vector<pair<int,int> >vec[mx],rev_vec[mx];
vector<pair<int,pair<int,int> > >vec1;

struct node{
    int u,w;
    node(){}
    node(int a,int b){
        u=a,w=b;
    }
    bool operator < (const node &p) const{
        return w>p.w;
    }
};

void dijkstra(int src){
    for(int i=0;i<mx;i++)dis1[i]=inf;
    priority_queue<node>pq;
    pq.push(node(src,0));
    dis1[src]=0;
    while(!pq.empty()){
        node pro=pq.top();
        pq.pop();
        int from=pro.u;
        int w=pro.w;
        for(int i=0;i<vec[from].size();i++){
            int to=vec[from][i].xx;
            int cst=vec[from][i].yy;
            if(dis1[to]>dis1[from]+cst){
                dis1[to]=dis1[from]+cst;
                pq.push(node(to,dis1[to]));
            }
        }
    }
}

void dijkstra1(int src){
    for(int i=0;i<mx;i++)dis2[i]=inf;
    priority_queue<node>pq;
    pq.push(node(src,0));
    dis2[src]=0;
    while(!pq.empty()){
        node pro=pq.top();
        pq.pop();
        int from=pro.u;
        int w=pro.w;
        for(int i=0;i<rev_vec[from].size();i++){
            int to=rev_vec[from][i].xx;
            int cst=rev_vec[from][i].yy;
            if(dis2[to]>dis2[from]+cst){
                dis2[to]=dis2[from]+cst;
                pq.push(node(to,dis2[to]));
            }
        }
    }
}

void clr(){
    for(int i=0;i<mx;i++){
        vec[i].clear();
        rev_vec[i].clear();
    }
    vec1.clear();
}

int main()
{
//    freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);

//    ios_base::sync_with_stdio(false);
//    cin.tie(false);
//    cout.tie(false);

    int tt,caseno=0;
    scanf("%d",&tt);
    while(tt--){
        clr();
        scanf("%d%d%d%d%d",&n,&m,&s,&t,&p);
        for(int i=0;i<m;i++){
            int u,v,p;
            scanf("%d%d%d",&u,&v,&p);
            vec[u].pb(mp(v,p));
            rev_vec[v].pb(mp(u,p));
            vec1.pb(mp(p,mp(u,v)));
        }
        printf("Case %d: ",++caseno);
        dijkstra(s);
        dijkstra1(t);

//        for(int i=1;i<=n;i++){
//            cout<<dis1[i]<<" ";
//        }
//        cout<<endl;
//        for(int i=1;i<=n;i++){
//            cout<<dis2[i]<<" ";
//        }
//        cout<<endl;

        int ans=-1;
        for(int i=0;i<m;i++){
            int u=vec1[i].yy.xx;
            int v=vec1[i].yy.yy;
            if( vec1[i].xx+dis1[u]+dis2[v]<=p  ){
                ans=max(ans,vec1[i].xx);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
