/*
auther : Abdullah Al Masum
*/

#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#define MAXX 1000000

using namespace std;

class Graph
{
public:
    int N, E, w, x, y;
    //array of list
    list<int> *li; //as we don'tknow the size of the array of the list
    Graph(int V)
    {
        this->N = V;
        li = new list<int>[V];
    }
    void addEdge(int x, int y, bool check)
    {
        li[x].push_back(y);
        if (check == true)
        {
            li[y].push_back(x);
        }
    }
    void printAdjList()
    {
        //iterate all the verices in adj_List
        for (int i = 0; i < N; i++)
        {
            cout << "vertex: " << i << " -> ";
            for (int nbr : li[i])
            {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int vertex;
    cout << "Enter total node of the graph: ";
    cin >> vertex;
    Graph g(vertex);
    bool check;
    cout << "is this graph bi-directional? [0/1]" << endl;
    cin >> check;
    cout << "Enter total Edges : ";
    int edges;
    cin >> edges;
    cout << "This representation is for non weighted graph" << endl;
    cout << "Enter Edges connected with: " << endl;
    int x, y;
    while (edges--)
    {
        cin >> x >> y;
        g.addEdge(x, y, check);
    }
    g.printAdjList();
    return 0;
}
