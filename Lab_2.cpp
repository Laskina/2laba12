/*Данные о файле представлены структурой с полями: каталог, имя файла, расширение, дата и время создания,
атрибуты (только на чтение, скрытый, системный), признак удаления, количество выделенных секторов (размер сектора фиксирован константой).
Поиск по каталогу, названию, дате, признаку удаления.
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "HelpUtils.h"
#include "Operation.h"
#include "File.h"
using namespace std;

int Menu()
{
	cout << " --------------------Меню---------------------  " << endl;
	cout << "1 - Добавить элемент" << endl;
	cout << "2 - Удалить элемент" << endl;
	cout << "3 - Изменить элемент" << endl;
	cout << "4 - Вывод на экран" << endl;
	cout << "5 - Сохранить в файл " << endl;
	cout << "6 - Линейный поиск" << endl;
	cout << "7 - Двоичный поиск" << endl;
	cout << "8 - Вывести подможество на экран" << endl;
	cout << "9 - Сохранить подмножество в файл" << endl;
	cout << "0 - Выход" << endl;
	int n = InputNumber(0, 9, "Ваш выбор: ");
	cout << "\n";
	return n;
}

bool ChangeInputData()
{
	Task<File> task;
	bool change = true;
	cout << " --------------------Меню---------------------  " << endl;
	cout << "1 - Заполнение контейнера с консоли" << endl;
	cout << "2 - Заполнение контейнера из файла " << endl;
	cout << "0 - Выход" << endl;
	int changemenu = InputNumber(0, 2, "Ваш выбор: ");
	switch (changemenu)
	{
	case 1:
		task.ReadFromScreen(InputScreenFile);
		break;

	case 2:
		change = task.ReadFromFile(ReadFromString);
		break;

	default:
		change = false;
		break;
	}
	if (change)
	{
		File elem;
		vector<File> subset;
		File search_elem;
		int num;
		while (1)
		{
			int n = Menu();
			switch (n)
			{
			case 1:
				task.Add(InputScreenFile());
				break;
			case 2:
				task.OutputScreen(task.vect, OutputScreenFile);
				task.Remove(InputNumber(0, task.size(), "Введите номер удаляемого элемента (0 для отмены): "));
				break;
			case 3:
				task.OutputScreen(task.vect, OutputScreenFile);
				num = InputNumber(0, task.size(), "Введите номер изменяемого элемента (0 для отмены): ");
				if (num != 0)
					task.vect[num - 1] = elem.ChangeFile(task.vect[num - 1]);
				break;
			case 4:
				task.OutputScreen(task.vect, OutputScreenFile);
				break;
			case 5:
				task.OutputFile(task.vect, ToString);
				break;
			case 6:
				num = InputNumber(1, 4, "Выберите тип поиска:\n 1 - по типу процессора\n 2 - по объему ОЗУ\n 3 - по объему видеопамяти\n 4 - по объему жесткого диска\nВаш выбор: ");
				search_elem = InputChangeTypeSearch(num);
				subset = task.LinearySearch(search_elem, SearchElement, num);
				if (subset.size() != 0)
					task.OutputScreen(subset, OutputScreenFile);
				else
					cout << "Элементы не найдены" << endl;
				break;
			case 7:
				num = InputNumber(1, 4, "Выберите тип поиска:\n 1 - по типу процессора\n 2 - по объему ОЗУ\n 3 - по объему видеопамяти\n 4 - по объему жесткого диска\nВаш выбор: ");
				search_elem = InputChangeTypeSearch(num);
				subset = task.BinarySearch(num, search_elem, Sort, SearchElement);
				if (subset.size() != 0)
					task.OutputScreen(subset, OutputScreenFile);
				else
					cout << "Элементы не найдены" << endl;
				break;
			case 8:
				task.OutputScreen(subset, OutputScreenFile);
				break;
			case 9:
				task.OutputFile(subset, ToString);
				break;
			default:
				cout << "Выход" << endl;
				exit(0);
				break;
			}
		}
	}
	system("pause");
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ChangeInputData();
	return 0;
}

