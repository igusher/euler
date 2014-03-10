#include<iostream>
#include"..\Common\utils.cpp"

#include<math.h>

using namespace std;

bool panDig(int num)
{
	int digits = log10((double)num)+1;
	int res = 0;
	while(num >0)
	{
		res += 1 << ((num %10) -1);
		num /=10;
	}
	if( res == ((1 << digits) - 1))
		return true;

	return false;

}

int main()
{
	for(int i = 7654321; i>1; i-=2)
	{

		if((panDig(i)) && (primes::isPrime(i)))
		{
			panDig(i);
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}