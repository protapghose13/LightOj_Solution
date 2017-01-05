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

int fx[]={-2,-2,1,-1};
int fy[]={1,-1,-2,-2};

vector<int>vec,v;
bool taken[30];

void backtrack(int id){
    if(val==k)
        return;
    else if(vec.size()==n){
        for(int i=0;i<n;i++){
            cout<<(char)(vec[i]+64);
        }
        cout<<endl;
        val++;
        return;
    }
    else{
        for(int i=1;i<=n;i++){
            if(taken[i]==false){
                taken[i]=true;
                vec.pb(i);
                backtrack(i+1);
                taken[i]=false;
                vec.pop_back();
            }
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
        cin>>n>>k;
        val=0;
        memset(taken,0,sizeof(taken));
        cout<<"Case "<<++caseno<<":"<<endl;
        backtrack(1);
    }
    return 0;
}
