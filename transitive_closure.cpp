#include <bits/stdc++.h>
using namespace std;
class graph{
    int V;
    bool **tc;
    list<int> *adj;
    void dfs_util(int u,int v);
    public:
        graph(int V){
            this->V=V;
            adj=new list<int> [V];
            tc=new bool *[V];
            for (int i=0;i<V;i++){
                tc[i]=new bool [V];
                memset(tc[i],false,V*sizeof(bool));
            }
        }
        void add_edge(int u,int v);
        void transitive_closure(){
            for (int i=0;i<V;i++){
                dfs_util(i,i);
            }
            for (int i=0;i<V;i++){
                for (int j=0;j<V;j++){
                    cout<<tc[i][j]<<" ";
                }
                cout<<endl;
            }
        }
};
void graph::dfs_util(int s,int v){
    if (s==v){
        // if (adj[v].contains(v)){
        //     tc[s][v]=true;
        // }
        // else {
        //     tc[s][v]=false;
        // }
    }
    list<int>::iterator it;
    for (it=adj[v].begin();it!=adj[v].end();it++){
        if (tc[s][*it]==false){
            dfs_util(s,*it);
        }
    }
}
void graph::add_edge(int v,int w){
    adj[v].push_back(w);
}
int main(){
    graph g(4);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,2);
    g.add_edge(2,0);
    g.add_edge(2,3);
    g.add_edge(3,3);
    g.transitive_closure();
    return 0;
}