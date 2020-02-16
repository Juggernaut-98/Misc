class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<int>> ans;
    vector<int> low;
    vector<int> detect;
    vector<bool> visited;
    int time=0;
    void dfs(int curr,int parent=-1){
        visited[curr]=true;
        low[curr]=++time;
        detect[curr]=time;
        for(auto itr:adj[curr]){
            if(visited[itr] && itr!=parent){
                low[curr]=min(low[curr],detect[itr]);
            }else if(!visited[itr]){
                dfs(itr,curr);
                low[curr]=min(low[curr],low[itr]);
                if(low[itr]>detect[curr]){
                    ans.push_back({curr,itr});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        low.resize(n);
        detect.resize(n);
        visited.resize(n);
        for(auto itr:connections){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        for(int i=0;i<n;i++){
            low[i]=0;
            detect[i]=0;
            visited[i]=false;
        }
        dfs(0);
        return ans;
    }
};