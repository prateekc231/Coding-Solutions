bool canFinish(int num, vector<vector<int>>& pre) {
        vector<int> adj[num];
        vector<int> indegree(num,0);
        for(int i = 0;i<pre.size();i++){
            int a = pre[i][0];
            int b = pre[i][1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        for(int i = 0;i<num;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count =0;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            count++;
            for(int u : adj[temp]){
                if(--indegree[u]==0){
                    q.push(u);
                }
            }
        }
        return count==num;
    }

