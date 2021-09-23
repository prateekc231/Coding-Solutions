class Solution {
public:
    int count, maxNow;
    void DFS(vector<vector<int>>& grid, int i, int j,
             vector<vector<bool>> &vis,int n, int m,int co){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0){
            return;
        }
        if(vis[i][j]== true) return;
        vis[i][j]=true;
        maxNow++;
        count= max(count,co);
         DFS(grid,i+1,j,vis,n,m,co+1);
         DFS(grid,i,j+1,vis,n,m,co+1);
         DFS(grid,i-1,j,vis,n,m,co+1);
         DFS(grid,i,j-1,vis,n,m,co+1);
        count = max(count,maxNow);
        return;

    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis( n , vector<bool> (m,false));
        count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]== false && grid[i][j]==1){
                    maxNow = 0;
                    DFS(grid,i,j,vis,n,m,1);
                }
            }
        }
        return count;
    }
};
