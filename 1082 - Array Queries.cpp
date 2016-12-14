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


int n,tree[4*mx],q,ara[mx];

void update(int node,int b,int e){
    if(b==e){
        tree[node]=ara[b];
        return;
    }
    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;

    update(l,b,mid);
    update(r,mid+1,e);

    tree[node]=min(tree[l],tree[r]);
    return;
}

int query(int node,int b,int e,int i,int j){
    if(i>e || b>j)
        return inf;
    if(b>=i&&e<=j){
        return tree[node];
    }

    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;

    return min( query(l,b,mid,i,j),query(r,mid+1,e,i,j) );

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
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&ara[i]);
        }
        update(1,1,n);
        printf("Case %d:\n",++caseno);
        for(int i=0;i<q;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",query(1,1,n,l,r));
        }
    }
    return 0;
}
