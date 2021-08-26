#include <bits/stdc++.h>
using namespace std;
#define v 5
void add_edge(int graph[][v],int r,int c){
    graph[r][c]=1;
}
void print(int graph[][v]){
    for (int i=0;i<v;i++){
        for (int j=0;j<v;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int graph[v][v]={0};
    int n;
    cin>>n;
    int i=0;
    while (i<n){
        int r,c;
        cin>>r>>c;
        if (r<=v-1 && c<=v-1){
            add_edge(graph,r,c);
            cout<<"ADDED"<<endl;
            i++;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    print(graph);
    return 0;
}