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

int n,m,par1[500],par2[500];
vector<pair<int,pair<int,int> > >vec,vec1;


int find1(int r){
    if(par1[r]==r)return r;
    return par1[r]=find1(par1[r]);
}

int find2(int r){
    if(par2[r]==r)return r;
    return par2[r]=find2(par2[r]);
}

void mst(){
    sort(vec.begin(),vec.end());
    int sz=vec.size();
    int cnt=0,cnt1=0;
    for(int i=0,j=sz-1;i<sz;i++,j--){
        int u=vec[i].yy.xx;
        int v=vec[i].yy.yy;
        int w=vec[i].xx;
        int p=find1(u);
        int q=find1(v);
        if(p!=q){
            par1[p]=q;
            cnt+=w;
        }
        u=vec[j].yy.xx;
        v=vec[j].yy.yy;
        w=vec[j].xx;
        p=find2(u);
        q=find2(v);
        if(p!=q){
            par2[p]=q;
            cnt1+=w;
        }
    }
    if((cnt+cnt1)%2)cout<<(cnt+cnt1)<<"/2"<<endl;
    else cout<<(cnt+cnt1)/2<<endl;
}


void clr(){
    for(int i=0;i<500;i++){
        par1[i]=i;
        par2[i]=i;
    }
    vec1.clear();
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
        for(int i=0;;i++){
            int u,v,w;
            cin>>u>>v>>w;
            if(u==0 &&v==0 && w==0)break;
            vec.pb(mp(w,mp(u,v)));
        }
        cout<<"Case "<<++caseno<<": ";
        mst();
    }


    return 0;
}
