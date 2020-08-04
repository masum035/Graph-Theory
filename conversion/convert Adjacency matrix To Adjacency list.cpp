#include<bits/stdc++.h>
#include<stdio.h>
#define MAX_VERTICES 15

using namespace std;

vector<vector <int>> Adj_List;
int adj_mat[MAX_VERTICES][MAX_VERTICES];
int vertices,total_edges;
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
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout<<adj_mat[i][j]<<"  ";
        }
        cout<<endl;
    }
}
void conversion(int row,int col)
{
    cout<<endl;int SIZE= 0;
    cout<<"conversion stared:"<<endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0,k = 0; j<col; k++,j++)
        {
            if(adj_mat[i][j] == 1)
            {
                Adj_List[i].push_back(j);
                SIZE++;
            }
        }
    }
    cout<<"total edges = "<<SIZE<<endl;
}
void print_the_adj_list(int v)
{
    cout<<endl;
    cout<<"Here is the adjacency list:"<<endl;
    cout<<endl;
    for(auto i=0; i<v; i++)
    {
        cout<<i<<"->";
        for(auto j=0; j<Adj_List[i].size(); j++)
        {
            cout<<Adj_List[i][j]<<"  ";
        }
        cout<<endl;
    }
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
    take_edge_list_input_and_process_it(total_edges);
    print_the_adj_matrix(vertices,vertices);
    Adj_List.resize(vertices+1);
    conversion(vertices,vertices);
    print_the_adj_list(vertices);
    return 0;
}
/*
5
8
1
0 2
2 0
2 1
1 3
2 3
3 4
2 4
4 2
*/
