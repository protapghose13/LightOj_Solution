#include <bits/stdc++.h>
#define mx 100011
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define xx first
#define yy second
#define inf 1000000000
//#define int long long
#define SIZE 100011
#define ll long long

using namespace std;

#define BLOCK 320

typedef pair<int,int>pp;
int n,d,ara[mx];
pp tree[4*mx];

void build(int node,int b,int e){
    if(b==e){
        tree[node].xx=ara[b];
        tree[node].yy=ara[b];
        return;
    }
    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;

    build(l,b,mid);
    build(r,mid+1,e);

    tree[node].xx = max(tree[l].xx,tree[r].xx);
    tree[node].yy = min(tree[l].yy,tree[r].yy);

    return;
}

pp query(int node,int b,int e,int i,int j){
    if(e<i || b>j)
        return mp(0,inf);
    if(b>=i && e<=j)
        return tree[node];

    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;

    pp p=query(l,b,mid,i,j);
    pp q=query(r,mid+1,e,i,j);

    return mp( max(p.xx,q.xx), min(p.yy,q.yy) );
}


int main() {
    int t,caseno=0;
    scanf("%d",&t);
    while(t--){

        scanf("%d%d", &n,&d);
        for(int i=1;i<=n;i++){
            scanf("%d",&ara[i]);
        }
        build(1,1,n);
        int ans=0;
        for(int i=1;i<=n-d+1;i++){
            pp p = query(1,1,n,i,i+d-1);
            ans = max(ans,p.xx-p.yy);
        }
        printf("Case %d: %d\n",++caseno,ans);
    }
}
