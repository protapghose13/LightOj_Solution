#include <bits/stdc++.h>
#define mx 1000001
#define pb push_back
#define mp make_pair
#define mod 100000007
#define xx first
#define yy second
#define inf 1000000000000000
#define int long long

using namespace std;

int n,x;
int dp[26][155];
int fact[26];

void precalc(){
    fact[0]=1;
    for(int i=1;i<=25;i++){
        fact[i]=fact[i-1]*6;
    }
}

int call(int id,int val){

    if(id==0)
        return val<=0;

    if(dp[id][val]!=-1)
        return dp[id][val];

    int res=0;
    for(int i=1;i<=6;i++){
        res += call(id-1,val-i);
    }
    return dp[id][val]=res;
}

int gcd(int a,int b){
    if(a==0)return b;
    return gcd(b%a,a);
}

main()
{
//    freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t,caseno=0;
    precalc();
    cin>>t;
    while(t--){
        cin>>n>>x;
        memset(dp,-1,sizeof(dp));
        int p=call(n,x);
        int q=gcd(p,fact[n]);
        int x=p/q;
        int y=fact[n]/q;
        cout<<"Case "<<++caseno<<": ";
        if(p==0)cout<<p<<endl;
        else if(y==1)cout<<x<<endl;
        else cout<<x<<"/"<<y<<endl;
    }
    return 0;
}
