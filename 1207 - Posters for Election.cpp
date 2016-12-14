#include <bits/stdc++.h>
#define mx 200011
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define xx first
#define yy second
#define inf 1000000000000000
//#define int long long
#define SIZE 100011
#define ll long long

using namespace std;

#define BLOCK 320

int tree[4*mx],cnt[mx],n,m;

void update(int node,int b,int e,int i,int j,int val){
    if(i>e || b>j)
        return;

    if(b>=i && e<=j){
        tree[node]=val;
        return;
    }

    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;

    if(tree[node]){
        tree[l]=tree[node];
        tree[r]=tree[node];
    }

    tree[node]=0;

    update(l,b,mid,i,j,val);
    update(r,mid+1,e,i,j,val);
}


int query(int node,int b,int e,int i,int j){
    if(i>e || b>j)
        return 0;

    if(b>=i && e<=j){
        return tree[node];
    }

    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;

    if(tree[node]){
        tree[l]=tree[node];
        tree[r]=tree[node];
    }

    tree[node]=0;

    int p=query(l,b,mid,i,j);
    int q=query(r,mid+1,e,i,j);

    return p|q;
}

int main() {
    int caseno=0,t;
    scanf("%d",&t);
    while(t--){
        memset(tree,0,sizeof(tree));
        memset(cnt,0,sizeof(cnt));
        scanf("%d", &n);
        m=n;
        n*=2;
        for(int i=1;i<=m;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            update(1,1,n,l,r,i);
        }

        for(int i=1;i<=n;i++){
            int x=query(1,1,n,i,i);
            cnt[x]=1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(cnt[i])ans++;
        }
        printf("Case %d: %d\n",++caseno,ans);

    }
}
