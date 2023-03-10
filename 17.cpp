#include <iostream>
#include <vector>
using namespace std;
vector<int> Obchislennya(int SIZE)
{
	bool *isPrime = new bool[SIZE + 1];
	for (int i = 0; i < SIZE + 1; i++) {
		isPrime[i] = true;
	}
	for (int p = 2; pow(p,2) <= SIZE; p++) 
		if (isPrime[p]) 
			for (int i = pow(p,2); i <= SIZE; i += p) 
				isPrime[i] = false;

	vector<int> prime;
	for (int i = 2; i <= SIZE; i++) 
		if (isPrime[i]) 
			prime.push_back(i);
	
	delete[] isPrime;
	return prime;
}
bool check(int A[], int P, int N)
{
	if (A[0] % P == 0)
		return 0;

	for (int i = 1; i < N; i++)
		if (A[i] % P)
			return 0;

	if (A[N - 1] % (P * P) == 0)
		return 0;

	return 1;
}
bool checkIrreducibilty(int A[], int N)
{
	int M = -1;

	for (int i = 0; i < N; i++) {
		M = max(M, A[i]);
	}

	vector<int> primes
		= Obchislennya(M + 1);

	for (int i = 0;
		i < primes.size(); i++) {

		if (check(A, primes[i], N)) {
			return 1;
		}
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "Ukr");
	const int SIZE = 4;
	int arr[4] = { 4, 7, 21, 28 }; // стандартні значення
	//cout << "Введіть значення: ";
	/*for (int i = 0; i < SIZE; i++) {
		cin >> arr[i];
	}*/
	cout << checkIrreducibilty(arr, SIZE);
}
