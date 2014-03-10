namespace primes{
	void eratBool(bool * primes, int limit);
	int eratLimit(int * primes, int limit, int size);
	void eratosthenes(int * primes, int size);

	
	bool completePrimeTest(int prime, int* divisors, int len);

	bool isPrime(int num);
}

namespace search{
	int binarySearch(int * arr, int size, int elem);
	int binarySearch(int * arr, int size, int l, int r, int elem);
}

namespace integers{
	void rotateLeft(int &num, int digits);
}