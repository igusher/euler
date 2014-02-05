#include<iostream>
#include<stdio.h>

using namespace std;

void main()
{
	//limit - 4 mlns
	int limit = 4000000;
	long sum = 0;
	int a1 = 1;
	int a2 = 2;
	int prevA1 = 1;
	do{
		sum += a2;
		prevA1 = a1;
		a1 = a1 + 2 * a2;
		a2 = a1 + prevA1 + a2;
	} while(a2 <= limit);

	cout << sum << endl;
}