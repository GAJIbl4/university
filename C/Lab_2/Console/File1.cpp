#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#include <math.h>
#else
typedef char _TCHAR;
#define _tmain main
#endif
#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

const pi=3.141592653589793238462643;

double f(double x) {
	return (asin(exp(-x/7.0)));
}

void integral(double c, double d, double eps, double *z) {
	int i = 0;
	double x, h=eps, S=0;
	x=c;
	while (x < d){
			S = S+ 0.5*(f(x + h) + f(x))*h;
			x = x + h;
		}
		i++;
	*z = S;
}

void tab(double z, int m, int n, double xn, double dx, double *ma, double *mx, double **my) {
	double x = xn;
	int i = 0;
	for (i = 0; i < n; i++) {
		mx[i] = x;
		x += dx;
}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			my[i][j] = ma[i]*z*(mx[j]*tan(pi*mx[j]/5.0)+2.0*ma[i]*cos(mx[j]*mx[j]/2.0));
		}
	}
}


void rezout(int m, int n, double *ma, double *mx, double **my){
int i,j;
cout << "         ";
for (i = 0; i < m; i++) {
cout << "A[" << i+1 << "]= " << ma[i] << " ";
}

for (i = 0; i < n; i++) {
if (mx[i]<0) {
cout << "\nX[" << i+1 << "]= " << mx[i] << " ";
}
else{
cout << "\nX[" << i+1 << "]= " << mx[i] << "  ";
}
   for (j = 0; j < m; j++) {
	 if (my[j][i]>0) {
	 if (my[j][i]>=10) {
	 printf("%.4f",my[j][i]);
	 cout << " ";                   //В случае, если число больше 10, либо
	 }                              //меньше нуля, на вывод числа с тем же
	 else{                          //количеством знаков после запятой
	 cout << " ";                   //требуется больше места, поэтому
	 printf("%.4f",my[j][i]);       //если число меньше 10 и больше нуля
	 cout << " ";                   //ставится дополнительный пробел.
     }                              //Таким образом, таблица становится ровной.
	 }
	 else{
	 printf("%.4f",my[j][i]);
	 cout << " ";
	 }
   }
}

}


void dataIn(double *ma, double an, double ak, double da) {//ввод массива А
	 double a=an;
	 int i=0;
	 while (a<=ak) {
		 ma[i]=a;
		 a += da;
		 i++;
	 }
}


int _tmain(int argc, _TCHAR* argv[]) {
	int err, m, n;
	double c, d, eps, xn, dx, z, an, ak, da;

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	cout << "Введите Eps \n";    cin >> eps;    //Ввод параметров
	cout << "Введите C \n";      cin >> c;
	cout << "Введите D \n";      cin >> d;
	cout << "Введите Xn \n";	 cin >> xn;
	cout << "Введите Dx \n";	 cin >> dx;
	cout << "Введите N \n";      cin >> n;
	cout << "Введите An \n";     cin >> an;
	cout << "Введите Ak \n";     cin >> ak;
	cout << "Введите Da \n";     cin >> da;
	m = floor((ak - an) / da + 1);
	double *ma = new double[m];                 //Инициализация динамических массивов
	double *mx = new double[n];
	double **my = new double*[m];
	for (int i = 0; i < m; i++)
		my[i] = new double[n];


	dataIn(ma, an, ak, da);                        //Ввод массива А
	integral(c, d, eps, &z);                       //Интеграл
	cout << "B=" << z << "\n";                     //Вывод значения интеграла
	tab(z, m, n, xn, dx, ma, mx, my);        //Табулирование
	rezout(m, n, ma, mx, my);                      //Вывод результатов

	delete ma, mx, my;                             //Очистка памяти

	cout << "\n";
	system("pause");
	return 0;
}
