#include <bits/stdc++.h>
#define mx 100011
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define xx first
#define yy second
#define int long long

using namespace std;

int N,M,K;
int nCr[1001][1001],fact[1001];

void precalc(){
    nCr[0][0]=1;
    fact[0]=1;
    for(int i=1;i<=1000;i++){
        nCr[i][0]=1;
        fact[i] = (fact[i-1]*i)%mod;
        if(fact[i]<0)fact[i]+=mod;
        for(int j=1;j<=1000;j++){
            if(j>i)continue;
            nCr[i][j] = (nCr[i-1][j]+nCr[i-1][j-1])%mod;
            if(nCr[i][j]<0)nCr[i][j]+=mod;
        }
    }
}

/*
M              M     M-K             M-K              M-K                    M-K  M-K
 C * (N-K)! -   C *(    C *(N-K-1) -    C *(N-K-2) +     C *(N-K-3) ... + (-1)       C   *(N-K-(M-K)) )
  K              K       1               2                3                           M-K

*/

main()
{
//    freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t;
    precalc();

    cin>>t;
    int caseno=0;
    while(t--){
        cin>>N>>M>>K;

        int p=M-K;

        int ans=(nCr[M][K]*fact[N-K])%mod;
        int ans1=0;
        for(int i=1;i<=p;i++){
            if(i%2==1){
                ans1 += (nCr[p][i]*fact[N-K-i])%mod;
            }
            else{
                ans1 -= (nCr[p][i]*fact[N-K-i])%mod;
            }
            ans1 = (ans1+mod)%mod;
        }
        ans1 = (ans1*nCr[M][K])%mod;
        ans -= ans1;
        if(ans<0)ans+=mod;

        cout<<"Case "<<++caseno<<": "<<ans%mod<<endl;
    }
    return 0;
}
