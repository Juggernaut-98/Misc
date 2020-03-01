#include <bits/stdc++.h>

using namespace std;
vector<long long> in;
vector<long long> out;
vector<long long> in_sum;
vector<long long> out_sum;
vector<vector<int>> adj;
vector<int>val;
int n;
void dfs1(int curr,int parent){
    in_sum[curr]=val[curr];
    for(auto itr:adj[curr]){
        if(itr!=parent){
            dfs1(itr,curr);
            in[curr]+=in[itr]+in_sum[itr];
            in_sum[curr]+=in_sum[itr];
        }
    }
}
void dfs2(int curr,int parent){
    out_sum[curr]=in_sum[parent]-in_sum[curr]+out_sum[parent];
    for(auto itr:adj[curr]){
        if(itr!=parent){
            out[itr]=in[curr]-in[itr]-in_sum[itr]+in_sum[curr]-in_sum[itr]+out_sum[curr]+out[curr];
            dfs2(itr,curr);
        }
    }
}
int main()
{
    cin>>n;
    in.resize(n,0);
    out.resize(n,0);
    in_sum.resize(n,0);
    out_sum.resize(n,0);
    adj.resize(n,vector<int>(0));
    val.resize(n,0);
    for (int i = 0; i < n; i++) {
        cin>>val[i];
    }
    for (int i = 0; i < n-1; i++) {
        int s,e;
        cin>>s>>e;
        s--;e--;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    dfs1(0,0);
    dfs2(0,0);
    long long ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,in[i]+out[i]);
    }
    cout<<ans;
    return 0;
}
