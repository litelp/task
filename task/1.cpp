#include <iostream>
#include <ctime>

using namespace std;

int n; //количество элементов в массиве
int first, last; 

//функция сортировки
void sort(int *mas, int first, int last) 
{
	int middle, count;
	int f = first, l = last;
	middle = mas[(f + l) / 2]; //вычисление опорного элемента
	do 
	{
		while (mas[f] < middle) f++;
		while (mas[l] > middle) l--;
		if (f <= l) 
		{ 
			count = mas[f]; //перестановка элементов
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	}
	while (f < l);
	if (first < l) sort(mas, first, l);
	if (f < last) sort(mas, f, last);
}

//основная функция
int main()
{
	cin >> n;
	int *A = new int[n];
	srand(time(NULL));
	cout << "Данный массив: ";
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 100;
		cout << A[i] << " ";
	}
	first = 0; last = n-1;
	sort(A, first, last);
	cout << endl << "Отсортированный массив: ";
	for (int i = 0; i < n; i++) cout << A[i] << " ";
	return 0;
}