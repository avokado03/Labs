#include "pch.h"
#include "stdio.h"
#include "conio.h"
#include <iostream>
#include <Windows.h>


// ��������� �������
// ����� �� ������ ��� ����������, �� ��������
// https://metanit.com/cpp/tutorial/3.1.php
const char* Conditions(int a, int X, int Y);
void Cycles(int X, char symbol);
int Arrays(const char* source, const char* charSet);


int main()
{
	//������������� ��������� �������
	SetConsoleCP(1251);
	//������������� ����
	setlocale(LC_ALL, "Russian");

// pragma region: https://docs.microsoft.com/ru-ru/cpp/preprocessor/region-endregion?view=vs-2019
// ������ ��� �� ����, ��� ����� ��� �������
// ����� ��������� ������ �����-�� �������, ���������������� �� ������

//�������
#pragma region Conditions
	//printf("%s\n", Conditions(1, 2, 4));
	//printf("%s\n", Conditions(2, 0, 5));
	//printf("%s\n", Conditions(-1, -2, 2));
#pragma endregion

//�����
#pragma region Cycles
	//Cycles(2, '*');
	//Cycles(8, '8');
	//Cycles(0, 'b');
#pragma endregion

//�������
#pragma region Arrays
	printf("%d\n", Arrays("Unique string", "in")); //4
	printf("%d\n", Arrays("� ������ ������, ��� ������ �� C++", "�+")); //7
	printf("%d\n", Arrays("�����-�� ������", "f")); //0
#pragma endregion

	// �� ���� ��������� ���������, ����� � conio.h
	// ������ �� Console.ReadKey() � �����
	// http://nullflow.blogspot.com/2011/05/c-getch.html
	_getch();
}


/* ���������� �������
 ��� const, ���� ������ � ���������
 ����� � MSDN, ��� ���� ������*/
const char* Conditions(int a, int X, int Y)
{
	
	const char* result;
	//����� ����������� "���", ����� �� else ����������
	result = "���";
	if (a >= X && a <= Y)
	{
		result = "��";
	}
	return result;
}

void Cycles(int X, char symbol)
{	
	//�� ��� ���� ����� ������������� �����
	if (X > 0) 
	{
		for (int i = 0; i < X; i++)
		{
			printf("%c", symbol);
		}
		printf("\n");
	}
	else
	{
		printf("��������� ����� � ������ ���� ������ 0\n");
	}
}

int Arrays(const char* source, const char* charSet)
{
	
	int result = 0;
	// strlen http://cppstudio.com/post/664/
	// ���������� ��� ������� �� 1�� ������� 
	for (int i = 0; i < strlen(source); i++)
	{
		//� ������ �������� 2�� �������
		for (int j = 0; j < strlen(charSet); j++)
		{
			if (source[i] == charSet[j])
				// ����������� �������, ���� ������� �������, �� 1
				// ����������� ��������� http://cppstudio.com/post/282/
				result++;
		}
	}
	return result;
}
