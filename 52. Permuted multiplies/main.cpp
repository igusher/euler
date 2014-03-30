#include<iostream>

using namespace std;

void main()
{
	const int limit = 10000000;
	int digits;
	int nextDigits;
	for(int num  = 1 ; num < limit; num++)
	{
		int temp = num;
		digits = 0;
		while(temp >0)
		{
			digits+= 1 << (3*(temp % 10));
			temp/=10;
		}
		bool ok = true;
		for(int mul = 2 ; mul <= 6; mul++)
		{
			nextDigits = 0;
			int next = mul * num;
			while(next > 0)
			{
				nextDigits+= 1 << (3*(next % 10));
				next/=10;
			}
			if(nextDigits != digits)
			{
				ok = false;
				break;
			}
		}
		if(ok)
		{
			cout<<num<<endl;
			break;
		}
	}
}