#include<bits/stdc++.h>
#include<stdio.h>
#include<limits>    //it actually uses for INT_MAX
#define MAXX 50
#define INF 99
using namespace std;

int adj_matrix[MAXX][MAXX];
int N,E,u,v,w;
char x,y;

char decode(int s)
{
    char val = 0;
    return val = s+97;
}
int encode(char s)
{
    int val;
    if(65<= s && s<=90)
    {
        return val = s-65;
    }
    if(97<= s && s<=122)
    {
        return val = s-97;
    }
}
void print_the_adj_matrix()
{
    cout<<endl;
    cout<<"Here is the output:"<<endl;
    cout<<endl;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            //cout<<adj_matrix[i][j]<<"  ";
            printf("%3d  ",adj_matrix[i][j]);
        }
        cout<<endl;
    }
}
int Distance[MAXX];
bool Relaxed[MAXX];
void Graph_Initialization()
{
    cin>>N>>E;
    //adj_matrix initialization
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            adj_matrix[i][j] = INF;
            if(i == j)
            {
                adj_matrix[i][j] = 0;
            }
        }
    }
    //array initialization
    for(int i = 0; i<N ; i++)
    {
        Distance[i] = INF;
        Relaxed[i]  = false;
    }
    for(int i=0; i<E; i++)
    {
        cin>>x>>y>>w;
        u = encode(x);
        v = encode(y);

        adj_matrix[u][v] = w;
        adj_matrix[v][u] = w;
        if(u == v)
        {
            adj_matrix[u][v] = 0;   //here we remove self loop
        }
    }
}
int min_distance(int distance[],bool Relaxed[])
{
    int MIN = INF,min_index;
    for(int i=0; i<N; i++)
    {
        if(Relaxed[i] != true && distance[i] <= MIN)
        {
            MIN = distance[i];
            min_index = i;
        }
    }
    return min_index;
}
void Dijkstra_algo(int s,int graph[MAXX][MAXX])
{
    Distance[s] = 0;
    for(int i=0; i<N-1; i++) //focus this,why N-1 ?? explain
    {
        int a = min_distance(Distance,Relaxed);
        Relaxed[a] = true;
        //now for update as well as relaxation
        for(int b=0; b<N; b++)
        {
            //not relaxed but graph contains edge and they are directly connected(distance not infinity)
            //here graph[a][b] means cost of edge a to b
            if(Relaxed[b] != true && graph[a][b] && Distance[a] != INF && Distance[a] + graph[a][b] <= Distance[b])
            {
                Distance[b] = Distance[a] + graph[a][b];    //aactually this is the relaxation condition
            }
        }
    }
}
void Print_Solution(int s)
{
    cout<<"All the distance are from the source : "<<decode(s)<<endl;
    cout<<"vertex      minimum distance"<<endl;
    for(int i=0; i<N; i++)
    {
        if(i == s)
        {
            continue;
        }
        else
        {
            cout<<"   "<<decode(i)<<"     :      "<<Distance[i]<<endl;
        }
    }
}
int main()
{
    Graph_Initialization();
    //print_the_adj_matrix();
    cout<<endl<<"Please input the source vertex: "<<endl;
    char source;
    cin>>source;
    int s = encode(source);
    if(s >= N)
    {
        cout<<"The vertex you inserted is not in the graph"<<endl<<"So,the program is terminating..."<<endl;
        exit(0);
    }
    Dijkstra_algo(s,adj_matrix);
    Print_Solution(s);
    //print_the_adj_matrix();
    return 0;
}
/*input
9
14
a b 4
b c 8
a h 8
b h 11
h i 7
c i 2
i g 6
h g 1
c d 7
f c 4
f g 2
d f 14
d e 9
e f 10
*/

/*
6
10
a b 3
a e 6
a f 5
b f 4
b c 1
c f 4
c d 6
d f 5
d e 8
e f 2
*/

