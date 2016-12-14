#include <bits/stdc++.h>
#define mx 100011
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

char s[mx];
int n,tree[4*mx],q;

void update(int node,int b,int e,int i,int j){
    if(i>e || b>j)
        return;
    if(b>=i&&e<=j){
        tree[node]++;
        return;
    }
    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;

    update(l,b,mid,i,j);
    update(r,mid+1,e,i,j);
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

    tree[l]+=tree[node];
    tree[r]+=tree[node];
    tree[node]=0;

    int p = query(l,b,mid,i,j);
    int q = query(r,mid+1,e,i,j);

    return p+q;
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
        getchar();
        scanf("%s",s);
        n=strlen(s);
        scanf("%d",&q);
        printf("Case %d:\n",++caseno);
        for(int i=0;i<q;i++){
            getchar();
            char c;
            int l,r;
            scanf("%c",&c);
            if(c=='I'){
                scanf("%d%d",&l,&r);
                update(1,1,n,l,r);
            }
            else{
                scanf("%d",&l);
                int p=query(1,1,n,l,l);
                int a=s[l-1]-48;
                if(p%2==1)a=!a;
                printf("%d\n",a);
            }
        }
        memset(tree,0,sizeof(tree));
    }
    return 0;
}
