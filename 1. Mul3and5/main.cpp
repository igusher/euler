#include<iostream>
#include<stdio.h>

using namespace std;

void main()
{
	//input 
	int n = 1000;
	int m1 = 3;
	int m2 = 5;

	n--;
	int m12 = m1 * m2;
	int n1 = n / m1;
	int n2 = n / m2;
	int n12 = n / m12;

	int s1 = n1 * (m1 * (n1 + 1) / 2.);
	int s2 = n2 * (m2 * (n2 + 1) / 2.);
	int s12 = n12 * (m12 * (n12 + 1) / 2.);

	int result = s1 + s2 - s12;
	cout << result;
}