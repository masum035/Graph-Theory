
#include<bits/stdc++.h>
#include<stdio.h>
#define MAX_VERTICES 15
using namespace std;

int p,q;
int adj_mat[MAX_VERTICES][MAX_VERTICES];
int vertices,total_edges;
bool visited_array[MAX_VERTICES];
bool isdirected;

void initial_adjacent_matrix(int v)//v for vertex
{
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            adj_mat[i][j]=0;
        }
    }
}

void take_edge_list_input_and_process_it(int edges)
{
    int x,y;
    for(int i=0; i<edges; i++)
    {
        cin>>x>>y;
        adj_mat[x][y] = 1;
        if(isdirected == false)
        {
            adj_mat[y][x] = 1;
        }
    }
}
void print_the_adj_matrix(int row,int col)
{
    cout<<endl;
    cout<<"Here is the output:"<<endl;
    cout<<endl;
    for(int i=0; i<row; i++)
    {
        cout<<"Vertex "<<i<<" is connected to: ";
        for(int j=0; j<col; j++)
        {
            if(adj_mat[i][j] == 1)
            {
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
}
void initialize_visited_array()
{
    for(int i=0; i<vertices; i++)
    {
        visited_array[i] = false;
    }
}
void BFS(int start_node)
{
    cout<<"Level-wise order according to start node: ";
    queue<int> queu;

    queu.push(start_node);
    visited_array[start_node] = true;
    printf("%d  ",start_node);
    while(!queu.empty())
    {
        p = queu.front();
        queu.pop();
        for(q = 0; q<vertices ; q++)
        {
            if(visited_array[q]==false && adj_mat[p][q]==1) //what does it mean? q vetex-ta unvisited and source p-er sathe q-er link ase/way ase
            {
                queu.push(q);
                visited_array[q] = true;

                printf("%d  ",q);
            }
        }
    }
    cout<<endl;
}
void connected_components()
{
    int count = 0;
    for(int i=0;i<vertices;i++)
    {
        if(visited_array[i] == false)
        {
            BFS(i);
            count++;
        }
    }
    cout<<"connected components: "<<count<<endl;
}
int main()
{
    cout<<"Please input the total number of vertices :"<<endl;
    cin>>vertices;
    initial_adjacent_matrix(vertices);
    cout<<"Please input the number of edges :"<<endl;
    cin>>total_edges;
    cout<<"Press 1 if directed or press 0 if undirected"<<endl;
    cin>>isdirected;
    cout<<"Please input the edges :"<<endl;
    visited_array[vertices];
    initialize_visited_array();
    take_edge_list_input_and_process_it(total_edges);
    print_the_adj_matrix(vertices,vertices);
//    cout<<endl<<"Please input the start node :"<<endl;
//    int start;
//    cin>>start;
    //BFS(start);
   connected_components();

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
