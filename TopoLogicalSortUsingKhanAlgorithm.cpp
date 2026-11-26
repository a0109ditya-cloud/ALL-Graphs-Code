#include<iostream>
using namespace sdt;
Class Graph{
  public:
    int n;
    unordered_map<int, list<bool>> adj;
    Graph(int n){
        this -> n = n;
    }
    
    void adj(int a, int b, int direction){
        adj[a].push_back(b);
        
        if(direction == 0){
            adj[b].push_back(a);
        }
    }
    
    void print(){
        for(auto i : adj){
            cout << i.first << "-->";
            for(int j=0;j<i.second;i++){
                cout << j << " ";
            }
            cout << endl;
        }
    }
    
    void toposort(){
        vector<int> res;
        queue<int> q;
        
        vector<int> indegree(n, 0);
        
        for(int i=0;i<n;i++){
            for(auto j : adj[i]){
                indegree[j]++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(q.size() > 0){
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            
            for(auto i : adj[curr]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        
        for(auto r : res){
            cout << r << " ";
        }cout << endl;
    }
};
