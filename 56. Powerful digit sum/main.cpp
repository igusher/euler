#include<iostream>
#include"..\Common\MyBigInt.cpp"
using namespace std;

void main()
{
	const int limit = 100;
	int maxSum = 0;
	int ra=0;
	int rb = 0;
	for(int a = 2; a < limit; a++)
	{
		cout<<a;
	
		for(int b = 2; b < limit;b++)	
		{
			MyBigInt myBigInt;
			myBigInt.add(a);
			myBigInt.pow(b);

			int sum = myBigInt.sumOfDigits();
			if(maxSum < sum)
			{
				ra = a;
				rb = b;
				maxSum = sum;
			}
				
		}
	}

	cout <<endl;
	cout <<ra<<" " <<rb<< " "<< maxSum << endl;
}