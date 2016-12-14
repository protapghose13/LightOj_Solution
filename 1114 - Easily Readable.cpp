#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define inf 1000000
#define mod 1000000007
#define int long long

using namespace std;

template<typename T> int toInt(T t){stringstream ss; ss<<t; int r; ss>>r; return r;}

map<string,int>mymap;
string s;

int nextint(){
    getline(cin,s);
    return toInt(s);
}

void solve(){
    int n=nextint();
    mymap.clear();
    for(int i=0;i<n;i++){
        getline(cin,s);
        if(s.length()>2)sort(s.begin()+1,s.end()-1);
        mymap[s]++;
    }
    n=nextint();
    for(int i=0;i<n;i++){
        getline(cin,s);
        stringstream ss(s);
        int ans=1;
        while(ss>>s){
            if(s.size()>2)sort(s.begin()+1,s.end()-1);
            ans*=mymap[s];
        }
        printf("%lld\n",ans);
    }
}

main()
{
//    freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(false);



    int t,caseno=0;
    t=nextint();
    while(t--)
    {
        printf("Case %lld:\n",++caseno);
        solve();
    }
    return 0;
}
