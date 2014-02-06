#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

void main()
{
	ifstream fin("input.txt");
	const int size = 15;
	int field[16][16];
	memset(field, 0 , sizeof(int) * 16 * 16); 
	for(int i = 1 ; i <= size; i++)
	{
		for(int j = 1 ; j <= i; j++)
		{
			fin >> field[i][j];
			field[i][j] += max(field[i-1][j-1], field[i-1][j]);
		}
	}
	int i = 15;
	int max = field[i][1];
	for(int j = 2 ; j <= size; j++)
	{
		if(field[i][j] > max)
			max = field[i][j];
	}

	cout << max;
	fin.close();
}