#include <bits/stdc++.h>
#define mx 30011
#define pb push_back
#define int long long
#define mod 100000007

using namespace std;

int m,n;
int dp[20][20][2][2][2];
string s1,s2;
int len;
int ara[20];


int fun(int pos,int pos1,int l1,int l2,int iszero,int ispal){
    if(pos1==len){
        return ispal;
    }

    if(dp[pos][pos1][l1][l2][ispal]!=-1){
        return dp[pos][pos1][l1][l2][ispal];
    }

    int min1=0,max1=9;
    if(l1==0)min1=s1[pos1]-48;
    if(l2==0)max1=s2[pos1]-48;
    int res=0;
    for(int i=min1;i<max1+1;i++){
        ara[pos1]=i;
        int temp=ispal;
        int zero=(iszero|i);
        if(zero){
            int x=(len-pos)>>1;
            int l=2*(pos+x)-pos1;
            if(pos1>=pos+x){
                if((len-pos)%2==0)l--;
                temp = temp&(ara[pos1]==ara[l]);
            }
        }
        int p1=pos,p2=pos1;
        if(iszero==0 && i==0)p1++,p2++;
        else p2++;
        res += fun(p1, p2 ,(l1|(i>min1)), (l2|(i<max1)), zero,temp );
    }
    //return res;
    return dp[pos][pos1][l1][l2][ispal]=res;
}

int makeString(int p,int q){
    stringstream ss,ss1;
    ss<<p;
    s1=ss.str();
    ss1<<q;
    s2=ss1.str();
    while(s1.length()<s2.length())
        s1="0"+s1;
    len=s1.length();
    memset(dp,-1,sizeof(dp));
    return fun(0,0,0,0,0,1);
}

main()
{
    int t,k;
    scanf("%lld",&t);
    int caseno=0;
    while(t--){
        scanf("%lld%lld",&n,&m);
        if(m<n)swap(n,m);
        printf("Case %lld: %lld\n",++caseno,makeString(n,m));
    }
}
