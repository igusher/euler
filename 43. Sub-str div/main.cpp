#include <iostream>

using namespace std;

int digits[] = {0, 1, 2, 3 ,4 ,5 ,6 ,7 ,8 ,9};
bool tookDigit[10] = {0,0,0,0,0,0,0,0,0,0};
int divisors[] = {13,11,7,5,3,2};

int nextNum[] = {0,0,0,0,0,0,0,0,0,0};
unsigned long long resultingSum = 0;

void sum()
{
	long long  num = 0;
	for(int i = 0 ; i < 10; i++)
	{
		cout<<nextNum[i];
		num *= 10;
		num += nextNum[i];
	}
	cout<<endl;
	resultingSum += num;
}

bool find(int num, int div , int digit)
{
	
	if(div == 6 )
	{
		for(int i = 0 ; i < 10 ; i ++)
			if(!tookDigit[i])
				nextNum[0] = i;
		if(nextNum[0] != 0)
			sum();
		return true;
	}

	int nextDiv = divisors[div];
	int remain = (nextDiv - (num / 10) % nextDiv) % nextDiv;
	
	for(int nextDig = 0 ; nextDig < 10; nextDig++)
	{
		int temp = num;

		if(!tookDigit[nextDig])
		{
			if ((nextDig * 100) % nextDiv == remain)
			{
				tookDigit[nextDig] = true;
				temp/=10;
				temp += 100 * nextDig;
				nextNum[digit] = nextDig;
				find(temp,div+1, digit-1);	
				tookDigit[nextDig] = false;
			}
		}
	}
	return false;
}

void main()
{
	for(int num = (100 / 17) * 17 + 17; num < 987; num+=17)
	{
		memset(tookDigit, 0, sizeof(bool)*10);
		memset(nextNum,0,sizeof(int)*10);
		int temp = num;

		int digit = 9;
		bool repeatingDigits = false;
		while(temp > 0)
		{
			int nextDig = temp % 10;
			nextNum[digit--] = nextDig;
			if(tookDigit[nextDig])
			{
				repeatingDigits=true;
				break;
			}
			tookDigit[nextDig] = true;
			temp/=10;
		}
		if(!repeatingDigits)
			find(num, 0, digit);
		
	}

	cout << resultingSum << endl;
}