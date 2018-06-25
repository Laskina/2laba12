#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

template <class Type>
Type InputNumber(Type min, Type max, string message)
{
	Type n;
	do
	{
		cout << message;
		while ((!(cin >> n)) || (cin.get() != '\n'))
		{
			cout << "������������ ����! ��������� ����\n";
			cin.clear(); //��������������� �����, ���� �� � ��������� ���������
			cin.sync(); //������� ����� �� ��������� ��������
			cout << message;
			getchar();
		}
	} while ((n < min) || (n > max));
	return n;
}

//���� ����������
string InputInformation(string message)
{
	string a;
	cout << message;
	cin >> a;
	return a;
}

//�������� ������� �� ������������ � ����� �����
bool CorrectSymbol(char c)
{
	switch (c)
	{
	case '.':
	case '*':
	case '?':
	case '<':
	case '>':
	case ':':
	case '|':
	case '/':
		return false;
	default:
		return true;
	}
}

//�������� ����� ����� �� ������������
bool CorrectName(string name)
{
	int i = 0;
	bool check = true;
	for (int i = 0; (i < name.length() && check); i++)
	{
		check = CorrectSymbol(name[i]);
	}
	return check;
}

//���� ����� �����
string InputFileName()
{
	string filename;
	do
	{
		cout << "������� ��� ����� (��� ����������, ��� ����� 35 �������� ����� ��������): ";
		cin >> filename;
		if (filename.length() > 35)
		{
			filename.erase(filename.begin(), filename.begin() + 35);
		}
		if (CorrectName(filename))
		{
			filename = filename + ".txt";
			break;
		}
		else
			cout << "�������� ��� �����\n";
	} while (true);
	return filename;
}