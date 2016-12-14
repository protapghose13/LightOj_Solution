#include <bits/stdc++.h>
#define mx 150011
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


int n,m,tree[4*mx],q,ara[mx],p;
char c;

void build(int node,int b,int e){
    if(b==e){
        if(b>n)tree[node]=0;
        else tree[node]=1;
        return;
    }
    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;

    build(l,b,mid);
    build(r,mid+1,e);

    tree[node]=tree[l]+tree[r];
}

void update(int node,int b,int e,int i,int j,int val){
    if(i>e || b>j)
        return;
    if(b==e){
        tree[node]=val;
        return;
    }
    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;

    update(l,b,mid,i,j,val);
    update(r,mid+1,e,i,j,val);

    tree[node]=(tree[l]+tree[r]);

}

int query(int node,int b,int e, int val){

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
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&ara[i]);
        }
        printf("Case %d:\n",++caseno);
        build(1,1,n+m);
        int k=0;
        for(int i=0;i<m;i++){
            getchar();
            scanf("%c",&c);
            if(c=='a'){
                k++;
                scanf("%d",&p);
                ara[k+n]=p;
                update(1,1,n+m,k+n,k+n,1);
            }
            else{
                scanf("%d",&p);
                if(p>tree[1])printf("none\n");
                else{
                    int x=query(1,1,n+m,p);
                    printf("%d\n",ara[x]);
                    update(1,1,n+m,x,x,0);
                }
            }
        }
    }
    return 0;
}
