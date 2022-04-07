#include<iostream>
using namespace std;
class node
{
   int x;
   node *succ;
   node *prev;	
   public:
   node *head=NULL;
  void insertend(int a)
  {
  	node *nn=new node();
  	nn->x=a;
  	nn->succ=NULL;
  	nn->prev=NULL;
  	if(head==NULL)
  	{
  		head=nn;
  		return;
  	}
  	node *temp=head;
  	while(temp->succ!=NULL)
  	{
  		temp=temp->succ;
    }
    temp->succ=nn;
    nn->prev=temp;
  }
   void swap()
   {
   	node *last;
   	node *temp=head;
   	int c=1;
   	while(temp->succ!=NULL)
   	{
   		temp=temp->succ;
   		c+=1;
	}
	cout<<c;
	last=temp;
	temp=head;
	int d;
	if(c%2!=0)
	{
	   while(last!=temp)
	  {
		d=last->x;
		last->x=temp->x;
		temp->x=d;
		temp=temp->succ;
		last=last->prev;
	  }
    }
    else
    {
       while(last->succ!=temp)
	  {
		d=last->x;
		last->x=temp->x;
		temp->x=d;
		temp=temp->succ;
		last=last->prev;
	  }
    }
    } 
   void display()
   {
   	node *temp=head;
   	cout<<"the swapped list :- \n";
   	while(temp!=NULL)
   	{
   		cout<<"\n"<<temp->x<<"\n";
   		temp=temp->succ;
   	}
   }
};
int main()
{
	int n,a;
	node p;
	cout<<"enter the value of n \n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
	  cout<<"Enter the number which u wanna insert \n";
	  cin>>a;
	  p.insertend(a); 
	}
	p.display();
	p.swap();
	p.display();
}
