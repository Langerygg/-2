// ТИ№2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const bool cnst = 1, cnst2 = 0;

int main()
{
	system("chcp 1251");
	string in;
	int buffleng;
	cout << "Строка: ";
	getline(cin, in);
	do
	{
		cout << "Длина буфера поиска [2;32]: ";
		cin >> buffleng;
	} while (buffleng < 2 || buffleng > 32);
	struct Code
	{
		int offset = 0;
		int leng = 0;
		char symbol;
	};
	vector<Code> result;
	Code marker;
	marker.symbol = in[0];
	result.push_back(marker);
	int currentpos = 1;
	while (currentpos < in.length())
	{
		Code max;
		if (currentpos < buffleng) {
			for (int i = currentpos - 1; i >= 0; i--)
			{
				if (in[currentpos] == in[i]) {
					marker.offset = currentpos - i;
					marker.leng++;
					while (currentpos + marker.leng < in.length())
					{
						if (in[currentpos + marker.leng] == in[i + marker.leng])
							marker.leng++;
						else break;
					}
					if (currentpos + marker.leng + 1 < in.length())
						marker.symbol = in[currentpos + 1];
					marker.symbol = in[currentpos + marker.leng];
					if (marker.leng > max.leng)
					{
						max.offset = marker.offset;
						max.leng = marker.leng;
						max.symbol = marker.symbol;
					}
					marker.leng = 0;
				}
			}
			marker.leng = 0;
			if (max.leng == 0)
				max.symbol = in[currentpos];
			result.push_back(max);
		}
		else {
			for (int i = currentpos - 1; i >= currentpos - buffleng; i--)
			{
				if (in[currentpos] == in[i]) {
					marker.offset = currentpos - i;
					marker.leng++;
					while (currentpos + marker.leng < in.length())
					{
						if (in[currentpos + marker.leng] == in[i + marker.leng])
							marker.leng++;
						else break;
					}
					if (currentpos + marker.leng + 1 < in.length())
						marker.symbol = in[currentpos + 1];
					marker.symbol = in[currentpos + marker.leng];
					if (marker.leng > max.leng)
					{
						max.offset = marker.offset;
						max.leng = marker.leng;
						max.symbol = marker.symbol;
					}
					marker.leng = 0;
				}
			}
			marker.leng = 0;
			if (max.leng == 0)
				max.symbol = in[currentpos];
			result.push_back(max);
		}
		currentpos += max.leng + 1;
		marker.symbol = '\0';
	}
	for (int i = 0; i < result.size(); i++)
		cout << "\n" << result[i].offset << " " << result[i].leng << " " << result[i].symbol;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
