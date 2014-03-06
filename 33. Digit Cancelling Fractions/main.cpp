#include<iostream>
#include<math.h>
#include<cmath>

using namespace std;

int main()
{
	// copunt of 2 3 5 7
	int primes[4] = {2,3,5,7};
	int numerator[10] = {0,0,0,0,0,0,0,0,0,0};

	long long prod = 1;
	for(int a = 11; a <= 50; a++)
	{
		if ( a % 10 == a/10) continue;
		if (a % 10 == 0) continue;
		for(int i = 0 ; i < 2 ; i++)
		{
			int d1 = a / pow(10,i) ;
			d1 %= 10;
			for( int d2 = d1 + 1; d2 <= 9; d2++)
			{
				int b = a / pow(10, 1-i);
				b%=10;
				int b1 = b*10 + d2;
				int b2 = d2*10 + b;
				if(((a * d2 == b1 * d1 ) ||
					(a * d2  == b2 * d1 )))
					{
						cout << a << " " << d1 <<" " <<d2<<" " << b << " " <<b1<<" " <<b2<<endl;
						
						for(int p = 0 ; p < 4 ; ) 
						{
							if(d1%primes[p] != 0){ p++; continue;}
							
							numerator[primes[p]]++;
							d1/= primes[p];
						}
						for(int p = 0 ; p < 4 ; ) 
						{
							if(d2%primes[p] != 0){ p++; continue;}
							
							numerator[primes[p]]--;
							d2/= primes[p];
						}
						
						break;
					}
			}
		}
	}
	for(int p = 0 ; p < 4 ; p++) 
		if(numerator[primes[p]]<0)
			prod *= pow(primes[p], abs(numerator[primes[p]]));
								
	cout << prod;
	return 0;
}