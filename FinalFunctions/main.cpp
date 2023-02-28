#include <iostream>
#include <cstdlib>
#include<ctime>
#include <algorithm> // ��� ������� sort


// ����� �������� � �������
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

// ���������� ������ ���������� �������
template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (left - right) + left;
}

//������ 1 ��� ������
void type_of(int num) { std::cout << "INT\n"; }
void type_of(double num) { std::cout << "double\n"; }
void type_of(char num) { std::cout << "char\n"; }
void type_of(float num) { std::cout << "float\n"; }

// ������ 1 ����������� ����� ��������� �� N �� M

int sum_AB(int A, int B) { // ����� ����� �� 6...9  ��� ���� �� 6...8 + 9, ���� 6..7+8 � ��. ���� ������� 6+7=13 +8 = 21
	if (A > B) {
		std::cout << "����������� ����� �������� \n";
		std::swap(A, B);
	}
	if (A == B)
		return A;
	return sum_AB(A, B - 1) + B;

}
// ������ 3 ���������� ��������       �������� �� ��������� ������ template <typename T>
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
	//������� ���������� 
	/*if(first_index != last_index)
	   std::sort(arr + first_index + 1, arr + last_index);*/

	//����������� ����������
	for (int i = last_index - 1; i > first_index + 1; i--) {
		for (int j = first_index; i < j; j++)
			if (arr[j] > arr[i + 1])
				std::swap(arr[j], arr[j + 1]);
	}

}

// ������ 4 ����� ������� �� ���� �������
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

	// ������ 1 ��� ������
	/*std::cout << "������ 1\n";
	std::cout << "7    -"; type_of(7);
	std::cout << "5.5  -"; type_of(5.5);
	std::cout << "\'A\'  - "; type_of('A');
	std::cout << "5.5F -"; type_of(5.5F);
	std::cout << std::endl;*/

	// ������ 2 ����������� ����� ��������� �� N �� M
	/*std::cout << "������� ������ ��������� -> ";
	std::cin>> n;
	std::cout << "������� ����� ��������� -> ";
	std::cin >> m;
	std::cout << "����� ����� �� "<< n << " �� "<< m << ": "<<sum_AB(n,m)<<'\n';*/

	// ������ 3 ���������� ��������
	/*std::cout << "������ 3. \n����������� ������: \n";
	const int size3 = 10;
	int arr3[size3];
	fill_arr(arr3, size3, -20, 21);
	print_arr(arr3, size3);
	std::cout << "�������� ������: \n";
	middle_sort(arr3, size3);
	print_arr(arr3, size3);
	std::cout << std::endl;*/

	// ������ 4 ����� �������
	std::cout << "������ 4. \n����������� ������: \n";
	const int size4 = 5;
	int arr4[size4]{ 1, 2, 3 ,4, 5 };
	print_arr(arr4, size4);
	move_arr(arr4, size4);
	std::cout << "�������� ������: \n";
	print_arr(arr4, size4);
	std::cout << std::endl;

	return 0;
}