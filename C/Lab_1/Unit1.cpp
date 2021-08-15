// ---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) {   //Рандом
	int i, j;
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++) {
			A[j][i] = rand() % 100;
		}
	}
}

void DataIn(float **A)
{
for (int i = 0; i < 7; i++) {
	for (int j = 0; j < 7; j++) {
        StringGrid1->Cells[i][j]=FloatToStr(A[j][i]);
	}
}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) {   //Выполнить
	float A[7][7];
	float Max=A[0][0];

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
		   if (Max<A[j][i]) {
			 Max=A[j][i];
		   }
		}
	}
}
// ---------------------------------------------------------------------------

