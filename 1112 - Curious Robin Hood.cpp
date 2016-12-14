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
int n,m,tree[mx];

void update(int id,int n,int val){
    while(id<=n){
        tree[id] += val;
        id += (id&-id);
    }
}

int query(int id){
    int sum=0;
    while(id>0){
        sum += tree[id];
        id-=(id&-id);
    }
    return sum;
}

int main()
{
//    freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);

//    ios_base::sync_with_stdio(false);
//    cin.tie(false);
//    cout.tie(false);

    int t,caseno=0,p;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&p);
            update(i,n,p);
        }
        printf("Case %d:\n",++caseno);
        for(int i=0;i<m;i++){
            int type;
            scanf("%d",&type);
            if(type==1){
                int l;
                scanf("%d",&l);
                l++;
                int x=query(l)-query(l-1);
                update(l,n,-x);
                printf("%d\n",x);
            }
            else if(type==2){
                int l,r;
                scanf("%d%d",&l,&r);
                l++;
                update(l,n,r);
            }
            else{
                int l,r;
                scanf("%d%d",&l,&r);
                l++,r++;
                int x=query(r)-query(l-1);
                printf("%d\n",x);
            }
        }

        memset(tree,0,sizeof(tree));

    }
    return 0;
}
