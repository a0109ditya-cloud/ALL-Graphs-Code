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
    
    void djk(int src, vector<vector<int>& edges){
        vector<int> dist(n, INT_MAX);
        dist[src]  = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        
        while(pq.size() > 0){
            int u = pq.front().second;
            pq.pop();
            for(edge i : edges[u]){
                if(dist[i.v] > dist[u] + i.wt){
                    dist[i.v] = dist[u] + i.wt;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            cout << dist[i] << " ";
        }
    }
};
