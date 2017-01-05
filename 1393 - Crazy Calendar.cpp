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

int n,m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t;
    cin>>t;
    int caseno=0;
    while(t--){
        cin>>n>>m;
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int p;
                cin>>p;
                int x = n-i-1 + m - j -1;
                if(x%2){
                    sum^=p;
                }
            }
        }
        if(sum)cout<<"Case "<<++caseno<<": win"<<endl;
        else cout<<"Case "<<++caseno<<": lose"<<endl;
    }
    return 0;
}
