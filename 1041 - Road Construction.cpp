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

int n,par[101],k;
vector<pair<int,pair<int,int> > >vec;
string s1,s2;
map<string,int>mymap;



int find(int r){
    if(par[r]==r)return r;
    return par[r]=find(par[r]);
}

void mst(){
    sort(vec.begin(),vec.end());
    int sz=vec.size();
    int cnt=0;
    int f=0;
    for(int i=0;i<sz;i++){
        int u=vec[i].yy.xx;
        int v=vec[i].yy.yy;
        int w=vec[i].xx;
        int p=find(u);
        int q=find(v);
        if(p!=q){
            f++;
            par[p]=q;
            cnt+=w;
            if(f==k-2){
                cout<<cnt<<endl;
                return;
            }
        }
    }
    cout<<"Impossible"<<endl;
}


void clr(){
    for(int i=0;i<101;i++){
        par[i]=i;
    }
    vec.clear();
    mymap.clear();
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
        k=1;
        for(int i=0;i<n;i++){
            int p;
            cin>>s1>>s2>>p;
            if(mymap[s1]==0)mymap[s1]=k++;
            if(mymap[s2]==0)mymap[s2]=k++;
            vec.pb(mp(p,mp(mymap[s1],mymap[s2])));
        }
        cout<<"Case "<<++caseno<<": ";
        mst();
    }


    return 0;
}
