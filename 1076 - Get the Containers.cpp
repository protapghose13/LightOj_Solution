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
int arr[1001];

bool ok(int val){
    int cnt=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(arr[i]>val)return false;
        if(sum>val){
            cnt++;
            sum=arr[i];
        }
    }
    cnt++;
    return cnt<=m;
}

void fun(){
    int low=1, high=1000000009;
    while(high-low>4){
        int mid=(low+high)>>1;

        if(ok(mid))high=mid;
        else low=mid;
    }

    for(int i=low;i<=high;i++){
        if(ok(i)){
            cout<<i<<endl;
            return;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t;
    cin>>t;
    int caseno=0;
    while(t--){
        cin>>n>>m;
        int maxval=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            maxval=max(maxval,arr[i]);
        }

        cout<<"Case "<<++caseno<<": ";
        if(m>=n){
           cout<<maxval<<endl;
        }
        else
           fun();
    }

    return 0;
}
