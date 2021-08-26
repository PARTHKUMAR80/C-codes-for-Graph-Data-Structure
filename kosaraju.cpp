#include <bits/stdc++.h>
using namespace std;
class graph{
    int V;
    list <int> *adj;
    void fill_order(int v,bool visited[],stack <int> &s){
        visited[v]=true;
        list<int>::iterator it;
        for (it=adj[v].begin();it!=adj[v].end();it++){
            if (visited[*it]==false){
                fill_order(*it,visited,s);
            }
        }
        s.push(v);
    }
    void dfs_util(int v,bool visited[]){
        visited[v]=true;
        cout<<v<<" ";
        list<int>::iterator it;
        for (it=adj[v].begin();it!=adj[v].end();it++){
            if (visited[*it]==false){
                dfs_util(*it,visited);
            }
        }
    }
    public:
        graph(int k){
            this->V=k;
            this->adj=new list <int> [k];
        }
        graph get_transpose(){
            graph g(V);
            for (int i=0;i<V;i++){
                list<int>::iterator it;
                for (it=adj[i].begin();it!=adj[i].end();it++){
                    g.adj[*it].push_back(i);
                }
            }
            return g;
        }
        void add_edge(int v,int w){
            adj[v].push_back(w);
        }
        void print_sccs(){
            stack <int> s;
            bool *visited=new bool [V];
            for (int i=0;i<V;i++){
                visited[i]=false;
            }
            for (int i=0;i<V;i++){
                if (visited[i]==false){
                    fill_order(i,visited,s);
                }
            }
            graph gr=get_transpose();
            for (int i=0;i<V;i++){
                visited[i]=false;
            }
            while (s.empty()==false){
                int v=s.top();
                s.pop();
                if (visited[v]==false){
                    gr.dfs_util(v,visited);
                    cout<<endl;
                }
            }
        }
};
int main(){
    graph g(5);
    g.add_edge(1,0);
    g.add_edge(0,2);
    g.add_edge(2,1);
    g.add_edge(0,3);
    g.add_edge(3,4);
    g.print_sccs();
    return 0;
}