#include<iostream>
#include<unordered_set>
#include"..\Common\utils.cpp"

using namespace std;

const int primesCount = 10000;
int primeDiv[primesCount];

int primeDivCount(int num)
{
	if(primes::isPrime(num))
		return 1;

	int divCount = 0;
	for(int d = 0 ; (d < primesCount) && (num >= primeDiv[d]); d++)
	{
		bool isDiv = false;

		while(num % primeDiv[d] == 0)
		{
			num /= primeDiv[d];
			isDiv = true;
		}
		if(isDiv)
			divCount++;
	}

	return divCount;
}

void main()
{
	int consecNum = 0;
	int targetConNums = 4;
	int targetDivCount = 4;
	int num = 2*3*5*7;
	
	primes ::eratosthenes(primeDiv, primesCount);

	timer::start();
	for(; consecNum < targetConNums ; num++)
	{
		if(primeDivCount(num) < targetDivCount)
		{
			consecNum=0;
		}
		else
		{
			consecNum++;
		}
	}

	cout<<timer::finish()<<endl;
	cout << num - targetConNums << endl;
}