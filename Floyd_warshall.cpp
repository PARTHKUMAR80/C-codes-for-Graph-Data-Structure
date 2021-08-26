#include <bits/stdc++.h>
using namespace std;
#define V 4
void print_solution(int graph[][V]){
    for (int i=0;i<V;i++){
        for (int j=0;j<V;j++){
            if (graph[i][j]==INT_MAX){
                cout<<"INFINITY"<<" ";
            }
            else {
                cout<<graph[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
}
void floyd_warshall(int graph[][V]){
    int dis[V][V];
    for (int i=0;i<V;i++){
        for (int j=0;j<V;j++){
            dis[i][j]=graph[i][j];
        }
    }
    for (int k=0;k<V;k++){
        for (int i=0;i<V;i++){
            for (int j=0;j<V;j++){
                if (dis[i][j]>(dis[i][k]+dis[k][j]) && (dis[k][j]!=INT_MAX && dis[i][k]!=INT_MAX)){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    print_solution(dis);
}
int main(){
    int graph[V][V]={ {0,5,INT_MAX,10},
        {INT_MAX,0,3,INT_MAX},
        {INT_MAX,INT_MAX,0,1},
        {INT_MAX,INT_MAX,INT_MAX,0} };
        floyd_warshall(graph);
    return 0;
}