#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale>
#include <string.h>
#include <Windows.h>

using namespace std;





void sohr(int* m, int* a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = m[i];
	}
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int n, * a;
	char* b;
	int* m;
	char* m1;
	char choice;
	char vib;

A: system("cls");

	printf("Введите количество элементов заданного множества\nN = "); //Ввод множества
	scanf("%d", &n);

	a = new int[n];
	m = new int[n];
	m1 = new char[n];
	b = new char[n];

B: system("cls");

	printf("Выберите способ ввода:\n");

	printf("Ввести вручную - 1\n");
	printf("Ввести случайно - 2\n");

	scanf("%s", &vib);

	switch (vib) {
	case '1':

		system("cls");

		printf("Введите %d элементов заданного множества\n", n); //Заполнение множества
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			m[i] = a[i];
		}
		system("cls");
		break;

	case '2':

		for (int i = 0; i < n; i++) {
			a[i] = rand() % 10;
			m[i] = a[i];
		}

		system("cls");
		printf("Полученный массив: ");

		for (int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}

		printf("\n");

		_getch();
		break;

	default: //Возврат

		system("cls");
		goto B;
		break;
	}

C:  sohr(m, a, n);
}
