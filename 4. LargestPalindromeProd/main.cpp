#include<iostream>
#include<stdio.h>

bool isPalindrome(int);

void main()
{
	int n = 0;
	int result = 0;
	for(int i = 100 ; i < 1000; i++)
		for(int j = i; j < 1000; j++)
		{
			n = i * j;
			if (isPalindrome(n) && result < n)
			{
				result = n;		
			}
		}
	std::cout << result << std::endl;
}

bool isPalindrome(int num)
{
	int left = num / 1000;
	int right = num % 1000;
	int firstDigit = right % 10;
	int lastDigit = right / 100;
	right = right - firstDigit + lastDigit;
	right = right - lastDigit * 100 + firstDigit * 100;
	return right == left;
}