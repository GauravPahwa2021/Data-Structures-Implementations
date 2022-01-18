#include<iostream>
using namespace std;
    /*   Singly Linked List Implementation   */
class Node
{
	public:
		int data;
	    Node *next;
		Node(int data)   
		{
			this->data=data;
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
		head=newNode;
		cout<<"%d Inserted"<<data<<endl;
	}
	else
	{
		temp=head;
		k=1;
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
			newNode->next=temp->next;
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
		cout<<"%d Deleted"<<temp->data<<endl;
		delete(temp);
	}
	else
	{
		temp=head;
		current=NULL;
		k=1;
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
			temp->next=NULL;
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
	Node *current=head,*temp=head->next;
	while(temp!=NULL)
	{
		current=temp;
		temp=temp->next;
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
	LinkedList SLL;
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
    			SLL.InsertAtFirst(data);
    			break;
			case 2:
				cout<<"Enter Your Data";
    			cin>>data;
    			cout<<"Enter Your pos";
    			cin>>pos;
    			SLL.InsertAtMiddle(data,pos);
    			break;
			case 3:
				cout<<"Enter Your Data";
    			cin>>data;
    			SLL.InsertAtLast(data);
    		    break;
			case 4:
				SLL.DeleteAtFirst();
				break;
			case 5:
				cout<<"Enter Your pos";
    			cin>>pos;
				SLL.DeleteAtMiddle(pos);
				break; 
			case 6:
				SLL.DeleteAtLast();
				break;
			case 7:
				cout<<"Enter Your Data";
    			cin>>data;
				x=SLL.Search(data);
				cout<<"Element Found At Index %d"<<x<<endl;
				break; 
			case 8:
				SLL.ReverseLinkedList(); 
				break;
			case 9:
				SLL.PrintLinkedList();
				break;
			case 10:
			    x=SLL.Length();
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