#include<bits/stdc++.h>
using namespace std;
const int N=301;
int graph[N][N];
int vis[N][N];
int row,col;
bool isValid(int i, int j){
    if(i>row || i<1 || j>col || j<1 || vis[i][j]==1 || graph[i][j]==0) return false;
    return true;
}
void dfs(int i, int j){
    vis[i][j]=true;
    if(isValid(i+1,j)) dfs(i+1,j);
    if(isValid(i-1,j)) dfs(i-1,j);
    if(isValid(i,j+1)) dfs(i,j+1);
    if(isValid(i,j-1)) dfs(i,j-1);

}
int main()
{

    cin>>row>>col;

    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
                cin>>graph[i][j];

        }
    }

    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            vis[i][j]=false;
        }
    }

    int cnt=0;

    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            if(vis[i][j] || graph[i][j]==false) continue;
            cnt++;
            dfs(i,j);
        }
    }
    cout<<cnt<<endl;
    return 0;

}
