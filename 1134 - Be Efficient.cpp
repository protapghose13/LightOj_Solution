#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define mx 100001
#define xx first
#define yy second
#define int long long

using namespace std;

const int inf=1000000000000;

int n,k,m;
int ara[mx],rem[mx];

void clr(){
    for(int i=0;i<mx;i++){
        rem[i]=0;
    }
}

main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(false);
//    cout.tie(false);

    int t;
    scanf("%lld",&t);
    int caseno=0;
    while(t--){
        clr();
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%lld",&ara[i]);
            ara[i]+=ara[i-1];
            ara[i]%=m;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(ara[i]==0)ans++;
            rem[ ara[i] ]++;
            ans += (rem[ ara[i] ]-1);
        }

        printf("Case %lld: ",++caseno);

        printf("%lld\n",ans);
    }
    return 0;
}
