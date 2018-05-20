#include "Header1.h"

void DrawLine();

void swapString(char *first, char *second);
//void reverseString(char *eString);
void generateDate(DATE *date);

/* Задание 6 */
void GenerateX(structX *x);
void GenerateY(structY *y);
void PrintInfoMatrix(structMatrix * matrix, int count);
structMatrix *GenerateMatrix(int *count);

/* Задание 7 */
void generateProduct(Article *pr);
void printInfoProduct(Product  * pr, int len);
void printInfoProductInd(Product * pr, int index);
void generateComp(Maker *cmp);

/* Задание 8 */
void generateComp(Maker *cmp);
void printInfoComp(Computer  * cmp, int len);
void printInfoCompInd(Computer  * cmp, int index);
