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
 void topo(vector<bool>& vis, int curr, stack<int>& s){
        vis[curr] = true;
        
        for(auto i : adj[curr]){
            if(!vis[i]){
                topo(vis, i, s);
            }
        }
        s.push(curr);
    }
    
    
    int topohelp(){
        vector<bool> vis(n, false);
        stack<int> s;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                topo(vis, i, s);
            }
        }
        
        while(s.size() > 0){
            cout << s.top() << " ";
            s.pop();
        }
        return s;
    }
};
