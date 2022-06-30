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

void perestanovka(int* a, int i, int j)
{
	int s = a[i];
	a[i] = a[j];
	a[j] = s;
}

bool leks(int* a, int n) //Алгоритм Нарайаны
{
	int j = n - 2;
	while (j != -1 && a[j] >= a[j + 1]) j--;
	if (j == -1)
		return false;
	int k = n - 1;
	while (a[j] >= a[k]) k--;
	perestanovka(a, j, k);
	int l = j + 1;
	int r = n - 1;
	while (l < r)
		perestanovka(a, l++, r--);
	return true;
}

void print(int* a, int n)
{

	static int num = 1;
	printf("Перестановка №%d ", num);
	num = num + 1;


	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	printf("\n");
}

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

	system("cls");

	printf("Провести перестановку в лексикографическом порядке - 1\n"); //Меню
	printf("Задать новое множество - 2\n");
	printf("Изменить элементы заданного множества - 3\n");
	printf("Выйти из программы - 4\n");

	scanf("%s", &choice);

	switch (choice) {
	case '1': //Перестановка
		system("cls");
		printf("Начинаем перестановку элементов\n");
		print(a, n);
		while (leks(a, n))
			print(a, n); //Вывод элементов

		FILE* fout;

		fout = fopen("D:\\out.txt", "w"); //Запись в файл

		if (fout) {
			for (int i = 0; i < n; i++) {
				fprintf(fout, "%d ", a[i]);
			}
		}

		_getch();
		goto C;
		break;

	case '2': //Новое множество

		system("cls");
		goto A;
		break;

	case '3': //Перезаполнение множества

		system("cls");
		goto B;
		break;

	case '4': //Выход

		system("cls");
		exit(0);
		break;

	default: //Возврат

		system("cls");
		goto C;
		break;
	}

	getchar();
	return 0;
}
