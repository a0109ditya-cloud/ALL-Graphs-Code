#include<iostream>
#include<unordered_map>
#include<list>
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
    
   
    
};
