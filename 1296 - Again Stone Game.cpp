#include <bits/stdc++.h>
#define mx 750011
#define mp make_pair
#define pb push_back
//#define int  long long
#define mod 1000000007
//#define inf 100000000
#define xx first
#define yy second
//#define N 3

using namespace std;

int n,m,cs,k,val;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t;

    cin>>t;
    int caseno=0;
    while(t--){
        cin>>n;
        int res=0;
        for(int i=0;i<n;i++){
            int p;
            cin>>p;
            if(p%2==0){
                res ^= p/2;
            }
            else{
                while(p%2!=0){
                    p/=2;
                }
                res ^= p/2;
            }
        }
        cout<<"Case "<<++caseno<<": ";
        if(res)cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}
