#include <bits/stdc++.h>
#define mx 100011
#define mp make_pair
#define pb push_back
#define mod 100003
#define xx first
#define yy second

using namespace std;

long long arr[1800000];
vector<int>vec;
int sz;
bool ar[1000000];
int global,fp=0;


void seive(){
    for(int i=3;i<1000;i+=2){
        if(!ar[i]){
            for(int j=i*i;j<1000000;j+=2*i){
                ar[j]=1;
            }
        }
    }
    for(int i=3;i<1000000;i+=2){
        if(!ar[i]){
            vec.pb(i);
        }
    }
    sz=vec.size();
}

void call(long long val,int id){
    if(val<0){
        cout<<"sdfdsf"<<endl;
        fp=1;
    }
    arr[global++]=val;
    for(int i=id;i<sz;i++){
        if(val*vec[i]<=1000000000000){ ///avoiding overflow
            if(val*vec[i]*vec[i]<=1000000000000){
                call( val*vec[i]*vec[i] , i);
            }
            else{
                break;
            }
        }
        else{
            break;
        }
    }

}

int  main(){
  //  freopen("in.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    seive();
    for(long long i=0;i<40;i++){
        call(1ll << i, 0);
    }

    sort(arr,arr+global);

    int t,caseno=0;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        int x=upper_bound(arr,arr+global,n)-arr;
        cout<<"Case "<<++caseno<<": "<<n-x<<endl;
    }

    return 0;
}
