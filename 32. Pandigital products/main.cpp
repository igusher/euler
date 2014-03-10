#include <iostream>
#include<math.h>
#include<memory.h>
using namespace std;

int main() {
	// your code goes here
	long long sum = 0;
	bool panDN[10000];
	memset(panDN, 1, sizeof(bool)*10000);
	int limitA = 330;
	for(int a = 2 ; a <= limitA; a++)
	{
		int digitsA = log10 (a) +1;
		int limitB = (9 - digitsA) / 2;
		limitB = pow(10, limitB) ;
			
		for(int b = a+1; b <= limitB; b++)
		{
			int digitsB = log10 (b) +1;
			int c = a * b;
			if((a==39)&&(b==186))
				cout << " c = " << c << endl;
			int digitsC = log10 (c) +1;
			if(digitsA + digitsB + digitsC == 9)
			{
				int result = 0;
				int temp  = a * pow(10, 9 - digitsA)+
							b * pow(10, 9 - digitsA -digitsB)+
							c;
				if((a==39)&&(b==186))
					cout << " temp = " << temp << endl;
				while(temp > 0)
				{
					result += 1 << (temp%10 - 1);
					temp /= 10;
				}
				if((a==39)&&(b==186))
					cout << " result = " << result << endl;
				if (result == 0x1FF)
				{
					if(panDN[c])
					{
						sum +=c;
						panDN[c] = 0;
					}
						
				}
			}
		}
	}
	cout << sum;
	return 0;
}