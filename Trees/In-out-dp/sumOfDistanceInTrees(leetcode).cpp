class Solution {
public:
    vector<int> in;
    vector<int> out;
    vector<int> count;
    vector<int> out_count;
    vector<vector<int>> adj;
    int n;
    void dfs1(int curr,int par){
        for(auto itr:adj[curr]){
            if(itr!=par){
                dfs1(itr,curr);
                in[curr]+=in[itr]+count[itr];
                count[curr]+=count[itr];
            }
        }
    }
    void dfs2(int curr,int par){
        for(auto itr:adj[curr]){
            if(itr!=par){
                out_count[itr]=out_count[curr]+count[curr]-count[itr];
                out[itr]=out[curr]+out_count[itr];
                out[itr]=out[itr]+in[curr]-in[itr]-count[itr];
                dfs2(itr,curr);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n=N;
        in.resize(n,0);
        out.resize(n,0);
        count.resize(n,1);
        out_count.resize(n,0);
        adj.resize(n,vector<int>(0));
        for(auto itr:edges){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        dfs1(0,-1);
        dfs2(0,0);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=in[i]+out[i];
        }
        return ans;
    }
};