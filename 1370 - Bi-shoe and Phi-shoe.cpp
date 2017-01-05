#include <bits/stdc++.h>
#define mx 1111111
#define mp make_pair
#define pb push_back
#define mod 100003
#define xx first
#define yy second

using namespace std;

int sz,k;
int arr[1111111];
int global,fp=0;
int cnt;
bool status[mx];
vector<int>vec;
int val;

struct node{
    int a,b;
    bool operator < (const node &p) const {
        if(b==p.b)
            return a<p.a;
        else
            return b<p.b;
    }
}ara[1000005];

int tree[4*mx];

void build(int node,int b,int e){
    if(b==e){
        tree[node]=ara[b].a;
        return;
    }
    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;
    build(l,b,mid);
    build(r,mid+1,e);
    tree[node]=min(tree[l],tree[r]);
}

int query(int node,int b,int e,int i,int j){
    if(i>e || b>j)
        return 100000000;
    if(b>=i && e<=j)
        return tree[node];
    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;
    int p=query(l,b,mid,i,j);
    int q=query(r,mid+1,e,i,j);
    return min(p,q);
}

void seive()
{
    int N=mx;
    int sq=sqrt(N);
    for(int i=4; i<=N; i+=2) status[i]=1;
    for(int i=3; i<=sq; i+=2)
        if(!status[i])
            for(int j=i*i; j<=N; j+=2*i) status[j]=1;

    status[1]=1;
    vec.pb(2);
    for(int i=3;i<mx;i+=2){
        if(!status[i]){
            vec.pb(i);
            if(i>1000000){
                val=i;
                break;
            }
        }
    }
    sz=vec.size();
}

void euler(){
    for(int i=2;i<mx;i++)arr[i]=i;
    for(int i=0;i<sz;i++){
        for(int j=vec[i];j<=val;j+=vec[i]){
            arr[ j ] -= arr[j]/vec[i] ;
        }
    }
    for(int i=1;i<=val;i++){
        ara[i].a=i;
        ara[i].b=arr[i];
    }
}

int findpos(int v){
    int low=1,high=val;

    while(high-low>4){
        int mid=(low+high)>>1;
        if(ara[mid].b>=v){
            high=mid;
        }
        else{
            low=mid;
        }
    }
    for(int i=low;i<=high;i++){
        if(ara[i].b>=v){
            return i;
        }
    }
}


int  main(){
   // freopen("in.txt","r",stdin);
    //freopen("in.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    seive();
    euler();
    sort(ara,ara+val+1);
    build(1,1,val);
//    for(int i=0;i<20;i++){
//        cout<<ara[i].a<<" "<<ara[i].b<<endl;
//    }
//    cout<<val<<endl;

    int t,caseno=0;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long ans=0;
        for(int i=0;i<n;i++){
            int p;
            cin>>p;
            int x=findpos(p);
            x = query(1,1,val,x,val);
            ans += x;
        }
        cout<<"Case "<<++caseno<<": "<<ans<<" Xukha"<<endl;
    }

    return 0;
}
