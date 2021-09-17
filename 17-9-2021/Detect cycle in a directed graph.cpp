bool DFS(vector<int> adj[], int node, bool vis[],bool recSt[]){
        vis[node]= true;
        recSt[node] = true;
        for(int u : adj[node]){
            if( vis[u]==false && DFS(adj,u,vis,recSt)){
                return true;
            }
            else{
                if(recSt[u]==true){
                    return true;
                }
            }
        }
        recSt[node]= false;
        return false;
    }


    bool isCyclic(int V, vector<int> adj[]) {
        // code here

        bool visited[V]= {false};
        bool recStack[V] = {false};
        for(int i=0;i<V;i++){
            if(DFS(adj,i,visited,recStack)==true){
                return true;
            }
        }
        return false;
    }
