#include <bits/stdc++.h>
#define mx 201
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
bool flag;
vector<pair<int,pair<int,int> > >vec,vec1;


int find(int r){
    if(par[r]==r)return r;
    return par[r]=find(par[r]);
}

void mst(){
    sort(vec.begin(),vec.end());
    for(int i=0;i<mx;i++)par[i]=i;
    int sz=vec.size();
    vec1.clear();
    ans=0;
    int cnt=0;
    for(int i=0;i<sz;i++){
        int u=vec[i].yy.xx;
        int v=vec[i].yy.yy;
        int w=vec[i].xx;
        int p=find(u);
        int q=find(v);
        if(p!=q){
            cnt++;
            if(cnt==n-1)flag=1;
            par[p]=q;
            ans+=w;
            vec1.pb(mp(w,mp(u,v)));
        }
    }
    if(flag==0)ans=-1;
    vec.clear();
    vec=vec1;
}


void clr(){
    for(int i=0;i<mx;i++){
        par[i]=i;
    }
    vec.clear();
    vec1.clear();
    flag=0;
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
        scanf("%d%d",&n,&m);
        printf("Case %d:\n",++caseno);
        for(int i=0;i<m;i++){
            int u,v,p;
            scanf("%d%d%d",&u,&v,&p);
            vec.pb(mp(p,mp(u,v)));
            mst();
            printf("%d\n",ans);
        }
    }


    return 0;
}
