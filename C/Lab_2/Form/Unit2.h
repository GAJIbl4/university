//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.OleCtnrs.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <VCLTee.Series.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TGroupBox *GroupBox2;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *ed_d;
	TEdit *ed_eps;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TEdit *ed_xn;
	TLabel *Label11;
	TEdit *ed_n;
	TEdit *ed_dx;
	TEdit *ed_an;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TGroupBox *GroupBox3;
	TGroupBox *GroupBox4;
	TEdit *ed_c;
	TGroupBox *GroupBox6;
	TButton *bt_run;
	TButton *bt_clear;
	TButton *bt_close;
	TLabel *Label3;
	TLabel *lb_root;
	TLabel *Label15;
	TStringGrid *sg_res;
	TLabel *Label16;
	TChart *ch_res;
	TImage *Image1;
	TImage *Image2;
	TEdit *ed_ak;
	TEdit *ed_da;
	TLabel *Label6;
	TLabel *Label7;
	void __fastcall bt_closeClick(TObject *Sender);
	void __fastcall bt_clearClick(TObject *Sender);
	void __fastcall bt_runClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
