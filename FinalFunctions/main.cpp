#include <iostream>
#include <cstdlib>
#include<ctime>
#include <algorithm> // Для бфстрой sort


// Вывод массмива в консоль
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

// Заполнение масива случайными числами
template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (left - right) + left;
}

//Задача 1 Тип данных
void type_of(int num) { std::cout << "INT\n"; }
void type_of(double num) { std::cout << "double\n"; }
void type_of(char num) { std::cout << "char\n"; }
void type_of(float num) { std::cout << "float\n"; }

// Задача 1 Рекурсивная сумма диапазона от N до M

int sum_AB(int A, int B) { // Сумма чисел от 6...9  это сумм от 6...8 + 9, сумм 6..7+8 и тд. Отог обратно 6+7=13 +8 = 21
	if (A > B) {
		std::cout << "Неправильно ввели диапазон \n";
		std::swap(A, B);
	}
	if (A == B)
		return A;
	return sum_AB(A, B - 1) + B;

}
// Задача 3 Сортировка серидины       Создадим ее шаблонной Значит template <typename T>
template <typename T>
void middle_sort(T arr[], const int length) {
	int first_index = 0,last_index = 0;
	for(int i = 0; i < length; i++) 
		if (arr[i] < 0) {
			first_index = i;
			break;
		}
	for(int i = length -1; i > 0; i--)
		if (arr[i] < 0) {
			last_index = i;
			break;
		}
	//Быстрая сортировка 
	/*if(first_index != last_index)
	   std::sort(arr + first_index + 1, arr + last_index);*/

	//Пузырьковая сортировка
	for (int i = last_index - 1; i > first_index + 1; i--) {
		for (int j = first_index; i < j; j++)
			if (arr[j] > arr[i + 1])
				std::swap(arr[j], arr[j + 1]);
	}

}

// Задача 4 Сдвиг массива на одну позицию
template <typename T>
void  move_arr(T arr[], const int length) {
	
		for (int i = 0; i < length; i++)
		  for (int j = length - 1; j > 0; j--)
			if (arr[j] > arr[i + 1])
				std::swap(arr[j], arr[j - 1]);
}


int main() {
	setlocale(LC_ALL, "Rus");
	int n, m;

	// Задача 1 Тип данных
	/*std::cout << "Задача 1\n";
	std::cout << "7    -"; type_of(7);
	std::cout << "5.5  -"; type_of(5.5);
	std::cout << "\'A\'  - "; type_of('A');
	std::cout << "5.5F -"; type_of(5.5F);
	std::cout << std::endl;*/

	// Задача 2 Рекурсивная сумма диапазона от N до M
	/*std::cout << "Введите начало диапазона -> ";
	std::cin>> n;
	std::cout << "Введите конец диапазона -> ";
	std::cin >> m;
	std::cout << "Сумма чисел от "<< n << " до "<< m << ": "<<sum_AB(n,m)<<'\n';*/

	// Задача 3 Сортировка серидины
	/*std::cout << "Задача 3. \nИзначальный массив: \n";
	const int size3 = 10;
	int arr3[size3];
	fill_arr(arr3, size3, -20, 21);
	print_arr(arr3, size3);
	std::cout << "Итоговый массив: \n";
	middle_sort(arr3, size3);
	print_arr(arr3, size3);
	std::cout << std::endl;*/

	// Задача 4 Сдвиг массива
	std::cout << "Задача 4. \nИзначальный массив: \n";
	const int size4 = 5;
	int arr4[size4]{ 1, 2, 3 ,4, 5 };
	print_arr(arr4, size4);
	move_arr(arr4, size4);
	std::cout << "Итоговый массив: \n";
	print_arr(arr4, size4);
	std::cout << std::endl;

	return 0;
}