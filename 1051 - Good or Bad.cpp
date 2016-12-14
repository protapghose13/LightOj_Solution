#include <bits/stdc++.h>
#define mx 1000001
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define xx first
#define yy second
#define inf 1000000000000000
#define int long long

using namespace std;

int n,m,len;
string s;
int dp[51][51][51];

bool isvowel(char c){
    return ( c=='A' || c=='E' || c=='I' || c=='O' || c=='U' );
}

int call(int id,int v,int c){
    if(id==len)
        return 2;

    if(dp[id][v][c]!=-1)
        return dp[id][v][c];

    int p1=0,p2=0;
    if(s[id]=='?'){
        if(v>=2)p1=1;
        else p1 = call(id+1,v+1,0);

        if(c>=4)p2=1;
        else p2 = call(id+1,0,c+1);

    }
    else if(isvowel(s[id])){
        if(v>=2)p1=1;
        else p1 = call(id+1,v+1,0);
    }
    else{
        if(c>=4)p2=1;
        else p2 = call(id+1,0,c+1);
    }

    return dp[id][v][c]= p1|p2;
}

main()
{
//    freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t,caseno=0;
    cin>>t;
    while(t--){
        cin>>s;
        len=s.length();
        memset(dp,-1,sizeof(dp));
        int p=call(0,0,0);
        cout<<"Case "<<++caseno<<": ";
        if(p==1)cout<<"BAD"<<endl;
        else if(p==2)cout<<"GOOD"<<endl;
        else cout<<"MIXED"<<endl;
    }
    return 0;
}
