#include"..\20. FactorialDigitSum\MyBigInt.h"
#include<iostream>

using namespace std;

void main()
{
	unsigned int term = 2;
	unsigned int a =1;
	unsigned int next = 1;
	bool done = false;
/*	while(true)
	{
		next += a;
		//overflow
		if(next < a)
		{
			next -= a;
			break;
		}
		a = next - a;
		term++;
	}
	*/
	MyBigInt * nextBig = new MyBigInt();
	MyBigInt * aBig = new MyBigInt();
	nextBig->add(next);
	aBig->add(a);
	MyBigInt * tempBig = new MyBigInt();
	char buffer[1024];
	while(!done)
	{
		tempBig->set(nextBig);
		nextBig->add(aBig);
		aBig->set(tempBig);
		nextBig->toString(buffer, 1024);
		term++;
		if(strlen(buffer) >= 1000)
			done = true;
		//cout<<buffer<<endl;
	}
	
	//nextBig->toString(buffer, 1024);

	cout<<buffer<<endl;
	cout<<term<<endl;
}