//---------------------------------------------------------------------------
#include <iostream>
#include <system.hpp>
#include <vcl.h>
#pragma hdrstop
#include<string>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool ilekrop=0;
string pobierz(TMemo *Sender, int nr) //od 0
{
      AnsiString  linia=Sender->Lines->Strings[nr];
      string slowo=linia.c_str(); //konwersja z ansi string do stringa
      return slowo;  
}
bool spr(string sl)
{
        if(sl[0]=='0') return 1;
        for(int i=0;i<sl.size();i++)if(sl[i]<'0' || sl[i]>'9') return 1;
        return 0;
}
void wystaw(TMemo *Sender, string co ,int nr)
{
      AnsiString x= AnsiString (co.c_str());
      Sender->Lines->Strings[nr]=x;
}
string kropkowy(string slowo)
{
        if(!ilekrop)
        {
           string pom="";
           for(int i=0;i<slowo.size();i++)
           {
                pom+=slowo[i];
                pom+='.';
           }
           return pom;
        }
        else
        {
           Application->MessageBox("Zosta³a przekroczona iloœæ mo¿liwych u¿yæ szyfru kropkowego! Tekst zostanie rozszyfrowany!", "Naruszenie!",MB_OK | MB_ICONWARNING);
           return "";

        }

}


string krod(string slowo)
{
        ilekrop=0;
     string pom="";
        for(int i=0;i<slowo.size();i++)
       {
                if(slowo[i]!='.' && slowo[i]!='-')pom+=slowo[i];
       }
       return pom;
}
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Memo1->WordWrap=0;
        TMemo *me=Memo1;
        int ite=-1;
        string in="1";
        while(in.size()!=0)
        {
            ite++;
            in=krod(pobierz(me,ite));
            wystaw(me,in,ite);
        }
        Memo1->WordWrap=1;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{

        Memo1->WordWrap=0;
        TMemo *me=Memo1;
        int ite=-1;
        string in="1";
        while(in.size()!=0)
        {
            ite++;
            in=kropkowy(pobierz(me,ite));
            if(ilekrop==1)
            {


                 TMemo* pomocnicza=Memo1;

                 Button2Click(static_cast<TObject*>(pomocnicza));
                 ilekrop=0;
                 break;
            }
            wystaw(me,in,ite);
        }
        Memo1->WordWrap=1;
        ilekrop=1;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


char lite(char li, int ile)
{
        if(li>64 && li< 91)
        {
             li=((li-65+ile)%26)+65;
             return li;
        }
        if(li>96 && li<123)
        {
                li=((li-97+ile)%26)+97;
             return li;
        }
        if(li==' ') return ' ';
        return '-';
}

string cezar(string slowo, int ile)
{
        string pom;
        for(int i=0;i<slowo.size();i++)
        {
                pom+=lite(slowo[i],ile);
        }
        return pom;
}
int zamiana(string sl)
{
        int li=0;
        int dl=sl.size();
        for(int i=dl-1;i>=0;i--)
        {
                int cos=sl[i]-'0';
                for(int j=0;j<dl-i-1;j++)
                {
                        cos*=10;
                }
                li+=cos;
        }
        return li;
}
string uncezar(string slowo, int ile)
{
        string pom;
        for(int i=0;i<slowo.size();i++)
        {
                pom+=lite(slowo[i],(26-(ile%26)));
        }
        return pom;
}
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        Memo1->WordWrap=0;
        TMemo *num=Memo2;
        string cos=pobierz(num,0);
        if(cos=="" || cos==" ")
        {
             Application->MessageBox("Niepoprawne dane wejœciowe!", "Naruszenie!",MB_OK | MB_ICONWARNING);
        }
        else
        {
                if(spr(cos))
                {
                       Application->MessageBox("Niepoprawne dane wejœciowe!", "Naruszenie!",MB_OK | MB_ICONWARNING);
                }
                else
                {
                        int ile=zamiana(cos);
                        TMemo *me=Memo1;
                        int ite=-1;
                        string in="1";
                        while(in.size()!=0)
                        {
                                ite++;
                                in=cezar(pobierz(me,ite),ile);
                                wystaw(me,in,ite);
                        }
                }
                Memo1->WordWrap=1;
        }
        

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
        Memo1->WordWrap=0;
       TMemo *num=Memo2;
        string cos=pobierz(num,0);
        if((spr(cos)==1) || cos=="" || cos==" ")
        {
                Application->MessageBox("Niepoprawne dane wejœciowe!", "Naruszenie!",MB_OK | MB_ICONWARNING);
        }
        else
        {
                int ile=zamiana(cos);
                TMemo *me=Memo1;
                int ite=-1;
                string in="1";
                while(in.size()!=0)
                {
                        ite++;
                        in=uncezar(pobierz(me,ite),ile);
                        wystaw(me,in,ite);
                }
        }
        Memo1->WordWrap=1;
}
//---------------------------------------------------------------------------
string wyrownaj(string jed, string dwa)//zwraca jed tylko ze dluzsze
{
        string pom;
        int npw=-1;
        int nr=-1;
        while((pom.size())!=(dwa.size()))
        {
                npw++;
                
                if(dwa[npw]==' ')
                {
                        pom+=' ';
                }
                else
                {
                        nr++;
                       if(nr==jed.size()) nr=0;
                      pom+=jed[nr];
                }
        }
        return pom;
}

void __fastcall TForm1::Button5Click(TObject *Sender)
{
        Memo1->WordWrap=0;
        TMemo *num=Memo2;
        string kod=pobierz(num,0);
        TMemo *me=Memo1;
        int ite=-1;
        string in="1";
        if(kod=="" || kod==" ") Application->MessageBox("Niepoprawne dane wejœciowe!", "Naruszenie!",MB_OK | MB_ICONWARNING);
        else
        {
               while(in.size()!=0)
                {
                        in="";
                        ite++;
                        string cala=(pobierz(me,ite));
                        kod=wyrownaj(kod,cala);
                        for(int i=0;i<cala.size();i++)
                        {
                                int pomoc=kod[i];
                                if(pomoc>96)in+=lite(cala[i],pomoc-97);
                                else  in+=lite(cala[i],pomoc-65);
                        }
                        wystaw(me,in,ite);
                        in="";
                }
                Memo1->WordWrap=1;
        }
        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
      Memo1->WordWrap=0;
        TMemo *num=Memo2;
        string kod=pobierz(num,0);
        TMemo *me=Memo1;
        int ite=-1;
        string in="1";
        if(kod=="" || kod==" ") Application->MessageBox("Niepoprawne dane wejœciowe!", "Naruszenie!",MB_OK | MB_ICONWARNING);
        else
        {
                while(in.size()!=0)
                {
                        in="";
                        ite++;
                        string cala=(pobierz(me,ite));
                        kod=wyrownaj(kod,cala);
                        for(int i=0;i<cala.size();i++)
                        {
                                int pomoc=kod[i];
                                if(pomoc>96)in+=lite(cala[i],26-((pomoc-97)%26));
                                else  in+=lite(cala[i],26-((pomoc-65)%26));
                        }
                        wystaw(me,in,ite);
                        in="";
                }
                Memo1->WordWrap=1;
        }
        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
      ilekrop=0;
}
//---------------------------------------------------------------------------





void __fastcall TForm1::Kopiuj1Click(TObject *Sender)
{
      Memo1->CopyToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Wklej1Click(TObject *Sender)
{
       Memo1->PasteFromClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Wytnik1Click(TObject *Sender)
{
      Memo1->CutToClipboard();  
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Czarnymotyw1Click(TObject *Sender)
{
        if(Czarnymotyw1->Checked==0)
        {
             Memo1->Font->Color=clRed;
             Memo2->Font->Color=clRed;
             Memo1->Color=clBlack;
             Memo2->Color=clBlack;
             Form1->Color=clGray;
             Czarnymotyw1->Checked=1;
        }
        else
        {
                Label2->Font->Color=clBlack;
                Label3->Font->Color=clBlack;
                Label4->Font->Color=clBlack;
             Memo1->Font->Color=clBlack;
             Memo2->Font->Color=clBlack;
             Memo1->Color=clWhite;
             Memo2->Color=clWhite;
             Form1->Color=clGradientActiveCaption;
             Czarnymotyw1->Checked=0;
        }
}
//---------------------------------------------------------------------------
AnsiString nazwa_pliku="";
void __fastcall TForm1::Zawija1Click(TObject *Sender)
{
        if(Memo1->WordWrap==0)
        {
            Zawija1->Checked=1;
            Memo1->WordWrap=1;
        }
        else
        {
          Zawija1->Checked=0;
          Memo1->WordWrap=0;
        }
         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Otwrz1Click(TObject *Sender)
{
       if(OpenDialog1->Execute())
       {
            try
            {
                Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
                nazwa_pliku=OpenDialog1->FileName;
            }
             
            catch(...)
            {
                 Application->MessageBox("B³¹d otwarcia pliku", "B³¹d!",MB_OK | MB_ICONWARNING);
            }
             
       }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zapiszjako1Click(TObject *Sender)
{
     if(SaveDialog1->Execute())
       {
            try
            {
                Memo1->Lines->SaveToFile(SaveDialog1->FileName);
                nazwa_pliku=SaveDialog1->FileName;
            }
            catch(...)
            {
               Application->MessageBox("B³¹d zapisu pliku", "B³¹d!",MB_OK | MB_ICONWARNING);
            }
            
       }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zapisz1Click(TObject *Sender)
{
        if(nazwa_pliku!="")
        {
                Memo1->Lines->SaveToFile(nazwa_pliku);
        }
        else
        {
                Form1->Zapiszjako1Click(MainMenu1);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Nowy1Click(TObject *Sender)
{
     if(Application->MessageBox("Czy na pewno chcesz utworzyæ nowy plik?", "Potwierdzenie", MB_YESNO | MB_ICONQUESTION)==IDYES );
     {
        Memo1->Lines->Clear();
        Memo2->Lines->Clear();
        nazwa_pliku="";
     }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Memo1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Shift.Contains(ssCtrl))
    {
         if((Key=='s')||(Key=='S'))
         {
                Form1->Zapisz1Click(MainMenu1);
         }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SzyfrKropkowy1Click(TObject *Sender)
{
        Application->MessageBox("Po prostu daje kropki miêdzy znakami", "Banalny do rozszyfrowania", MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SzyfrCezara1Click(TObject *Sender)
{
      if(Application->MessageBox("Szyfruje za pomoc¹ liczby. Kliknij TAK ¿eby o nim poczytaæ", "W miarê ciê¿ki do rozszyfrowania", MB_YESNO | MB_ICONINFORMATION)==IDYES)
      {
            ShellExecute(NULL,"open","https://pl.wikipedia.org/wiki/Szyfr_Cezara",NULL,NULL,SW_SHOWNORMAL);
      }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SzyfrVinegrete1Click(TObject *Sender)
{
      if(Application->MessageBox("Szyfruje za pomoc¹ innego s³owa. Kliknij TAK ¿eby o nim poczytaæ", "Bardzo ciê¿ki a czasem niemo¿liwy do rozszyfrowania", MB_YESNO | MB_ICONINFORMATION)==IDYES)
      {
            ShellExecute(NULL,"open","https://pl.wikipedia.org/wiki/Szyfr_Vigen%C3%A8re%E2%80%99a",NULL,NULL,SW_SHOWNORMAL);
      }
}
//---------------------------------------------------------------------------





