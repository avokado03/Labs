#include "pch.h"
#include "stdio.h"
#include "conio.h"
#include <iostream>
#include <Windows.h>


// объявляем функции
// можно их просто тут определить, не объявляя
// https://metanit.com/cpp/tutorial/3.1.php
const char* Conditions(int a, int X, int Y);
void Cycles(int X, char symbol);
int Arrays(const char* source, const char* charSet);


int main()
{
	//устанавливаем кодировку консоли
	SetConsoleCP(1251);
	//устанавливаем язык
	setlocale(LC_ALL, "Russian");

// pragma region: https://docs.microsoft.com/ru-ru/cpp/preprocessor/region-endregion?view=vs-2019
// писать вам не надо, мне прост так удобнее
// чтобы запустить вызовы какой-то функции, раскомментируйте ее регион

//условия
#pragma region Conditions
	//printf("%s\n", Conditions(1, 2, 4));
	//printf("%s\n", Conditions(2, 0, 5));
	//printf("%s\n", Conditions(-1, -2, 2));
#pragma endregion

//циклы
#pragma region Cycles
	//Cycles(2, '*');
	//Cycles(8, '8');
	//Cycles(0, 'b');
#pragma endregion

//массивы
#pragma region Arrays
	printf("%d\n", Arrays("Unique string", "in")); //4
	printf("%d\n", Arrays("Я совсем забыла, как писать на C++", "а+")); //7
	printf("%d\n", Arrays("Какая-то строка", "f")); //0
#pragma endregion

	// не дает закрыться консольке, сидит в conio.h
	// похоже на Console.ReadKey() в шарпе
	// http://nullflow.blogspot.com/2011/05/c-getch.html
	_getch();
}


/* определяем функции
 про const, типы данных и указатели
 ищите в MSDN, мне лень писать*/
const char* Conditions(int a, int X, int Y)
{
	
	const char* result;
	//сразу присваиваем "нет", чтобы от else избавиться
	result = "Нет";
	if (a >= X && a <= Y)
	{
		result = "Да";
	}
	return result;
}

void Cycles(int X, char symbol)
{	
	//ну тут явно число положительное нужно
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
	// strlen http://cppstudio.com/post/664/
	// сравниваем все символы из 1го массива 
	for (int i = 0; i < strlen(source); i++)
	{
		//с каждым символом 2го массива
		for (int j = 0; j < strlen(charSet); j++)
		{
			if (source[i] == charSet[j])
				// увеличиваем счетчик, если символы совпали, на 1
				// постфиксный инкремент http://cppstudio.com/post/282/
				result++;
		}
	}
	return result;
}
