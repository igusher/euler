#include<iostream>

using namespace std;

void main()
{
	char letters[10] = {'0','1','2','3','4','5','6','7','8','9'};
	bool taken[10] = {0,0,0,0,0,0,0,0,0,0};
	unsigned int permutations[10] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
	int target = 1000000-1;
	for(int i = 9; i >= 1; i--)
	{
		int id = target / permutations[i];
		target -= (id * permutations[i]);
		
		for(int j = 0; j <10 ; j++)
		{
			if(!taken[j])
			{	
				if(id == 0)
				{
					cout<<letters[j];
					taken[j] = 1;
					break;
				}
				id--;

			}
		}
		
	}
	for(int j = 0; j <10 ; j++)
		if(!taken[j])		
			cout<<letters[j];
}