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

typedef pair<int,int> pp;
int n,m,tree[4*mx],q,ara[mx],p;
char c;
vector<int>vec,vec1;
vector<pp>vec2;

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
    if(b>=i && e<=j){
        tree[node] += val;
        return;
    }
    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;

    tree[l] += tree[node];
    tree[r] += tree[node];
    tree[node]=0;

    update(l,b,mid,i,j,val);
    update(r,mid+1,e,i,j,val);

}

int query(int node,int b,int e,int i,int j){
    if(i>e || b>j)
        return 0;

    if(b==e){
        return tree[node];
    }


    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;

    tree[l] += tree[node];
    tree[r] += tree[node];
    tree[node]=0;

    return ( query(l,b,mid,i,j) + query(r,mid+1,e,i,j) );

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
            int l,r;
            scanf("%d%d",&l,&r);
            vec2.pb(mp(l,r));
            vec.pb(l);
            vec.pb(r);
        }
        for(int i=0;i<m;i++){
            int l;
            scanf("%d",&l);
            vec1.pb(l);
            vec.pb(l);
        }
        printf("Case %d:\n",++caseno);
        int sz=vec.size();
        map<int,int>mymap;
        sort(vec.begin(),vec.end());
        int k=0;
        for(int i=0;i<sz;i++){
            if(mymap[vec[i]] == 0){
                mymap[vec[i]] = ++k;
            }
        }

        sz=vec2.size();
        for(int i=0;i<sz;i++){
            int x=mymap[vec2[i].xx];
            int y=mymap[vec2[i].yy];
            update(1,1,k,x,y,1);
        }

        sz=vec1.size();
        for(int i=0;i<sz;i++){
            int x=mymap[ vec1[i] ];
            printf("%d\n",query(1,1,k,x,x));
        }

        vec.clear();
        vec1.clear();
        vec2.clear();
        memset(tree,0,sizeof(tree));

    }
    return 0;
}
