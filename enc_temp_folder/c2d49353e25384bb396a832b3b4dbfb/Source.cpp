#include <iostream>//include-це директива препроцесора, яка говорить препроцесору включати головні файли
// в програму.iostream - Для читання або запису в стандартні потоки вводу-виводу
using namespace std;//підключаємо всі імена з простору імен std
#include <Windows.h> // підключення заголовного файлу Windows.h//ф-ція для обмена значення комірок
#define SIZE 10 // визначення константи SIZE=10


void inputVoid(int* arr, int size) {
	cout << "Згенерований масив: \n";	
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		//cout << "Введіть " << i + 1 << " елемент масиву: ";
		arr[i] = 1 + rand() % 1'000;
		cout << arr[i] << " | ";
	}
	cout << endl;
}

//ф-ція для обмена значення комірок
void swapEl(int* arr, int i) 
{
	int buff;
	buff = arr[i];
	arr[i] = arr[i - 1];
	arr[i - 1] = buff;
}

//ф-ція для бінарного пошуку
int binarySearch(int* arr, int size, int key)
{
	int left = 0;
	int right = size - 1;
	int midd;
	
	while (1) {
		midd = (left + right) / 2;
		
		if (key < arr[midd]) {
			right = midd - 1;
		}
		else if (key > arr[midd]) {
			left = midd + 1;
			
		}
		else {
			return midd;
		}
		if (left > right)
		{
			return -1;
		}
		


	}

}
//ф-ція "шейкер"-сортування
void myShakerSort(int* arr, int size)
{
	int leftMark = 1;
	int rightMark = size - 1;

	while (leftMark <= rightMark)
	{	

		for (int i = rightMark; i >= leftMark; i--)
			
			if (arr[i - 1] > arr[i]) swapEl(arr, i); // виклик ф-ції для обміну значень "<" за зростанням
		leftMark++;


		for (int i = leftMark; i <= rightMark; i++)
			
			if (arr[i - 1] > arr[i]) swapEl(arr, i);
		rightMark--;

		cout << "\nІтерація: " << leftMark - 1; // кількість ітерацій
	}
}

// Відсортувати масив за допомогою бульбашкового сортування
void bubbleSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swapEl(arr, j + 1);
			}
		}
	}
}

int main()// вхідна точка програми
{
	SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
	SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення
	
	int A[SIZE] = {};// масив
	inputVoid(A, SIZE); // виклик ф-ції для введення елементів масиву

	short choice;
	cout << "\n1. Бульбашкове сортування\n2. Шейкерне сортування\nВиберіть вид сортування: ";
	cin >> choice;

	switch (choice)
	{
		case 1:
			bubbleSort(A, SIZE); // сортування
		case 2:
			myShakerSort(A, SIZE); // сортування
	default:
		break;
	}

	//bubbleSort(A, SIZE); // сортування
	//myShakerSort(A, SIZE); // сортування

	cout << "\n3. Масив після сортування:\n";
	for (int k = 0; k < SIZE; k++)
	{
		cout << A[k] << " | ";
	}

	int key;
	cout << "\n\nВведіть ключ для пошуку: ";
	cin >> key;

	int result = binarySearch(A, SIZE, key);
	(result == -1)
		? cout << "Неамє"// виклик ф-ції для пошуку елемента
	: cout << "Індекс вашого шуканого числа:" << result; // виклик ф-ції для пошуку елемента

	delete[] A; // видалення масиву
	system("pause");
	return 0;
}
