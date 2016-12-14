#include <bits/stdc++.h>
#define mx 2022
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define xx first
#define yy second
#define inf 1000000000000000
//#define int long long
#define SIZE 100011
#define ll long long

using namespace std;

#define BLOCK 320
string arr[mx];
int tree[4*mx],ara[mx],n,m;

int histogram(){
    stack<int>mystk;
    int top;
    int ans=0;
    int area;
    for(int i=0;i<=n;){/// 0 based index & in the nth pos insert 0 or -1
        if(mystk.empty()){
            mystk.push(i);
            i++;
        }
        else if(ara[i]>=ara[mystk.top()]){
            mystk.push(i);
            i++;
        }
        else{
            top = mystk.top();
            mystk.pop();
            if(mystk.empty()){
                area = ara[top]*i;
            }
            else{
                area = ara[top] * (i-mystk.top()-1);
            }
            ans = max(ans,area);
        }
    }
    return ans;
}

int main() {
    int caseno=0,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        for(int i=0;i<m;i++){
            cin>>arr[i];
        }
        int ans=0;
        memset(ara,0,sizeof(ara));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]=='0')ara[j]++;
                else ara[j]=0;
            }
            ara[n]=0;
            ans = max(ans,histogram());
        }
        printf("Case %d: %d\n",++caseno,ans);
    }
}
