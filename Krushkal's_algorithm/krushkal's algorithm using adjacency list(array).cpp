#include<bits/stdc++.h>
#include<stdio.h>
#define MAXX 50
using namespace std;

int N,E,weight;
char x,y;
int a,b;
int MST_cost;

struct Edge
{
    int u;
    int v;
    int w;
};
Edge arr[MAXX];
int parent[MAXX];

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
        parent[i] = -1;
    }
    for(int i=0; i<E; i++)
    {
        cin>>x>>y>>weight;
        a = encode(x);
        b = encode(y);

        arr[i].u = a;
        arr[i].v = b;
        arr[i].w = weight;
    }
}

void print_the_edge_and_weight()
{
    cout<<"From"<<"  :   "<<"To"<<"    "<<"Weight"<<endl;
    for(int i=0; i<E; i++)
    {
        cout<<"   "<<decode(arr[i].u)<<"  :   "<<decode(arr[i].v)<<"     "<<arr[i].w<<endl;
    }
}

bool comp(Edge a,Edge b)
{
    if(a.w < b.w)
        return true;

    return false;
}

int find_parent(int a)      //this is disjoint function
{
    if(parent[a] == -1)
        return a;

    return parent[a] = find_parent(parent[a]);
}

void Union(int a,int b)     //this is disjoint function
{
    parent[a] = b;
}
void implement_Disjoint_set()
{
    for(int i=0; i<E; i++)
    {
        a = find_parent(arr[i].u);
        b = find_parent(arr[i].v);

        if(a != b)  //here we checked if they are not in same set
        {
            MST_cost += arr[i].w;
            Union(a,b);
        }
    }
    cout<<endl<<"minimum spanning tree cost : "<<MST_cost;
}

int main()
{
    Graph_Initialization();
    cout<<"---Before Sorting ---"<<endl;
    print_the_edge_and_weight();
    sort(arr,arr+E,comp);
    cout<<endl<<"---After Sorting ---"<<endl;
    print_the_edge_and_weight();
    implement_Disjoint_set();
    cout<<endl;
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
