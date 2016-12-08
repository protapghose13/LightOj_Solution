#include <bits/stdc++.h>
#define mx 100011
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define xx first
#define yy second
//#define int long long
#define inf 1000000007

using namespace std;

int m,n;
string s;
int dp[(1<<10)][1001],fact[10];

int call(int mask,int val){
    if(mask==(1<<n)-1)
        return val==0;
    if(dp[mask][val]!=-1)
        return dp[mask][val];
    int res=0;
    for(int i=0;i<n;i++){
        if((mask&(1<<i))==0){
            res += call( (mask|(1<<i)) , ( (s[i]-48)+(val*10) )%m  );
        }
    }
    return dp[mask][val]=res;
}

main()
{
//    freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t;
    cin>>t;
    fact[0]=1;
    for(int i=1;i<=9;i++){
        fact[i]=fact[i-1]*i;
    }
    int caseno=0;
    while(t--){
        cin>>s>>m;
        n=s.length();
        memset(dp,-1,sizeof(dp));
        int ans=call(0,0);
        for(int i=0;i<=9;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i==s[j]-48)
                    cnt++;
            }
            ans/=fact[cnt];
        }
        cout<<"Case "<<++caseno<<": "<<ans<<endl;
    }
    return 0;
}
