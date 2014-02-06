#include<iostream>
#include<stdio.h>

using namespace std;

bool isLeapYear(int );

void main()
{
	int monthes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int start = 0;
	for(int m = 0; m < 12; m++)
	{
		start += monthes[m];
	}
	start %=7;
	
	int result = 0;
	for(int y = 1901; y < 2001; y++)
	{
		monthes[1] = 28;
		if((isLeapYear(y)) || (y == 2000))
			monthes[1] = 29;
		for(int m = 0; m < 12; m++)
		{
			if(start == 0)
				result++;
			start = ( start + monthes[m]) % 7;
		}
	}

	cout << result;
}

bool isLeapYear(int year)
{
	return (year % 4) == 0;
}