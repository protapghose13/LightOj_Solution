#include <bits/stdc++.h>
#define mx 30011
#define pb push_back
#define int long long
#define mod 100000007

using namespace std;

int m,n;
int dp[11][2][2][11];
string s1,s2;
int len;


int fun(int pos,int l1,int l2,int iszero,int cnt){
    if(pos==len)
        return cnt;

    if(dp[pos][l1][l2][cnt]!=-1)
        return dp[pos][l1][l2][cnt];

    int min1=0,max1=9;
    if(l1==0)min1=s1[pos]-48;
    if(l2==0)max1=s2[pos]-48;

    int res=0;
    for(int i=min1;i<max1+1;i++){
        int p=0;
        if(iszero&&i==0)p=1;
        res += fun( pos+1,(l1|(i>min1)),(l2|(i<max1)), (iszero|i),cnt+p ) ;
    }
    return dp[pos][l1][l2][cnt]=res;
}


int makeString(int p,int q){
    int x=p;
    s1="",s2="";
    while(p)s1+=((p%10)+48),p/=10;
    while(q)s2+=((q%10)+48),q/=10;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    while(s1.length()<s2.length())s1="0"+s1;
    len=s1.length();
    memset(dp,-1,sizeof(dp));
    return fun(0,0,0,0,0)+(x==0);
}

main()
{
    int t,k;
    scanf("%lld",&t);
    int caseno=0;
    while(t--){
        scanf("%lld%lld",&n,&m);
        printf("Case %lld: %lld\n",++caseno,makeString(n,m));
    }
}
