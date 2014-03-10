#include<iostream>
#include<fstream>

using namespace std;

const int size = 80;

unsigned long long  twoWays(unsigned long long matrix[size][size]);
unsigned long long threeWays(unsigned long long matrix[size][size]);
//unsigned long long fourWays(unsigned long long matrix[size][size])

int  main()
{
	//ifstream fin("matrix.txt");
	ifstream fin("matrix3.txt");
	////ifstream fin("test.txt");
	//ifstream fin("test3.txt");
	unsigned long long matrix[size][size];
	
	for(int i  = 0; i < size ; i++)
	{
		for(int j = 0; j < size ; j++)
		{
			fin >> matrix[i][j] ;
		}
	}

	

	unsigned long long result = threeWays(matrix);
	cout<<result<<endl;
	

	fin.close();
}

unsigned long long twoWays(unsigned long long matrix[size][size])
{
	for(int i = 1; i < size ; i++)
	{
		matrix[i][0] = matrix[i][0] + matrix[i-1][0];
		matrix[0][i] = matrix[0][i] + matrix[0][i-1];
	}

	for(int i  = 1; i < size ; i++)
	{
		for(int j = 1; j < size ; j++)
		{
			matrix[i][j] = min(matrix[i-1][j], matrix[i][j-1])+matrix[i][j];
		}
	}
	return matrix[size-1][size-1];

}


unsigned long long threeWays(unsigned long long matrix[size][size])
{
	unsigned long long mTemp[size][size];
	//memset(mTemp,1, sizeof mTemp);
	for(int i = 0 ; i < size; i++)
	{
		mTemp[i][0] = matrix[i][0];
	}
	for(int j = 1; j < size ; j++)
	{
		for(int i = 0 ; i < size ; i++)
			mTemp[i][j] = mTemp[i][j-1] + matrix[i][j];
		for(int i = 1 ; i < size ; i++)
			mTemp[i][j] = min(mTemp[i][j], mTemp[i-1][j] + matrix[i][j]);
		for(int i = size-2 ;  i>=0 ; i--)
			mTemp[i][j] = min(mTemp[i][j], mTemp[i+1][j] + matrix[i][j]);
	}

	unsigned long long min = mTemp[0][size-1];
	for(int j = 1; j < size; j++)
	{
		if(min > mTemp[j][size-1])
			min = mTemp[j][size-1];

	}


	return min;
}

unsigned long long fourWays(unsigned long long matrix[size][size])
{

}