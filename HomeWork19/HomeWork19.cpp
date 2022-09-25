#include <iostream>
#include <cstdlib>
#include <ctime>
int common_divisor(int num1, int num2);
int mirror_number(int num);
template <typename T>
T SortArr_indexN(T arr[], int size, T n);
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end);
template <typename T>
void show_arr(T arr[], const int length);
template <typename T>
void fill_AtoB_arr(T arr[], const int lenght, T A, T B);
int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	//������ 1
	//	�������� �������, ������� ��������� ��� ����� �	���������� �� ���������� ����� ��������.
	
	std::cout << "������ 1\n������� ��� �����:";
	std::cin >> n >> m;
	std::cout << "���������� �������� ������ ����� = " << common_divisor(n, m) << "\n\n";
	
	//������ 2
	//�������� ������� mirror_number, ������� ��������� ����� � ���������� ��� � ��������� ����.
	std::cout << "������ 2\n������� ����� �� 1 �� 999-999:\n";
	std::cin >> n;
	std::cout << mirror_number(n) << "\n\n";
	
	//������ 3
	//	�������� �������, ������� ��������� ������, ���	����� � ����� N.������� ���������� ������ �������
	//	����� N � �������, � ����� ��������� ��� ��������, ������� ��������� ������ �� N.
	srand(time(NULL));
	const int size = 10;
	int array[size];
	std::cout << "������ 3\n��������� ������:\n";
	fill_arr(array, size, 0, 10);
	show_arr(array, size);
	std::cout<<"������� ����� �� �������:";
	std::cin >> n;
	std::cout << "������ ������� ������������ ��������� ����� = " << SortArr_indexN(array, size, n);
	std::cout<< "\n�������������� ������:\n";
	show_arr(array, size);
	
	//������ 4
	//	�������� �������, ������� ��������� ������ ������, ��� ����� � ��� ����� A � B, ������� ��������
	//	������� � ������ ���������.������� ������ ��������� ������ ���������� ������� �� ����������	���������
	const int size4 = 10;
	int arr4[size4];
	std::cout << "������� ��� ����� � �������� ������� ���������� ������:";
	std::cin >> n >> m;
	fill_AtoB_arr(arr4,size4,n,m);
	std::cout << "������ � ��������� ����� �� " << n << " �� " << m << ":\n";
	show_arr(arr4, size4);
	return 0;
}
//������ 1
//������� ���������� ����� ��������
int common_divisor(int num1, int num2) {
	int divisor = 1;
	if (num1 / 2 > num2 / 2) {
		divisor = num2 / 2;
		for (int i = divisor; i > 0; i--)
			if (num1 % i == 0 && num2 % i == 0)
				return i;
	}
	else {
		divisor = num1 / 2;
		for (int i = divisor; i > 0; i--)
			if (num1 % i == 0 && num2 % i == 0)
				return i;
	}
	return 1;
}
//������ 2
//���������� ����� � ��������� �����
int mirror_number(int num) {
	int divider = 1;
	const int size2 = 6;
	int arr[size2]{ 0,0,0,0,0,0 };
	for (int i = size2-1; i > 0; i--) {
		arr[i] = num / divider % 10;
		divider *= 10;
	}	
	for (int j = 0; j < size2 - 1; j++) {
		if (arr[0] != 0)
			break;
		for (int i = 0; i < size2 - 1; i++)
			std::swap(arr[i], arr[i + 1]);
	}
	num = 0;
	divider = 1;
	for (int i = 0; i < size2; i++) {
		num += arr[i] * divider;
		divider *= 10;
	}
	
	return num;
}
//������ 3
//���������� �������
template <typename T>
T SortArr_indexN(T arr[], int size, T n) {
	int FirstIndex = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] == n) {
			FirstIndex = i; break;
		}
	for (int i = size - 1; i > 0; i--)
		for (int j = FirstIndex + 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
	return FirstIndex;
}
//���������� �������
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}
//����� �������
template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
//������ 4
//��������� ������� � ��������� �� A �� B
template <typename T>
void fill_AtoB_arr(T arr[], const int lenght, T A, T B) {
	if (A > B)
		std::swap(A, B);
	srand(time(NULL));
	for (int i = 0; i < lenght; i++)
		arr[i] = A+rand()%(B-A);
}