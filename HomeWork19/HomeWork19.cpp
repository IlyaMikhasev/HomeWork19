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
	//Задача 1
	//	Создайте функцию, которая принимает два числа и	возвращает их наибольший общий делитель.
	
	std::cout << "Задача 1\nВведите два числа:";
	std::cin >> n >> m;
	std::cout << "Наибольший делитель данных чисел = " << common_divisor(n, m) << "\n\n";
	
	//Задача 2
	//Напишите функцию mirror_number, которая принимает число и возвращает его в отражённом виде.
	std::cout << "Задача 2\nВведите число от 1 до 999-999:\n";
	std::cin >> n;
	std::cout << mirror_number(n) << "\n\n";
	
	//Задача 3
	//	Создайте функцию, которая принимает массив, его	длину и число N.Функция возвращает первую позицию
	//	числа N в массиве, а также сортирует все элементы, которые находятся справа от N.
	srand(time(NULL));
	const int size = 10;
	int array[size];
	std::cout << "Задача 3\nНачальный массив:\n";
	fill_arr(array, size, 0, 10);
	show_arr(array, size);
	std::cout<<"Введите число из массива:";
	std::cin >> n;
	std::cout << "Индекс первого расположения выбраного числа = " << SortArr_indexN(array, size, n);
	std::cout<< "\nОтсортированый массив:\n";
	show_arr(array, size);
	
	//Задача 4
	//	Создайте функцию, которая принимает пустой массив, его длину и два числа A и B, которые являются
	//	началом и концом диапазона.Функция должна заполнять массив случайными числами из указанного	диапазона
	const int size4 = 10;
	int arr4[size4];
	std::cout << "Введите два числа в пределах которых заполнится массив:";
	std::cin >> n >> m;
	fill_AtoB_arr(arr4,size4,n,m);
	std::cout << "Массив в диапазоне чисел от " << n << " до " << m << ":\n";
	show_arr(arr4, size4);
	return 0;
}
//задача 1
//Находит наибольший общий делитель
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
//Задача 2
//Возвращает число в зекальном ввиде
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
//Задача 3
//Сортировка массива
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
//Заполнение массива
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}
//вывод массива
template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
//Задача 4
//Запонение массива в диапазоне от A до B
template <typename T>
void fill_AtoB_arr(T arr[], const int lenght, T A, T B) {
	if (A > B)
		std::swap(A, B);
	srand(time(NULL));
	for (int i = 0; i < lenght; i++)
		arr[i] = A+rand()%(B-A);
}