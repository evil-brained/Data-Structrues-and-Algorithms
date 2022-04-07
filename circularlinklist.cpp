#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	node *next;
	node *last=NULL;
	void insertbegin(int s)
	{
		node *newnode=new node();
		newnode->data=s;
		if(last==NULL)
		{
			last=newnode;
		}
	    newnode->next=last->next;
        last->next=newnode;
	}
	void insertend(int s)
	{
       node *newnode=new node();
       newnode->data=s;
       newnode->next=NULL;
       if(last==NULL)
       {
          last=newnode;
       }
       newnode->next=last->next;
       last->next=newnode;
       last=newnode;
   }
   void print()
   {
   	 node *nn=last->next;
   	 cout<<"the output:"<<"\n";
   	 do
   	 {
   	 	cout<<nn->data<<"\n";
   	 	nn=nn->next;
   	 }while(nn!=last->next);
   }

};
int main()
{
	node x;
	int i,val;
    do
    {
      cout<<"Enter choice :1-frontinsertion \n 2-backinsertion \n 3-print\n";
      cin>>i;
      switch(i)
      {
      	
        case 1: cout<<"\nenter the value you want to insert";
                cin>>val;
                x.insertbegin(val);
                break;
        case 2: cout<<"\nenter the value you want to insert";
                cin>>val;
		        x.insertend(val);
		        break;
        case 3: x.print();
                break;
        default: exit(0);
        
    }
  }while(i!=4);
	

}
