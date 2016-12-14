#include <bits/stdc++.h>
#define mx 100011
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define xx first
#define yy second
#define inf 100000000
//#define int long long
#define SIZE 100011
#define ll long long

using namespace std;

typedef pair<int,int> pp;
int n,m,tree[4*mx],ara[mx];



void build(int node,int b,int e){
    if(b==e){
        tree[node]=1;
        return;
    }
    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;

    build(l,b,mid);
    build(r,mid+1,e);

    tree[node]=tree[l]+tree[r];
}

void update(int node,int b,int e,int i,int j){
    if(e<i || b>j)
        return;
    if(b>=i&&e<=j){
        tree[node]=0;
        return;
    }

    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;

    update(l,b,mid,i,j);
    update(r,mid+1,e,i,j);

    tree[node]=tree[l]+tree[r];
}

int query(int node,int b,int e,int val){

    if(b==e){
        return b;
    }

    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;

    if(tree[l]<val){
        query(r,mid+1,e,val-tree[l]);
    }
    else{
        query(l,b,mid,val);
    }

}

main()
{
//    freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);

//    ios_base::sync_with_stdio(false);
//    cin.tie(false);
//    cout.tie(false);

    int t,caseno=0,p,q;
    scanf("%d",&t);
    while(t--){


        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&ara[i]);
        }
        int ans;
        build(1,1,n);
        for(int i=n;i>0;i--){
            int p=tree[1]-ara[i];
            ans = query(1,1,n,p);
            update(1,1,n,ans,ans);
        }
        printf("Case %d: %d\n",++caseno,ans);

    }
    return 0;
}
