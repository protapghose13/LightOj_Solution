#include <bits/stdc++.h>
#define mx 100011
#define mp make_pair
#define pb push_back
#define mod 100003
#define xx first
#define yy second

using namespace std;

vector<long long>vec,ans;
int sz,k;
bool ar[10000011];
int global,fp=0;
int cnt;

void seive(){
    for(int i=3;i<=3163;i+=2){
        if(!ar[i]){
            for(int j=i*i;j<=10000000;j+=2*i){
                ar[j]=1;
            }
        }
    }
    for(int i=3;i<=10000000;i+=2){
        if(!ar[i]){
            vec.pb(i);
        }
    }
    sz=vec.size();
}

long long factors[100],exponents[100];

void solve()
{
    long long factors_count=1;
    for (long long i = 0; i < k; ++i)
    {
        factors_count *= 1+exponents[i];
    }

    ans.resize(factors_count);
    ans[0] = 1;
    for (long long stack_level = 0; stack_level < k; ++stack_level)
    {
        long long count_so_far = cnt;
        long long prime = factors[stack_level];
        long long exponent = exponents[stack_level];
        long long multiplier = 1;
        for (long long j = 0; j < exponent; ++j)
        {
            multiplier *= prime;
            for (long long i = 0; i < count_so_far; ++i)
            {
                if( (ans[i] * multiplier)%2 )
                     ans[cnt++] = ans[i] * multiplier;
            }
        }
    }
    sort(ans.begin(),ans.end());
}

void divisor(long long n){
    while(n%2==0){
        n/=2;
    }
    for(int i=0;vec[i]*vec[i]<=n&&i<sz;i++){
        if(n%vec[i]==0){
            int cnt=0;
            while(n%vec[i]==0){
                n/=vec[i];
                cnt++;
            }
            factors[k]=vec[i];
            exponents[k]=cnt;
            k++;
        }
    }
    if(n!=1){
        factors[k]=n;
        exponents[k]=1;
        k++;
    }
}


int  main(){
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    seive();
    int t,caseno=0;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        k=0;
        cnt=1;
        divisor(n);
        solve();
        cout<<"Case "<<++caseno<<": "<<cnt-1<<endl;
    }

    return 0;
}
