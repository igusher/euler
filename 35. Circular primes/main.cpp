#include<iostream>
#include<math.h>
#include"..\Common\utils.h"
#include"..\Common\utils.cpp"

using namespace std;

const int size = 1000000;

//'2' is already counted
long long count = 1;

int main()
{
//	//bool visited[size];
//	memset(visited, 0, sizeof(visited));
	for(int i = 3 ; i <= size ; i+=2)
	{
		//if(visited[i]) continue;
		
		if(!primes::isPrime(i)) continue;
		if(i == 101)
			cout<<"";
		count ++;
		int digits = log10(double(i))+1;
		int temp = i;
		bool flag = true;
		for(int c = 0 ; c < digits; c++)
		{
			integers::rotateLeft(temp, digits);
			if(!primes::isPrime(temp))
			{
				count --;
				flag = false;
				break;
			}
		}
		if(flag)
			cout<<i<<endl;
	}
	cout << "res: " << count << endl;
	return 1;
}