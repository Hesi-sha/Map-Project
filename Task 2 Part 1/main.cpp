#include <iostream>
using namespace std;

#define V 10

string printPlace(int dist){
    if (dist == 0)
        return "Parking";
    else if(dist == 1)
        return "Markaz Kharid";
    else if(dist == 2)
        return "Bimarestan";
    else if(dist == 3)
        return "Park Koohestani";
    else if(dist == 4)
        return "Terminal";
    else if(dist == 5)
        return "Foroodgah";
    else if(dist == 6)
        return "Restooran";
    else if(dist == 7)
        return "Madrese";
    else if(dist == 8)
        return "Sakhteman Edari";
    else if(dist == 9)
        return "Daneshgah";
}

int minDistance(int distance[], bool included[]){

    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (included[v] == false && distance[v] <= min)
            min = distance[v], min_index = v;

    return min_index;
}

void printPath(int parent[], int j){
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    cout << printPlace(j) << " >> ";
}

void dijkstra(int map[V][V], int src, int Destination){
    int distance[V];
    bool included[V];

    for (int i = 0; i < V; i++)
        distance[i] = INT_MAX, included[i] = false;

    int parent[V] = { -1 };
    distance[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(distance, included);

        included[u] = true;

        for (int v = 0; v < V; v++)
            if (!included[v] && map[u][v] && distance[u] != INT_MAX
                && distance[u] + map[u][v] < distance[v]) {
                distance[v] = distance[u] + map[u][v];
                parent[v] = u;
            }
    }
    cout << "Short path to ";
    cout << printPlace(Destination);
    cout << " is : " << distance[Destination] << endl << endl << "Path: " << endl << " Parking >> ";
    printPath(parent,Destination);
    cout << "end" << endl;
    return;
}

int main(){

    int destination;
    cin >> destination;

    int map[V][V] = {{0,  3 , 0 ,  6,   0 ,  9 ,  0,  0,  0,  0 },
                     {3,  0,  2,   4,   9,   9,   0,  0,  0,  0 },
                     {0 , 2,  0,   2,   8,   16,  9,  0,  0,  0 },
                     {6 , 4 , 2 ,  0 ,  11 , 0,   9,  20, 0,  0 },
                     {0,  9,  8 ,  11 , 0,   8,   7,  0 , 9 , 10 },
                     {9,  9 , 16 , 0 ,  8 ,  0 ,  0 , 0 , 0 , 18 },
                     {0,  0 , 9 ,  9,   7 ,  0 ,  0 , 4 , 5,  0 },
                     {0,  0 , 0 ,  20,  0,   0 ,  4 , 0,  1 , 9},
                     {0 , 0 , 0 ,  0 ,  9 ,  0 ,  5 , 1,  0 , 0 },
                     {0,  0 , 0 ,  0,   10,  18 , 0 , 9,  0,  0 } };

    dijkstra(map, 0, destination);
    return 0;
}