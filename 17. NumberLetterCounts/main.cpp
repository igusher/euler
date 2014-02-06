#include<iostream>
#include<stdio.h>

using namespace std;

void main()
{
	//one, two, three, four, five, six, seven, eight, nine
	int units[10] = {0, 3,3,5,4,4,3,5,5,4};
	//eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen
	int secondDecade[10] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
	//twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety
	int tens[10] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
	int hundred = 7;
	int andcost = 3;
	int sum = 0;
	int num;
	for (int i = 1 ; i < 1000 ; i++)
	{
		num = i;
		//hundreds
		if ( num > 99)
		{
			sum += units[num/100] + hundred;
			if(num % 100 != 0)
				sum+= andcost;
		}
		num %= 100;
		
		if(num / 10 == 1)
		{
			sum += secondDecade[num % 10];
		}
		else
		{
			sum += tens[num / 10] + units[num % 10];
		}

	}

	//one thousand
	sum += 11;

	cout << sum << endl;
}