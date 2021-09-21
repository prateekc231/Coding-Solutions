class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<string> color(n,"white");
        for(int i=0;i<n;i++){
            if(color[i]=="white"){
                queue<int> q;
                q.push(i);
                color[i]= "blue";
                while(!q.empty()){
                    int parent = q.front();
                    q.pop();
                    for(int u: graph[parent]){
                        if(color[u]=="white"){
                            if(color[parent]=="blue") color[u]="red";
                            else color[u]="blue";
                            q.push(u);
                        }
                        else{
                            if(color[parent]==color[u]){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
