#include <iostream>

using namespace std;
int maxChain = 0;
int resultP = 0;
int main()
{
	int nextChain = 0;
	for(int p = 1 ; p < 1000; p++)
	{
		nextChain = 0;
		for(int a = 2 ; a < p/3 ; a++)
		{
			for(int b = a +1 ; b < ((p-a)/2); b++)
			{
				int c = p - a - b;
				if( c*c == a*a + b*b)
				{
					nextChain ++;
				}
			}
		}
		if(maxChain < nextChain)
		{
			maxChain = nextChain;
			resultP = p;
		}
	}

	cout <<maxChain<< " " << resultP <<endl;
	return 0;
}