#include<iostream>
#define MAX 30
using namespace std;
char arr[MAX];
int top;
void init()
{
	top=-1;
}
void push(char c)
{ 
   if(top==MAX-1)
     cout<<"overflow";
   else
   {
   top++;
   arr[top]=c;
}
}
char pop()
{
	if(top!=-1)
	{
		int x=arr[top];
		top--;
		return x;
	}
	else 
	    return ('\0');
}
int priority(char data)
{
    if(data=='*'||data=='/'||data=='%')
       return 3;
   else if(data=='-'||data=='+')
       return 2;
   else if(data=='>' || data == '<')  
      return 1;  
    else
      return 0;
}
int eval(int d1,int d2,char sym)
{
	int r;
	switch(sym)
	{
		case '+': r=d1+d2; break;
		case '-': r=d1-d2; break;
		case '*': r=d1*d2; break;
		case '/': r=d1/d2; break;
	}
	return r;
}
int main()
{
  int len,i;
  char opr;
  string s,post;
  cout<<"enter the infix expression to be converted\n";
  getline(cin,s);   
  len=s.length();  
  init();
  for(i=0;i<len;i++)
  {
  	if(s[i]=='\t' || s[i]==' ')
  	   continue;
  	else if((isdigit(s[i]))||(isalpha(s[i])))  
     {                                                        
      post.append(1,s[i]);                                      
     }
     else if(s[i]=='(')
     {
     	push(s[i]);
	 }
	 else if(s[i]==')')                           
    {
      do
     {
	  opr=pop();                       
	  if(opr=='(')    
	     break;
	  else
	     post.append(1,opr);                      
	 }while (opr!='('); 
    }
    else                                    
    {
	if(top== -1)         
	  push(s[i]);            
	else
	{
	opr=pop(); 
	if(opr=='(')
	{
	  push(opr);
	  push(s[i]);
	}  
	else
	{        
    while(priority(opr)>=priority(s[i]))  
	{                                         
	    post.append(1,opr);                                       
	    opr=pop();
	    if(opr=='\0')
	      break;
	}
	push(opr);                
	push(s[i]);               
      } 
	  }                                    
    }                                       
  }    
  char x;
  do 
  { x=pop();
    if (x!='\0')
	  post.append(1,x);
   }while (x!='\0');
  cout<<"The converted POSTFIX EXPRESSION : \n" ;
  cout<<post<<"\n";
 
  int len1,val,opd1,opd2;
  len1=post.length();
 
  for(i=0;i<len1;i++)
  {
		if ((post[i]==' ')||(post[i]=='\t'))
		 continue;
		else if (isdigit(post[i]))
		{
			val=post[i]-48;
			push((char)val);
		}
		else if (isalpha(post[i]))
		{
		   cout<<"\nenter the value of\n: -  "<<post[i];
		   cin>>val;
		   push((char)val);
		}
		else
		{
			opd2=pop();
			opd1=pop();
			int x=eval((int)opd1,(int)opd2,post[i]);
			push((char)x);
		
	
		}
		
	}
	cout<<"THE EVALUATED POSTFIX EXPRESSION :"<<"\n"<<(int)pop();
}
  
  


