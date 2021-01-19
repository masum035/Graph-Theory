//**Auther : Abdullah Al Masum
//to convert into int or string or char type data type
//change inside <> when Graph class is called
//in driver code,change input type.

#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#define MAXX 1000000

using namespace std;

template <typename T>
class Graph
{
public:
    int N;
    map<T, list<T>> li;
    Graph(int V)
    {
        this->N = V;
    }
    void addEdge(T x, T y)
    {
        li[x].push_back(y);
        li[y].push_back(x);
    }
    void BFS(T src)
    {
        map<T, bool> visited;
        queue<T> q;

        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << " ";
            for (auto i : li[node])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
};

int main()
{
    int vertex;
    cout << "Enter total node of the graph: ";
    cin >> vertex;
    Graph<char> g(vertex);
    bool check;
    cout << "Enter total Edges : ";
    int edges;
    cin >> edges;
    cout << "This representation is for non weighted graph" << endl;
    cout << "Enter Edges connected with: " << endl;
    char x, y;
    while (edges--)
    {
        cin >> x >> y;
        g.addEdge(x, y);
    }
    cout << "To BFS call,Enter a node : " << endl;
    char s;
    cin >> s;
    g.BFS(s);
    return 0;
}
/*
6
5
a b
a d
d e
f m
*/
