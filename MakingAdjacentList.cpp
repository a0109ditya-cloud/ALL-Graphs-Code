#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class Graph{
  public:
    unordered_map<int ,list<int>> adj;
    
    
    void adjacentLIST(int u, int m, int direction){
        adj[u].push_back(m);
        if(direction == 0){
            adj[m].push_back(u);
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
};
int main(){
    Graph g;
    int n;
    cout << "enter the number of nodes in the graph : ";
    cin >> n;
    int m;
    // this the number of edges in the graph
    cout << "enter the number of edges : ";
    cin >> m;
    int u;
    int v;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        g.adjacentLIST(u, v, 0);
    }
    
    g.print();
    return 0;
    
}
