#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};


   struct node *head=NULL;
   struct node *tail=NULL;

 void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
        tail->next=head;
    }
    void insertatbeg(int a)
    {
    	struct node *ptr=new node;
    	ptr->data=a;
    	struct node *p=head->next;
    	while(p->next!=head)
    	{
    		p=p->next;
		}
    p->next=ptr;
    ptr->next=head;
    head=ptr;
  
	}
	void insertatpos(int b,int pos)
	{
		struct node *new_node,*current;
		if (pos==1)
		{
			insertatbeg(b);
		}
		else
		{
			new_node=new node;
			new_node->data=b;
			current=head;
			for(int i=1;i<pos;i++)
			{
				current=current->next;
			}
			new_node->next=current->next;
			current->next=new_node;
		}
	}

    void displaydata()
{
struct node *ptr=head;
	do	{
			cout<<ptr->data<<" ";
		ptr=ptr->next;
		}while(ptr!=head);
	}


int main()
{
  int n,i,value,a,opt,b,pos;
 
   cout<<"how many nodes you want to enter";
   cin>>n;
   for(int i=0;i<n;i++)
   {
   	cout<<"enter value for "<<i+1<<" node";
   	cin>>value;
   	add_node(value);
   }
    displaydata();
    while(true){
	
    cout<<"press 1 to insert at beg.\n";
    cout<<"press 2 to insert at any pos\n";
	cout<<"select your option\n";
	cin>>opt;
	switch(opt)
	{
		case 1:
			cout<<"enter value\n";
			cin>>a;
			insertatbeg(a);
			displaydata();
			break;
		case 2:
			cout<<"enter value\n";
			cin>>b;
			cout<<"enter position\n";
			cin>>pos;
			insertatpos(b,pos);
			displaydata();
			break;
							
	}}
    
    return 0;
}
