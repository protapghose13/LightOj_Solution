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


int n,tree[4*mx],q,ara[mx],ara1[mx],p;

void update(int node,int b,int e,int i,int j,int val){
    if(i>e || b>j)
        return;
    if(b==e){
        tree[node]=(tree[node]+val)%mod;
        return;
    }
    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;

    update(l,b,mid,i,j,val);
    update(r,mid+1,e,i,j,val);
    tree[node]=(tree[l]+tree[r])%mod;
    return;
}

int query(int node,int b,int e,int i,int j){
    if(i>e || b>j)
        return 0;
    if(b>=i&&e<=j){
        return tree[node];
    }

    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;

    return ( query(l,b,mid,i,j)+query(r,mid+1,e,i,j) )%mod;

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
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&ara[i]);
            ara1[i-1]=ara[i];
        }
        sort(ara1,ara1+n);
        map<int,int>mymap;
        p=0;
        for(int i=0;i<n;i++){
            if(mymap[ ara1[i] ]==0){
                mymap[ ara1[i] ]=++p;
            }
        }
        memset(tree,0,sizeof tree);

        printf("Case %d: ",++caseno);
        int ans=0;
        for(int i=0;i<n;i++){
            int x=mymap[ ara[i+1] ];
            int y=query(1,1,p,1,x-1);
            ans=(ans+y+1)%mod;
            update(1,1,p,x,x,(y+1)%mod );
        }
        printf("%d\n",ans);
    }
    return 0;
}
