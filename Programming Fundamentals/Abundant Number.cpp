#include<iostream>
using namespace std;
int main()
{
	int num,div,sum=0;
	cout<<"Enter a Number: "; cin>>num;
	for(int i=1;i<num;i++)
	{
		div=num%i;
		if(div==0)
		{
			sum+=i;
		}
	}
	if(sum>num)
	{
		cout<<"The Number is Abundant: "<<endl;
	}
	else
	cout<<"The Number is Not Abundant: "<<endl;

}
