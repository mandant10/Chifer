//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Z1;
        TMenuItem *Zapisz1;
        TMenuItem *Zapiszjako1;
        TMenuItem *Otwrz1;
        TMenuItem *Nowy1;
        TMenuItem *Edycja1;
        TMenuItem *Kopiuj1;
        TMenuItem *Wklej1;
        TMenuItem *Wytnik1;
        TMenuItem *Formatowanie1;
        TMenuItem *Pomoc1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TMemo *Memo1;
        TMemo *Memo2;
        TMenuItem *Czarnymotyw1;
        TMenuItem *SzyfrKropkowy1;
        TMenuItem *SzyfrCezara1;
        TMenuItem *SzyfrVinegrete1;
        TMenuItem *Zawija1;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TImage *Image1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Kopiuj1Click(TObject *Sender);
        void __fastcall Wklej1Click(TObject *Sender);
        void __fastcall Wytnik1Click(TObject *Sender);
        void __fastcall Czarnymotyw1Click(TObject *Sender);
        void __fastcall Zawija1Click(TObject *Sender);
        void __fastcall Otwrz1Click(TObject *Sender);
        void __fastcall Zapiszjako1Click(TObject *Sender);
        void __fastcall Zapisz1Click(TObject *Sender);
        void __fastcall Nowy1Click(TObject *Sender);
        void __fastcall Memo1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall SzyfrKropkowy1Click(TObject *Sender);
        void __fastcall SzyfrCezara1Click(TObject *Sender);
        void __fastcall SzyfrVinegrete1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
