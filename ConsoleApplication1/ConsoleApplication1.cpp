#include "pch.h"
#include "stdio.h"
#include "conio.h"
#include <typeinfo>
#include <exception>
#include <iostream>
#include <locale>


const char* Conditions(int a, int X, int Y);
void Cycles(int X, char symbol);
int Arrays(const char* source, const char* charSet);


int main()
{
	setlocale(LC_ALL, "Russian");
	//setlocale(LC_ALL, "ru_UA.UTF-8");

#pragma region U5
	//printf("%s\n", Conditions(1, 2, 4));
	//printf("%s\n", Conditions(2, 0, 5));
	//printf("%s\n", Conditions(-1, -2, 2));
#pragma endregion

#pragma region TS5
	//Cycles(2, '*');
	//Cycles(8, '8');
	//Cycles(0, 'b');
#pragma endregion

#pragma region M5
	printf("%d\n", Arrays("Unique string", "in")); //4
	printf("%d\n", Arrays("Я совсем забыла, как писать на C++", "a+")); //7
	printf("%d\n", Arrays("Какая-то строка", "f")); //0
#pragma endregion

	_getch();
}

const char* Conditions(int a, int X, int Y)
{
	
	const char* result;
	result = "Нет";
	if (a >= X && a <= Y)
	{
		result = "Да";
	}
	return result;
}

void Cycles(int X, char symbol)
{	
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
		printf("Введенное число Х должно быть больше 0\n");
	}
}

int Arrays(const char* source, const char* charSet)
{
	int result = 0;
	for (int i = 0; i < strlen(source); i++)
	{
		for (int j = 0; j < strlen(charSet); j++)
		{
			if (source[i] == charSet[j])
				result++;
		}
	}
	return result;
}
