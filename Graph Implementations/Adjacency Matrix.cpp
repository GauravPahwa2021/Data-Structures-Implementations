#include<iostream>
using namespace std;
#define INF 1e5
    /*   Adjacency Matrix Implementation {Undirected Graph}  */
class Graph
{
	int vertex;
	int edge;
	int **AdjMatrix;
	public:
	    Graph(int V)
		{
			this->vertex=V;
			this->edge=0;
			this->AdjMatrix=new int*[V];
			for(int i=0; i<V; i++)
	        {
		        this->AdjMatrix[i]=new int[V]; 
	        }
	        for(int i=0; i<V; i++)
	        {
		        for(int j=0; j<V; j++)
		        {
			        if(i==j)
			        {
				        this->AdjMatrix[i][j]=0;
			        }
			        else
			        {
				        this->AdjMatrix[i][j]=INF;
			        }
		        }
	        }
		}
		void InsertEdge(int source,int destination,int weight);
		void DisplayEdge();
		void DisplayGraph();
		void DeleteEdge(int source,int destination);
		~Graph()
		{
			for(int i=0; i<vertex; i++)
			{
				delete[] AdjMatrix[i];
			}
			delete[] AdjMatrix;
			cout<<"\nGraph Is Removed";
		}
};
void Graph::InsertEdge(int source,int destination,int weight) 
{
	if((source<0 || source>=vertex) && (destination<0 || destination>=vertex))
	{
		cout<<"Memory Error"<<endl;
	}
	if(AdjMatrix[source ][destination ]==INF)
	{
		AdjMatrix[source][destination]=weight;
		AdjMatrix[destination][source]=weight;
		edge=edge+1;
	}
	cout<<"Edge Inserted From "<<source<<" To "<<destination<<endl;
}
void Graph::DisplayEdge() 
{
	cout<<"Edges Are:"<<endl;
	for(int i=0; i<vertex; i++)
	{
		for(int j=0; j<vertex; j++)
		{
			if(AdjMatrix[i][j]==0 || AdjMatrix[i][j]==INF)
			{
				continue;
			}
			else
			{
				cout<<i<<"->"<<j<<endl;
			}
		}
	}
}
void Graph::DisplayGraph()
{
	cout<<"Vertex = "<<vertex<<" Edges = "<<edge<<endl;
	for(int i=0; i<vertex; i++)
	{
		for(int j=0; j<vertex; j++)
		{
			if(AdjMatrix[i][j]==INF)
			{
				cout<<"INF"<<" ";
			}
			else
			{
				cout<<AdjMatrix[i][j]<<" ";
			}
		}
		cout<<"\n";
	}
}
void Graph::DeleteEdge(int source,int destination)
{
	if((source<0 || source>=vertex) && (destination<0 || destination>=vertex))
	{
		cout<<"Memory Error"<<endl;
	}
	if(AdjMatrix[source][destination]!=0 && AdjMatrix[source][destination]!=INF)
	{
		AdjMatrix[source][destination]=INF;
		AdjMatrix[destination][source]=INF;
		edge=edge-1;
	}
	cout<<"Edge Deleted From "<<source<<" To "<<destination<<endl;
}
int main()
{
	Graph G(5);
	G.DisplayGraph();
	G.InsertEdge(0,4,4);
	G.InsertEdge(1,3,7);
	G.InsertEdge(2,4,2);
	G.InsertEdge(3,0,9);
	G.InsertEdge(0,2,8);
	G.InsertEdge(4,3,5);
	G.InsertEdge(1,2,6);
	G.DisplayGraph();
	G.DisplayEdge();
	G.DeleteEdge(2,4);
	G.DeleteEdge(3,0);
	G.DisplayGraph();
	G.DisplayEdge();
	return 0;
}