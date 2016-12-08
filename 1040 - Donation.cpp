#include <bits/stdc++.h>
#define mx 1000001
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define xx first
#define yy second
#define inf 1000000000
//#define int long long

using namespace std;

int n,par[50];
vector<pair<int,pair<int,int> > >vec;


int find(int r){
    if(par[r]==r)return r;
    return par[r]=find(par[r]);
}

int mst(int ans){
    sort(vec.begin(),vec.end());
    int sz=vec.size();
    int cnt=0;
    for(int i=0,j=sz-1;i<sz;i++,j--){
        int u=vec[i].yy.xx;
        int v=vec[i].yy.yy;
        int w=vec[i].xx;
        int p=find(u);
        int q=find(v);
        if(p!=q){
            par[p]=q;
            cnt+=w;
        }
    }
    int f=0;
    for(int i=0;i<n;i++)if(par[i]==i)f++;
    if(f>1)return ans+1;
    return cnt;
}


void clr(){
    for(int i=0;i<50;i++){
        par[i]=i;
    }
    vec.clear();
}

int main()
{
//    freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t,caseno=0;
    cin>>t;
    while(t--){
        clr();
        cin>>n;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int p;
                cin>>p;
                ans+=p;
                if(p)vec.pb(mp(p,mp(i,j)));
            }
        }
        cout<<"Case "<<++caseno<<": "<<ans-mst(ans)<<endl;;
    }


    return 0;
}
