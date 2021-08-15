//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#pragma hdrstop
#define _USE_MATH_DEFINES
#include <cmath>
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}

const pi=3.141592653589793238462643;

void __fastcall TForm2::bt_closeClick(TObject *Sender)
{
	Close();
}

void freeRes() {
	Form2->ch_res->SeriesList->Clear();
	Form2->lb_root->Caption = "";
	for (int i = 0; i < Form2->sg_res->RowCount; i++)
		for (int j = 0; j < Form2->sg_res->ColCount; j++)
			Form2->sg_res->Cells[j][i] = "";
}

void __fastcall TForm2::bt_clearClick(TObject *Sender) //кнопка "ќчистить"
{
	ed_c->Clear(); ed_d->Clear(); ed_eps->Clear();
	ed_xn->Clear(); ed_n->Clear(); ed_dx->Clear();
	ed_an->Clear(); ed_ak->Clear(); ed_da->Clear();
	freeRes();
}
//---------------------------------------------------------------------------

void dataIn(double *ma, double an, double ak, double da) {
	 double a=an;
	 int i=0;
	 while (a<=ak) {
		 ma[i]=a;
		 a += da;
		 i++;
	 }
}

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

void resOut(double z, int m, int n,  double *ma, double *mx, double **my) {
	freeRes();
	Form2->lb_root->Caption = z;
	Form2->sg_res->RowCount = n + 1;
	Form2->sg_res->ColCount = m + 1;
	Form2->sg_res->Cells[0][0] = "X \\ A";
	for (int j = 0; j < m; j++) {
		Form2->sg_res->Cells[j + 1][0] = "A(" + IntToStr(j + 1) + ") = " + FloatToStrF(ma[j], ffGeneral, 0, 0);
		Form2->ch_res->AddSeries(new TLineSeries(Form2->ch_res));
		Form2->ch_res->Series[j]->Title = "A(" + IntToStr(j + 1) + ") = " + FloatToStrF(ma[j], ffGeneral, 0, 0);
		for (int i = 0; i < n; i++) {
			Form2->sg_res->Cells[j + 1][i + 1] = FloatToStrF(my[j][i], ffGeneral, 6, 0);
			Form2->ch_res->Series[j]->AddXY(mx[i], my[j][i]);
		}
	}
	for (int i = 0; i < n; i++)
		Form2->sg_res->Cells[0][i + 1] = "X(" + IntToStr(i + 1) + ") = " + FloatToStr(mx[i]);
}


void __fastcall TForm2::bt_runClick(TObject *Sender)
{
	freeRes();
	int err, m, n;
	double c, d, eps, xn, dx, z, an, ak, da;
	c = StrToFloat(ed_c->Text);
	d = StrToFloat(ed_d->Text);
	eps = StrToFloat(ed_eps->Text);
	xn = StrToFloat(ed_xn->Text);
	n = StrToFloat(ed_n->Text);
	dx = StrToFloat(ed_dx->Text);
	an = StrToFloat(ed_an->Text);
	ak = StrToFloat(ed_ak->Text);
	da = StrToFloat(ed_da->Text);
	m = floor((ak - an) / da + 1);
    double *ma = new double[m];
	double *mx = new double[n];
	double **my = new double*[m];
	for (int i = 0; i < m; i++)
		my[i] = new double[n];
	dataIn(ma, an, ak, da);
	integral(c, d, eps, &z);
	tab(z, m, n, xn, dx, ma, mx, my);
	resOut(z, m, n, ma, mx, my);
}
//---------------------------------------------------------------------------
