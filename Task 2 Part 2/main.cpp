
#include<bits/stdc++.h>

using namespace std;

int inp[10][10],completed[10],n,length=0;
int input[10];
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

int least(int c)
{
int i,nc=999;
int min=999,kmin;

for(i=0;i < n+1;i++)
{
if((inp[c][i]!=0)&&(completed[i]==0))
if(inp[c][i]+inp[i][c] < min)
{
min=inp[i][0]+inp[c][i];
kmin=inp[c][i];
nc=i;
}
}

if(min!=999)
length+=kmin;

return nc;
}

void mincost(int place)
{
int i=0,nplace;

completed[place]=1;
i++;
cout<<printPlace(input[place])<<"--->";
nplace=least(place);

if(nplace==999)
{
nplace=0;
cout<<printPlace(input[nplace]);
i++;
length+=inp[place][nplace];

return;
}

mincost(nplace);
}

int main()
{ int weight[10][10]= { {0, 3 ,0 ,6, 0 ,9 ,0, 0, 0,0 },
                        { 3, 0, 2, 4, 9, 9, 0, 0, 0, 0 },
                        { 0 ,2, 0, 2, 8, 16, 9, 0, 0, 0 },
                        { 6 ,4 ,2 ,0 ,11 ,0, 9, 20, 0, 0 },
                        { 0, 9, 8 ,11 ,0, 8, 7, 0 ,9 ,10 },
                        { 9, 9 ,16 ,0 ,8 ,0 ,0 ,0 ,0 ,18 },
                        { 0, 0 ,9 ,9, 7 ,0 ,0 ,4 ,5, 0 },
                        {0, 0 ,0 ,20, 0, 0 ,4 ,0, 1 ,9},
                        { 0 ,0 ,0 ,0 ,9 ,0 ,5 ,1, 0 ,0 },
                        { 0, 0 ,0 ,0, 10, 18 ,0 ,9, 0, 0 } };

  int begin;
  cout<<"Enter the begining of the path: "<<endl;
  cin>>begin;

  cout<<"Enter numbers of middle places: "<<endl;
  cin>>n;
  int vertex;
  int weight2[10][10];

  input[0]=begin;

  memset(weight2,0,sizeof(weight2));
  for(int i=1;i<n+1;i++){
      cout<<"Enter a middle place: "<<endl;
      cin>>input[i];
  }

      for(int i=0;i<n+1;i++)
          for(int j=0;j<n+1;j++){
              if(i!=j)
                   weight2[i][j]=weight2[j][i]=weight[input[i]][input[j]];
              else
                  weight2[i][j]=0;
          }

    for(int i=0;i < n+1;i++)
    {


    for(int j=0;j < n+1;j++)
    inp[i][j]=weight2[i][j];

    completed[i]=0;
    }

cout<<"The Path is: ";
cout<<endl;
mincost(0);

cout<<endl;

cout<<"Length of the path: "<<length<<endl;

return 0;
}
