#include <bits/stdc++.h>
#define mx 100011
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define xx first
#define yy second
//#define int long long
#define inf 1000000007

using namespace std;

typedef pair<int,int> pp;
pp tree[4*mx],ara[mx];
int n,t,m,tim,nd,val,cnt,num,vis[mx],vis1[mx];
vector<int>vec[mx],rem;

void dfs1(int node,int par){
    val=max(val,vis1[node]-1);
    int sz=vec[node].size();
    num++;
    for(int i=0;i<sz;i++){
        int v=vec[node][i];
        if(vis1[v])continue;
        vis1[v]=vis1[node]+1;
        dfs1(v,node);
    }
}

void dfs(int node,int par){
    rem.pb(node);
    if(vis[node]>val){
        nd=node;
        val=vis[node];
    }
    int sz=vec[node].size();
    for(int i=0;i<sz;i++){
        int v=vec[node][i];
        if(vis[v])continue;
        vis[v]=vis[node]+1;
        dfs(v,node);
    }
}

void build(int node,int b,int e){
    if(b==e){
        tree[node]=ara[b];
        return;
    }
    int l=node<<1;
    int r=l+1;
    int mid=(b+e)>>1;

    build(l,b,mid);
    build(r,mid+1,e);

    if(tree[l].yy>tree[r].yy)tree[node]=tree[l];
    else tree[node]=tree[r];
}

int query(int node,int b,int e,int i,int j){
    if(i>e||b>j)
        return 0;
    if(b>=i && e<=j)
        return tree[node].yy;
    int l=node<<1;
    int r=l+1;
    int mid=(b+e)>>1;

    int p=query(l,b,mid,i,j);
    int q=query(r,mid+1,e,i,j);

    return max(p,q);
}

int findpos(int val){
    int low=1;
    int high=cnt;
    while(high-low>4){
        int mid=(low+high)>>1;
        if(ara[mid].xx<val)
            low=mid;
        else
            high=mid;
    }
    for(int i=low;i<=high;i++){
        if(ara[i].xx>=val)
            return i;
    }
    return 0;
}

void clr(){
    for(int i=0;i<mx;i++){
        vec[i].clear();
    }
}

main()
{
//    freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//
//    ios_base::sync_with_stdio(false);
//    cin.tie(false);
//    cout.tie(false);

    scanf("%d",&t);
    int caseno=0;
    while(t--){
        clr();
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            vec[u].pb(v);
            vec[v].pb(u);
        }
        memset(vis,0,sizeof(vis));
        cnt=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                val=0,vis[i]=1;
                rem.clear();
                dfs(i,-1);
                int sz=rem.size();
                for(int i=0;i<sz;i++){
                    vis1[rem[i]]=0;
                }
                vis1[nd]=1,val=0,num=0;
                dfs1(nd,-1);
                ara[++cnt]=mp(num,val);
            }
        }

        sort(ara+1,ara+cnt+1);
        build(1,1,cnt);

        int q;
        scanf("%d",&q);
        printf("Case %d:\n",++caseno);
        for(int i=0;i<q;i++){
            int k;
            scanf("%d",&k);
            int p=findpos(k);
            if(p==0)printf("impossible\n");
            else{
                int x=query(1,1,cnt,p,cnt);
                if(k<=x+1)printf("%d\n",k-1);
                else printf("%d\n",x+(k-x-1)*2);
            }
        }
    }

    return 0;
}
