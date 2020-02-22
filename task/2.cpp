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

//функция поиска
int search (int array[], int left, int right, int k) 
{
    int mid = 0;
    while(1)
    {
        mid = (left + right) / 2;
        
        if (k < array[mid]) {
            right = mid - 1;
        } else if (k > array[mid]) {
            left = mid + 1;
        } else {
            return mid;
        }
        if (left > right) {
            return -1;
        }
    }
}

//основная функция
int main()
{
    int k = 0; //искомый элемент
    int index = 0; //индекс искомого элемента
    cin >> n;
    
	int *array = new int[n];
	srand(time(NULL));
	cout << "Данный массив: ";
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % 100;
		cout << array[i] << " ";
	}
	first = 0; last = n-1;
	sort(array, first, last);
	cout << endl << "Отсортированный массив: ";
	for (int i = 0; i < n; i++)
	{
	     cout << array[i] << " ";
	}
    cout << "\n\nВведите любое число: ";
    cin >> k;
    index = search (array, 0, n, k);
    
    if (index >= 0) 
    {
        cout << "Указанное число находится в ячейке с индексом: " << index;
    } else {
        cout << "В массиве нет такого числа.";
    }
    
    return 0;
}
