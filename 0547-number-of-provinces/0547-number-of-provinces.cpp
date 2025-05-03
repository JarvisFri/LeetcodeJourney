class Solution {
public:
    void dfs(int i, vector<int> & visited, vector<vector<int>> & isConnected){
        int n=isConnected.size();
        visited[i]=1;

        for(int j=0; j<n; j++){
            if(isConnected[i][j] && !visited[j])
                dfs(j,visited,isConnected);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> visited(n,0);
        int res=0;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, visited,isConnected);
                res++;
            }
        }

        return res;

    }
};