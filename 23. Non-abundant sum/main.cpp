#include<iostream>
#include<fstream>
#include<vector>
#include <math.h>

using namespace std;

bool isAbundant(int);
void printDivisors(int);
ofstream fout ("out.txt");

void main()
{
	vector<int> abNums;
	const int limit = 28125;
	bool abNumSums[limit+1];
	memset(abNumSums, 1, sizeof(bool)*limit+1);

	for(int i = 12; i <= limit ; i++)
	{
		if(isAbundant(i))
		{
			abNums.push_back(i);
			fout << i <<": ";
			printDivisors(i);
			fout<<endl;
		}
	}

	for(int i = 0 ; i <abNums.size(); i++)
	{
		for(int j = i ; j < abNums.size(); j++)
		{
			int id = abNums[i]+abNums[j];
			if (id < limit)
			{
				if(id == 21)
					cout<<"";
				abNumSums[id] = 0;
			}
			else
				break;
			
		}
	}
	unsigned long sum = 0;
	for(int i = 1 ; i <limit; i++)
	{
		if(abNumSums[i])
			fout<<i<<endl;
		//if abNumSums[i] == true:
		sum += i * abNumSums[i];
	}
	cout<<sum;

	fout.close();
}

bool isAbundant(int num)
{
	unsigned int sumOfDiv = 1;
	for(int i = 2; i <= sqrt((float)num);i++)
	{
		if((num % i) == 0)
		{
			sumOfDiv += i;
			if(i != num/i)
				sumOfDiv += num/i;
		}
	}

	return sumOfDiv > num;
}

void printDivisors(int num)
{
	unsigned int sumOfDiv = 1;
	for(int i = 2; i <= num/2 ;i++)
	{
		if((num % i) == 0)
		{sumOfDiv+=i;
			fout << i<< " ";
		}
	}
	fout<<" - " << sumOfDiv;

}