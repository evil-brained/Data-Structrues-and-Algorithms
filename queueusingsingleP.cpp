#include<iostream>
using namespace std;
class node
{
	int data;
	node *next;
	public:
	node *p=NULL;
	void enqueue(int d)
	{
		node *nn=new node();
		nn->data=d;
		nn->next=NULL;
		if(p==NULL)
		{
			p=nn;
			p->next=p;
			return;
		}
	   nn->next=p->next;
       p->next=nn;
       p=nn;
	}
	int dequeue()
	{
		if(p==NULL)
		{
			return 999999;
		}
		if(p->next==p)
		{
            node *temp=p;
			int x=p->data;
            p->next=NULL;
            p=NULL;
            delete(temp);
			return x;
		}
		else 
		{
	
		node *temp=p->next;
		int x=temp->data;
		p->next=temp->next;
		delete(temp);
		
		return x;
	}

	}
	void print()
   {
   	 node *temp=p->next;
   	 cout<<"the output:"<<"\n";
   	 do
   	 {
   	 	cout<<temp->data<<"\n";
   	 	temp=temp->next;
   	 }while(temp!=p->next);
   }

	
};
int main()
{
	node obj;
	int p;
	int choice,val;
	do
    {
    cout<<"\nenter ur choice 1-enqueue 2-dequeue 3-display";
    cin>>choice;
    switch(choice)
    {
        case 1: cout<<"\nenter the value u want to insert";
                cin>>val;
                obj.enqueue(val);
                break;
        case 2:  p=obj.dequeue();
                if(p==999999)
                {
                	cout<<"the queue is empty can't dequeue\n";
                	break;
				}
				cout<<"the deleted item is    :"<<p<<"\n";
                break;
        case 3: obj.print();
                break;
        default: exit(0);
        
    }
  }while(choice!=4);
	
	
}
