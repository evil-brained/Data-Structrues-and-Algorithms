#include<iostream>
using namespace std;
class node
{
	int data;
    node *prev;
    node *succ;
    node *top;
    node *bot;
    public:
    node *head=NULL;
    node *head1=NULL;
    void insertbeg(int val)
    {
    node *nn=new node();
    nn->data=val;
    nn->succ=NULL;     
    nn->prev=NULL;
    if(head==NULL)
    {
            head=nn;
           
            return;
    }
    else
    {nn->succ=head;
     head->prev=nn;
     head=nn;
    }
   }
   void insertbot(int val)
    {
    node *nn=new node();
    nn->data=val;
    nn->top=NULL;     
    nn->bot=NULL;
    if(head1==NULL)
    {
            head1=nn;
           
            return;
    }
    else
    {
	 nn->top=head1;
     head1->bot=nn;
     head1=nn;
    }
   }
   void insertend(int val)
   {
    node *nn=new node();
    nn->data=val;
    nn->succ=NULL;
    nn->prev=NULL;
    if(head==NULL)
    {
            head=nn;
            return;
    }
    node *temp=head;
    while(temp->succ!=NULL)
    { temp=temp->succ;
    }
    
    temp->succ=nn;
    nn->prev=temp;
    
   }
   void inserttop(int val)
   {
    node *nn=new node();
    nn->data=val;
    nn->top=NULL;
    nn->bot=NULL;
    if(head1==NULL)
    {
            head1=nn;
            return;
    }
    node *temp=head1;
    while(temp->top!=NULL)
    { temp=temp->top;
    }
    
    temp->top=nn;
    nn->bot=temp;
    
   }
   void deletebeg()
   {
         node *temp;
       if(head==NULL)
       {cout<<" the list is empty. u can't delete";
        return;
     }
       temp=head;
       head=head->succ;
       head->prev=NULL;
       cout<<"the deleted item is "<<temp->data;
       delete(temp);
   }
  void deletebot()
   {
       node *temp;
       if(head1==NULL)
       {
	    cout<<" the list is empty. u can't delete";
        return;
       }
       temp=head1;
       head1=head1->top;
       head1->bot=NULL;
       cout<<"the deleted item is "<<temp->data;
       delete(temp);
   }
   void deleteend()
   {
       node  *temp=head;
       while(temp->succ!=NULL)
                temp=temp->succ;
   (temp->prev)->succ=NULL;
   cout<<"the deleted item is "<<temp->data;
   delete(temp);
   }
   void deletetop()
   {
       node  *temp=head1;
       while(temp->top!=NULL)
            temp=temp->top;
   
   (temp->bot)->top=NULL;
   cout<<"the deleted item is "<<temp->data;
   delete(temp);
   }
   
   void display()
   {
       node *temp=head;
       node *dup=head1;
       cout<<"elements from left to right\n";
       while(temp!=NULL)
       {
           cout<<temp->data<<" ";
           temp=temp->succ;
       }
       cout<<"\n";
       cout<<"elements from top to bottom\n";
       while(dup!=NULL)
       {
       	   cout<<dup->data<<"\n";
       	   dup=dup->top;
	   }
   }
   void insertmiddle(int val)
   {int n;
       node *nn=new node();
    nn->data=val;
    nn->succ=NULL;
    nn->prev=NULL;
    if(head==NULL)
    {
            head=nn;
            return;
    }
    cout<<"enter the number of nodes after which you want to insert this\n";
    cin >>n;
    node *temp=head;
    int count=1;
    while(count<n && temp->succ!=NULL)
    {
      temp=temp->succ;
      count++;
    }
    nn->succ=temp->succ;
    (temp->succ)->prev=nn;
    temp->succ=nn;
    nn->prev=temp;
   }
   void insertcenter(int val)
   {
    int n;
    node *nn=new node();
    nn->data=val;
    nn->top=NULL;
    nn->bot=NULL;
    if(head1==NULL)
    {
            head1=nn;
            return;
    }
    cout<<"enter the number of nodes after which you want to insert this\n";
    cin >>n;
    node *temp=head1;
    int count=1;
    while(count<n && temp->top!=NULL)
    {
      temp=temp->top;
      count++;
    }
    nn->top=temp->top;
    (temp->top)->bot=nn;
    temp->top=nn;
    nn->top=temp;
   }
   void deletemiddle()
   {int delval;
        node *temp=head;
        cout<<"enter the node value that u want to delete\n";
        cin>>delval;
        while(temp->data!=delval&&temp->succ!=NULL)
            temp=temp->succ;
     if(temp->data!=delval)
    {cout<<"there is no such node in the list";
      return;
    }
     (temp->prev)->succ=temp->succ;
     (temp->succ)->prev=temp->prev;
     cout<<"deleted item is "<<temp->data;
     delete(temp);
   }
   void deletecenter()
   {
       int delval;
       node *temp=head1;
        cout<<"enter the node value that u want to delete\n";
        cin>>delval;
        while(temp->data!=delval&&temp->top!=NULL)
            temp=temp->top;
     if(temp->data!=delval)
    {
	  cout<<"there is no such node in the list";
      return;
    }
     (temp->bot)->top=temp->top;
     (temp->top)->bot=temp->bot;
     cout<<"deleted item is "<<temp->data;
     delete(temp);
   }
};
int main()
{
    int choice,val;
    node obj;
    do
    {
    
    cout<<"enter ur choice 1-insert in the beg 2-insert at the end  3-insert at the bottom 4-insert at the top  5-insertmiddle 6-insert center\n.......";
    cin>>choice;
    switch(choice)
    {
        case 1: cout<<"enter the value u want to insert";
                cin>>val;
                obj.insertbeg(val);
                break;
        case 2: cout<<"enter the value u want to insert";
                cin>>val;
                obj.insertend(val);
                break;
        case 3: cout<<"enter the value u want to insert";
                cin>>val;
                obj.insertbot(val);
                break;
        case 4: cout<<"enter the value u want to insert";
                cin>>val;
                obj.inserttop(val);
                break;
        case 5: cout<<"enter the value u want to insert";
                cin>>val;
                obj.insertmiddle(val);
                break;
        case 6: cout<<"enter the value u want to insert";
                cin>>val;
                obj.insertcenter(val);
                break;
        case 7:obj.deletebeg();
               break;
        case 8:obj.deleteend();
               break;
        case 9:obj.deletebot();
               break;
        case 10:obj.deletetop();
               break;
        case 11: obj.deletemiddle();
                break;
        case 12: obj.deletecenter();
                break;
        case 13: obj.display();
                break;
        
    }
  }while(choice!=14);
}
