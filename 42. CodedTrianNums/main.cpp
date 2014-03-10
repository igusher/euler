#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;
int triangle(int n)
{
	return n * (n+1) / 2;
}

bool isTriangle(int num)
{
	int n = (sqrt((double)(1 + 8*num)) - 1) / 2;
	return triangle(n) == num;
}

int wordCost(char * buffer, int len)
{
	int result = 0;
	for(int i = 0 ; i < len; i++)
	{
		if(buffer[i] >='A' && buffer[i] <= 'Z')
			result += buffer[i] - 'A' + 1;
	}
	return result;
}

int main()
{
	int count = 0;
	ifstream fin("words.txt");
	char buffer[30];
	while(fin.getline(buffer,29,','))
	{
		int cost = wordCost(buffer, strlen(buffer));
		if(isTriangle(cost))
			count++;
	}

	cout << count;
	fin.close();
}