#include<fstream>
#include<iostream>

using namespace std;

void main()
{
	ifstream fin("input.txt");
	short result[53];
	memset(result,0,53*sizeof(short));
	const int numLength = 50;
	const int countOfNums = 100;
	char number[numLength+1];
	for(int i = 0 ; i < countOfNums ; i++)
	{
		fin.getline(number,51,'\n');
		for(int j = numLength - 1; j>=0; j--)
		{
			int remainder = number[j] - '0';
			int remId = numLength - j - 1;
			while(remainder != 0)
			{
				int temp = result[remId] + remainder;
				result[remId] = temp % 10;
				remainder = temp / 10;
				remId++;
			}
		}
	}
	int start = 52;
	while(result[start] == 0) start--;
	for(int i = 0 ; i < 10; i++)
	{
		cout<< result[start - i];
	}
	cout << endl;

	fin.close();
}