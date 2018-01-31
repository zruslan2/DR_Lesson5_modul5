#include <locale.h>
#include <math.h>
#include <vector>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

void head(char mas[]);
void yellow();
void white();
void red();

using namespace std;
unsigned short int nz;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));

	int i, j;
	while (true)
	{
		cout << "Введите номер задания, 0 - для выхода "; cin >> nz;

		if (nz == 0)
		{
			break;
			system("exit");
		}
		else if (nz == 1)
		{
			//1.	Дан целочисленный квадратный массив 10×10.Найти сумму элементов  каждой строки.
			head("1. Дан целочисленный квадратный массив 10x10. Найти сумму элементов каждой строки.");
			int mas[10][10], sum[10] = { 0 };
			yellow();
			cout << " Массив 10x10\n";
			white();
			for (i = 0; i < 10; i++)
			{
				for (j = 0; j < 10; j++)
				{
					mas[i][j] = 1 + rand() % 100;
					cout << mas[i][j] << "\t";
				}
				cout << endl;
			}
			yellow();
			cout << " Сумма\n";
			white();
			for (i = 0; i < 10; i++)
			{
				for (j = 0; j < 10; j++)
				{
					sum[i] += mas[i][j];
				}
				cout << i + 1 << " строки = " << sum[i] << endl;
			}
		}
		else if (nz == 2)
		{
			/*2.	Дан целочисленный квадратный массив 4×4.Найти строку с наименьшей суммой 
			элементов*/
			head("2. Дан целочисленный квадратный массив 4x4. Найти строку с наименьшей суммой элементов.");
			int mas[4][4], sum[4] = { 0 }, min, min_ind;
			yellow();
			cout << " Массив 4x4\n";
			white();
			for (i = 0; i < 4; i++)
			{
				for (j = 0; j < 4; j++)
				{
					mas[i][j] = 1 + rand() % 100;
					cout << mas[i][j] << "\t";
				}
				cout << endl;
			}
			for (i = 0; i < 4; i++)
			{
				for (j = 0; j < 4; j++)
				{
					sum[i] += mas[i][j];
				}				
			}
			min = sum[0];
			min_ind = 0;
			for (i = 1; i < 4; i++)
			{
				if (sum[i] < min)
				{
					min = sum[i];
					min_ind = i;
				}
			}
			yellow();
			cout << " Строка с наименьшей суммой - "<<min_ind+1<<endl;
			white();
		}
		else if (nz == 3)
		{
			/*3.	Дана целочисленная матрица  6× 8. Найти произведение положительных 
			элементов первого столбца.*/
			head("3. Дана целочисленная матрица  6x8. Найти произведение положительных элементов первого столбца.");
			int mas[6][8], proizv=1;
			yellow();
			cout << " Массив 6x8\n";
			white();
			for (i = 0; i < 6; i++)
			{
				for (j = 0; j < 8; j++)
				{
					mas[i][j] = -20 + rand() % 100;
					cout << mas[i][j] << "\t";
				}
				cout << endl;
			}
			for (i = 0; i < 6; i++)
			{
				if (mas[i][0] > 0)
				{
					proizv *= mas[i][0];
				}
			}
			yellow();
			cout <<" Произведение положительных элементов первого столбца = "<< proizv<<endl;
			white();
			cout << endl;
		}
		else if (nz == 4)
		{
			/*4.	Составить программу, которая заполняет квадратную матрицу порядка n 
			натуральными числами 1, 2, 3, .. ., n2, записывая их в нее "по спирали" по 
			часовой стрелке.*/
			head("4. Составить программу, которая заполняет квадратную матрицу порядка n натуральными числами 1, 2, 3, .. ., n2, записывая их в нее ""по спирали"" по часовой стрелке.");
#define n 5
			int mas[n][n], kol = n*n, ch = 1, hod = n - 1, krug = 0;
			while (krug <= n / 2)
			{
				int j = krug;
				int i = krug;
				while (i < hod)
				{
					mas[j][i] = ch;
					i++;
					ch++;
				}
				i = n - krug - 1;
				while (j < hod)
				{
					mas[j][i] = ch;
					j++;
					ch++;
				}
				int h = krug;
				while (h < hod)
				{
					mas[j][i] = ch;
					h++;
					i--;
					ch++;
				}
				h = krug;
				while (h < hod)
				{
					mas[j][i] = ch;
					h++;
					j--;
					ch++;
				}
				krug++;
				hod--;
			}
			if (n % 2 == 1)mas[n / 2][n / 2] = n*n;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cout << mas[i][j] << "\t";
				}
				cout << endl;
			}
		}
		else if (nz == 5)
		{
			/*5.	Дан двухмерный целочисленный массив A(M, N).Составить одномерный 
			массив B из номеров строк этого массива*/
			head("5. Дан двухмерный целочисленный массив A(M,N). Составить одномерный массив B из номеров строк этого массива");
			int A[3][4], B[12];
			yellow();
			cout << " Массив 3x4\n";
			white();
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 4; j++)
				{
					A[i][j] = -20 + rand() % 100;
					cout << A[i][j] << "\t";
				}
				cout << endl;
			}
			yellow();
			cout << " Одномерный массив\n";
			white();
			int l = 0;
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 4; j++)
				{
					B[l] = A[i][j];
					l++;
				}				
			}
			for (i = 0; i < 12; i++)
			{
				cout << B[i] << "\t";
			}
			cout << endl<<endl;
		}
		else if (nz == 6)
		{
			/*6.	Написать программу, которая в матрице чисел A(N, M) находит все элементы, 
				превышающие по абсолютной величине заданное число B. Подсчитать число таких 
				элементов и записать их в массив C.*/
			head("6. Написать программу, которая в матрице чисел A(N,M) находит все элементы, превышающие по абсолютной величине заданное число B. Подсчитать число таких элементов и записать их в массив C.");
			int A[5][4],B,C[20];
			yellow();
			cout << " Массив 5x4\n";
			white();
			for (i = 0; i < 5; i++)
			{
				for (j = 0; j < 4; j++)
				{
					A[i][j] = 1 + rand() % 100;
					cout << A[i][j] << "\t";
				}
				cout << endl;
			}
			yellow();
			cout << " Введите число B = "; cin >> B;
			cout << " Массив с числами больше "<<B;
			white();
			int kol = 0;
			for (i = 0; i < 5; i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (A[i][j] > B)
					{
						C[kol] = A[i][j];
						kol++;
					}
				}				
			}
			cout << endl;
			for (i = 0; i < kol; i++)cout << C[i] << "\t";
			yellow();
			cout <<endl<< " Количество элементов больше " << B <<" - "<<kol<< endl;
			white();
			cout << endl;
		}
		else if (nz == 7)
		{
			/*7.	Дана целочисленная матрица размера 8х5.Определить:
			a.сумму всех элементов второго столбца массива;
			b.сумму всех элементов 3 - й строки массива.*/
			head("7.Дана целочисленная матрица размера 8х5. Определить:    a.сумму всех элементов второго столбца массива;    b.сумму всех элементов 3 - й строки массива.");
			int mas[8][5], sum_col = 0, sum_str = 0;
			yellow();
			cout << " Массив 8x5\n";
			white();
			for (i = 0; i < 8; i++)
			{
				for (j = 0; j < 5; j++)
				{
					mas[i][j] = 1 + rand() % 100;
					cout << mas[i][j] << "\t";
				}
				cout << endl;
			}
			for (i = 0; i < 8; i++)
			{
				sum_col += mas[i][1];
			}
			yellow();
			cout << " a. Сумма 2 столбца = "<<sum_col<<endl;
			for (i = 0; i < 5; i++)
			{
				sum_str += mas[2][i];
			}
			yellow();
			cout << " b. Сумма 3 строки = " << sum_str << endl;
			cout << endl;
			white();
		}
		else if (nz == 8)
		{
			/*8.	Дана целочисленная прямоугольная матрица размера M•N.Сформировать одномерный 
				массив, состоящий из элементов, лежащих в интервале[1, 10].Найти произведение 
				элементов полученного одномерного массива.*/
			head("8. Дана целочисленная прямоугольная матрица размера MxN. Сформировать одномерный массив, состоящий из элементов, лежащих в интервале [1,10]. Найти произведение элементов полученного одномерного массива.");
			int A[5][4], proiz=1, C[20];
			yellow();
			cout << " Массив 5x4\n";
			white();
			for (i = 0; i < 5; i++)
			{
				for (j = 0; j < 4; j++)
				{
					A[i][j] = 1 + rand() % 50;
					cout << A[i][j] << "\t";
				}
				cout << endl;
			}
			int kol = 0;
			for (i = 0; i < 5; i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (A[i][j] > 0 && A[i][j] < 11)
					{
						C[kol] = A[i][j];
						kol++;
					}
				}				
			}
			yellow();
			cout << " Массив из элементов лежащих в диапозоне от 1 до 10 \n";
			white();
			for (i = 0; i < kol; i++)
			{
				cout << C[i] << "\t";
				proiz *= C[i];
			}
			cout << endl;
			yellow();
			cout << " Произведение элементов второго массива = "<<proiz<<endl<<endl;
			white();
		}
		else if (nz == 9)
		{
			/*9.	Дана целочисленная квадратная матрица. Указать столбец (назвать его номер), 
				где минимальное количество элементов, кратных сумме индексов*/
			head("9. Дана целочисленная квадратная матрица. Указать столбец (назвать его номер), где минимальное количество элементов, кратных сумме индексов");
			int mas[8][8], sum_ind = 28, ke[8],min,min_ind;
			yellow();
			cout << " Массив 8x8\n";
			white();
			for (i = 0; i < 8; i++)
			{
				for (j = 0; j < 8; j++)
				{
					mas[i][j] = 1 + rand() % 200;
					cout << mas[i][j] << "\t";
				}
				cout << endl;
			}
			int kol = 0;
			for (i = 0; i < 8; i++)
			{
				kol = 0;
				for (j = 0; j < 8; j++)
				{
					if (mas[j][i] % sum_ind == 0)kol++;
				}
				ke[i] = kol;
			}
			cout << endl;
			for (i = 0; i < 8; i++)
			{
				cout << ke[i] << "\t";
			}
			cout << endl;
			yellow();
			cout << "Столбцы с минимальным кол-вом элементов кратным сумме индексов: ";
			for (i = 0; i < 8; i++)
			{
				if (ke[i] == 0)cout << i + 1<<", ";
			}
			white();
			cout << endl<<endl;
		}
		else if (nz == 10)
		{
		/*	10.	Дана целочисленная квадратная матрица. Найти сумму элементов матрицы, 
				лежащих выше главной диагонали.*/
			head("10. Дана целочисленная квадратная матрица. Найти сумму элементов матрицы, лежащих выше главной диагонали.");
			int mas[5][5], sum=0,nach=1;
			yellow();
			cout << " Массив 5x5\n";
			white();
			for (i = 0; i < 5; i++)
			{
				for (j = 0; j < 5; j++)
				{
					mas[i][j] = 1 + rand() % 20;
					cout << mas[i][j] << "\t";
				}
				cout << endl;
			}
			for (i = 0; i < 4; i++)
			{
				for (j = nach; j < 5; j++)
				{
					sum += mas[i][j];					
				}
				nach++;
			}
			yellow();
			cout << " Сумма элементов матрицы, лежащих выше главной диагонали = "<<sum<<endl<<endl;
			white();

		}
	}
}


void head(char mas[])
{
	int len, third, s1_len, s2_len, s3_len, maks;
	len = strlen(mas);
	third = len / 3;
	s1_len = third;
	for (int i = s1_len; i < len; i++)
	{
		if (mas[s1_len] != ' ') s1_len++;
		else break;
	}
	s2_len = third;
	for (int i = s1_len + s2_len; i < len; i++)
	{
		if (mas[s1_len + s2_len] != ' ') s2_len++;
		else break;
	}
	s3_len = len - (s1_len + s2_len);
	vector<char>str1(s1_len);
	vector<char>str2(s2_len);
	vector<char>str3(s3_len);
	for (int i = 0; i < s1_len; i++)
	{
		str1[i] = mas[i];
	}
	for (int i = s1_len + 1; i < s1_len + s2_len; i++)
	{
		str2[i - (s1_len + 1)] = mas[i];
	}
	for (int i = s1_len + s2_len + 1; i < len; i++)
	{
		str3[i - (s1_len + s2_len + 1)] = mas[i];
	}
	maks = s1_len;
	if (s2_len > maks)maks = s2_len;
	if (s3_len > maks)maks = s3_len;
	system("cls");
	SetConsoleTextAttribute(hConsole, 11);
	setlocale(LC_ALL, ".866");
	cout << " Ъ";
	for (int i = 0; i <= maks + 1; i++)cout << "Д";
	cout << "ї\n";
	cout << " і "; setlocale(LC_ALL, ".1251");
	for (int i = 0; i<s1_len; i++) cout << str1[i];
	if (s1_len < maks)
	{
		for (int i = 0; i < maks - s1_len; i++)cout << " ";
	}
	setlocale(LC_ALL, ".866"); cout << " і\n";
	cout << " і "; setlocale(LC_ALL, ".1251");
	for (int i = 0; i<s2_len; i++) cout << str2[i];
	if (s2_len < maks)
	{
		for (int i = 0; i < maks - s2_len; i++)cout << " ";
	}
	setlocale(LC_ALL, ".866"); cout << " і\n";
	cout << " і "; setlocale(LC_ALL, ".1251");
	for (int i = 0; i<s3_len; i++) cout << str3[i];
	if (s3_len < maks)
	{
		for (int i = 0; i < maks - s3_len; i++)cout << " ";
	}
	setlocale(LC_ALL, ".866"); cout << " і\n";
	cout << " А";
	for (int i = 0; i <= maks + 1; i++)cout << "Д";
	cout << "Щ\n";
	SetConsoleTextAttribute(hConsole, 15);
	setlocale(LC_ALL, ".1251");
}

void yellow()
{
	SetConsoleTextAttribute(hConsole, 14);
}

void white()
{
	SetConsoleTextAttribute(hConsole, 15);
}

void red()
{
	SetConsoleTextAttribute(hConsole, 12);
}

