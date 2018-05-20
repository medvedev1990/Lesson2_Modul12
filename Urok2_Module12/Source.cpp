#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <iostream>
#include "Header.h"

FILE * fp;

struct pets {
	char name[80];
	double price;
};


void main()
{

	setlocale(LC_ALL, "RUS");
	printf("В работе имеется 8 заданий.\n");
	printf("Для выхода наберите 0.\n");
	int n;

	do
	{

		printf("\nВведите номер задания: \n");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
		{
			/*1. Имеется текстовый файл. Переписать его строки в другой файл.
			Порядок строк во втором файле должен:
			a.	совпадать с порядком строк в заданном файле;
			b.	быть обратным по отношению к порядку строк в заданном файле. */

			char path1[30] = "01.file1.txt";
			char path2[30] = "01.file2.txt";

			char string1[40] = "Я помню чудное мгновенье";
			char string2[40];
			char string3[40];
			char string4[40];
			char string5[40];

			printf("a):\n");
			printf("Записываем строку в файл 01.file1.txt\n");

			if ((fp = fopen(path1, "w+b")) != NULL) // создаем бинарный файл для чтения/записи
			{
				fwrite(&string1, sizeof(string1), 1, fp);

				rewind(fp);

				fread(&string2, sizeof(string2), 1, fp); // читаем строку в string2

				printf("Читаем строку из файла 01.file1.txt\n");
				printf("\n%s\n", string2);

			}
			else
			{
				printf("Ошибка!");
				exit(1);
			}

			if ((fp = fopen(path2, "w+b")) != NULL)
			{
				printf("\nЗаписываем строку в файл 01.file2.txt\n");
				fwrite(&string2, sizeof(string2), 1, fp);

				rewind(fp);

				fread(&string3, sizeof(string3), 1, fp);

				printf("Читаем строку из файла 01.file2.txt\n");
				printf("\n%s\n", string3);
			}
			else
			{
				printf("Ошибка!");
				exit(1);
			}
			printf("\n");
			printf("b):\n");

			if ((fp = fopen(path2, "w+b")) != NULL) // создаем бинарный файл для чтения/записи
			{
				printf("Записываем строку в обратном порядке в файл 01.file2.txt\n");

				char *first, *last, *start;
				int flag = 0, i = 0;

				start = string2;
				while (*start)
				{
					if (!flag)
					{
						if (*start != ' ')
						{
							flag = 1;
							first = start;
						}
					}
					else
					{
						if (*start == ' ' || !*(start + 1))
						{
							flag = 0;
							last = start - 1;

							if (!*(start + 1))
								last = start;

							swapString(first, last);
						}
					}
					start++;
				}

				swapString(string2, start - 1);

				strcpy(string4, string2);

				fwrite(&string4, sizeof(string4), 1, fp);
				rewind(fp);

				fread(&string5, sizeof(string5), 1, fp);
				printf("Читаем строку из файла 01.file2.txt\n");
				printf("\n%s\n", string5);
			}
			else
			{
				printf("Ошибка!");
				exit(1);
			}

			fclose(fp);
			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 2:
		{
			/*2.	Имеется текстовый файл. Переписать его строки в обратном порядке (справа налево) в другой файл.
			Порядок строк во втором файле должен:
			a.	совпадать с порядком строк в заданном файле;
			b.	быть обратным по отношению к порядку строк в заданном файле. */

			char path3[30] = "02.file1.txt";
			char path4[30] = "02.file2.txt";

			char string1[30] = "У Лукоморья дуб зеленый";
			char string2[30];
			char string3[30];
			char string4[30];
			char string5[30];
			char string6[30];

			printf("a):\n");
			printf("Записываем строку в файл 02.file1.txt\n");

			if ((fp = fopen(path3, "w+b")) != NULL) // создаем бинарный файл для чтения/записи
			{
				fwrite(&string1, sizeof(string1), 1, fp);

				rewind(fp);

				fread(&string2, sizeof(string2), 1, fp); // читаем строку в string2

				printf("Читаем строку из файла 02.file1.txt\n");
				printf("\n%s\n", string2);

			}
			else
			{
				printf("Ошибка!");
				exit(1);
			}
			printf("\n");
			if ((fp = fopen(path4, "w+b")) != NULL) // создаем бинарный файл для чтения/записи
			{
				strcpy(string3, string2);
				printf("Записываем строку в обратном порядке в файл 02.file2.txt\n");

				char *first, *last, *start;
				int flag = 0, i = 0;

				start = string3;
				while (*start)
				{
					if (!flag)
					{
						if (*start != ' ')
						{
							flag = 1;
							first = start;
						}
					}
					else
					{
						if (*start == ' ' || !*(start + 1))
						{
							flag = 0;
							last = start - 1;

							if (!*(start + 1))
								last = start;

							swapString(first, last);
						}
					}
					start++;
				}

				swapString(string3, start - 1);

				strcpy(string4, string3);

				fwrite(&string4, sizeof(string4), 1, fp);
				rewind(fp);

				fread(&string5, sizeof(string5), 1, fp);
				printf("Читаем строку из файла 02.file2.txt\n");
				printf("\n%s\n", string5);
			}
			else
			{
				printf("Ошибка!");
				exit(1);
			}
			printf("\n");
			printf("b):\n");

			if ((fp = fopen(path4, "w+b")) != NULL) // создаем бинарный файл для чтения/записи
			{
				printf("Записываем строку в прямом порядке в файл 02.file2.txt\n");
				fwrite(&string2, sizeof(string2), 1, fp);

				rewind(fp);

				fread(&string6, sizeof(string6), 1, fp); // читаем строку в string2

				printf("Читаем строку из файла 02.file2.txt\n");
				printf("\n%s\n", string6);

			}
			else
			{
				printf("Ошибка!");
				exit(1);
			}

			fclose(fp);
			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 3:
		{
			/*3. Имеется текстовый файл. Получить текст, в котором
			в конце каждой строки из заданного файла добавлен восклицательный знак.*/
			char path5[30] = "03.file1.txt";
			char path6[30] = "03.file2.txt";

			char string1[50] = "У Лукоморья дуб зеленый. Златая цепь на дубе том.";
			char string2[50];
			char string3[50];

			printf("Записываем строки в файл 03.file1.txt\n");

			if ((fp = fopen(path5, "w+b")) != NULL) // создаем бинарный файл для чтения/записи
			{
				fwrite(&string1, sizeof(string1), 1, fp);

				rewind(fp);

				fread(&string2, sizeof(string2), 1, fp); // читаем строку в string2

				printf("Читаем строку из файла 03.file1.txt\n");
				printf("\n%s\n", string2);

			}
			else
			{
				printf("Ошибка!");
				exit(1);
			}

			if ((fp = fopen(path6, "w+b")) != NULL) // создаем бинарный файл для чтения/записи
			{
				printf("\nЗаписываем измененную строку в файл 03.file2.txt\n");

				for (int i = 0; string2[i] != '\0'; i++)
				{
					if (string2[i] == '.')
						string2[i] = '!';
				}

				fwrite(&string2, sizeof(string2), 1, fp);
				rewind(fp);

				fread(&string3, sizeof(string3), 1, fp);
				printf("Читаем строку из файла 03.file2.txt\n");
				printf("\n%s\n", string3);
				printf("\n");
			}
			else
			{
				printf("Ошибка!");
				exit(1);
			}

			fclose(fp);
			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 4:
		{
			/*4. Дан файл, содержащий различные даты. Каждая дата - это число,
			месяц и год. Найти самую позднюю дату.*/
			char path[30] = "04.file1.txt";
			int count = 10;
			DATE *dates = (DATE*)calloc(count, sizeof(DATE));

			printf("Записываем даты в файл 04.file1.txt\n");

			if ((fp = fopen(path, "w+b")) != NULL) // создаем бинарный файл для чтения/записи
			{
				for (int i = 0; i < count; i++)
				{
					(dates + i)->day = 1 + rand() % 31;
					(dates + i)->month = 1 + rand() % 12;
					(dates + i)->year = 1980 + rand() % 40;
				}

				fwrite(dates, count * sizeof(DATE), 1, fp);
				fclose(fp);

				printf("\n");
			}
			else
			{
				printf("Ошибка!");
				exit(1);
			}

			DATE *dates1 = (DATE*)calloc(count, sizeof(DATE));

			if ((fp = fopen(path, "r+b")) != NULL) // создаем бинарный файл для чтения/записи
			{
				rewind(fp);

				fread(dates1, count * sizeof(DATE), 1, fp);

				int mDay = 0, mMonth = 0, mYear = 0, maxIndex;

				for (int i = 0; i < count; i++)
				{
					printf("%d.%d.%d  ", (dates1 + i)->day, (dates1 + i)->month, (dates1 + i)->year);

					if ((dates1 + i)->year > mYear)
					{
						mDay = (dates1 + i)->day;
						mMonth = (dates1)->month;
						mYear = (dates1 + i)->year;
						maxIndex = i;
					}
					else if ((dates1 + i)->month > mMonth && (dates1 + i)->year == mYear)
					{
						mDay = (dates1 + i)->day;
						mMonth = (dates1)->month;
						mYear = (dates1 + i)->year;
						maxIndex = i;
					}
					else if ((dates1 + i)->day > mDay && (dates1 + i)->month == mMonth && (dates1 + i)->year == mYear)
					{
						mDay = (dates1 + i)->day;
						mMonth = (dates1)->month;
						mYear = (dates1 + i)->year;
						maxIndex = i;
					}
					//printf("Самая поздняя дата: %d.%d.%d  \n", mDay, mMonth, mYear);
				}
				printf("\n");
				printf("\nСамая поздняя дата: %d.%d.%d\n", (dates1 + maxIndex)->day, (dates1 + maxIndex)->month, (dates1 + maxIndex)->year);

				printf("\n");

			}
			else
			{
				printf("Ошибка!");
				exit(1);
			}

			fclose(fp);

			system("pause");
			system("cls");

		}break;

		case 5:
		{
			char path1[15] = "05.f.txt";
			char path2[15] = "05.g.txt";
			char path3[15] = "05.h.txt";
			int count = 10, even = 0, odd = 0;

			int *f = (int*)calloc(count, sizeof(int)); // для всех чисел

			if ((fp = fopen(path1, "w+b")) != NULL)
			{
				// *pr = (Product*)calloc(count, sizeof(Product));
				if (f != NULL)
				{
					for (int i = 0; i < count; i++)
					{
						*(f + i) = 10 + rand() % 100;
					}
					//printInfoProduct(pr, count);
				}
				else
				{
					printf("Ошибка!");
					exit(1);
				}
				fwrite(f, count * sizeof(int), 1, fp);
			}
			fclose(fp);

			int *f1 = (int*)calloc(count, sizeof(int));

			printf("Числа в файле \"05.f.txt\" для всех чисел:\n");
			if ((fp = fopen(path1, "r+b")) != NULL)
			{
				fread(f1, count * sizeof(int), 1, fp);
				for (int i = 0; i < count; i++)
				{
					printf("%d  ", *(f1 + i));
				}
			}
			fclose(fp);

			for (int i = 0; i < count; i++)
			{
				if (*(f1 + i) % 2 == 0)
				{
					//*(g + i) = *(f1 + i);
					even++;
				}
				else if (*(f1 + i) % 2 != 0)
				{
					//*(h + i) = *(f1 + i);
					odd++;
				}
			}

			int *g = (int*)calloc(even, sizeof(int)); // для четных чисел
			int *h = (int*)calloc(odd, sizeof(int)); // для нечетных чисел
			even = 0, odd = 0;
			for (int i = 0; i < count; i++)
			{
				if (*(f1 + i) % 2 == 0)
				{
					*(g + even) = *(f1 + i);
					even++;
				}
				else if (*(f1 + i) % 2 != 0)
				{
					*(h + odd) = *(f1 + i);
					odd++;
				}
			}

			if ((fp = fopen(path2, "w+b")) != NULL)
			{
				fwrite(g, even * sizeof(int), 1, fp);
			}
			fclose(fp);
			if ((fp = fopen(path3, "w+b")) != NULL)
			{
				fwrite(h, odd * sizeof(int), 1, fp);
			}
			fclose(fp);

			int *g1 = (int*)calloc(even, sizeof(int));

			printf("\n\nЧисла в файле \"05.g.txt\" для четных чисел:\n");
			if ((fp = fopen(path2, "r+b")) != NULL)
			{
				fread(g1, even * sizeof(int), 1, fp);
				for (int i = 0; i < even; i++)
				{
					printf("%d  ", *(g1 + i));
				}
			}

			printf("\n\nЧисла в файле \"05.р.txt\" для нечетных чисел:\n");
			int *h1 = (int*)calloc(odd, sizeof(int));
			if ((fp = fopen(path3, "r+b")) != NULL)
			{
				fread(h1, odd * sizeof(int), 1, fp);
				for (int i = 0; i < odd; i++)
				{
					printf("%d  ", *(h1 + i));
				}
			}

			fclose(fp);

			printf("\n");
			system("pause");
			system("cls");
		}break;

		case 6:
		{
			/*6. В первом файле хранится k матриц из n строк и n+1 столбцов каждая 
				 (последний столбец - столбец свободных членов). Во втором файле 
				 хранится k векторов - результатов решений соответствующих систем ЛАУ 
				 с матрицами из первого файла. Вывести на экран покомпонентно исходную 
				 систему уравнений и результат, проверив его предварительно; добавить 
				 в файлы новые данные; удалить ненужную информацию.*/

			char path1[30] = "06.matrix.txt";
			int count = 2;

			structMatrix *matrix;

			DrawLine();
			printf("Записываем данные в файл 06.matrix.txt\n");

			matrix = GenerateMatrix(&count);

			PrintInfoMatrix(matrix, count);

				if ((fp = fopen(path1, "w+b")) != NULL)
				{
					fwrite(matrix, count * sizeof(structMatrix), 1, fp);
				}
				else
				{
					printf("Ошибка!");
					exit(1);
				}

			fclose(fp);

			structMatrix *matrix2 = (structMatrix*)calloc(count, sizeof(structMatrix));

			DrawLine();
			printf("Считываем данные из файла 06.matrix.txt\n");

				if ((fp = fopen(path1, "r+b")) != NULL)
				{
					rewind(fp);

					fread(matrix2, count * sizeof(structMatrix), 1, fp);

					int k, x, y, z;
					printf("Введите номер матрицы ЛАУ, строки и столбца элемента системы для изменения:\n");
					
					scanf("%d", &k);
					scanf("%d", &x);
					scanf("%d", &y);

					printf("Введите значение для изменения:\n");

					scanf("%d", &z);

					(matrix2 + k)->X.Xn[x][y] = z;

					PrintInfoMatrix(matrix2, count);
				}
				fclose(fp);

			DrawLine();

			printf("Записываем данные в файл 06.matrix.txt\n");

				if ((fp = fopen(path1, "w+b")) != NULL) // создаем бинарный файл для чтения/записи
				{
					fwrite(matrix2, count * sizeof(structMatrix), 1, fp);
				}
			fclose(fp);

			structMatrix *matrix3 = (structMatrix*)calloc(count, sizeof(structMatrix));

				if ((fp = fopen(path1, "r+b")) != NULL)
				{
					rewind(fp);

					fread(matrix3, count * sizeof(structMatrix), 1, fp);

					int k, x, y, z;
					
					printf("Введите номер матрицы ЛАУ, номера строки и столбца элемента системы для удаления:\n");
				
					scanf("%d", &k);
					scanf("%d", &x);
					scanf("%d", &y);
				
					(matrix3 + k)->X.Xn[x][y] = 0;
					PrintInfoMatrix(matrix3, count);
				}
				fclose(fp);

			printf("Записываем данные в файл 06.matrix.txt\n");

				if ((fp = fopen(path1, "w+b")) != NULL) // создаем бинарный файл для чтения/записи
				{
					fwrite(matrix3, count * sizeof(structMatrix), 1, fp);
				}
				fclose(fp);

			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 7:
		{
			char path[30] = "07.product.txt";
			int count = 10;

			if ((fp = fopen(path, "w+b")) != NULL)
			{

				Product *pr = (Product*)calloc(count, sizeof(Product));
				if (pr != NULL)
				{
					for (int i = 0; i < count; i++)
					{
						generateProduct(&pr[i].art);
						pr[i].quantity = 100 + rand() % 1000;
						pr[i].price = 1000 + rand() % 5000;
					}
					//printInfoProduct(pr, count);
				}
				else
				{
					printf("Ошибка!");
					exit(1);
				}
				fwrite(pr, count * sizeof(Product), 1, fp);
			}
			fclose(fp);

			Product *pr4 = (Product*)calloc(count, sizeof(Product));
			if ((fp = fopen(path, "r+b")) != NULL)
			{
				fread(pr4, count * sizeof(Product), 1, fp);
				printInfoProduct(pr4, count);
			}

			int sum = 0;
			float average;
			for (int i = 0; i < count; i++)
			{
				sum += (pr4 + i)->price;
			}
			printf("Общая стоимость товаров: %d\n", sum);
			printf("Средняя стоимость товаров: %0.2f\n", (float)sum / count);

		}break;

		case 8:
		{
			char path[30] = "08.comp.txt";
			int count = 10;

			if ((fp = fopen(path, "w+b")) != NULL)
			{
				Computer *cmp = (Computer*)calloc(count, sizeof(Computer));

				if (&cmp != NULL)
				{
					for (int i = 0; i < count; i++)
					{
						generateComp(&cmp[i].cmpMkr);
						cmp[i].frequency = 1 + rand() % 4;
						cmp[i].RAM = 1 + rand() % 10;
						cmp[i].DVD = 0 + rand() % 2;
						cmp[i].price = 100000 + rand() % 500000;
					}
					//printInfoComp(cmp, 10);

				}
				else
				{
					printf("Ошибка!");
					exit(1);
				}

				fwrite(cmp, count * sizeof(Computer), 1, fp);
			}
			fclose(fp);

			Computer *cmp4 = (Computer*)calloc(10, sizeof(Computer));
			if ((fp = fopen(path, "r+b")) != NULL)
			{
				fread(cmp4, count * sizeof(Computer), 1, fp);
				printInfoComp(cmp4, count);
			}
			printf("\nКомпьютеры ASUS с частотой процессора более 2 ГГц/сек:\n");
			for (int i = 0; i < count; i++)
			{
				if ((strcmp((cmp4 + i)->cmpMkr.mkr, "ASUS ") == 0) && (cmp4 + i)->frequency > 2)
					printInfoCompInd(cmp4, i);
			}


			fclose(fp);

		}break;

		}
	} while (n != 0);

}
