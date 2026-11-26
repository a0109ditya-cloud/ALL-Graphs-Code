#include<iostream>
using namespace sdt;
Class Graph{
  public:
    int n;
    int wt;
    unordered_map<int, list<bool>> adj;
    Graph(int n){
        this -> n = n;
        this -> wt = wt;
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
    
    void bellman(int src, vector<edge>& g){
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        for(int i=0;i<n-1;i++){
            for(int j=0;j<i;j++){
                for(auto k : edge[j]){
                    if(dist[v.k] > dist[u] + k.wt){
                        dist[v.k] = dist[u] + wt.k;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            cout << dist[i] << " ";
        }
    }
};
