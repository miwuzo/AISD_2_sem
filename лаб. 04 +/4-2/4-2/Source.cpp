#include <iostream>
#include <string>
using namespace std;

void sort(int* arr, int size)
{
	int min = arr[0];

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				min = arr[i];
				arr[i] = arr[j];
				arr[j] = min;
			}
		}
	}
}

bool isProved(string num)
{
	char nums[] = "0123456789";
	bool isNotNum = false;

	for (int i = 0; i < num.size(); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (num[i] == nums[j])
			{
				isNotNum = false;
				break;
			}
			else
			{
				isNotNum = true;
			}
		}

		if (isNotNum)
		{
			return false;
		}
	}

	return true;
}


void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	const int size = 3;
	string a = " ";
	int arr_b[size];

	int kol, j = 0;
	cout << "количество участников: ";

	getline(cin, a);

	while (true)
	{
		while (!isProved(a)) 
		{
			cout << "!!!!!!!!!!!!!! введите реальное количество !!!!!!!!!!!!!!!";
			getline(cin, a);
		}
		kol = stoi(a);

		if (kol > 0 && kol <= 10000)
		{
			break;
		}
		else
		{
			cout << "!!!!!!!!!!!!! введите реальное количество !!!!!!!!!!!!!!!!!! ";
			getline(cin, a);
		}
	}

	cout << "баллы: \n";
	int* arr = new int[kol];
	for (int i = 0; i < kol; i++)
	{
		arr[i] = rand() % 100 + 1;
		cout << arr[i] << " ";
	}

	sort(arr, kol);

	cout << "\n\nБаллы, с которыми участники получат дипломы: " << endl;

	if (kol > 3)
	{
		for (int i = kol - 1;; i--)
		{
			if (arr[i] != arr[i + 1])
			{
				arr_b[j] = arr[i];
				cout << arr_b[j] << " ";
				j++;

				if (j == 3)
				{
					break;
				}
			}
		}

		int kol_pr = 0;

		for (int i = 0; i < kol; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (arr[i] == arr_b[j])
				{
					kol_pr += 1;
				}
			}

		}
		cout << "\n\nКоличество призёров: " << kol_pr << endl << endl;
	}

	else
	{
		for (int i = 0; i < kol; i++)
		{
			cout << arr[i] << " ";
		}

		cout << "\n\nКоличество призёров: " << kol << endl << endl;
	}


	delete[] arr;
}