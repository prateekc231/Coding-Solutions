struct cell {
    int x, y;
    int dis;
    cell() {}
    cell(int x, int y, int dis)
        : x(x), y(y), dis(dis)
    {
    }
};

class Solution
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	bool isInside(int x, int y, int N)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}


	int minStepToReachTarget(vector<int>&knightPos,vector<int>&targetPos,int N)
	{

	    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
        int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
        queue<cell> q;
        q.push(cell(knightPos[0], knightPos[1], 0)); cell t;
        int x, y;
        bool visit[N + 1][N + 1];
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                visit[i][j] = false;
        visit[knightPos[0]][knightPos[1]] = true;
        while (!q.empty()) {
            t = q.front();
            q.pop();

        if (t.x == targetPos[0] && t.y == targetPos[1])
            return t.dis;
        for (int i = 0; i < 8; i++) {
            x = t.x + dx[i];
            y = t.y + dy[i];
            if (isInside(x, y, N) && !visit[x][y]) {
                visit[x][y] = true;
                q.push(cell(x, y, t.dis + 1));
                }
            }
        }

	}
};
