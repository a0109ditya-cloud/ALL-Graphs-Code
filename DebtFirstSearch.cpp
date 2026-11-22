#include<iostream>
#include<unordered_map>
#include<list>
#include <vector>
using namespace std;
class Graph{
    public:
        unordered_map<int, list<int>> adj;
        
    void adjlist(int u, int v, int direction){
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }
    
    void print(){
        for(auto i : adj){
            cout << i.first << "-->";
            for(auto j : i.second){
                cout << j << " ";
            }cout << endl;
        }
    }
    void dfshelper(int u, vector<bool> &visited){
        visited[u] = true;
        cout << u << " ";
        for(auto i : adj[u]){
            if(!visited[i]){
                dfshelper(i, visited);
            }
        }
    }
    
    void dfs(int n){
        int src = 0;
        vector<bool> visited(n, false);
        
        dfshelper(src, visited);
    }
    
   
};
int main(){
    Graph G;
    int n;
    cout << "enter the number of nodes in the graph :: ";
    cin >> n;
    
    int e;
    cout  << "enter the number of edges in the graph :: ";
    cin >> e;
    
    
    for(int i=0;i<e;i++){
        int u;
        int v;
        cin >> u >> v;
        G.adjlist(u, v, 0);
    }
    G.print();
    cout << endl;
    G.dfs(n);
    G.print();
}
