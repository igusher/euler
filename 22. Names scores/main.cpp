#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;

int compare(const void* a, const void* b)
{
	string * ac = (string*)a;
//	int len1 = strlen(ac);
	string * bc = (string*)b;
/*	int len2 = strlen(bc);
	int len = min(len1,len2);
	for(int i = 0 ; i < len1; i++)
	{
		if(ac[i] - bc[i] != 0)
			return ac[i] - bc[i];
	}
	return len2-len1;
*/
	return strcmp(ac->c_str(), bc->c_str());
}

int main()
{
	ifstream fin("names.txt");

	unsigned long long result = 0;
	char * buffer = new char[20];
	string arr[6000];
	int size = 0;
	while(fin.getline(buffer,20,','))
	{
		int wordSize = strlen(buffer)-1;
		
		arr[size] = string(buffer+1);
		
		arr[size][wordSize-1] = 0;
		size++;
	}
	//sort(
//	sort(&arr[0],&arr[2], compare);
//	qsort(arr,size,sizeof(char*),compare);
	qsort(arr,size,sizeof(string),compare);
	for(int i = 0 ; i < size ;i++)
	{
		if(strcmp(arr[i].c_str(),"COLIN")==0)
			cout<<"";
		int p1 = 0;
		for(int j = 0 ; j < arr[i].size()-1; j++)
		{
			p1 += arr[i][j] - 'A' +1;
		}
		result += (i+1)* p1;
	}
	cout<<result;
	fin.close();
}