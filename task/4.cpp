#include <iostream>
 
using namespace std;
 
//функция нахождения факториала
int factorial(int n)
{
	int F = 1;
	for(int i = 1; i <= n; ++i)
	{
		F *= i;
	}
	return F;
}
 
int main()
{
	int n;
	cout << "Введите n = ";
	cin >> n;
	
	if (n >= 0)
	{
		cout << factorial(n); 
	}
	else
	{
		cout << "Error: n < 0.";
	}
	
	return 0;
}