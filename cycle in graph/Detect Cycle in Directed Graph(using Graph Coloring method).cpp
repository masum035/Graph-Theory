///Each node can have any number of "parent" or "children" as long as there is no loop
///In DAG,it is impossible to traverse the entire graph starting at one edge.
/*
Auther: Abdullah Al Masum
*/
#define White -1 //for unvisited
#define Black 1 //for visited
#define Blue 0  //currently visiting
#include<bits/stdc++.h>

using namespace std;
int N,E,w,x,y;
bool hasweight;
int flag = 0;
vector<vector <int>> Adj_list1;
vector <vector <pair<int,int>>> Adj_list2;

vector<int> color;
vector<bool> visited;

void DFS(int source)
{
    int curr = source;
    visited[curr] = true;
    color[curr] = Blue;
    if(hasweight == false)
    {
        for(auto it=Adj_list1[curr].begin(); it != Adj_list1[curr].end(); it++)
        {
            if(!visited[*it])
            {
                visited[*it] = true;
                color[*it] = Blue;
                DFS(*it);
            }
            else if(visited[*it]==true && color[*it]==Blue)
            {
                flag = 1;
            }
        }
    }
    else
    {
        for(auto it=Adj_list2[curr].begin(); it != Adj_list2[curr].end(); it++)
        {
            int x = it->first;
            if(!visited[x])
            {
                visited[x] = true;
                color[x] = Blue;
                DFS(x);
            }
            else if(visited[x]==true && color[x]==Blue)
            {
                flag = 1;
            }
        }
    }
    color[curr] = Black;
}
void Graph_initialization()
{
    cout<<"Insert The total number of vertices :"<<endl;
    cin>>N;
    color.resize(N+1);
    visited.resize(N+1);
    Adj_list1.resize(N+1);
    Adj_list2.resize(N+1);
    for(int i=0; i<N; i++)
    {
        color[i] = White;
        visited[i] = false;
    }
    cout<<"Insert The total number of Edges :"<<endl;
    cin>>E;
    cout<<"Does the graph contains weight? 1 or 0 "<<endl;
    cin>>hasweight;
    cout<<"Input the Edges..."<<endl;
    if(!hasweight)
    {
        while(E--)
        {
            cin>>x>>y;
            Adj_list1[x].push_back(y);
        }
    }
    else
    {
        while(E--)
        {
            cin>>x>>y>>w;
            Adj_list2[x].push_back(make_pair(y,w));
        }
    }
}
void print_adjacency_list()
{
    int v,w;
    cout<<endl<<"adjacency list printed :"<<endl;
    for(int i=0; i<N; i++)
    {
        cout<<"source: "<<i<<"->";
        if(hasweight == 0)
        {
            for(int j=0; j<Adj_list1[i].size(); j++)
            {
                cout<<Adj_list1[i][j]<<" ";
            }
        }
        else
        {
            for(auto j=Adj_list2[i].begin(); j != Adj_list2[i].end(); j++)
            {
                v = j->first;
                w = j->second;
                cout<<"(Dest: "<<v<<",Weight: "<<w<<")"<<" ";
            }
        }
        cout<<endl;
    }
}
int main()
{
    Graph_initialization();
    print_adjacency_list();
    cout<<endl<<"Input the start vertex :"<<endl;
    int s;
    cin>>s;
    if(s >= N)
    {
        cout<<"source can not be greater than Total number of vertex"<<endl<<"So,the programme is terminating..."<<endl;;
        exit(0);
    }
    for(int i=0;i<N;i++){
            if(!visited[i])
    DFS(i);
}
    if(flag==1)
    {
        cout<<endl<<"Yes,This Graph has Cycle.not DAG"<<endl;
    }
    else
    {
        cout<<endl<<"Yes,This is DAG(Directed Acyclic Graph)"<<endl;
    }
    return 0;
}
/*
This is not DAG
11
11
0
6 8
1 3
1 4
1 2
2 0
0 9
0 10
2 7
8 2
7 5
7 6
*/
/*
This is weighted graph
This is not DAG
9
14
1
0 1 4
1 2 8
0 7 8
1 7 11
7 8 7
2 8 2
8 6 6
7 6 1
2 3 7
5 2 4
5 6 2
3 5 14
3 4 9
4 5 10
*/
/*
This is also DAG
14
17
0
0 9
0 1
0 2
0 4
0 7
9 10
9 11
9 12
10 13
10 14
1 3
2 3
3 6
4 5
4 8
7 8
5 6
*/
/*
This is DAG
13
14
0
0 1
0 9
1 8
8 9
2 3
3 4
3 7
3 5
7 8
5 6
6 7
7 10
7 11
10 11
*/
