#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "russian");

	int n, funk(int);
	cout << "������� N ����� ������������������ ���������: ";
	cin >> n;
	int a = 0, b = 1;
	cout << "\n";
	unsigned int start_time = clock();
	cout << n << " ������� ������������������ ��������� ����� " << funk(n) << "\n\n\n";
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << "����� ���������� ��������: " << search_time << " ��.\n\n\n" << endl;
	return 0;
}
int funk(int n) {
	if (n <= 3) {
		if (n == 3) {
			return 1;
		}
		if (n == 2) {
			return 1;
		}
		if (n == 1) {
			return 0;
		}
	}
	return funk(n - 1) + funk(n - 2);
}