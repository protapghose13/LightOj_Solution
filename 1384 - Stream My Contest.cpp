#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define mx 61
#define xx first
#define yy second

using namespace std;

const int inf=1000000009;
int N,M,C,cnt,n,m,k;


struct node{
    int u,v,band,cost;
    node(){}
    node(int a,int b,int c,int d){
        u=a,v=b,band=c,cost=d;
    }
};
vector<node>vec1;
vector<pair<int,pair<int,int> > >vec;

int val[mx],par[mx],mark[mx],id[mx];
void clr(){
    for(int i=0;i<mx;i++){
        val[i]=inf,par[i]=inf,mark[i]=-1,id[i]=-1;
    }
}

int Edmond(){
    int ans=0;
    while(1){
        clr();
        for(int i=0;i<m;i++){
            int u=vec[i].yy.xx;
            int v=vec[i].yy.yy;
            int w=vec[i].xx;
            if(val[v]>w && u!=v){
                val[v]=w;
                par[v]=u;
            }
        }

        val[k]=0;
        for(int i=0;i<n;i++){
            if(val[i]==inf)return -1;
        }
        int cur=0;
        for(int i=0;i<n;i++){
            ans+=val[i];
            int u=i;
            while( u!=k && mark[u]!=i && id[u]<0 ){
                mark[u]=i;
                u=par[u];
            }
            if( u!=k && id[u]<0 ){
                for(int v=par[u];v!=u;v=par[v])
                    id[v]=cur;
                id[u]=cur++;
            }
        }
        if(cur==0)return ans;
        for(int i=0;i<n;i++){
            if(id[i]<0)id[i]=cur++;
        }
        for(int i=0;i<m;i++){
            int u=id[ vec[i].yy.xx ];
            int v=id[ vec[i].yy.yy ];
            int w=vec[i].xx;
            if(u!=v)w-=val[ vec[i].yy.yy ];
            vec[i]=mp(w,mp(u,v));
        }
        k=id[k];
        n=cur;
    }
}

void make_network(int mval){
    int sz=vec1.size();
    vec.clear();
    for(int i=0;i<sz;i++){
        if( vec1[i].band>=mval ){
            vec.pb(mp(vec1[i].cost,mp(vec1[i].u,vec1[i].v)));
        }
    }
    n=N;
    m=vec.size();
    k=0;
}

int solve(int maxval){
    int low=1,high=maxval;
    while(high-low>4){
        int mid=(low+high)>>1;
        make_network(mid);
        int p=Edmond();
        if(p==-1)high=mid;
        else if(p>C)high=mid;
        else low=mid;
    }
    for(int i=high;i>=low;i--){
        make_network(i);
        int p=Edmond();
        if( p<=C && p!=-1 )return i;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t;
    cin>>t;
    int caseno=0;
    while(t--){
        vec.clear();
        vec1.clear();
        cin>>N>>M>>C;
        int maxval=0;
        for(int i=0;i<M;i++){
            int u,v,a,b;
            cin>>u>>v>>a>>b;
            maxval=max(maxval,a);
            if(v==0||u==v)continue;
            vec1.pb(node(u,v,a,b));
        }
        int ans=solve(maxval);
        if(ans==-1)cout<<"Case "<<++caseno<<": impossible"<<endl;
        else cout<<"Case "<<++caseno<<": "<<ans<<" kbps"<<endl;
    }
    return 0;
}
