#pragma once
class MyBigInt
{

public:
	unsigned int* val;
	int size;
	void resizeOne();
	void resize(int newSize);
public:
	MyBigInt(void);
	MyBigInt(unsigned int* val, int size);
	~MyBigInt(void);

	void add(unsigned int a);
	void add(MyBigInt * a);
	MyBigInt* shiftLeft(int sh);
	void add(unsigned int *, int);
	void mul(unsigned int m);
	void div(unsigned int divident, unsigned int & rem);
};

