#include <bits/stdc++.h>
using namespace std;
class graph{
    int v;
    list<int> *adj;
    public:
        map < int , bool > mapp;
        graph(int k){
            v=k;
            adj=new list<int>[v];
        }
        void add_edge(int v,int w){
            adj[v].push_back(w);
            adj[w].push_back(v);
        }
        void dfs(int k){
            mapp[k]=true;
            cout<<k<<" ";
            list<int>::iterator it;
            for (it=adj[k].begin();it!=adj[k].end();it++){
                if (mapp[*it]==false){
                    dfs(*it);
                }
            }
        }
        void bfs(int k){
            bool *visited=new bool[v];
            for (int i=0;i<v;i++){
                visited[i]=false;
            }
            list<int> queue;
            visited[k]=true;
            queue.push_back(k);
            while (queue.empty()==false){
                cout<<queue.front()<<" ";
                queue.pop_front();
                for (auto it=adj[k].begin();it!=adj[k].end();it++){
                    if (visited[*it]==false){
                        visited[*it]=true;
                        queue.push_back(*it);
                    }
                }
            }
        }
};
int main(){
    graph g(4);
    g.add_edge(0,1);
    g.add_edge(0,9);
    g.add_edge(1,2);
    g.add_edge(2,0);
    g.add_edge(2,3);
    g.add_edge(9,3);
    // g.bfs(2);
    g.dfs(2);
    return 0;
}