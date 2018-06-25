#pragma once
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"

using namespace std;

//подтип дата
class MyDate {

	// проверка является ли год високосным
	bool IsLeap(int year)
	{
		if (year % 4)
			return false;
		if (year % 100)
			return true;
		return !(year % 400);
	}

	// проверка даты на корректность
	bool CorrectDate(int day, int month, int year, string &message) {

		// если год вискосный                            если не високосный
		if ((month == 2 && day > 29 && IsLeap(year)) || (month == 2 && day > 28 && !IsLeap(year)))
		{
			message = "Неверное кол-во дней в феврале!";
			return false;
		}
		//кол-во дней в месяце
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day > 30)
			{
				message = "Неверное кол-во дней в месяце!";
				return false;
			}
		}
	}
public:
	// день
	int day;
	// месяц
	int month;
	// год
	int year;

	// конструктор по умолчанию
	MyDate()
	{
		int day = 1;
		int month = 1;
		int year = 1970;
	}

	// ввод даты с консоли
	void InputDate()
	{
		bool correct_date = true; // корректна ли введенная дата
		string message = "";  // сообщение о причине ошибки
		do
		{
			if (!correct_date)
				cout << message << endl;
			day = InputNumber(1, 31, "Ввод даты:\nВведите день (1-31): ");
			month = InputNumber(1, 12, "Введите номер месяца (1-12): ");
			year = InputNumber(1970, 2100, "Введите год (1970-2100): ");
			correct_date = CorrectDate(day, month, year, message);
		} while (!correct_date);  // повторять ввод пока не корректная дата
	}

	// перевод даты в строку (для последующей записи в файл)
	string ToString()
	{
		return (to_string(day) + ' ' + to_string(month) + ' ' + to_string(year));
	}

	// перегруженный оператор равенства
	bool operator == (const MyDate &c)
	{
		return ((day == c.day) && (month == c.month) && (year == c.year));
	}

	// конструктор копирования
	MyDate& operator = (MyDate c)
	{
		day = c.day;
		month = c.month;
		year = c.year;

		return (*this);
	}

	// перегруженный оператор больше
	bool operator > (const MyDate &c)
	{
		return ((year > c.year) || ((year == c.year) && (month > c.month)) || ((year == c.year) && (month == c.month) && (day > c.day)));
	}

	// перегруженные оператор меньше
	bool operator < (const MyDate &c)
	{
		return ((year < c.year) || ((year == c.year) && (month < c.month)) || ((year == c.year) && (month == c.month) && (day < c.day)));
	}

};

class File {
public:
	//Название кататлога
	string catalog;
	//Имя файла
	string File_name;
	//Расширение файла
	string extension;
	//Дата и время создания
	MyDate Date_Time;
	//Атрибуты
	enum attribute { read_only, system, hidden };
	//Признак удаления
	bool sign_of_delete;
	//Кол-во секторов
	int count_sectors;

	//конструктор по умолчанию
	File()
	{
		string catalog = "";
		string File_name = "";
		string extension = "";
		MyDate Data_Time;
		sign_of_delete = false;
		int count_sectors = 0;
	}

	//Изменение структуры "Файл"
	File ChangeFile(File &result)
	{
		if (InputNumber(0, 1, "Вы хотите изменить каталог файла " + result.catalog + " (0 - нет, 1 - да) \nВаш выбор: ") == 1)
			result.catalog = InputInformation("Введите новый каталог файла: ");
		if (InputNumber(0, 1, "Вы хотите изменить имя файла " + result.File_name + " (0 - нет, 1 - да) \nВаш выбор: ") == 1)
			result.File_name = InputInformation("Введите новое имя файла: ");
		if (InputNumber(0, 1, "Вы хотите изменить расширение файла " + result.extension + " (0 - нет, 1 - да) \nВаш выбор: ") == 1)
			result.extension = InputInformation("Введите новое расширение файла: ");
		if (InputNumber(0, 1, "Вы хотите изменить дату и время создания " + result.Date_Time + " (0 - нет, 1 - да) \nВаш выбор: ") == 1)
			result.Date_Time.InputDate();
		if (InputNumber(0, 1, "Вы хотите изменить частоту процессора " + result.CPU_frequency + " (0 - нет, 1 - да) \nВаш выбор: ") == 1)
			result.CPU_frequency = InputInformation("Введите новую частоту процессора: ");
		if (InputNumber(0, 1, "Вы хотите изменить объем оперативной памяти " + to_string(result.capacity_RAM) + " (0 - нет, 1 - да) \nВаш выбор: ") == 1)
			result.capacity_RAM = InputNumber(0, 256, "Введите новый объем оперативной памяти (0-256): ");
		if (InputNumber(0, 1, "Вы хотите изменить объем жесткого диска " + to_string(result.capacity_HDD) + " (0 - нет, 1 - да) \nВаш выбор: ") == 1)
			result.capacity_HDD = InputNumber(0, 8192, "Введите новый объем жесткого диска (0-8.192): ");
		if (InputNumber(0, 1, "Вы хотите изменить объем памяти видеокарты " + to_string(result.capacity_GPU) + " (0 - нет, 1 - да) \nВаш выбор: ") == 1)
			result.capacity_GPU = InputNumber(0, 16, "Введите новый объем памяти видеокарты (0-16): ");
		if (InputNumber(0, 1, "Вы хотите изменить стоимость компьютера " + to_string(result.Cost) + " (0 - нет, 1 - да) \nВаш выбор: ") == 1)
			result.Cost = InputNumber(0, 1000000, "Введите новую стоимость компьютера (0-1.000.000): ");
		if (InputNumber(0, 1, "Вы хотите изменить количество экземпляров " + to_string(result.Count) + " (0 - нет, 1 - да) \nВаш выбор: ") == 1)
			result.Count = InputNumber(0, 100, "Введите новое количество экземпляров (0-100): ");
		return result;
	}

	//Перегруженный оператор равенства для структуры "Компьютер"
	File& operator = (File c)
	{
		File_ID = c.File_ID;
		File_name = c.File_name;
		type_of_CPU = c.type_of_CPU;
		CPU_frequency = c.CPU_frequency;
		capacity_RAM = c.capacity_RAM;
		capacity_HDD = c.capacity_HDD;
		capacity_GPU = c.capacity_GPU;
		Cost = c.Cost;
		Count = c.Count;

		return (*this);
	}

};

//Функция ввода структуры "Компьютер" с консоли
File InputScreenFile()
{
	File c;
	c.File_ID = InputNumber(0, 999999, "Введите код компьютера (0-999.999): ");
	c.File_name = InputInformation("Введите имя компьютера: ");
	c.type_of_CPU = InputInformation("Введите тип процессора: ");
	c.CPU_frequency = InputInformation("Введите частоту процессора: ");
	c.capacity_RAM = InputNumber(0, 256, "Введите объем оперативной памяти (0-256): ");
	c.capacity_HDD = InputNumber(0, 8192, "Введите объем жесткого диска (0-8.192): ");
	c.capacity_GPU = InputNumber(0, 16, "Введите объем памяти видеокарты (0-16): ");
	c.Cost = InputNumber(0, 1000000, "Введите стоимость компьютера (0-1.000.000): ");
	c.Count = InputNumber(0, 100, "Введите количество экземпляров (0-100): ");

	return c;
}

//Функция вывода структуры "Компьютер" на консоль
void OutputScreenFile(File c)
{
	cout << "Код компьютера: " << c.File_ID << endl;
	cout << "Имя марки компьютера: " << c.File_name << endl;
	cout << "Тип процессора: " << c.type_of_CPU << endl;
	cout << "Частота процессора: " << c.CPU_frequency << endl;
	cout << "Объем оперативной памяти: " << c.capacity_RAM << endl;
	cout << "Объем жесткого диска: " << c.capacity_HDD << endl;
	cout << "Объем памяти видеокарты: " << c.capacity_GPU << endl;
	cout << "Стоимость компьютера: " << c.Cost << endl;
	cout << "Количество экземпляров: " << c.Count << endl;
}


//извлечение структуры "дата" из строки 
// Формат:
// день месяц год
MyDate FromString(string str)
{
	MyDate result;
	try
	{
		istringstream is(str);
		string s;
		if (getline(is, s, ' '))
			result.day = atoi(s.c_str());
		if (getline(is, s, ' '))
			result.month = atoi(s.c_str());
		if (getline(is, s, ' '))
			result.year = atoi(s.c_str());
	}
	catch (...)
	{
		cout << "Ошибка записи в файл!" << endl;
	}
	return result;
}


//Перевод структуры "Компьютер" в строку
string ToString(File c, int i)
{
	string result = "Запись № " + to_string(i) + "\n" + "Код компьютера: " + to_string(c.File_ID) + "\n" + "Имя марки компьютера: " + c.File_name + "\n" + "Тип процессора: " + c.type_of_CPU + "\n" + "Частота процессора: " + c.CPU_frequency + "\n" + "Объем оперативной памяти: " + to_string(c.capacity_RAM) + "\n" + "Объем жесткого диска: " + to_string(c.capacity_HDD) + "\n" + "Объем памяти видеокарты: " + to_string(c.capacity_GPU) + "\n" + "Стоимость компьютера: " + to_string(c.Cost) + "\n" + "Количество экземпляров: " + to_string(c.Count) + "\n";
	return result;
}

//Считывание структуры "Компьютер" из строки
File ReadFromString(ifstream& input)
{
	File result;
	string s;
	try
	{
		if (!input.eof())
		{
			getline(input, s);
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Код компьютера: ";
			result.File_ID = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Имя компьютера: ";
			result.File_name = s.substr(wrd.length(), s.length()).c_str();
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Тип процессора: ";
			result.type_of_CPU = s.substr(wrd.length(), s.length()).c_str();
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Частота процессора: ";
			result.CPU_frequency = s.substr(wrd.length(), s.length()).c_str();
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Объем оперативной памяти: ";
			result.capacity_RAM = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Объем жесткого диска: ";
			result.capacity_HDD = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Объем памяти видеокарты: ";
			result.capacity_GPU = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Стоимость компьютера: ";
			result.Cost = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Количество экземпляров: ";
			result.Count = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
	}
	catch (...)
	{
		cout << "Ошибка записи в файл!" << endl;
	}
	return result;
}

//Поиск равного элемента по выбранному критерию
/*type_search - тип поиска
1 - тип процессора
2 - объем оперативной памяти
3 - объем памяти видеокарты
4 - объем жесткого диска*/
bool SearchElement(File first, File second, int type_search)
{
	switch (type_search)
	{
	case 1:
		return (first.type_of_CPU == second.type_of_CPU);
	case 2:
		return (first.capacity_RAM == second.capacity_RAM);
	case 3:
		return (first.capacity_GPU == second.capacity_GPU);
	case 4:
		return (first.capacity_HDD == second.capacity_HDD);
	default:
		return false;
	}
}

//Ввод критерия поиска в зависимости от выбранного типа
File InputChangeTypeSearch(int type_search)
{
	File result;
	switch (type_search)
	{
	case 1:
		result.type_of_CPU = InputInformation("Введите тип процессора: ");
		return result;
	case 2:
		result.capacity_RAM = InputNumber(0, 256, "Введите объем оперативной памяти(0 - 256) :");
		return result;
	case 3:
		result.capacity_GPU = InputNumber(0, 16, "Введите объем памяти видеокарты (0-16): ");
		return result;
	case 4:
		result.capacity_HDD = InputNumber(0, 8192, "Введите объем жесткого диска (0-8.192): ");
		return result;
	default:
		return result;
	}
}

//Сравнение структур в зависимости от выбранного поля для сортировки
int Sort(File first, File second, int type_search)
{
	switch (type_search)
	{
	case 1:
		if (first.type_of_CPU > second.type_of_CPU) return 1;
		else if (first.type_of_CPU < second.type_of_CPU) return -1;
		else return 0;
	case 2:
		if (first.capacity_RAM > second.capacity_RAM) return 1;
		else if (first.capacity_RAM < second.capacity_RAM) return -1;
		else return 0;
	case 3:
		if (first.capacity_GPU > second.capacity_GPU) return 1;
		else if (first.capacity_GPU < second.capacity_GPU) return -1;
		else return 0;
	case 4:
		if (first.capacity_HDD > second.capacity_HDD) return 1;
		else if (first.capacity_HDD < second.capacity_HDD) return -1;
		else return 0;
	default:
		return -2;
	}
}