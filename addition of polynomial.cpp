#include<iostream>
using namespace std;
class node
{
	int pow;
	int coeff;
	node *next;
	public:
	node *head1=NULL;
	node *head2=NULL;
	node *head3=NULL;
	void insert1(int c,int p)   //inserting the coefficient and powers values of each term of polynomial 1 in node 1
	{
		node *newnode= new node();
		newnode->pow=p;
		newnode->coeff=c;
		newnode->next=NULL;
		if(head1==NULL)
		   head1=newnode;
		else
		{
			node *temp;
			temp=head1;
			while(temp->next!=NULL)
			{
				temp=temp->next;
		    }
			temp->next=newnode;
				
		}
    }
    void insert2(int c,int p)   //inserting the coefficient and powers values of each term of polynomial 2 in node 2
	{
		node *newnode= new node();
		newnode->pow=p;
		newnode->coeff=c;
		newnode->next=NULL;
		if(head2==NULL)
		   head2=newnode;
		else
		{
			node *temp;
			temp=head2;
			while(temp->next!=NULL)
			{
				temp=temp->next;
		    }
			temp->next=newnode;
				
		}
    }
    void add()
	{
		node *temp1=head1;
		node *temp2=head2;
		node *temp3=head3;
		while(temp1!=NULL && temp2!=NULL)    
		{   node *newnode= new node();
			if(temp1->pow==temp2->pow)          //this is the condition required when the powers of the terms in both the polynomials are equal
			{
				newnode->pow=temp1->pow;
				newnode->coeff=temp1->coeff+temp2->coeff;
				newnode->next=NULL;
				temp1=temp1->next;
				temp2=temp2->next;
			}
			else if(temp1->pow>temp2->pow)      //this is the condition required when the power of the terms in first polynomial is greater than the second polynomial 
			{
				newnode->pow=temp1->pow;
				newnode->coeff=temp1->coeff;
				newnode->next=NULL;
				temp1=temp1->next;
			}
			else if(temp1->pow<temp2->pow)     //this is the condition required when the power of the terms in second polynomial is greater than the first polynomial
			{
				newnode->pow=temp2->pow;
				newnode->coeff=temp2->coeff;
				newnode->next=NULL;
				temp2=temp2->next;
			}
			if(head3==NULL)
			  head3=newnode;
			else
			{
			  temp3=head3;
			  while(temp3->next!=NULL)
			  {
			      
			      temp3=temp3->next;
		      }
		      temp3->next=newnode;
		     }
     	}
		while(temp1!=NULL && temp1->next!=NULL)  //this is the condtion required when there are any remaining terms in polynomail 1
			{
				node *nn=new node();
				nn->pow=temp1->pow;
				nn->coeff=temp1->coeff;
				nn->next=NULL;
				temp3=head3;
				while(temp3->next!=NULL)
				     temp3=temp3->next;
				temp3->next=nn;
				temp1=temp1->next;
				
			}
			while(temp2!=NULL && temp2->next!=NULL)   //this is the condtion required when there are any remaining terms in polynomail 2
			{
				node *nn=new node();
				nn->pow=temp2->pow;
				nn->coeff=temp2->coeff;
				nn->next=NULL;
				temp3=head3;
				while(temp3->next!=NULL)
				     temp3=temp3->next;
				temp3->next=nn;
				temp2=temp2->next;
				
			}
			
	}
	void print()
	{
		node *temp3=head3;
		cout<<"\n THIRD LIST \n";
		while(temp3!=NULL)
		{
			cout<<"("<<temp3->coeff<<","<<temp3->pow<<")"<<"->";
			temp3=temp3->next;	
		}
	}
	
};
int main()
{
	node x;
    int i,n1,n2,p,coeff;
	cout<<"enter the highest degree for the polynomial 1";
	cin>>n1;
	cout<<"enter the highest degree for the polynomial 2";
	cin>>n2;
	cout<<"enter the polynomial 1";
	for(i=n1;i>=0;i--)
	{
		cin>>coeff;
		cout<<coeff<<"\n";
		x.insert1(i,coeff); //here i is the power of the variables in equation 1
	}
	cout<<"enter the polynomial 2";
	for(i=n2;i>=0;i--)
	{
		cin>>coeff;
		x.insert2(i,coeff); //here i is the power of the variables in equation 2
	}
	x.add();
	x.print();
}
