#include <bits/stdc++.h>
#define mx 100011
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define xx first
#define yy second
#define int long long
#define inf 1000000007

using namespace std;

int m,n,len;
string s;
int cnt[26],fact[22];

int calc(int n){
    int sum=fact[n];
    for(char i=0;i<=25;i++){
        sum/=fact[ cnt[i] ];
    }
    return sum;
}

void call(int pos,int n){
    if(pos>=len){
        cout<<endl;
        return;
    }
    int i;
    for(i=0;i<26;i++){
        if(cnt[i]){
            cnt[i]--;
            int p=calc(len-pos-1);
            if(p>=n){
                break;
            }
            cnt[i]++;
            n-=p;
        }
    }
    cout<<(char)(i+97);
    call(pos+1,n);
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
    for(int i=1;i<=21;i++){
        fact[i]=fact[i-1]*i;
    }
    int caseno=0;
    while(t--){
        cin>>s>>n;
        len=s.length();
        memset(cnt,0,sizeof(cnt));

        for(int i=0;i<len;i++){
            cnt[ s[i]-97 ]++;
        }
        cout<<"Case "<<++caseno<<": ";
        if(calc(len)<n){
             cout<<"Impossible"<<endl;
        }
        else{
            call(0,n);
        }
    }
    return 0;
}
