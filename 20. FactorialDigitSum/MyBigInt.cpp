#include "MyBigInt.h"
#include <memory.h>
#include <math.h>

MyBigInt::MyBigInt(void)
{
	size = 1;
	val = new unsigned int[1];
	val[0] = 0;
}

MyBigInt::MyBigInt(unsigned int * val, int size)
{
	this->val = new unsigned int[size];
	memcpy(this->val, val, sizeof(unsigned int) * size);
	this->size = size;
}


MyBigInt::~MyBigInt(void)
{
	delete [] val;
}



void MyBigInt::add(unsigned int a)
{
	unsigned long long rem = a;
	int i = 0;
	do
	{
		rem += val[i];
		val[i] = (long)rem & 0xFFFFFFFFFFFFFFFF;
		rem =  rem >> (long)32;
		i++;
	}while(rem != 0 && i < size);
	if ((rem >0) && (i == size))
	{
		resizeOne();
		val[size-1] = rem;
	}
}

void MyBigInt::add(MyBigInt * a)
{
	if(a->size > this->size)
		resize(a->size);
	else
		if (a->size < this->size)
			a->resize(this->size);
	//assume len <= size
	unsigned long long rem = 0;//a[0];
	int i = 0;
	do
	{
		rem += (unsigned long long) a->val[i];
		rem += (unsigned long long) val[i];
		val[i] = (int)rem;
		rem =  rem >> 32;
		i++;
	}while( i < size);
	if ((rem >0) && (i == size))
	{
		resizeOne();
		val[size-1] = rem;
	}
}

void MyBigInt::mul(unsigned int m)
{
	MyBigInt * tempBigInt = new MyBigInt();
	int i = 0;
	while(m>0)
	{	
		
		if((m&1) == 1)
		{ MyBigInt * tt = this->shiftLeft(i);
			tempBigInt->add(tt);
		}
		i++;
		m >>= 1;
	}
	this->val=tempBigInt->val;
	this->size = tempBigInt->size;
}

void MyBigInt::div(unsigned int divident, unsigned int & rem)
{
	unsigned long long  local_rem = 0;
	for(int i = size - 1 ; i >= 0 ; i--)
	{
		local_rem = local_rem << 32;
		local_rem+= val[i];
		val[i] = local_rem / divident;
		
		local_rem = local_rem % divident;
	}
	if(val[size - 1] == 0) size--;
	rem = 0xFFFFFFFF & local_rem;
}

MyBigInt* MyBigInt::shiftLeft(int sh)
{
	if(sh == 0 )
	{
		return new MyBigInt(val,size);
	}
	//sh < 32
	unsigned int * result;
	int newSize = size;
	if((val[size - 1] >> (32- sh) ) > 0)
	{
		newSize+=1;
		result = new unsigned int[newSize];
		memset(result, 0, sizeof(result));
		result[newSize-1] = val[size-1] >> (32 - sh);
	}
	else
	{
		result = new unsigned int[newSize];
	}
	unsigned long rem = 0;
	for(int i = 0 ; i < size; i++)
	{
		result[i] = (val[i] << sh) | rem;
		rem = val[i] >> (32-sh);
	}
	return new MyBigInt(result, newSize);
}

void MyBigInt::resizeOne()
{
	this->resize(size+1);
}

void MyBigInt::resize(int newSize)
{
	unsigned int* newVal = new unsigned int[newSize];
	memcpy(newVal,val,sizeof(int)*size);
	memset(newVal + size, 0 , sizeof(int) * (newSize - size));
	size = newSize;
	delete [] val;

	val = newVal;

	
}
