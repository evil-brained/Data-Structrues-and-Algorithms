//queue using linklist
#include<iostream>
using namespace std;
class  node 
{
	int  data;
	node *next;
	public:
	node *rear=NULL,*front=NULL;
	void enqueue(int d)
	{
        node *nn=new node();
        nn->data=d;
        nn->next=NULL;
        if(rear==NULL)
        {
          front=nn;
          rear=nn;
        }
        else
        {
            rear->next=nn;
            rear=nn;
        }
 
    }
    void dequeue()
    {
     if(front==NULL)
         cout<<"queue is empty. Can't dequeue\n";
    else
     {
      node *temp=front;      
      cout<<temp->data;
      front=front->next;
      if(front==NULL)
          rear=NULL;
      delete(temp);
     }
   }
   void display()
   {
   	if(front==NULL)
   	{
   		cout<<"the queue is empty\n";
    }
    node *temp=front;
    while(temp!=NULL)
   {
     cout<<temp->data<<" ";
     temp=temp->next;
   }
} 
};
int main()
{
	node obj;
	int choice,val;
	do
    {
    
    cout<<"\nenter ur choice 1-enqueue 2-dequeue 3-display\n";
    cin>>choice;
    switch(choice)
    {
        case 1: cout<<"\nenter the value u want to insert\n";
                cin>>val;
                obj.enqueue(val);
                break;
        case 2: obj.dequeue();
                break;
        case 3: obj.display();
                break;
        default: exit(0);
        
    }
  }while(choice!=4);
}
