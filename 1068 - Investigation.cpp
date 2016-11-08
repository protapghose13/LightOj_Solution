#include <bits/stdc++.h>
#define mx 30011
#define pb push_back
//#define int long long
#define mod 100000007

using namespace std;

int n,m,k;
int dp[11][2][2][90][90];
string s1,s2;
int len;

int call(int pos,int l1,int l2,int val,int val1){

    if(pos==len)
        return (val%k==0&&val1%k==0);

    if(dp[pos][l1][l2][val][val1]!=-1)
        return dp[pos][l1][l2][val][val1];

    int min1=0,max1=9;
    if(l1==0)min1=s1[pos]-48;
    if(l2==0)max1=s2[pos]-48;

    int res=0;
    for(int i=min1;i<max1+1;i++){
        res += call( pos+1,(l1|(i>min1)) ,(l2|(i<max1)), val+i ,(val1*10+i)%k );
    }
    return dp[pos][l1][l2][val][val1]=res;
}

int makeString(int p,int q){
    s1="",s2="";
    while(p)s1+=(p%10)+48,p/=10;
    while(q)s2+=(q%10)+48,q/=10;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    while(s1.length()<s2.length())s1="0"+s1;
    len=s1.length();
    memset(dp,-1,sizeof(dp));
    return call(0,0,0,0,0);
}


main()
{
    int t;
    scanf("%d",&t);
    int caseno=0;
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        int ans;
        if(k>=90)ans=0;
        else ans=makeString(n,m);
        printf("Case %d: %d\n",++caseno,ans);
    }
}
