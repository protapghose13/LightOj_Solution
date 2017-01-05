#include <bits/stdc++.h>
#define mx 20011
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

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};


int n,m;
string src,des,s1,s2,s3;
int ans;
map<string,int>mymap,mymap1;

void bfs(){
    queue<pair<string,int> >myq;
    if(mymap1[src]==0)myq.push(mp(src,0));
    mymap[src]=1;
    while(!myq.empty()){
        string s=myq.front().xx;
        int dis =myq.front().yy;
        myq.pop();
        if(s==des){
            cout<<dis<<endl;
            return;
        }
        for(int i=0;i<3;i++){
            string d=s;
            if(d[i]=='z')d[i]='a';
            else d[i]++;
            if(mymap1[d]==0 && mymap[d]==0){
                mymap[d]=1;
                myq.push(mp(d,dis+1));
            }
        }
        for(int i=0;i<3;i++){
            string d=s;
            if(d[i]=='a')d[i]='z';
            else d[i]--;
            if(mymap1[d]==0 && mymap[d]==0){
                mymap[d]=1;
                myq.push(mp(d,dis+1));
            }
        }
    }
    cout<<"-1"<<endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t,caseno=0;
    cin>>t;
    while(t--){
        cin>>src>>des;
        cin>>n;
        mymap.clear();
        mymap1.clear();
        for(int i=0;i<n;i++){
            cin>>s1>>s2>>s3;
            int l1=s1.length();
            int l2=s2.length();
            int l3=s3.length();
            for(int j=0;j<l1;j++){
                for(int k=0;k<l2;k++){
                    for(int l=0;l<l3;l++){
                        string s="";
                        s+=s1[j],s+=s2[k],s+=s3[l];
                        mymap1[s]=1;
                    }
                }
            }
        }
        cout<<"Case "<<++caseno<<": ";
        bfs();
    }
    return 0;
}
