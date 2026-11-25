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
    
    bool isCyclic(vector<bool>& vis, vector<bool>& revis, int curr){
        revis[curr] = true;
        vis[curr] = true;
        
        for(auto i : adj[u]){
            if(!vis[i]){
                if(isCyclic(vis, revis, i)){
                    return true;
                }
                
            }
            else if(revis[i]){
                return true;
            }
        }
        revis[curr] = false;
        vis[curr] = false;
        return false;
    }
    
};
