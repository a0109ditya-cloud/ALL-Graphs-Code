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
    
    
    bool dsfhelper(int u, int par, vector<bool>& visited){
        visited[u] = true;
        cout << u << " ";
        
        for(auto i : adj[u]){
            if(!visited[i]){
                if(dsfhelper(i, u, visited)){
                    return true;
                }
            }else if(i != par){
                return true;
                
            }
        }
        return false;
    }
    
    
    bool iscycle(int n){
        int src = 0;
        vector<bool> visited(n, false);
        
        for(int i = 0;i< n;i++){
            if(!visited[i]){
                if(dsfhelper(i, -1, visited)){
                    return true;
                }
            }
        }
        return false;
        
    }
};
int main() {
    Graph g(5);

    g.adjLIST(0, 1, 0);
    g.adjLIST(1, 2, 0);
    g.adjLIST(2, 3, 0);
    g.adjLIST(3, 4, 0);
    g.adjLIST(4, 1, 0);  // Creates a cycle

    g.print();

    if(g.iscycle(5)) {
        cout << "Cycle is present";
    }
    else {
        cout << "Cycle is not present";
    }
}
