#include <bits/stdc++.h>
using namespace std;
class graph{
    int V;
    list <int> *adj;
    public:
        graph(int k){
            this->V=k;
            this->adj=new list<int> [V];
        }
        void add_edge(int v,int w){
            adj[v].push_back(w);
        }
        int find_mother();
        void dfs_util(int v,vector <bool> &visited){
            visited[v]=true;
            list<int>::iterator it;
            for (it=adj[v].begin();it!=adj[v].end();it++){
                if (visited[*it]==false){
                    dfs_util(*it,visited);
                }
            }
        }
};
int graph::find_mother(){
    vector <bool> visited(V,false);
    int v=0;
    for (int i=0;i<V;i++){
        if (visited[i]==false){
            dfs_util(i,visited);
            v=i;
        }
    }
    fill(visited.begin(),visited.end(),false);
    dfs_util(v,visited);
    for (int i=0;i<V;i++){
        if (visited[i]==false){
            return -1;
        }
    }
    return v;
}
int main(){
    graph g(7);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,3);
    g.add_edge(4,1);
    g.add_edge(6,4);
    g.add_edge(5,6);
    g.add_edge(5,2);
    g.add_edge(6,0);
    cout<<g.find_mother();
    return 0;
}