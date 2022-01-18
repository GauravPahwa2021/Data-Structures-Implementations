#include<iostream>
using namespace std;
    /*   Circular Singly Linked List Implementation   */
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
		void ReverseLinkedList();
		void PrintLinkedList();
};
void LinkedList:: InsertAtFirst(int data)
{
	Node *newNode=new Node(data);
	Node *temp;
	if(head==NULL)
	{
		head=newNode;
		newNode->next=newNode;
	}
	else
	{
		newNode->next=head;
		head=newNode;
		temp=newNode;
		while(temp->next!=newNode)
		{
			temp=temp->next;
		}
		temp->next=newNode;
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
		temp=newNode;
		while(temp->next!=newNode)
		{
			temp=temp->next;
		}
		temp->next=newNode;
		cout<<"%d Inserted"<<data<<endl;
	}
	else
	{
		temp=head;
		k=1;
		while(k<pos-1 && temp->next!=head)
		{
			k++;
			temp=temp->next;
		}
		if(k<pos-1)
		{
			cout<<"position does not exist";
		}
		else if(k=pos-1 && temp->next==head)
		{
			temp->next=newNode;
			newNode->next=head;
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
		newNode->next=newNode;
	}
	else
	{
		temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=newNode;
		newNode->next=head;
	}
	cout<<"%d Inserted"<<data<<endl;
}
void LinkedList:: DeleteAtFirst()
{
	Node *temp,*current;
	if(head==NULL)
	{
		cout<<"list is empty"<<endl;
	}
	else
	{
		temp=head;
		current=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		head=current->next;
		temp->next=current->next;
		current->next=NULL;
		cout<<"%d Deleted"<<current->data<<endl;
		delete(current);
	}
}
void LinkedList:: DeleteAtMiddle(int pos)
{
	int k;
	Node *temp,*current;
	if(pos==1)
	{
		temp=head;
		current=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		head=current->next;
		temp->next=current->next;
		current->next=NULL;
		cout<<"%d Deleted"<<current->data<<endl;
		delete(current);
	}
	else
	{
		temp=head;
		current=NULL;
		k=1;
		while(k<pos && temp->next!=head)
		{
			k++;
			current=temp;
			temp=temp->next;
		}
		if(k<pos-1)
		{
			cout<<"position does not exist"<<endl;
		}
		else if(k=pos-1 && temp->next==head)
		{
			current->next=head;
			temp->next=NULL;
		    cout<<"%d Deleted"<<temp->data<<endl;
		    delete(temp);
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
		while(temp->next!=head)
		{
			current=temp;
			temp=temp->next;
		}
		current->next=head;
		temp->next=NULL;
		cout<<"%d Deleted"<<temp->data<<endl;
		delete(temp);
	}
}
void LinkedList:: ReverseLinkedList()
{
	Node *current=head,*temp=head->next;
	while(temp!=head)
	{
		current=temp;
		temp=temp->next;
		current->next=head;
		head=current;
	}
	temp->next=head;
}
void LinkedList:: PrintLinkedList()
{
	Node *temp=head;
	while(temp->next!=head)
	{
		cout<<temp->data;
		temp=temp->next;
	}
	cout<<temp->data;
}
int main()
{
	int data,choice,pos,x;
	LinkedList CSLL;
    cout<<"---Main Menu---"<<endl;
    cout<<"1-Insert At First"<<endl;
    cout<<"2-Insert At Middle"<<endl;
    cout<<"3-Insert At Last"<<endl;
    cout<<"4-Delete First"<<endl;
    cout<<"5-Delete At Middle"<<endl;
    cout<<"6-Delete Last"<<endl;
    cout<<"7-Reverse Linked List"<<endl;
    cout<<"8-Print Linked List"<<endl;
    cout<<"9-Exit"<<endl;
    while(true)
    {
    	cout<<"Enter Your Choice";
    	cin>>choice;
    	switch(choice)
    	{
    		case 1:
    			cout<<"Enter Your Data";
    			cin>>data;
    			CSLL.InsertAtFirst(data);
    			break;
			case 2:
				cout<<"Enter Your Data";
    			cin>>data;
    			cout<<"Enter Your pos";
    			cin>>pos;
    			CSLL.InsertAtMiddle(data,pos);
    			break;
			case 3:
				cout<<"Enter Your Data";
    			cin>>data;
    			CSLL.InsertAtLast(data);
    		    break;
			case 4:
				CSLL.DeleteAtFirst();
				break;
			case 5:
				cout<<"Enter Your pos";
    			cin>>pos;
				CSLL.DeleteAtMiddle(pos);
				break; 
			case 6:
				CSLL.DeleteAtLast();
				break;
			case 7:
				CSLL.ReverseLinkedList(); 
				break;
			case 8:
				CSLL.PrintLinkedList();
				break;
			case 9:
				exit(0);
				break;
			default:
			    cout<<"Please Enter A  Valid Choice"; 
		}
	}
	return 0;
}