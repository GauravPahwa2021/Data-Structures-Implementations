#include<iostream>
using namespace std;
    /*   Adjacency List Implementation {Directed Graph}  */
class ListNode
{
	public:
		int data;
		ListNode *next;
		ListNode(int vertex)
		{
			this->data=vertex;
			this->next=NULL;
		}
};
class Graph
{
	int vertex;
	int edge;
	ListNode **AdjList;
	public:
		Graph(int V)
		{
			this->vertex=V;
			this->edge=0;
			this->AdjList=new ListNode*[V];
			for(int i=0; i<V; i++)
			{
				this->AdjList[i]=new ListNode(V);
				this->AdjList[i]->data=i;
			    this->AdjList[i]->next=NULL;
			}
		}
		void InsertEdge(int source,int destination);
		void DisplayEdge();
		void DisplayGraph();
		void DeleteEdge(int source,int destination);
		~Graph()
		{
			ListNode *temp,*current;
			for(int i=0; i<vertex; i++)
			{
				temp=AdjList[i];
				while(temp!=NULL)
				{
					current=temp;
					temp=temp->next;
					delete[] current;
				}
				temp=NULL;
			}
			cout<<"\nGraph Is Removed";
		}
};
void Graph::InsertEdge(int source,int destination)
{
	ListNode *temp,*current=NULL,*newNode=NULL;
	if((source<0 || source>=vertex) && (destination<0 || destination>=vertex))
	{
		cout<<"Memory Error"<<endl;
	}
	temp=AdjList[source];
	while(temp!=NULL)
	{
		current=temp;
		temp=temp->next;
	}
	if(source==destination)
	{
		cout<<"Edge Can Not be Inserted In This Location"<<endl;
	}
	else
	{
		newNode=new ListNode(destination);
	    current->next=newNode;
	    edge=edge+1;
	    cout<<"Edge Inserted From "<<source<<" To "<<destination<<endl;
	}
}
void Graph::DisplayEdge() 
{
	ListNode *temp,*current;
	cout<<"Edge Are:"<<endl;
	for(int i=0; i<vertex; i++)
	{
		current=AdjList[i];
		temp=AdjList[i]->next;
		while(temp!=NULL)
		{
			cout<<current->data<<"->"<<temp->data<<endl;
			temp=temp->next;
		}
	}
}
void Graph::DisplayGraph() 
{
	ListNode *temp,*current;
	cout<<"Vertex = "<<vertex<<" Edges = "<<edge<<endl;
	for(int i=0; i<vertex; i++)
	{
		current=AdjList[i];
		temp=AdjList[i]->next;
		cout<<current->data<<" -> ";
		while(temp!=NULL)
		{
			cout<<temp->data<<" -> ";
			temp=temp->next;
		}
		cout<<"\n";
	}
}
void Graph::DeleteEdge(int source,int destination)
{
	ListNode *temp,*current=NULL;
	if((source<0 || source>=vertex) && (destination<0 || destination>=vertex))
	{
		cout<<"Memory Error"<<endl;
	}
	temp=AdjList[source];
	while(temp!=NULL && temp->data!=destination)
	{
		current=temp;
		temp=temp->next;
	}
	if(current==NULL || source==destination)
	{
		cout<<"Edge Is Not Exist In This Location"<<endl;
	}
	else if(temp==NULL && temp->data!=destination)
	{
		cout<<"Edge Can Not Be Deleted From This Location"<<endl;
	}
	else
	{
		current->next=temp->next;
	    edge=edge-1;
	    cout<<"Edge Deleted From "<<source<<" To "<<destination<<endl;
	}
} 
int main()
{
	Graph G(5);
	G.DisplayGraph();
	G.InsertEdge(0,4);
	G.InsertEdge(1,3);
	G.InsertEdge(2,4);
	G.InsertEdge(3,0);
    G.InsertEdge(4,1);
	G.DisplayGraph();
	G.DisplayEdge();
	G.InsertEdge(2,0);
	G.InsertEdge(1,4);
    G.InsertEdge(3,2);
    G.InsertEdge(1,0);
	G.DisplayGraph();
	G.DisplayEdge();
	G.DeleteEdge(1,4);
	G.DeleteEdge(3,0);
	G.DisplayGraph();
	G.DisplayEdge();
	return 0;
}