#include <bits/stdc++.h>
using namespace std;
class graph{
    int V;
    list <int> *adj;
    bool is_cyclic_util(int v,bool visited[],bool recc[]){
        if (visited[v]==false){
            visited[v]=true;
            recc[v]=true;
            list <int>::iterator it;
            for (it=adj[v].begin();it!=adj[v].end();it++){
                if (!visited[*it] && is_cyclic_util(*it,visited,recc)){
                    return true;
                }
                else if (visited[*it]){
                    return false;
                }
            }
        }
        recc[v]=false;
        return false;
    }
    public:
        graph(int k){
            this->V=k;
            this->adj=new list <int> [V];
        }
        void add_edge(int v,int w){
            adj[v].push_back(w);
        }
        bool is_cyclic(){
            bool *visited=new bool[V];
            for (int i=0;i<V;i++){
                visited[i]=false;
            }
            bool *recc=new bool[V];
            for (int i=0;i<V;i++){
                recc[i]=false;
            }
            for (int i=0;i<V;i++){
                if (is_cyclic_util(i,visited,recc)){
                    return true;
                }
            }
            return false;
        }
};
int main(){
    graph g(4);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,2);
    g.add_edge(2,0);
    g.add_edge(2,3);
    g.add_edge(3,3);
    if (g.is_cyclic()){
        cout<<"CONTAINS CYCLE"<<endl;
    }
    else {
        cout<<"DOSENT CONTAIN A CYCLE"<<endl;
    }
}