//TOWERS OF HANOI
#include<iostream>
using namespace std;
void TowersofHanoi(int n, char A,char C, char B) 
{   if(n<1)
      return;
    if (n == 1) 
    { 
    cout << "Move disk 1 from rod " <<A << " to rod " << C<<"\n"; 
     return;
    } 
    TowersofHanoi(n - 1, A, B, C); 
    cout << "Move disk " << n <<" from rod " <<A <<" to rod " << C<<"\n"; 
    TowersofHanoi(n - 1, B, C, A); 
}
int main()
{
	int n;
	cout<<"enter the value of n";
	cin>>n;
	TowersofHanoi(n,'A', 'C', 'B');
	return 0;
}
