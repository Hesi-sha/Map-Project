#include <bits/stdc++.h>
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

int minDist(int distance[], bool included[]){
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (included[v] == false && distance[v] < min)
            min = distance[v], min_index = v;

    return min_index;
}

void printMST(int nearest[], int map[V][V]){
    int sum = 0;
    cout << "Path: " << endl;
    for (int i = 1; i < V; i++) {
        sum += map[i][nearest[i]];
        cout << printPlace(nearest[i]) << "->" << printPlace(i) << "  >>  ";
    }
        cout << "end" << endl << endl<< "Path length: " << sum << "\n";
}

void primMST(int map[V][V]){

    int nearest[V];
    int distance[V];
    bool included[V];

    for (int i = 0; i < V; i++)
        distance[i] = INT_MAX, included[i] = false;

    distance[0] = 0;
    nearest[0] = -1;

    for (int count = 0; count < V - 1; count++) {

        int vnear = minDist(distance, included);
        included[vnear] = true;

        for (int v = 0; v < V; v++)
            if (map[vnear][v] && included[v] == false && map[vnear][v] < distance[v]) {
                nearest[v] = vnear;
                distance[v] = map[vnear][v];
            }
    }
    printMST(nearest, map);
}

int main(){

    int map[V][V] = { {0, 3 ,0 ,6, 0 ,9 ,0, 0, 0,0 },
                        { 3, 0, 2, 4, 9, 9, 0, 0, 0, 0 },
                        { 0 ,2, 0, 2, 8, 16, 9, 0, 0, 0 },
                        { 6 ,4 ,2 ,0 ,11 ,0, 9, 20, 0, 0 },
                        { 0, 9, 8 ,11 ,0, 8, 7, 0 ,9 ,10 },
                        { 9, 9 ,16 ,0 ,8 ,0 ,0 ,0 ,0 ,18 },
                        { 0, 0 ,9 ,9, 7 ,0 ,0 ,4 ,5, 0 },
                        {0, 0 ,0 ,20, 0, 0 ,4 ,0, 1 ,9},
                        { 0 ,0 ,0 ,0 ,9 ,0 ,5 ,1, 0 ,3 },
                        { 0, 0 ,0 ,0, 10, 18 ,0 ,9, 3, 0 } };

    primMST(map);
    return 0;
}