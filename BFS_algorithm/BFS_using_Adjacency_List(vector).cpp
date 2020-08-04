/* BFS concept: In a graph, starting from a certain node, visit all other nodes.
The order of visiting is "all of my friends first, then my friends friends".
*/
//this code is for 0 to n-1 vertices  be careful taking input
#include<bits/stdc++.h>
#include<stdio.h>
#define MAXX 100

using namespace std;

int N,E,w,x,y;
bool is_directed;
vector<vector <int>> adj_List;
queue<int> QUEUE;
bool visited[MAXX] = {false};

void Graph_initialization()
{
    cout<<"input total vertices:"<<endl;
    cin>>N;
    adj_List.resize(N+1);
    cout<<"input total edges number: "<<endl;
    cin>>E;
    cout<<"press 1 if the graph is directed or press 0 if it is undirected:"<<endl;
    cin>>is_directed;
    cout<<"input the edges:"<<endl;
    while(E--)
    {
        cin>>x>>y;
        adj_List[x].push_back(y);
        if(is_directed == false)
        {
            adj_List[y].push_back(x);
        }
    }
}

void print_adjacency_List()
{
    cout<<"this is the adjacency List representation:"<<endl;
    for(int i=0; i<N; i++)
    {
        cout<<i<<"->";
        for(int j=0; j<adj_List[i].size(); j++)
        {
            cout<<adj_List[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Breadth_First_Search(int source)
{
    cout<<"Level-wise order according to start node: ";
    visited[source] = true;
    QUEUE.push(source);

    int verTex,neighbour;
    while(!QUEUE.empty())
    {
        verTex = QUEUE.front();
        QUEUE.pop();
        cout<<verTex<<" ";

        for(int i=0;i<adj_List[verTex].size();i++)
        {
            neighbour = adj_List[verTex][i];

            if(visited[neighbour]==false)
            {
                visited[neighbour] = true;
                QUEUE.push(neighbour);
            }
        }
    }
cout<<endl;
}

int main()
{
    Graph_initialization();
    print_adjacency_List();
    int start;
    cout<<"input the start vertex:"<<endl;
    cin>>start;

    Breadth_First_Search(start);
    return 0;
}

/*
9
9
0
0 2
0 6
0 4
1 4
1 7
2 5
3 4
3 5
5 8

*/
