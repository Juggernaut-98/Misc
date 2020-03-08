#include "bits/stdc++.h"
using namespace std;
class Solution{
public:
	class TrieNode{
	public:
		unordered_map<char,TrieNode*>dp;
		bool isEnd;
		TrieNode(){
			isEnd=false;
		}
	};
	class Trie{
	public:
		TrieNode*root;
		Trie(){
			root=new TrieNode();
		}
		~Trie(){
			delete root;
		}
		void insert(const string& word){
			TrieNode* temp=root;
			for (int i = 0; i < word.length(); ++i)
			{
				if(temp->dp.find(word[i])==temp->dp.end()){
					temp->dp[word[i]]=new TrieNode();
				}
				temp=temp->dp[word[i]];
			}
			temp->isEnd=true;
		}
		void dfs(TrieNode* temp,vector<string>&result,string res=""){
			if(temp->isEnd){
				result.push_back(res);
			}
			res+=' ';
			for(auto itr:temp->dp){
				res[res.length()-1]=itr.first;
				dfs(itr.second,result,res);
			}
		}
	};
	vector<vector<string>> solve(vector<string> arr,string userInput){
		Trie graph;
		vector<vector<string>> results;
		TrieNode* temp=graph.root;
		for(auto itr:arr)graph.insert(itr);
		for(int i=0;i<userInput.length();i++){
			vector<string>result;
			if(temp->dp.find(userInput[i])==temp->dp.end()){
				break;
			}
			temp=temp->dp[userInput[i]];
			graph.dfs(temp,result,userInput.substr(0,i-0+1));
			sort(result.begin(), result.end());
			if(result.size()>3){
				results.push_back(vector<string>(result.begin(),result.begin()+3));
			}else{
				results.push_back(result);
			}
		}
		return results;
	}
};
int main(){
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
	int tt=1;
	//cin>>tt;
	while(tt--){
		vector<string> arr({"mobile", "mouse", "moneypot", "monitor", "mousepad","cake","bake","sake","cat"});
		Solution solve;
		vector<vector<string>> results;
		string userInput="mouse";
		results=solve.solve(arr,userInput);
		for(auto itr:results){
			for(auto itr1:itr){
				cout<<itr1<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}