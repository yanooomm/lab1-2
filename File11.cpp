/*File11  Дан файл вещественных чисел. Создать два новых файла,
первый из которых содержит элементы исходного файла с нечетными
номерами, а второй - с четными.*/

#include <iostream>
#include <fstream>

using namespace std;

struct num
{
	float number;
};

int main()
{
	setlocale(LC_ALL, "rus");
	/*записываем числа в файл
	ofstream out;
	// создаем главный файл
	struct num s;
	int n;
	cout << "Введите количество чисел" << endl;
	cin >> n;
	out.open("num.bin", ofstream::binary); //открываем бинарный файл
	for (int i = 0; i < n; i++)
	{
		cin >> s.number;
		out.write((char*)&s, sizeof(struct num)); //записываем числа в файл
	}
	out.close();// закрываем файл*/


	// читаем числа из созданного ранее файла
	ifstream in;
	int length, n;
	in.open("num.bin", ifstream::binary);
	if (!in.is_open())
	{
		cout << "Ошибка при открытии файла";
		return 0;
	}
	in.seekg(0, ios::end);
	length = in.tellg();
	in.seekg(0, ios::beg);
	n = length / sizeof(num);
	if (n == 0)
	{
		cout << "файл пустой";
		return 0;
	}
	if (n == 1)
	{
		ofstream file1;
		struct num s;
		file1.open("num1.bin", ofstream::binary);
		in.read((char*)&s, sizeof(num));
		file1.write((char*)&s, sizeof(num));
		file1.close();
	}
	else
	{
		ofstream file1;
		ofstream file2;
		file2.open("num1.bin", ofstream::binary);
		file1.open("num2.bin", ofstream::binary);
		struct num s;
		for (int i = 0; i < n; i++)
		{
			in.read((char*)&s, sizeof(num));
			if (i % 2 == 0)
			{
				file1.write((char*)&s, sizeof(num));
			}
			else
			{
				file2.write((char*)&s, sizeof(num));
			}
		}
		file2.close();
		file1.close();
	}
	in.close();