#pragma once
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"

using namespace std;

//������ ����
class MyDate {

	// �������� �������� �� ��� ����������
	bool IsLeap(int year)
	{
		if (year % 4)
			return false;
		if (year % 100)
			return true;
		return !(year % 400);
	}

	// �������� ���� �� ������������
	bool CorrectDate(int day, int month, int year, string &message) {

		// ���� ��� ���������                            ���� �� ����������
		if ((month == 2 && day > 29 && IsLeap(year)) || (month == 2 && day > 28 && !IsLeap(year)))
		{
			message = "�������� ���-�� ���� � �������!";
			return false;
		}
		//���-�� ���� � ������
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day > 30)
			{
				message = "�������� ���-�� ���� � ������!";
				return false;
			}
		}
	}
public:
	// ����
	int day;
	// �����
	int month;
	// ���
	int year;

	// ����������� �� ���������
	MyDate()
	{
		int day = 1;
		int month = 1;
		int year = 1970;
	}

	// ���� ���� � �������
	void InputDate()
	{
		bool correct_date = true; // ��������� �� ��������� ����
		string message = "";  // ��������� � ������� ������
		do
		{
			if (!correct_date)
				cout << message << endl;
			day = InputNumber(1, 31, "���� ����:\n������� ���� (1-31): ");
			month = InputNumber(1, 12, "������� ����� ������ (1-12): ");
			year = InputNumber(1970, 2100, "������� ��� (1970-2100): ");
			correct_date = CorrectDate(day, month, year, message);
		} while (!correct_date);  // ��������� ���� ���� �� ���������� ����
	}

	// ������� ���� � ������ (��� ����������� ������ � ����)
	string ToString()
	{
		return (to_string(day) + ' ' + to_string(month) + ' ' + to_string(year));
	}

	// ������������� �������� ���������
	bool operator == (const MyDate &c)
	{
		return ((day == c.day) && (month == c.month) && (year == c.year));
	}

	// ����������� �����������
	MyDate& operator = (MyDate c)
	{
		day = c.day;
		month = c.month;
		year = c.year;

		return (*this);
	}

	// ������������� �������� ������
	bool operator > (const MyDate &c)
	{
		return ((year > c.year) || ((year == c.year) && (month > c.month)) || ((year == c.year) && (month == c.month) && (day > c.day)));
	}

	// ������������� �������� ������
	bool operator < (const MyDate &c)
	{
		return ((year < c.year) || ((year == c.year) && (month < c.month)) || ((year == c.year) && (month == c.month) && (day < c.day)));
	}

};

class File {
public:
	//�������� ���������
	string catalog;
	//��� �����
	string File_name;
	//���������� �����
	string extension;
	//���� � ����� ��������
	MyDate Date_Time;
	//��������
	enum attribute { read_only, system, hidden };
	//������� ��������
	bool sign_of_delete;
	//���-�� ��������
	int count_sectors;

	//����������� �� ���������
	File()
	{
		string catalog = "";
		string File_name = "";
		string extension = "";
		MyDate Data_Time;
		sign_of_delete = false;
		int count_sectors = 0;
	}

	//��������� ��������� "����"
	File ChangeFile(File &result)
	{
		if (InputNumber(0, 1, "�� ������ �������� ������� ����� " + result.catalog + " (0 - ���, 1 - ��) \n��� �����: ") == 1)
			result.catalog = InputInformation("������� ����� ������� �����: ");
		if (InputNumber(0, 1, "�� ������ �������� ��� ����� " + result.File_name + " (0 - ���, 1 - ��) \n��� �����: ") == 1)
			result.File_name = InputInformation("������� ����� ��� �����: ");
		if (InputNumber(0, 1, "�� ������ �������� ���������� ����� " + result.extension + " (0 - ���, 1 - ��) \n��� �����: ") == 1)
			result.extension = InputInformation("������� ����� ���������� �����: ");
		if (InputNumber(0, 1, "�� ������ �������� ���� � ����� �������� " + result.Date_Time + " (0 - ���, 1 - ��) \n��� �����: ") == 1)
			result.Date_Time.InputDate();
		if (InputNumber(0, 1, "�� ������ �������� ������� ���������� " + result.CPU_frequency + " (0 - ���, 1 - ��) \n��� �����: ") == 1)
			result.CPU_frequency = InputInformation("������� ����� ������� ����������: ");
		if (InputNumber(0, 1, "�� ������ �������� ����� ����������� ������ " + to_string(result.capacity_RAM) + " (0 - ���, 1 - ��) \n��� �����: ") == 1)
			result.capacity_RAM = InputNumber(0, 256, "������� ����� ����� ����������� ������ (0-256): ");
		if (InputNumber(0, 1, "�� ������ �������� ����� �������� ����� " + to_string(result.capacity_HDD) + " (0 - ���, 1 - ��) \n��� �����: ") == 1)
			result.capacity_HDD = InputNumber(0, 8192, "������� ����� ����� �������� ����� (0-8.192): ");
		if (InputNumber(0, 1, "�� ������ �������� ����� ������ ���������� " + to_string(result.capacity_GPU) + " (0 - ���, 1 - ��) \n��� �����: ") == 1)
			result.capacity_GPU = InputNumber(0, 16, "������� ����� ����� ������ ���������� (0-16): ");
		if (InputNumber(0, 1, "�� ������ �������� ��������� ���������� " + to_string(result.Cost) + " (0 - ���, 1 - ��) \n��� �����: ") == 1)
			result.Cost = InputNumber(0, 1000000, "������� ����� ��������� ���������� (0-1.000.000): ");
		if (InputNumber(0, 1, "�� ������ �������� ���������� ����������� " + to_string(result.Count) + " (0 - ���, 1 - ��) \n��� �����: ") == 1)
			result.Count = InputNumber(0, 100, "������� ����� ���������� ����������� (0-100): ");
		return result;
	}

	//������������� �������� ��������� ��� ��������� "���������"
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

//������� ����� ��������� "���������" � �������
File InputScreenFile()
{
	File c;
	c.File_ID = InputNumber(0, 999999, "������� ��� ���������� (0-999.999): ");
	c.File_name = InputInformation("������� ��� ����������: ");
	c.type_of_CPU = InputInformation("������� ��� ����������: ");
	c.CPU_frequency = InputInformation("������� ������� ����������: ");
	c.capacity_RAM = InputNumber(0, 256, "������� ����� ����������� ������ (0-256): ");
	c.capacity_HDD = InputNumber(0, 8192, "������� ����� �������� ����� (0-8.192): ");
	c.capacity_GPU = InputNumber(0, 16, "������� ����� ������ ���������� (0-16): ");
	c.Cost = InputNumber(0, 1000000, "������� ��������� ���������� (0-1.000.000): ");
	c.Count = InputNumber(0, 100, "������� ���������� ����������� (0-100): ");

	return c;
}

//������� ������ ��������� "���������" �� �������
void OutputScreenFile(File c)
{
	cout << "��� ����������: " << c.File_ID << endl;
	cout << "��� ����� ����������: " << c.File_name << endl;
	cout << "��� ����������: " << c.type_of_CPU << endl;
	cout << "������� ����������: " << c.CPU_frequency << endl;
	cout << "����� ����������� ������: " << c.capacity_RAM << endl;
	cout << "����� �������� �����: " << c.capacity_HDD << endl;
	cout << "����� ������ ����������: " << c.capacity_GPU << endl;
	cout << "��������� ����������: " << c.Cost << endl;
	cout << "���������� �����������: " << c.Count << endl;
}


//���������� ��������� "����" �� ������ 
// ������:
// ���� ����� ���
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
		cout << "������ ������ � ����!" << endl;
	}
	return result;
}


//������� ��������� "���������" � ������
string ToString(File c, int i)
{
	string result = "������ � " + to_string(i) + "\n" + "��� ����������: " + to_string(c.File_ID) + "\n" + "��� ����� ����������: " + c.File_name + "\n" + "��� ����������: " + c.type_of_CPU + "\n" + "������� ����������: " + c.CPU_frequency + "\n" + "����� ����������� ������: " + to_string(c.capacity_RAM) + "\n" + "����� �������� �����: " + to_string(c.capacity_HDD) + "\n" + "����� ������ ����������: " + to_string(c.capacity_GPU) + "\n" + "��������� ����������: " + to_string(c.Cost) + "\n" + "���������� �����������: " + to_string(c.Count) + "\n";
	return result;
}

//���������� ��������� "���������" �� ������
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
			string wrd = "��� ����������: ";
			result.File_ID = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "��� ����������: ";
			result.File_name = s.substr(wrd.length(), s.length()).c_str();
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "��� ����������: ";
			result.type_of_CPU = s.substr(wrd.length(), s.length()).c_str();
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "������� ����������: ";
			result.CPU_frequency = s.substr(wrd.length(), s.length()).c_str();
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����� ����������� ������: ";
			result.capacity_RAM = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����� �������� �����: ";
			result.capacity_HDD = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����� ������ ����������: ";
			result.capacity_GPU = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "��������� ����������: ";
			result.Cost = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "���������� �����������: ";
			result.Count = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
	}
	catch (...)
	{
		cout << "������ ������ � ����!" << endl;
	}
	return result;
}

//����� ������� �������� �� ���������� ��������
/*type_search - ��� ������
1 - ��� ����������
2 - ����� ����������� ������
3 - ����� ������ ����������
4 - ����� �������� �����*/
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

//���� �������� ������ � ����������� �� ���������� ����
File InputChangeTypeSearch(int type_search)
{
	File result;
	switch (type_search)
	{
	case 1:
		result.type_of_CPU = InputInformation("������� ��� ����������: ");
		return result;
	case 2:
		result.capacity_RAM = InputNumber(0, 256, "������� ����� ����������� ������(0 - 256) :");
		return result;
	case 3:
		result.capacity_GPU = InputNumber(0, 16, "������� ����� ������ ���������� (0-16): ");
		return result;
	case 4:
		result.capacity_HDD = InputNumber(0, 8192, "������� ����� �������� ����� (0-8.192): ");
		return result;
	default:
		return result;
	}
}

//��������� �������� � ����������� �� ���������� ���� ��� ����������
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