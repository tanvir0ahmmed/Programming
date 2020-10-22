#include<iostream>
using namespace std;
int n,e;
int arr[100][100]= {0};

bool isBiPartite(int i,int color[])
{
    bool flag = true;
    for(int j=0; j<n; j++)
    {
        if(arr[i][j] == 1)
        {
            if(color[j] == -1) //If color of current node not set
            {
                color[j] = 1 - color[i];//Set color opposite to adjacent node
                flag = flag & isBiPartite(j,color);//Check for adjacent node
            }
            else if(color[i] == color[j])  //If color is same for adjacent node return false
            {
                return false;
            }
        }
    }
    return flag;
}

int main()
{
    cin >> n>>e;//No of nodes in graph
    int color[n],ss,dd;//For coloring of graph

    for(int i=0; i<n; i++)
        color[i] = -1;
    for(int j=0; j<e; j++)
    {
        cin>>ss>>dd;
        arr[ss][dd]=1;
        arr[dd][ss]=1;
    }

    for(int i=0; i<n; i++)
    {
        if(color[i]==-1)
        {
            color[i] = 0;//Color starting node(of connected/disconnected graph) as 0
            if(!isBiPartite(i,color)) //If not bipartite then print -1
            {
                cout << "-1" << endl;
                return 0;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        if(color[i] == 0)
        {
            cout << i << " ";//Print all nodes with color 0
        }
    }

    return 0;
}
