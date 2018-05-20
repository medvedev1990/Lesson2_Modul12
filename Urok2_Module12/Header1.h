
struct DATE
{
	int day;
	int month;
	int year;
};

struct task4
{
	DATE task4Dates;
};

/* Задание 6 */
struct structX
{
	int Xn[3][4];		
};

struct structY
{
	int Yn[3];
};

struct structMatrix
{
	structX X;
	structY Y;
};

/* Задание 7 */
struct Article
{
	char articles[30];
};

struct Product
{
	Article art;
	int quantity;
	int price;
};

/* Задание 8 */
struct Maker
{
	char mkr[10];
};

struct Computer
{
	Maker cmpMkr;
	int frequency;
	int RAM;
	int DVD;
	int price;
};
