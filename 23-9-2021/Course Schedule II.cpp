class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<int> ans;
        if(pre.size() ==0){
            for(int i =0;i<num;i++){
                ans.push_back(i);
            }
            return ans;
        }
        vector<int> adj[num];
        int indegree[num];
        fill(indegree, indegree+num,0);
        for(int i=0;i<pre.size();i++){
            indegree[pre[i][0]]++;
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        queue<int> q;
        for(int i=0;i<num;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count =q.size();
        while(!q.empty()){
            int t = q.front();
            ans.push_back(t);
            q.pop();
            for(int u : adj[t]){
                indegree[u]--;
                if(indegree[u] == 0){
                    q.push(u);
                    count++;
                }
            }
        }
        if(count == num){
            return ans;
        }
        else{

            vector<int> temp;
            return temp;
        }
    }
};
