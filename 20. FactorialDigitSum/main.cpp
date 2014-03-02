#include <iostream>
#include "MyBigInt.h"

using namespace std;

void main ()
{
	unsigned long long sum =0;
	char * buff = new char[1000];
	int buffSize = 0;
	MyBigInt * bigInt = new MyBigInt();
	bigInt->add(1);
	unsigned int rem;
	
	for(int i = 2 ; i <= 100; i++)
	{
		bigInt->mul(i);
	}
	//bigInt->mul(21);

	while((bigInt->val[0] != 0) || (bigInt->size > 1))
	{
		
		bigInt->div(10, rem);
		sum+=rem;
		buff[buffSize++] = '0' + rem;
	}
	buff[buffSize] = 0;
	strrev(buff);
	cout<<sum << endl;
	cout<<buff;
	cout<<endl;
	for(int i = 0 ; i< bigInt->size; i++)
	{
		cout << bigInt->val[i] << endl;
	}
 	delete bigInt;
}
