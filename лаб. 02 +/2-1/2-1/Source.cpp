#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
		char otvet;
		int N;
			cout << " ������� ����� N \n";
			cin >> N;
			cout << " ��������� ����� �� 1 �� N \n";

			int a = 1;
			int X = N / 2, kolichestvo = 0, polov = N / 2;
			while (a != 2) {
				
				cout << " � ����� ��� �����: " << X << "\n";
				cout << "1 - ������ \n";
				cout << "2 - ������ \n";
				cout << "3 - ������ \n";
				cin >> otvet;
				

				kolichestvo = kolichestvo + 1;
				if (otvet == '1') {
					if (kolichestvo == 1) {
						X = polov - polov / 2;
						polov = polov / 2;
					}
					else {
						X = X - polov;
					}
					if (polov == 0) {
						X = X - 1;
					}
				}
				if (otvet == '2') {
					if (kolichestvo == 1) {
						X = polov + polov / 2;
						polov = polov / 2;
					}
					else {
						X = X + polov;
					}
					if (polov == 0) {
						X = X + 1;
					}
				}
				if (otvet == '3') {
					a = 2;
				}
				polov = polov / 2;
			}

			int max_shag = 0, pol = N;
			while (pol != 0) {
				pol = pol / 2;
				max_shag = max_shag + 1;
			}
			

			cout << "���������� \n";
			cout << " �� �������� ����� " << X << "\n";
			
			cout << " ������������ ���������� ����� ��������� ������ =  " << max_shag << "\n";

			while (N > 1) {
				cout << N << endl;
				N = N - N / 2;
			}
		}