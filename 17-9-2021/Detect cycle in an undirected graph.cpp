bool DFS(vector<int> adj[],int node, bool visited[], int parent){
        visited[node] = true;
        for(int u : adj[node]){
            if(visited[u]== false){
                if(DFS(adj,u,visited,node) == true){
                    return true;
                }
            }
            else if( u!= parent){
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool visited[V] = {false};
        for(int i=0;i<V;i++){
            if(visited[i]== false){
                if(DFS(adj,i,visited,-1) == true){
                    return true;
                }
            }
        }
        return false;
    }
