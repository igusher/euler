#include<iostream>
using namespace std;

void main()
{
	unsigned int sum;
	int digits[10];
	unsigned int resultSum = 0;
	for(int i = 1; i<10; i++)
	{
		cout << i << ": " << i * pow(9.,5) << " - " << pow(10.,i)<<endl;
		if(i * pow(9.,5)  < pow(10.,i))
			break;
	}
	
	for(int i = 2 ; i < 354294; i++)
	{
		unsigned int tempSum = 0;
		int tempNum =i;
		while(tempNum > 0)
		{
			tempSum += pow(double(tempNum % 10), 5);
			tempNum/=10;
		}
		if(tempSum == i)
		{
			cout << i << endl;
			resultSum += i;
		}
	}
	cout <<" Sum: " << resultSum << endl;
}