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
    
    void prims(){
        vector<bool> inMst(n, false);
        
        priority_queue<pair<int, int> vector<pair<int, int>> greater<pair<int, int>>> pq;
        
        pq.push({0, 0});
        int mstcost = 0
        while(pq.size() > 0){
            auto p = pq.front();
            int u = p.first;
            int wt = p.second;
            mstcost += wt;
            if(!inMst[u]){
                inMst[u] = true;
                
                for(int i=0;i<adj[u].size();i++)){
                    int v = adj[u][i].first;
                    int wt = adj[u][i].second;
                    
                    pq.push({wt, v});
                }
            }
        }
        return mstcost;
    }
};
