#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

void main()
{
	ifstream fin ("input.txt");
	int n = 20;
	int nums[20][20];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0 ; j < n ; j ++)
		{
			fin >> nums[i][j];
		}
	}
	int newProd = 1;
	int largestProd = -1;

	//find max product on a reverse diagonal
	for(int i = 0 ; i < n - 3; i++)
		for(int j = 3 ; j < n ;j++)
		{
			newProd = nums[i][j] * nums[i+1][j-1] * nums[i+2][j-2] * nums[i+3][j-3];
			largestProd= max(largestProd, newProd);
		}

	//find max product on main diagonal
	for(int i = 0 ; i < n - 3; i++)
		for(int j = 0 ; j < n -3 ;j++)
		{
			newProd = nums[i][j] * nums[i+1][j+1] * nums[i+2][j+2] * nums[i+3][j+3];
			largestProd= max(largestProd, newProd);
		}

	//find max product in one column
	for(int i = 0 ; i < n - 3; i++)
		for(int j = 0 ; j < n ;j++)
		{
			newProd = nums[i][j] * nums[i+1][j] * nums[i+2][j] * nums[i+3][j];
			largestProd = max(largestProd,newProd);
		}
	//find max product in a row
	for(int i = 0 ; i < n; i++)
		for(int j = 0 ; j < n -3 ;j++)
		{
			newProd = nums[i][j] * nums[i][j+1] * nums[i][j+2] * nums[i][j+3];
			largestProd = max(largestProd,newProd);
		}

	cout<< largestProd << endl;
	fin.close();

}