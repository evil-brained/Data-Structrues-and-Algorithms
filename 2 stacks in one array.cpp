#include<iostream>
#define max 50
//2 Stacks Using One Array
using namespace std;
int arr[max];
int top1=-1,top2=max;
int isempty1()
{
	if(top1==-1)
	  return 1;
	else
	  return 0;
}
int isempty2()
{
	if(top2==max)
	  return 1;
	else
	  return 0;
}

int isfull()
{
	if(top2==top1+1||top1==top2-1)
	 return 1;
	else
	  return 0;
}
void push1(int n)
{
	if(isfull())
	cout<<"the stack is full";
	else
	{
	top1++;
	arr[top1]=n;
    }
}
void push2(int n)
{
	if(isfull())
	cout<<"stack is full";
	else
	{
		top2--;
		arr[top2]=n;
	}
}
int pop1()
{
	if (isempty1())
	return 70707;
	else
	{
	int y=arr[top1];
	top1--;
	return y;
    }   
}
int pop2()
{
	if (isempty2())
	return 70707;
	else
	{
	int z=arr[top2];
	top2--;
	return z;
    }   
}
int display1()
{
	for(int i=0;i<=top1;i++)
	{
		cout<<arr[i]<<" ";
	}
}
int display2()
{
	for(int i=max-1;i>=top2;i--)
	{
		cout<<arr[i]<<" ";
	}
}

int main()
{{
	int c,n,x;
	do
	{
		cout<<"enter the choice ";
		cin>>c;
		switch(c)
		{
		case 1:
			cout<<"enter the element \n";
			cin>>n;
		    push1(n);
		    break;
		case 2:
		    x = pop1();
		   if (x!=70707)
		   {
		   	cout<<"the popped item";
		   	cout<<x<<"\n";
		   	
		   }
		   else
		      cout<<"stack underflow \n";
		    break;
		case 3:
			cout<<"enter the element \n";
			cin>>n;
		    push2(n);
		    break;
		case 4:
			x = pop2();
		   if (x!=70707)
		   {
		   	cout<<"the popped item";
		   	cout<<x<<"\n";
		   	
		   }
		   else
		      cout<<"stack underflow \n";
		    break;
		case 5: 
			cout<<"the stack1 elements are \n";
		    display1();
		    break;
		case 6:
			cout<<"the stack2 elements are \n";
			display2();
			break;
		      
		}
		
    }while(c<6);
}

	
}
