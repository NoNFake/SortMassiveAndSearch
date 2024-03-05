#include <iostream>//include-�� ��������� ������������, ��� �������� ������������ �������� ������ �����
// � ��������.iostream - ��� ������� ��� ������ � ��������� ������ �����-������
using namespace std;//��������� �� ����� � �������� ���� std
#include <Windows.h> // ���������� ����������� ����� Windows.h//�-��� ��� ������ �������� ������
#define SIZE 10 // ���������� ��������� SIZE=10


void inputVoid(int* arr, int size) {
	cout << "������������ �����: \n";	
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		//cout << "������ " << i + 1 << " ������� ������: ";
		arr[i] = 1 + rand() % 1'000;
		cout << arr[i] << " | ";
	}
	cout << endl;
}

//�-��� ��� ������ �������� ������
void swapEl(int* arr, int i) 
{
	int buff;
	buff = arr[i];
	arr[i] = arr[i - 1];
	arr[i - 1] = buff;
}

//�-��� ��� �������� ������
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
//�-��� "������"-����������
void myShakerSort(int* arr, int size)
{
	int leftMark = 1;
	int rightMark = size - 1;

	while (leftMark <= rightMark)
	{	

		for (int i = rightMark; i >= leftMark; i--)
			
			if (arr[i - 1] > arr[i]) swapEl(arr, i); // ������ �-��� ��� ����� ������� "<" �� ����������
		leftMark++;


		for (int i = leftMark; i <= rightMark; i++)
			
			if (arr[i - 1] > arr[i]) swapEl(arr, i);
		rightMark--;

		cout << "\n��������: " << leftMark - 1; // ������� ��������
	}
}

// ³���������� ����� �� ��������� ������������� ����������
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

int main()// ������ ����� ��������
{
	SetConsoleCP(1251); // ������������ ��������� Windows-1251 �  ���� ��������
	SetConsoleOutputCP(1251); // ������������ ��������� Windows-1251 �  ���� ���������
	
	int A[SIZE] = {};// �����
	inputVoid(A, SIZE); // ������ �-��� ��� �������� �������� ������

	short choice;
	cout << "\n1. ����������� ����������\n2. �������� ����������\n������� ��� ����������: ";
	cin >> choice;

	switch (choice)
	{
		case 1:
			bubbleSort(A, SIZE); // ����������
		case 2:
			myShakerSort(A, SIZE); // ����������
	default:
		break;
	}

	//bubbleSort(A, SIZE); // ����������
	//myShakerSort(A, SIZE); // ����������

	cout << "\n3. ����� ���� ����������:\n";
	for (int k = 0; k < SIZE; k++)
	{
		cout << A[k] << " | ";
	}

	int key;
	cout << "\n\n������ ���� ��� ������: ";
	cin >> key;

	int result = binarySearch(A, SIZE, key);
	(result == -1)
		? cout << "����"// ������ �-��� ��� ������ ��������
	: cout << "������ ������ �������� �����:" << result; // ������ �-��� ��� ������ ��������

	delete[] A; // ��������� ������
	system("pause");
	return 0;
}
