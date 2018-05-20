#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<string.h>
#include<time.h>
#include "Header1.h"


void DrawLine()
{
	printf("-----------------------------------------------\n");
}

/* Функция в заданной строке распологает все слова в обратном порядке .
Разделителями слов считаются пробелы*/

void swapString(char *first, char *second)
{
	char tmp;
	while (second > first)
	{
		tmp = *first;
		*first++ = *second;
		*second-- = tmp;
	}
}

//void reverseString(char *eString)
//{
//	//char string1[50];
//	char *first, *last, *start;
//	int flag = 0, i = 0;
//
//	//gets_s(string1);
//
//	start = eString;
//	while (*start)
//	{
//		if (!flag)
//		{
//			if (*start != ' ')
//			{
//				flag = 1;
//				first = start;
//			}
//		}
//		else
//		{
//			if (*start == ' ' || !*(start + 1))
//			{
//				flag = 0;
//				last = start - 1;
//				if (!*(start + 1))
//					last = start;
//				swapString(first, last);
//			}
//		}
//		start++;
//	}
//
//	swapString(eString, start - 1);
//
//}

void generateDate(DATE *date)
{
	date->day = 1 + rand() % 31;
	date->month = 1 + rand() % 12;
	date->year = 1980 + rand() % 20;
}

/* Задание 6 */
void GenerateX(structX *x)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			x->Xn[i][j] = 1 + rand() % 9;
		}
	
	}
}

void GenerateY(structY *y)
{
	for (int i = 0; i < 3; i++)
	{
		y->Yn[i]= 1 + rand() % 9;
	}
}
void PrintInfoMatrix(structMatrix * matrix, int count)
{
	for (int l = 0; l < count; l++)
	{
		DrawLine();
		printf("Система линейных уравнений %d:\n", l+1);

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (j == 0)
					printf("%dx + ", (matrix + l)->X.Xn[i][j]);
				if (j == 1)
					printf("%dx + ", (matrix + l)->X.Xn[i][j]);
				if (j == 2 )
					printf("%dx = ", (matrix + l)->X.Xn[i][j]);
				if (j == 3)
					printf("%d\n", (matrix + l)->X.Xn[i][j]);
			}
			//printf("\n");
		}
		//printf("\n");
		printf("Решение системы уравнений:\n");
		for (int i = 0; i < 3; i++)
		{
			printf("y%d = %d  ",i, (matrix + l)->Y.Yn[i]);
		}
		
		printf("\n");
		DrawLine();
	}
}

structMatrix *GenerateMatrix(int *count)
{
	structMatrix *matrix = (structMatrix*)calloc(*count, sizeof(structMatrix));
	if (matrix != NULL)
	{
		for (int i = 0; i < *count; i++)
		{
			GenerateX(&(matrix+i)->X);
			GenerateY(&(matrix + i)->Y);
		}
	}
	else
	{
		printf("Ошибка!");
		exit(1);
	}
	return matrix;
}



/* Задание 7 */
void generateProduct(Article *pr)
{
	int rnd = 0 + rand() % 4;

	switch (rnd)
	{
	case 0:
		strcpy(pr->articles, "Компьютер");
		break;

	case 1:
		strcpy(pr->articles, "Планшет");
		break;

	case 2:
		strcpy(pr->articles, "Смартфон");
		break;

	case 3:
		strcpy(pr->articles, "Телевизор");
		break;
	}
}


void printInfoProduct(Product  * pr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("#%2d. %12s: Количество %d, Цена %d\n",
			i + 1,
			pr[i].art.articles,
			pr[i].quantity,
			pr[i].price);
	}
}

void printInfoProductInd(Product * pr, int index)
{
	printf("%12s: Количество %d, Цена %d\n",
		pr[index].art.articles,
		pr[index].quantity,
		pr[index].price);
}

/* Задание 8 */

void printInfoComp(Computer  * cmp, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("#%2d. %7s: Частота %d, RAM %d, DVD ROM %d, Стоимость %d\n",
			i + 1,
			cmp[i].cmpMkr.mkr,
			cmp[i].frequency,
			cmp[i].RAM,
			cmp[i].DVD,
			cmp[i].price);
	}
}

void printInfoCompInd(Computer  * cmp, int index)
{
	printf("%s: Частота %d, RAM %d, DVD ROM %d, Стоимость %d\n",
		cmp[index].cmpMkr.mkr,
		cmp[index].frequency,
		cmp[index].RAM,
		cmp[index].DVD,
		cmp[index].price);
}

void generateComp(Maker *cmp)
{
	int rnd = 0 + rand() % 4;

	switch (rnd)
	{
	case 0:
		strcpy(cmp->mkr, "ASUS ");
		break;

	case 1:
		strcpy(cmp->mkr, "HP ");
		break;

	case 2:
		strcpy(cmp->mkr, "LENOVO ");
		break;

	case 3:
		strcpy(cmp->mkr, "DELL ");
		break;
	}
}




