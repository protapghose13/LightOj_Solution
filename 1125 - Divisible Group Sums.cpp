#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define mx 10010
#define mod 1000000007
#define int long long
#define pi acos(-1.0)
#define BLOCK 320
#define inf 1000000000000000001

using namespace std;

int n,m,d;
int ara1[201],ara[201];
int dp[201][22][11];

int call(int low,int val,int cnt)
{
    if(cnt==m)
        return (val%d==0);

    if(low>=n)
        return 0;

    if(dp[low][val][cnt]!=-1)
        return dp[low][val][cnt];

    int res=0;
    for(int i=low; i<n; i++)
    {
        res += call(i+1,(ara[i]+val)%d,cnt+1);
    }

    return dp[low][val][cnt]=res;
}

main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    int t;
    scanf("%lld",&t);


    int caseno=0;
    int p,q;
    while(t--)
    {
        scanf("%lld%lld",&n,&q);
        for(int i=0; i<n; i++)
        {
            scanf("%lld",&ara1[i]);
        }
        printf("Case %lld:\n",++caseno);
        for(int i=0; i<q; i++)
        {
            scanf("%lld%lld",&d,&m);
            memset(dp,-1,sizeof(dp));
            for(int j=0;j<n;j++){
                ara[j]=ara1[j]%d;
                ara[j]+=d;
                ara[j]%=d;
            }
            printf("%lld\n",call(0,0,0));
        }
    }
}
