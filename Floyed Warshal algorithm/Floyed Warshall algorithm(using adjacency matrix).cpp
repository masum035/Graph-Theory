#include<bits/stdc++.h>
#include<stdio.h>
#include<climits>    //it actually uses for INT_MAX
#define MAXX 50
#define INF INT_MAX

using namespace std;

int adj_matrix[MAXX][MAXX];
int N,E,u,v,w;
char x,y;
stack<int> STACK;
int dp[MAXX][MAXX];
int Path[MAXX][MAXX];

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
void Graph_Initialization()
{
    cout<<"This algo is for directed graph"<<endl;
    cin>>N>>E;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            adj_matrix[i][j] = INF;
            Path[i][j] = -1;
        }
    }
    for(int i=0; i<E; i++)
    {
        cin>>x>>y>>w;
        u = encode(x);
        v = encode(y);

        adj_matrix[u][v] = w;
        Path[u][v] = u;
//        adj_matrix[v][u] = w;   //uncomment this if we want to work on directed graph
//        Path[v][u] = v;
//        we can't do this here cause i want my adj_matrix neat&clean just like input
//        if(u == v)
//        {
//            adj_matrix[u][v] = 0;   //here we remove self loop
//        }
    }
}

void Floyed_Warshall_algo()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            dp[i][j] = adj_matrix[i][j];
            if(i==j)
            {
                dp[i][j] = 0;   //here we are removing self loop
            }
        }
    }

    int k,i,j;
    for(int k=0; k<N; k++)
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(dp[i][k] + dp[k][j] < dp[i][j] && dp[i][k] < INF && dp[k][j] < INF)
                {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    Path[i][j] = Path[k][j];
                }
            }
        }
    }
}
void Print_PATH(int source,int destination)
{
    STACK.push(destination);
    while(Path[source][destination] != source)
    {
        STACK.push(Path[source][destination]);
        destination = Path[source][destination];
    }
    cout<<decode(source)<<" ";
    while(!STACK.empty())
    {
        cout<<decode(STACK.top())<<" ";
        STACK.pop();
    }
}
void Print_Result()
{
    for(int i=0; i<N; i++)
    {
        cout<<"Minimum Cost With Respect to Node: "<<decode(i)<<endl;
        cout<<"     Edges        :      minimum cost"<<"   :   Path"<<endl;
        for(int j=0; j<N; j++)
        {
            if(dp[i][j] == 0 || dp[i][j] == INF)
            {
                continue;
            }
            printf("%2c  <-->  %2c      :         %3d         :    ",decode(i),decode(j),dp[i][j]);
           // cout<<"  "<<decode(i)<<"  <-->  "<<decode(j)<<"      :         "<<dp[i][j]<<"            ";
            Print_PATH(i,j);
            cout<<endl;
        }
    }
}
int main()
{
    Graph_Initialization();
    //print_the_adj_matrix();
    Floyed_Warshall_algo();
    Print_Result();
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
/*
7
10
a b 1
a c 1
c b 1
b d 4
d c -6
d e 1
d f 1
e f 1
e g 3
f g 1
*/
