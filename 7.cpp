#include<iostream>
#include<unordered_map>
using namespace std;

int StepinMod(int x, int y, int p)
{
	int result = 1; 
	x = x % p; 
	do
	{
		if (y & 1) {
			result = (result * x) % p;
		}
		y = y >> 1;
		x = (x * x) % p;
	} while (y);
	return result;
}

int Diskretniy_Lohorifm(int a, int b, int m) {

	unordered_map<int, int> znachennya;
	int step = (int)sqrt(m) + 1;
	for (int i = step; i >= 1; --i) {
		znachennya[StepinMod(a, i * step, m)] = i;
	}
	for (int j = 0; j < step; ++j)
	{
		int cur = (StepinMod(a, j, m) * b) % m;
		if (znachennya[cur])
		{
			int ans = znachennya[cur] * step - j;
			if (ans < m)
				return ans;
		}
	}
	return -1;
}

int main()
{
	setlocale(LC_ALL, "Ukr");
	int a, b, m;
	cout << "Введіть a: ";
	cin >> a;
	cout << "Введіть b: ";
	cin >> b;
	cout << "Введіть m: ";
	cin >> m;
	cout << Diskretniy_Lohorifm(a, b, m) << endl;
}
