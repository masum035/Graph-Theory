//**Auther : Abdullah Al Masum
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#define MAXX 1000000

using namespace std;

class Graph
{
public:
    int N, E, w, x, y;
    unordered_map<string, list<pair<string, int>>> map;
    Graph(int V)
    {
        this->N = V;
    }
    void addEdge(string x, string y, int w, bool check)
    {
        map[x].push_back(make_pair(y, w));
        if (check == true)
        {
            map[y].push_back(make_pair(x, w));
        }
    }
    void printAdjList()
    {
        //iterate all the verices in map
        for (auto element : map)
        {
            string li = element.first;
            list<pair<string, int>> neighbours = element.second;
            cout << "vertex: " << li << " -> ";
            for (auto nbr : neighbours)
            {
                string something = nbr.first;
                int weight = nbr.second;
                cout << something << " " << weight << "|";
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
    cout << "Enter Edges connected with weight: [something like: Motijheel Airport 30]" << endl;
    string x, y;
    int w;
    while (edges--)
    {
        cin >> x >> y >> w;
        g.addEdge(x, y, w, check);
    }
    g.printAdjList();

    return 0;
}
/*
6 0 5
m e 6
f d 7
a d 3
a b 5
b m 4
*/
