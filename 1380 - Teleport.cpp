#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define mx 1001
#define xx first
#define yy second

using namespace std;

const int inf=10000000;
int n,m,k;
typedef pair<int,pair<int,int> > pp;
vector<pp>vec;
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t;
    cin>>t;
    int caseno=0;
    while(t--){
        vec.clear();
        cin>>n>>m>>k;
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            vec.pb(mp(w,mp(u,v)));
        }
        int ans=Edmond();
        if(ans==-1) cout<<"Case "<<++caseno<<": impossible"<<endl;
        else cout<<"Case "<<++caseno<<": "<<ans<<endl;
    }
    return 0;
}
