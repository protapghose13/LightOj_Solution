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

struct node{
    int zero,one,two,lazy;
};

node tree[4*mx];
int n,q;

void push_down(int node){
    tree[node].lazy%=3;
    int l=node<<1;
    int p=tree[l].zero;
    int q=tree[l].one;
    int r=tree[l].two;
    if(tree[node].lazy==1){
        tree[l].lazy+=tree[node].lazy;
        tree[l].lazy%=3;
        tree[l].zero=r;
        tree[l].one=p;
        tree[l].two=q;
    }
    else if(tree[node].lazy==2){
        tree[l].lazy+=tree[node].lazy;
        tree[l].lazy%=3;
        tree[l].zero=q;
        tree[l].one=r;
        tree[l].two=p;
    }
    l++;
    p=tree[l].zero;
    q=tree[l].one;
    r=tree[l].two;
    if(tree[node].lazy==1){
        tree[l].lazy+=tree[node].lazy;
        tree[l].lazy%=3;
        tree[l].zero=r;
        tree[l].one=p;
        tree[l].two=q;
    }
    else if(tree[node].lazy==2){
        tree[l].lazy+=tree[node].lazy;
        tree[l].lazy%=3;
        tree[l].zero=q;
        tree[l].one=r;
        tree[l].two=p;
    }
    tree[node].lazy=0;
    return;
}

void push_up(int node){
    int l=node<<1;
    int r=l+1;
    tree[node].one=tree[l].one+tree[r].one;
    tree[node].two=tree[l].two+tree[r].two;
    tree[node].zero=tree[l].zero+tree[r].zero;
}

void build(int node,int b,int e){
    if(b==e){
        tree[node].zero=1;
        tree[node].one=0;
        tree[node].two=0;
        return;
    }
    int mid=(b+e)>>1;
    int l=2*node;
    int r=l+1;

    build(l,b,mid);
    build(r,mid+1,e);

    push_up(node);
}

void update(int node,int b,int e,int i,int j){
    if(i>e || b>j)
        return;
    if(b>=i&&e<=j){
        tree[node].lazy++;
        tree[node].lazy%=3;
        int p=tree[node].zero,q=tree[node].one,r=tree[node].two;
        tree[node].zero=r;
        tree[node].one=p;
        tree[node].two=q;
        return;
    }
    push_down(node);

    int mid=(b+e)>>1;
    int l=2*node;
    int r=l+1;

    update(l,b,mid,i,j);
    update(r,mid+1,e,i,j);

    push_up(node);
}

int query(int node,int b,int e,int i,int j){
    if(i>e || b>j )
        return 0;
    if(b>=i&&e<=j)
        return tree[node].zero;

    push_down(node);

    int mid=(b+e)>>1;
    int l=2*node;
    int r=l+1;

    int p=query(l,b,mid,i,j);
    int q=query(r,mid+1,e,i,j);

    push_up(node);

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
        scanf("%d%d",&n,&q);
        printf("Case %d:\n",++caseno);
        build(1,1,n);
        for(int i=0;i<q;i++){
            int type;
            scanf("%d",&type);
            if(type==0){
                int l,r;
                scanf("%d%d",&l,&r);
                l++,r++;
                update(1,1,n,l,r);
            }
            else{
                int l,r;
                scanf("%d%d",&l,&r);
                l++,r++;
                printf("%d\n",query(1,1,n,l,r) );
            }
        }
        memset(tree,0,sizeof(tree));
    }
    return 0;
}
