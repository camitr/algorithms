#include<iostream>
#define INF 999
#define vertex1 5
using namespace std;
//void graphShow(int cost[][vertex]);

class Floydmarshall
{
private: 
int		graph[vertex1][vertex1];
public:
void	floyd(int graph[][vertex1]);
void	graphInput();
void	graphShow(int cost[][vertex1]);

};

void Floydmarshall::floyd(int graph[][vertex1])
{
	int cost[vertex1][vertex1],i,j,k;

	for(i=0;i<vertex1;i++)
	{
		for(j=0;j<vertex1;j++)
		{
			cost[i][j]=graph[i][j];
		}
	}

	for(i=0;i<vertex1;i++)
	{
		for(j=0;j<vertex1;j++)
		{
			for(k=0;k<vertex1;k++)
			{
				if(cost[i][k]+cost[k][j]<cost[i][j])
					cost[i][j]=cost[i][k]+cost[k][j];
			}
		}
	}

	graphShow(cost);
}

void Floydmarshall::graphShow(int cost[][vertex1])
{
	cout<<"Graph enter is "<<endl;
	
	for(int i=0;i<vertex1;i++)
	{
		for(int j=0;j<vertex1;j++)
		{
			if(cost[i][j]==INF)
				cout<<"\tINF";
			else
				cout<<"\t"<<cost[i][j];
		}
		cout<<endl;
	}
}

void Floydmarshall::graphInput()
{
	cout<<"Enter the weight of edges"<<endl;
	for(int i=0;i<vertex1;i++)
	{
		for(int j=0;j<vertex1;j++)
		{
			cin>>graph[i][j];
		}
	}
	graphShow(graph);	
	floyd(graph);
}
int main()
{
	
	Floydmarshall obj;
	obj.graphInput();



}

