#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll m,n;
vector<string> s;
void dfs(ll r, ll c){
    s[r][c] = 'v';
    ll moves[4][2] = {{0,-1},{-1,0},{1,0},{0,1}};
    for(int i =0;i<4;i++){
        ll new_x = r + moves[i][0];
        ll new_y = c + moves[i][1];
        if(new_x >=0 && new_x<m && new_y>=0 && new_y<n
        && s[new_x][new_y]=='.'){
            dfs(new_x,new_y);
        }
    }
    return;
}
int main(){
    ll i,j, ans =0;
    cin>>m>>n;
    string temp;
    for(i = 0;i<m;i++){
        cin>>temp;
        s.pb(temp);
    }
    for(i=0;i<m;i++){
        if(s[i][0]=='.'){
            dfs(i,0);
        }
    }
    for(i=0;i<m;i++){
        if(s[i][n-1]=='.'){
            dfs(i,n-1);
        }
    }
    for(j=0;j<n;j++){
        if(s[0][j]=='.'){
            dfs(0,j);
        }
    }
    for(j=0;j<n;j++){
        if(s[m-1][j]=='.'){
            dfs(m-1,j);
        }
    }
    for(i =0;i <m;i++){
        for(j=0;j<n;j++){
            if(s[i][j]== '.'){
                ans++;
            }
        }
    }
    cout<<ans;
}
