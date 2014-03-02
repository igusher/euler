#include <iostream>


using namespace std;

void main()
{
	int maxRecLen = 0;
	int* remainder = new int[1000];
	int divident = 1000;
	int maxLen = 0;
	int maxD = 0;
	for(int i = 133 ; i < 1000; i++)
	{
		divident = 1000;
		if((i-1)/divident > 0)
			divident *= 10;
		memset(remainder, 0, sizeof(int) * divident);
		int nextLen = 0;
		divident/=10;
		while(true)
		{
			divident *=10;
			nextLen++;
			if(divident < i)
				continue;

			int rem = divident % i;
			if(rem == 0)
			{
				nextLen = 0;
				break;
			}
			if(remainder[rem]>0)
			{
				nextLen = nextLen - remainder[rem];
				break;
			}
			remainder[rem] = nextLen;
			divident=rem;
			
		}

		if(maxLen < nextLen)
		{
			maxLen = nextLen;
			maxD = i;
		}
	}
	cout << maxD <<endl;
	cout<<maxLen; 
}