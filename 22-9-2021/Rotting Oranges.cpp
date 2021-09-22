class temp{
    public:
    int r;
    int c;
    int depth;
    temp(int row,int col, int d){
        this->r = row;
        this->c = col;
        this->depth = d;
    }
};


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<temp> q;
        int row = grid.size();
        int col = grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    temp t(i,j,0);
                    q.push(t);
                }
            }
        }
        int max_depth = 0;
        while(!q.empty()){
            temp t = q.front();
            q.pop();
            int i= t.r;
            int j= t.c;
            int k= t.depth;
            max_depth = max(max_depth,k);
            if(i-1 >= 0 && grid[i-1][j]==1 ){
                grid[i-1][j] =2;
                temp n(i-1,j,k+1);
                q.push(n);
            }
            if(j-1>=0 && grid[i][j-1]==1 ){
                grid[i][j-1] =2;
                temp n(i,j-1,k+1);
                q.push(n);
            }
            if(j+1<col && grid[i][j+1]==1 ){
                grid[i][j+1] =2;
                temp n(i,j+1,k+1);
                q.push(n);
            }
            if(i+1<row && grid[i+1][j]==1 ){
                grid[i+1][j] =2;
                temp n(i+1,j,k+1);
                q.push(n);
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return max_depth;
    }
};
