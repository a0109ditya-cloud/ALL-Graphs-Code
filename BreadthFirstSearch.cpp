#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;
class Graph{
  public:
    int n;
    unordered_map<int, list<int>> adj;
    
    Graph(int n){
        this -> n = n;
    }
    
    void print(){
        for(auto i : adj){
            cout << i.first << "-->";
            for(auto j : i.second){
                cout << j << " ";
            }cout << endl;
        }
    }
    
    void adjLIST(int u, int v, int direction){
        adj[u].push_back(v);
        
        if(direction == 0){
            adj[v].push_back(u);
        }
    }
    
    
    void bfs(){
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        
        visited[0] =  true;
        
        while(q.size() > 0){
            int u = q.front();
            q.pop();
            
            cout << q << " ";
            for(auto i : adjLIST[u]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }
};
