#include <iostream>
#include <ctime>
using namespace std;

int main() {

	setlocale(LC_ALL, "russian");

	int n;
	cout << "������� N ����� ������������������ ���������: ";
	cin >> n;
	cout << "\n";
	int a = 0, b = 1, c;
	unsigned int start_time = clock();
	if (n <= 3) {
		if (n == 1) {
			cout << n << " ������� ������������������ ��������� ����� " << a << "\n\n\n";
		}
		if (n == 2) {
			cout << n << " ������� ������������������ ��������� ����� " << b << "\n\n\n";
		}
		if (n == 3) {
			cout << n << " ������� ������������������ ��������� ����� " << b << "\n\n\n";
		}
	}
	else {
		for (int i = 4; i <= n + 1; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		cout << n << " ������� ������������������ ��������� ����� " << b << "\n\n";
	}
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << "����� ���������� : " << search_time << " ��.\n\n\n" << endl;
	return 0;
}
