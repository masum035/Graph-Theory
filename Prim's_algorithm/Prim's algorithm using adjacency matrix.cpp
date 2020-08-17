/*
    Created by Abdullah Al Masum
*/
#include<bits/stdc++.h>
#include<stdio.h>
#include<limits>    //it actually uses for INT_MAX
#define MAXX 50
#define INF 99

using namespace std;

int adj_matrix[MAXX][MAXX];
bool visited[MAXX] = {false};
int N,E,u,v,w;
char x,y;

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

char decode(int s)
{
    char val = 0;
    return val = s+65;
}

void Graph_Initialization()
{
    cin>>N>>E;
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
    for(int i=0; i<E; i++)
    {
        cin>>x>>y>>w;
        u = encode(x);
        v = encode(y);

        adj_matrix[u][v] = w;
        adj_matrix[v][u] = w;   //if u r thinking,this is just i put,wrong.This is actually crucial for my algo

    }
}

void Prims_Algo()
{
    int No_of_edges = 0,MST_cost = 0;
    visited[0]=true;
    cout<<endl<<"  ***Minimum Edge Cost***"<<endl;
    cout<<"From"<<"  :  "<<"To :  "<<endl;
    while(No_of_edges < N-1)
    {
        int p=0,q=0,min_cost = INF;     //here p,q is the crucial element,keep focus on it
        for(int i=0; i<N; i++)
        {
            if(visited[i]==true)
            {
                for(int j=0; j<N; j++)
                {
                    if(!visited[j])
                    {
                        if(adj_matrix[i][j] == 0 || adj_matrix[i][j] >= min_cost)
                        {
                            continue;
                        }
                        else if(adj_matrix[i][j] < min_cost)
                        {
                            min_cost = adj_matrix[i][j];
                            p = i;
                            q = j;
                        }
                    }
                }
            }
        }
        visited[q]=true;
        MST_cost += min_cost;
        cout<<"   "<<decode(p)<<"  :  "<<decode(q)<<"  :  "<<min_cost<<endl;
        No_of_edges++;
        adj_matrix[p][q] = adj_matrix[q][p] = 100;
    }
    cout<<endl<<"minimum spanning tree cost: "<<MST_cost<<endl;
}

int main()
{
    Graph_Initialization();
    //print_the_adj_matrix();
    Prims_Algo();
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
