///if a graph contains odd cycle,then it will definitely not Bipartite
/*
Auther : Abdullah Al Masum
*/
#include<bits/stdc++.h>
#include<stdio.h>
#define MAX_VER 50
using namespace std;

int N,E,x,y;
bool dir;
int adj_matrix[MAX_VER][MAX_VER];   //this is also 2d vector
vector<vector<int>> adj_list;       //this is a 2d vector
vector<bool> visited;               //this is my visited array
vector<bool> color;                 //this is for Bipartite
void Graph_initialization()
{
    cout<<"input the total number of vertices:"<<endl;
    cin>>N;
    visited.resize(N+1);
    color.resize(N+1);
    adj_list.resize(N+1);           //this is to give space for the vertices
    for(int i=0; i<N; i++)
    {
        visited[i] = false;
        color[i] = false;
    }
    cout<<"input the total edges:"<<endl;
    cin>>E;
    cout<<"Is the graph dircted? 1 or 0 :"<<endl;
    cin>>dir;
    cout<<"input the edges:"<<endl;
    //below is for adjacency_matrix
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            adj_matrix[i][j]=0;
        }
    }
    while(E--)
    {
        cin>>x>>y;
        if(dir == false)
        {
            //below is for undirected graph
            adj_matrix[x][y]=1;
            adj_matrix[y][x]=1;
            adj_list[x].push_back(y);
            adj_list[y].push_back(x);
        }
        else
        {
            //below is for directed graph
            adj_matrix[x][y]=1;
            adj_list[x].push_back(y);
        }
    }
}
bool DFS(int val,bool col)
{
    visited[val] = true;
    color[val] = col;
    for(int child : adj_list[val])
    {
        if(!visited[child])
        {
            if(DFS(child,col^1) == false)   //here we operate XOR operation(^).otherwise use if else
                return false;
        }
        else
        {
            if(color[val] == color[child])
                return false;
        }
    }
    return true;
}
void print_adjeceny_matrix()
{
    cout<<endl<<"adjacency matrix printed :"<<endl;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<adj_matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void print_adjacency_list()
{
    cout<<endl<<"adjacency list printed :"<<endl;
    for(int i=0; i<N; i++)
    {
        //cout<<i<<"->";
        printf("%2d->",i);
        for(int j=0; j<adj_list[i].size(); j++)
        {
            //cout<<adj_list[i][j]<<" ";
            printf("%2d ",adj_list[i][j]);
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    Graph_initialization();
    print_adjeceny_matrix();
    print_adjacency_list();
    int source;
    cout<<"Input the source :"<<endl;
    cin>>source;
    bool isBipartite = DFS(source,1);
    if(isBipartite == true)
        cout<<"This Graph is Bipartite."<<endl;
    else
        cout<<"This Graph is Not Bipartite."<<endl;

    return 0;
}
/*
This is not Bipartite graph
5
5
0
0 1
1 3
1 2
2 3
3 4
*/
/*
This is Bipartite graph
14
28
0
0 10
0 8
7 1
7 2
7 3
7 4
1 9
1 10
1 11
2 8
2 9
2 10
2 11
2 12
3 8
3 9
3 10
3 11
3 12
3 13
4 10
4 13
5 11
5 13
6 13
6 12
6 11
6 10
*/
