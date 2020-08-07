///My Tarjans_algo can not consider (single node self looped) as a connected components,so i handled this case while taking input
/*
auther : Abdullah Al Masum
*/
#include<bits/stdc++.h>
#include<stdio.h>
#define MAXX 100

using namespace std;

int N,E,x,y;
int SCCcount = 0;
int vertex=0;
vector<vector <int>> adj_List;
vector<vector <int>> SCC;
vector<int> LowLink;
vector<int> discovery;
bool onStack[MAXX];

void Tarjans_algo(int source)
{
    static stack<int> STACK;
    discovery[source] = LowLink[source] = vertex++;
    STACK.push(source);
    onStack[source] = true;
    for(auto i:adj_List[source])
    {
        if(discovery[i] == -1)
        {
            Tarjans_algo(i);
            LowLink[source] = min(LowLink[source],discovery[i]); //the last i'th value will be checkout here
        }
        else if(onStack[i]==true)
        {
            LowLink[source] = min(LowLink[source],discovery[i]);
        }
    }
    ///Here is the main checkpost
    if(discovery[source] == LowLink[source])
    {
        vector<int> temp;
        while(1)
        {
            int top = STACK.top();
            STACK.pop();
            onStack[top] = false;
            temp.push_back(top);
            if(source == top)
                break;
        }
        SCC.push_back(temp);
    }
}
void Graph_initialization()
{
    cout<<"input total vertices:"<<endl;
    cin>>N;
    adj_List.resize(N+1);
    discovery.resize(N+1);   //initialized all to -1
    LowLink.resize(N+1);
    for(int i=0; i<N; i++)
    {
        discovery[i] = -1;
        onStack[i] = false;
    }
    cout<<"input total edges number: "<<endl;
    cin>>E;
    cout<<"input the edges:"<<endl;
    while(E--)
    {
        cin>>x>>y;
        adj_List[x].push_back(y);
        if(x == y)
            SCCcount++;
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
int main()
{
    Graph_initialization();
    print_adjacency_List();
    for(int i=0; i<N; i++)
    {
        if(discovery[i]== -1)
        {
            Tarjans_algo(i);
            SCCcount++;
        }
    }
    cout<<"Strongly connected components :"<<SCCcount<<endl;
    cout<<"it actually calculates loop in the bigger graph"<<endl;
    return 0;
}
/*
This has self loop
9
17
0 1
1 0
0 2
2 0
2 3
1 3
3 5
5 3
4 2
4 5
6 4
4 7
7 6
7 5
8 7
8 6
8 8
*/
/*
4
4
0 1
1 1
0 3
0 2
*/
/*
9
11
0 3
3 0
4 3
1 4
1 2
2 5
5 1
4 8
6 7
7 6
7 4
*/
