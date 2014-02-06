#include<fstream>
#include<iostream>
#include<stdio.h>

using namespace std;

int prod(char* buffer, int len);

void main()
{
	ifstream fin("input.txt");
	int i;
	int frameSize = 5;
	int n = 1000;
	char buffer[6];
	fin.get(buffer, 6);
	int resultProd = prod(buffer, frameSize);
	int lastChar = 0;
	char c;
	int newProd = 0;
	for(i = frameSize; i < 1000; i++)
	{
		c = fin.get();
		buffer[lastChar] = c;
		lastChar = (lastChar + 1) % frameSize;
		newProd = prod(buffer, frameSize);
		if(newProd > resultProd)
			resultProd = newProd;
		
	}
	cout << resultProd << endl;
	fin.close();
}

int prod(char* buffer, int len)
{
	int prod = 1;
	for(int i = 0; i < len; i++)
		prod *= (buffer[i] - '0');
	return prod;
}
