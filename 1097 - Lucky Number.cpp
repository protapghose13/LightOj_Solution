#include <bits/stdc++.h>
#define mx 1429500
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
vector<int>ans;

void build(int node,int b,int e){
    if(b==e){
        if(b%2==1)tree[node]=1;
        else tree[node]=0;
        return;
    }
    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;
    build(l,b,mid);
    build(r,mid+1,e);
    tree[node]=tree[l]+tree[r];
}

int query(int node,int b,int e,int val){
    if(b==e)
        return b;
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

void update(int node,int b,int e, int val){
    if(b==e){
        tree[node]=0;
        return;
    }
    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;
    if(tree[l]<val){
        update(r,mid+1,e,val-tree[l]);
    }
    else{
        update(l,b,mid,val);
    }
    tree[node]=tree[l]+tree[r];
}

void solve(){
    build(1,1,mx);
    ans.pb(1);
    for(int i=2;i<=100000;i++){
        int x=query(1,1,mx,i);
        ans.pb(x);
        int k=0;
        int j=1;
        int p=(j*x)-k;
        while( p < tree[1] ){
            k++;j++;
            update(1,1,mx,p);
            p=(j*x)-k;
        }
    }
}

int main() {
    int caseno=0,t;
    solve();
    scanf("%d",&t);
    while(t--){
        scanf("%d", &n);
        printf("Case %d: %d\n",++caseno,ans[n-1]);
    }
}
