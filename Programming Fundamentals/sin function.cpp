#include<iostream>
using namespace std;
int main()
{
  int n,fact,sign=-1;
  float x,p,sum = 0;
  cout<<"Enter the value of x : "; cin>>x;
  cout<<"Enter the value of n : "; cin>>n;
  for (int i=1;i<=n;i+=2)
  {
    	p=1;
    	fact=1;
    	for(int j=1;j<=i;j++)
    	{
     		 p=p*x;
     		 fact=fact*j;
    	}
    	sign=-1*sign;
    	sum+=sign*p/fact;
  }
  cout<<"sin("<<x<<") = "<<sum;
  return 0;
}
