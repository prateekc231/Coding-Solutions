class Solution {
public:
    void DFS(vector<vector<char>>& grid, int i, int j,
             vector<vector<bool>> &vis,int n, int m){
        if(i<0 || j<0 || i>=n || j>=m){
            return;
        }
        if(vis[i][j]== true) return;
        vis[i][j]=true;
        if(grid[i][j] == '0') return;
         DFS(grid,i+1,j,vis,n,m);
         DFS(grid,i,j+1,vis,n,m);
         DFS(grid,i-1,j,vis,n,m);
         DFS(grid,i,j-1,vis,n,m);
        return;

    }


    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis( n , vector<bool> (m,false));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]== false && grid[i][j]=='1'){
                    DFS(grid,i,j,vis,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};
