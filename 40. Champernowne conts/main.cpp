#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int prod = 1;
	for(int d = 1 ; d <= 1000000; d *= 10)
	{
		int temp = d-1;
		for(int dg = 1; dg <= 6; dg++)
		{
			if(temp < dg * (pow(10.,dg) - pow(10., dg-1)))
			{

				int elem = temp / dg;
				temp %= dg;
				elem = pow(10.,dg-1)+elem;
				int result = (int)(elem/pow(10., dg - temp - 1)) % 10;
				prod *= result;
				break;
			}
			temp -= dg * pow(10.,dg-1)*9;

		}
	}

	cout <<prod<<endl;
	return 0;
}