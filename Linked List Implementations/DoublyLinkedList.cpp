#include<iostream>
using namespace std;
   /*   Doubly Linked List  Implementation   */
class Node
{
	public:
		int data;
		Node *prev;
		Node *next;
		Node(int data)   
		{
			this->data=data;
			this->prev=NULL;
			this->next=NULL;
		}
};
class LinkedList
{
	Node *head;
	public:
		LinkedList()
		{
			this->head=NULL;
		}
		void InsertAtFirst(int data);
		void InsertAtMiddle(int data,int pos);
		void InsertAtLast(int data); 
	    void DeleteAtFirst();
		void DeleteAtMiddle(int pos);
		void DeleteAtLast();
		int Search(int data);
		void ReverseLinkedList();
		void PrintLinkedList();
		int Length();
};
void LinkedList:: InsertAtFirst(int data)
{
	Node *newNode=new Node(data);
	if(head==NULL)
	{
		head=newNode;
	}
	else
	{
		newNode->next=head;
		newNode->prev=NULL;
		head=newNode;
	}
	cout<<"%d Inserted"<<data<<endl;
}
void LinkedList:: InsertAtMiddle(int data,int pos)
{
	int k;
	Node *newNode=new Node(data);
	Node *temp;
	if(pos==1)
	{
		newNode->next=head;
		newNode->prev=NULL;
		head=newNode;
		cout<<"%d Inserted"<<data<<endl;
	}
	else
	{
		k=1;
		temp=head;
		while(k<pos-1 && temp->next!=NULL)
		{
			k++;
			temp=temp->next;
		}
		if(k<pos-1)
		{
			cout<<"position does not exist"<<endl;
		}
		else
		{
			temp->next=newNode;
			newNode->prev=temp;
			newNode->next=temp->next;
			temp->next->prev=newNode;
			cout<<"%d Inserted"<<data<<endl;
		}
	}
}
void LinkedList:: InsertAtLast(int data)
{
	Node *newNode=new Node(data);
	Node *temp;
	if(head==NULL)
	{
		head=newNode;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newNode;
		newNode->prev=temp;
		newNode->next=NULL;
	}
	cout<<"%d Inserted"<<data<<endl;
}
void LinkedList:: DeleteAtFirst() 
{
	Node *temp;
	if(head==NULL)
	{
		cout<<"list is empty"<<endl;
	}
	else
	{
		temp=head;
		head=head->next;
		temp->next=NULL;
		head->next->prev=NULL;
		cout<<"%d Deleted"<<temp->data<<endl;
		delete(temp);
	}
}
void LinkedList:: DeleteAtMiddle(int pos) 
{
	int k;
	Node *temp,*current;
	if(pos==1)
	{
		temp=head;
		head=head->next;
		temp->next=NULL;
		head->next->prev=NULL;
		cout<<"%d Deleted"<<temp->data<<endl;
		delete(temp);
	}
	else
	{
		k=1;
		temp=head;
		current=NULL;
		while(k<pos && temp->next!=NULL)
		{
			k++;
			current=temp;
			temp=temp->next;
		}
		if(k<pos-1)
		{
			cout<<"position does not exist"<<endl;
		}
		else
		{
			current->next=temp->next;
			temp->next->prev=current;
			temp->next=NULL;
			temp->prev=NULL;
			cout<<"%d Deleted"<<temp->data<<endl;
			delete(temp);
		}
	}
}
void LinkedList:: DeleteAtLast() 
{
	Node *temp,*current;
	if(head==NULL)
	{
		cout<<"list is empty"<<endl;
	}
	else
	{
		temp=head;
		current=NULL;
		while(temp->next!=NULL)
		{
			current=temp;
			temp=temp->next;
		}
		current->next=NULL;
		temp->prev=NULL;
		cout<<"%d Deleted"<<temp->data<<endl;
		delete(temp);
	}
}
int LinkedList:: Search(int data)
{
	int k=1;
	Node *temp=head;
	while(temp->data!=data && temp->next!=NULL)
	{
		k++;
		temp=temp->next;
	}
	if(temp->data==data)
	{
		return k;
	}
	else
	{
		return -1;
	}
}
void LinkedList:: ReverseLinkedList()
{
	Node *temp=head->next,*current=head;
	while(temp!=NULL)
	{
		current=temp;
		temp=temp->next;
		head->prev=current;
		current->next=head;
		head=current;
	}
	
}
void LinkedList:: PrintLinkedList() 
{
	Node *temp=head;
	while(temp->next!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
	cout<<temp->data;
}
int LinkedList:: Length() 
{
	int k=1;
	Node *temp=head;
	while(temp->next!=NULL)
	{
		k++;
		temp=temp->next;
	}
	return k;
}
int main()
{
	int data,choice,pos,x;
	LinkedList DLL;
    cout<<"---Main Menu---"<<endl;
    cout<<"1-Insert At First"<<endl;
    cout<<"2-Insert At Middle"<<endl;
    cout<<"3-Insert At Last"<<endl;
    cout<<"4-Delete First"<<endl;
    cout<<"5-Delete At Middle"<<endl;
    cout<<"6-Delete Last"<<endl;
    cout<<"7-Search"<<endl;
    cout<<"8-Reverse Linked List"<<endl;
    cout<<"9-Print Linked List"<<endl;
    cout<<"10-Length"<<endl;
    cout<<"11-Exit"<<endl;
    while(true)
    {
    	cout<<"Enter Your Choice";
    	cin>>choice;
    	switch(choice)
    	{
    		case 1:
    			cout<<"Enter Your Data";
    			cin>>data;
    			DLL.InsertAtFirst(data);
    			break;
			case 2:
				cout<<"Enter Your Data";
    			cin>>data;
    			cout<<"Enter Your pos";
    			cin>>pos;
    			DLL.InsertAtMiddle(data,pos);
    			break;
			case 3:
				cout<<"Enter Your Data";
    			cin>>data;
    			DLL.InsertAtLast(data);
    		    break;
			case 4:
				DLL.DeleteAtFirst();
				break;
			case 5:
				cout<<"Enter Your pos";
    			cin>>pos;
				DLL.DeleteAtMiddle(pos);
				break; 
			case 6:
				DLL.DeleteAtLast();
				break;
			case 7:
				cout<<"Enter Your Data";
    			cin>>data;
				x=DLL.Search(data);
				cout<<"Element Found At Index %d"<<x<<endl;
				break; 
			case 8:
				DLL.ReverseLinkedList(); 
				break;
			case 9:
				DLL.PrintLinkedList();
				break;
			case 10:
			    x=DLL.Length();
			    cout<<"Length of Linked List Is %d"<<x<<endl;
			    break;
			case 11:
				exit(0);
				break;
			default:
			    cout<<"Please Enter A  Valid Choice"; 
		}
	}
	return 0;
}