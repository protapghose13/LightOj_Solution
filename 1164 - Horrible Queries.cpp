#include <bits/stdc++.h>
#define mx 100011
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define xx first
#define yy second
#define inf 100000000
#define int long long
#define SIZE 100011
#define ll long long

using namespace std;

typedef pair<int,int> pp;
int n,m,tree[4*mx],lazy[4*mx];

void push_down(int node,int b,int e){
    int l=node<<1;
    int r=l+1;
    int mid=(b+e)>>1;
    if(lazy[node]){
        lazy[l] += lazy[node];
        lazy[r] += lazy[node];
        tree[l] += ((mid-b+1)*lazy[node]);
        tree[r] += ((e-mid)*lazy[node]);
        lazy[node]=0;
    }
}

void push_up(int node){
    tree[node] = tree[ (node<<1) ] + tree[ (node<<1)+1 ];
}

void update(int node,int b,int e,int i,int j,int val){
    if(e<i || b>j)
        return;
    if(b>=i&&e<=j){
        lazy[node] += val;
        tree[node] += (e-b+1)*val;
        return;
    }
    push_down(node,b,e);

    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;

    update(l,b,mid,i,j,val);
    update(r,mid+1,e,i,j,val);

    push_up(node);
}

int query(int node,int b,int e,int i,int j){
    if(e<i || b>j)
        return 0;
    if(b>=i&&e<=j){
        return tree[node];
    }

    push_down(node,b,e);

    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;

    int p=query(l,b,mid,i,j);
    int q=query(r,mid+1,e,i,j);

    push_up(node);

    return p+q;
}

main()
{
//    freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);

//    ios_base::sync_with_stdio(false);
//    cin.tie(false);
//    cout.tie(false);

    int t,caseno=0,p;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&m);
        printf("Case %lld:\n",++caseno);
        for(int i=0;i<m;i++){
            int type;
            scanf("%lld",&type);
            if(type==0){
                int l,r,v;
                scanf("%lld%lld%lld",&l,&r,&v);
                l++,r++;
                update(1,1,n,l,r,v);
            }
            else{
                int l,r;
                scanf("%lld%lld",&l,&r);
                l++,r++;
                p=query(1,1,n,l,r);
                printf("%lld\n",p);
            }
        }

        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));

    }
    return 0;
}
