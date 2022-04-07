#include<iostream>
#include<conio.h>
using namespace std;
void dijkstra(int source,int dest);
int d[6],p[6];
int i,j,n;
int a[6][6]={{0,15,10,99999,45,99999},{99999,0,15,99999,20,99999},{20,99999,0,20,99999,99999},{99999,10,99999,0,35,99999},{99999,99999,99999,30,0,99999},{99999,99999,99999,4,99999,0}
	};
int main()
{   int source,dest;
    
    for(source=0;source<6;source++)
    {  for(dest=0;dest<6;dest++)
       {
       dijkstra(source,dest);
       if(d[dest]==99999)
         cout<<dest<<"not reachable from"<<source<<"\n";
       else
       {
           cout<<"shortest path ";
           i=dest;
           while(i!=source)
           { cout<<i<<"<--";
             i=p[i];
           }
           cout<<i<<"="<<d[dest]<<"\n";
       }
       }
    }
    getch();
    return 0;
}
void dijkstra(int source,int dest)
{int i,u,v,s[6],min;
     for(i=0;i<6;i++)
     {
       d[i]=a[source][i];
       s[i]=0;
       p[i]=source;
     }
     s[source]=1;
     for(i=1;i<6;i++)
     {
         min=99999;
         u=-1;
         for(j=0;j<6;j++)
         {
           if(s[j]==0)
           {
             if(d[j]<min)
             {
               min=d[j];
               u=j;
             } 
           }     
         }
         if(u==-1)
           return;
         s[u]=1;
         if(u==dest)
           return;
         for(v=0;v<6;v++)
         {
           if(s[v]==0)
           {  if(d[u]+a[u][v]<d[v])
              { d[v]=d[u]+a[u][v];
                p[v]=u;
              }
           }
         }
     }
}   

