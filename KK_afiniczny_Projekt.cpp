#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<conio.h>

/* 
	Program dokonuj¹cy kryptoanalizy szyfrogramu
	zaszyfrowanego szyfrem afinicznym
	Autor: Koæmierowski Szymon 
*/

using namespace std;

/* ----------------------- Zmienne Globalne ----------------------- */

string alfabet_32 = "a\245bc\206de\251fghijkl\210mn\344o\242prs\230tuwyz\253\276";
string alfabet_26 = "abcdefghijklmnopqrstuvwxyz";

double czestosci_32Znaki[32] = {10.503, 0.699, 1.740, 3.895, 0.743, 3.725, 7.352,
							    1.035, 0.143, 1.731, 1.015, 8.328, 1.836, 2.753,
							    2.564, 2.109, 2.515, 6.237, 0.362, 6.667, 1.141,
							    2.445, 5.243, 5.224, 0.814, 2.475, 2.062, 5.813,
							    3.206, 4.852, 0.078, 0.706};
							    
double czestosci_26Znakow[26] = {8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015,
								 6.094, 6.966, 0.153, 0.772, 4.025, 2.406, 6.749,
								 7.507, 1.929, 0.095, 5.987, 6.327, 9.056, 2.758,
								 0.978, 2.360, 0.150, 1.974, 0.074};
								 
int zlicz_alfabet_32[32];
int zlicz_alfabet_26[26];

fstream file;
string szyfrogram;
int licznik;

int klucze26[12] = {1, 3, 5, 7, 9, 11,
					15, 17, 19 ,21, 23, 25};
					
int klucze32[16] = {1, 3, 5, 7, 9, 11, 13,
					15, 17, 19, 21, 23, 25,
					27, 29, 31};

/* ------------------------------G³ówna funkcja programu------------------------------------- */

int main(){
	
	/*-----------------------------Menu-------------------------------*/
	
	int n;
	bool dziala=true;
    while(dziala){
        system("cls");
        cout<<"Program do kryptoanalizy szyfru afinicznego"<<endl;
        cout<<"Autor: Kocmierowski Szymon"<<endl;
        cout<<endl;
        cout<<"**********Menu**********"<<endl;
        cout<<"Wybierz operacje:"<<endl;
        cout<<"1. Zaladuj plik"<<endl;
        cout<<"2. Zdeszyfruj szyfrogram z wykorzystaniem alfabetu 26 znakowego"<<endl;
        cout<<"3. Zdeszyfruj szyfrogram z wykorzystaniem alfabetu 32 znakowego"<<endl;
        cout<<"9. Zakoncz dzialanie programu"<<endl;
        cout<<"Wybor: ";
        cin>>n;
        switch(n){
        	
        	/*------------------------------------------------------------*/
			
			/*
				Wybranie pierwszej opcji zmusza u¿ytkownika
				
				do wpisania nazwy pliku wraz z jego rozszerzeniem,
				
				w celu jego otworzenia i za³adowania zawartoœci
				
				do string-a. W razie pomyœlnego otwarcia jak
				
				i niemo¿liwoœci otwarcia wyœwietlany jest stosowny komunikat
				
			*/
			 
            case 1:{
            	cout<<endl;
            	file.close();
            	cout<<"Poprzedni plik zostal zamkniety."<<endl;
            	string nazwa;
            	cout<<endl;
            	cout<<"Prosze podac nazwe pliku"<<endl;
            	cout<<"Nazwa: ";
            	cin>>nazwa;
            	cout<<endl;
    			file.open(nazwa.c_str(),std::ios::in);
    			if(!file.good()){
        			cout<<"Nie udalo sie otworzyc pliku"<<endl;
        			getch();
    			}
    			else{
    				cout<<"Zawartosc pliku wczytana pomyslnie"<<endl;
        			getch();
				}
    			break;
			}
			
			/*--------------------------------------------------------------------*/
			
			/*--------------------------------------------------------------------*/
			
			/*
				Po wybraniu drugiej opcji program zlicza wystapienia wszystkich
				
				znakow w szyfrogramie w oparciu o alfabet jêzyka angielskiego,
				
				odpowiednie warunki dokonuj¹ modyfikacji stringa, aby polskie
				
				znaki by³y rozpoznawalne. Wyœwietla siê menu, które umo¿liwia wybór
				
				metody kryptoanalizy, b¹dŸ te¿ powrót do wczeœniejszego menu.
			*/
			
            case 2:{
            	for(int i=0; i<26; i++){
            		zlicz_alfabet_26[i]=0;
				}
            	getline(file, szyfrogram);
        		licznik=0;
        		while(szyfrogram[licznik]!=0){
        			int l = szyfrogram[licznik];
        			
        			if(l==(-71)||l==(-91)){
        				szyfrogram[licznik]='\245';
					}
					
        			else if(l==(-26)||l==(-58)){
        				szyfrogram[licznik]='\206';
					}
					
        			else if(l==(-22)||l==(-54)){
        				szyfrogram[licznik]='\251';
					}
					
        			else if(l==(-77)||l==(-93)){
        				szyfrogram[licznik]='\210';
					}
					
        			else if(l==(-15)||l==(-47)){
        				szyfrogram[licznik]='\344';
					}
					
        			else if(l==(-13)||l==(-45)){
        				szyfrogram[licznik]='\242';
					}
					
        			else if(l==(-100)||l==(-116)){
        				szyfrogram[licznik]='\230';
					}
					
        			else if(l==(-97)||l==(-113)){
        				szyfrogram[licznik]='\253';
					}
					
        			else if(l==(-65)||l==(-81)){
        				szyfrogram[licznik]='\276';
					}
				licznik++;
				}
				licznik=0;
        		while(szyfrogram[licznik]!=0){
           			if((szyfrogram[licznik]%32)-1<26 && szyfrogram[licznik]>64)
                		zlicz_alfabet_26[(szyfrogram[licznik]%32)-1]++;
            		licznik++;
            	}
				bool dzial=true;
				int n1;
				while(dzial){
					system("cls");
					cout<<endl; 
					for(int i=0; i<26; i++){
        				cout<<alfabet_26[i]<<": "<<zlicz_alfabet_26[i]<<"; ";
        			}
        			cout<<endl;
        			cout<<endl;
    	    		cout<<"Szyfrogram: "<<szyfrogram<<endl;
        			cout<<endl;
					cout<<"Prosze wybrac operacje"<<endl;
					cout<<"1. Kryptoanaliza przy uzyciu metody brute-force"<<endl;
					cout<<"2. Kryptoanaliza przy uzyciu ukladu rownan"<<endl;
					cout<<"9. Powrot do menu"<<endl;
					cout<<"Wybor: ";
					cin>>n1;
					switch(n1){
						
						/*------------------------------------------------------------------*/
						
						/*
							Dla ka¿dej kombinacji klucza (a,b) ka¿da litera szyfrogramu 
							
							jest przekszta³cana z wykorzystaniem wzoru f(x) = a^(-1)*(y-b)
							
							gdzie:
							
							a^(-1) - odwrotnosc a w ciele Z_26
							y - numer litery w alfabecie
							b - druga wartoœæ klucza
							
							Po wyœwietleniu przekszta³conego szyfrogramu wyœwietlaj¹ siê opcje
							
							sprawdzenia nastêpnej kombinacji lub zaprzestania sprawdzania.						
							 
						*/
						
						case 1:{
							bool go=true;
							string odp = szyfrogram;
							for(int i = 0; i<12; i++){
								int a = klucze26[i];
								int oda = 0;
								while((oda*a)%26!=1)
									oda++;	
								for(int j = 0; j<26; j++){
									int licz=0;
									while(szyfrogram[licz]!=0){
										for(int k = 0; k<26; k++){
											if(((szyfrogram[licz]%32)-1>=j&&szyfrogram[licz]>64))
												odp[licz]=alfabet_26[((((szyfrogram[licz]%32)-1)-j)*oda)%26];
												
											else if(((szyfrogram[licz]%32)-1<j&&szyfrogram[licz]>64))
												odp[licz]=alfabet_26[((((szyfrogram[licz]%32)-1)+26-j)*oda)%26];
										}
										licz++;
									}
									system("cls");
									cout<<"Dla klucza: a = "<<a<<" i b = "<<j<<endl;
									cout<<"Odwrotnosc a: a' = "<<oda<<endl;
									cout<<endl;
									cout<<"Szyfrogram: "<<szyfrogram<<endl;
									cout<<endl;
									cout<<"String: "<<odp<<endl;
									cout<<endl;
									int n2;
									cout<<"Wybierz jedna z opcji"<<endl;
									cout<<"1. Pokaz nastepna kombinacje"<<endl;
									cout<<"2. Zakoncz przeszukiwanie"<<endl;
									cout<<"Wybor: ";
									cin>>n2;
									if(n2==1){
										go=true;
									}
									else if(n2==2){
										go=false;
									}
									else{
										go=false;
										cout<<"Wybrano nie istniejaca opcje. Powrot do wyboru metody kryptoanalizy."<<endl;
            							getch();
										break;
									}
									if(!go){
										break;
									}
								}
								if(!go){
									break;
								}
							}
							break;
						}

						/*------------------------------------------------------------------*/
						
						
						/*------------------------------------------------------------------*/
						
						/*
							Wyœwietlanie s¹ litery, iloœæ ich wyst¹pieñ w szyfrogramie i ich czêstoœæ
							
							wystêpowania w jêzyku angielski, po czym u¿ytkownik na dokonuje dwóch wyborów
							
							podmiany liter np. a bêdzie przechodzi³o na b i d bêdzie przechodzi³o na w.
							
							Nastêpnie na podstawie wyborów wyliczane s¹ wspó³czynniki, które maj¹ na celu
							
							rozwi¹zanie uk³adu równañ:
							
							a*x1 + b = n1
							a*x2 + b = n2
							
							Najpierw zostanie wyliczona pierwsza wartoœæ klucza a. Je¿eli wyliczona
							
							wartoœæ a znajduje siê w tablicy kluczy, wyliczana jest drug¹ wartoœæ klucza b
							
							i odwrotnoœæ wartoœci a. Natêpnie wykonywane jest przekszta³cana z wykorzystaniem 
							
							wzoru f(x) = a^(-1)*(y-b) gdzie:
							
							a^(-1) - odwrotnosc a w ciele Z_26
							y - numer litery w alfabecie
							b - druga wartoœæ klucza
							
							Po wyœwietleniu przekszta³conego szyfrogramu wyœwietlaj¹ siê opcje
							
							sprawdzenia innej kombinacji lub zaprzestania sprawdzania.
							
							Je¿eli wyliczona wartoœæ a nie znajduje siê w tablicy kluczy, program zwraca
							
							komunikat, ¿e dla tej kombinacji kryptoanaliza jest niemo¿liwa i wyœwietla
							
							opcje sprawdzenia innej kombinacji lub zaprzestania sprawdzania.			
							 
						*/
						
						case 2:{
							bool go=true;
							system("cls");
							while(go){
								char lit11, lit12, lit21, lit22;
								int a1, w1, a2, w2, zes1, zes2, a, b;
								int oda=0;
								int licz=0;
								string odp=szyfrogram;
								cout<<"Litera, liczba liter; litera, czestosc wystepowania litery"<<endl;
								for(int i=0; i<26; i++){
									cout<<alfabet_26[i]<<":         "<<zlicz_alfabet_26[i]<<";            "<<alfabet_26[i]<<":        "<<czestosci_26Znakow[i]<<endl;
								}
								cout<<"Podstaw 1-sza litere."<<endl;
								cout<<"Za: ";
								cin>>lit11;
								cout<<"Podstaw: ";
								cin>>lit12;
								cout<<endl;
								cout<<"Podstaw 2-ga litere."<<endl;
								cout<<"Za: ";
								cin>>lit21;
								cout<<"Podstaw: ";
								cin>>lit22;
								for(int i=0; i<26; i++){
									if(lit11==alfabet_26[i])
										w1=i;
									if(lit12==alfabet_26[i])
										a1=i;
									if(lit21==alfabet_26[i])
										w2=i;
									if(lit22==alfabet_26[i])
										a2=i;
								}
								zes1=a2-a1;
								if(zes1<0)
									zes1=zes1+26;
								
								zes2=w2-w1;
								if(zes2<0)
									zes2=zes2+26;
								bool znal=false;
								for(int i=0; i<26; i++){
									if((zes1*i)%26==zes2){
										a=i;
										break;
									}
								}
								
								for(int i=0; i<12; i++){
									if(a==klucze26[i]){
										znal=true;
									}
								}
								if(znal){
									b=w1-(a1*a)%26;
									if(b<0)
										b=b+26;

									while((oda*a%26)!=1)
										oda++;	

									while(szyfrogram[licz]!=0){
										for(int k = 0; k<26; k++){
											if(szyfrogram[licz]>64&&(szyfrogram[licz]%32)-1>=b)
												odp[licz]=alfabet_26[((((szyfrogram[licz]%32)-1)-b)*oda)%26];
											
											else if(szyfrogram[licz]>64&&(szyfrogram[licz]%32)-1<b)
												odp[licz]=alfabet_26[((((szyfrogram[licz]%32)-1)+26-b)*oda)%26];
										}
										licz++;
									}
									system("cls");
									cout<<"Dla klucza: a = "<<a<<" i b = "<<b<<endl;
									cout<<"Odwrotnosc a: a' = "<<oda<<endl;
									cout<<endl;
									cout<<"Szyfrogram: "<<szyfrogram<<endl;
									cout<<endl;
									cout<<"String: "<<odp<<endl;
									cout<<endl;
									int n2;
									cout<<"Wybierz jedna z opcji"<<endl;
									cout<<"1. Sprobuj inna kombinacje"<<endl;
									cout<<"2. Zakoncz przeszukiwanie"<<endl;
									cout<<"Wybor: ";
									cin>>n2;
									if(n2==1){
										go=true;
									}
							
									else if(n2==2){
										go=false;
									}
							
									else{
										go=false;
										cout<<"Wybrano nie istniejaca opcje. Powrot do wyboru metody kryptoanalizy."<<endl;
										getch();
										cout<<endl;
									}
								}
								else{
									system("cls");
									cout<<"Nie ma poprawnej kombinacji dla tej pary podstawien."<<endl;
									cout<<"Wartosc a = "<<a<<" nie da pelnego alfabetu."<<endl;
									int n2;
									cout<<"Wybierz jedna z opcji"<<endl;
									cout<<"1. Sprobuj inna kombinacje"<<endl;
									cout<<"2. Zakoncz przeszukiwanie"<<endl;
									cout<<"Wybor: ";
									cin>>n2;
									if(n2==1){
										go=true;
									}
							
									else if(n2==2){
										go=false;
									}
							
									else{
										go=false;
										cout<<"Wybrano nie istniejaca opcje. Powrot do wyboru metody kryptoanalizy."<<endl;
            							getch();
										break;
									}
								}
							}
							break;
						}
						
						/*------------------------------------------------------------------*/
						
						case 9:{
							dzial=false;
							break;
						}
						
						default:{
							cout<<"Wybrano nie istniejaca opcje. Prosze wybrac ponownie."<<endl;
            				getch();
							break;
						}
					}
				}
            	break;
			}
			
			/*-------------------------------------------------------------------*/
			
			
			/*-------------------------------------------------------------------*/
			
			/*
				Po wybraniu drugiej opcji program zlicza wystapienia wszystkich
				
				znakow w szyfrogramie w oparciu o alfabet jêzyka polskiego,
				
				odpowiednie warunki dokonuj¹ modyfikacji stringa, aby polskie
				
				znaki by³y rozpoznawalne. Wyœwietla siê menu, które umo¿liwia wybór
				
				metody kryptoanalizy, b¹dŸ te¿ powrót do wczeœniejszego menu.
			*/
			
			case 3:{
				for(int i=0; i<32; i++){
            		zlicz_alfabet_32[i]=0;
				}
				getline(file, szyfrogram);
        		licznik=0;
        		while(szyfrogram[licznik]!=0){
        			int l = szyfrogram[licznik];
        			
        			if(l==(-71)||l==(-91)){
        				szyfrogram[licznik]='\245';
        				zlicz_alfabet_32[1]++;
					}
					
        			else if(l==(-26)||l==(-58)){
        				szyfrogram[licznik]='\206';
        				zlicz_alfabet_32[4]++;
					}
					
        			else if(l==(-22)||l==(-54)){
        				szyfrogram[licznik]='\251';
        				zlicz_alfabet_32[7]++;
					}
					
        			else if(l==(-77)||l==(-93)){
        				szyfrogram[licznik]='\210';
        				zlicz_alfabet_32[15]++;
					}
					
        			else if(l==(-15)||l==(-47)){
        				szyfrogram[licznik]='\344';
        				zlicz_alfabet_32[18]++;
					}
					
        			else if(l==(-13)||l==(-45)){
        				szyfrogram[licznik]='\242';
        				zlicz_alfabet_32[20]++;
					}
					
        			else if(l==(-100)||l==(-116)){
        				szyfrogram[licznik]='\230';
        				zlicz_alfabet_32[24]++;
					}
					
        			else if(l==(-97)||l==(-113)){
        				szyfrogram[licznik]='\253';
        				zlicz_alfabet_32[30]++;
					}
					
        			else if(l==(-65)||l==(-81)){
        				szyfrogram[licznik]='\276';
        				zlicz_alfabet_32[31]++;
					}        			
					for(int i=0; i<32; i++){
						if((szyfrogram[licznik]%32)-1==(alfabet_32[i]%32)-1 && l>0)
                			zlicz_alfabet_32[i]++;
                	}
            			licznik++;
        		}       		
        		bool dzial=true;
        		int n1;
				while(dzial){
					system("cls");
					cout<<endl; 
				   	for(int i=0; i<32; i++){
        				cout<<alfabet_32[i]<<": "<<zlicz_alfabet_32[i]<<"; ";
        			}
        			cout<<endl;
        			cout<<endl;
        			cout<<"Szyfrogram: "<<szyfrogram<<endl;
        			cout<<endl;
					cout<<"Prosze wybrac operacje"<<endl;
					cout<<"1. Kryptoanaliza przy uzyciu metody brute-force"<<endl;
					cout<<"2. Kryptoanaliza przy uzyciu ukladu rownan"<<endl;
					cout<<"9. Powrot do menu"<<endl;
					cout<<"Wybor: ";
					cin>>n1;
					switch(n1){
						
						
						/*------------------------------------------------------------------*/
						
						/*
							Dla ka¿dej kombinacji klucza (a,b) ka¿da litera szyfrogramu 
							
							jest przekszta³cana z wykorzystaniem wzoru f(x) = a^(-1)*(y-b)
							
							gdzie:
							
							a^(-1) - odwrotnosc a w ciele Z_26
							y - numer litery w alfabecie
							b - druga wartoœæ klucza
							
							Po wyœwietleniu przekszta³conego szyfrogramu wyœwietlaj¹ siê opcje
							
							sprawdzenia nastêpnej kombinacji lub zaprzestania sprawdzania.						
							 
						*/
						
						case 1:{
							bool go=true;
							string odp = szyfrogram;
							for(int i = 0; i<16; i++){
								int a = klucze32[i];
								int oda = 0;
								while((oda*a)%32!=1)
									oda++;	
								for(int j = 0; j<32; j++){
									int licz=0;
									while(szyfrogram[licz]!=0){
										if(szyfrogram[licz]>64&&szyfrogram[licz]<96)
											szyfrogram[licz]=szyfrogram[licz]+32;
										for(int k = 0; k<32; k++){
											if(szyfrogram[licz]==alfabet_32[k]&&k>=j)
												odp[licz]=alfabet_32[((k-j)*oda)%32];
												
											else if(szyfrogram[licz]==alfabet_32[k]&&k<j)
												odp[licz]=alfabet_32[((k+32-j)*oda)%32];
										}
										licz++;
									}
									system("cls");
									cout<<"Dla klucza: a = "<<a<<" i b = "<<j<<endl;
									cout<<"Odwrotnosc a: a' = "<<oda<<endl;
									cout<<endl;
									cout<<"Szyfrogram: "<<szyfrogram<<endl;
									cout<<endl;
									cout<<"String: "<<odp<<endl;
									cout<<endl;
									int n2;
									cout<<"Wybierz jedna z opcji"<<endl;
									cout<<"1. Pokaz nastepna kombinacje"<<endl;
									cout<<"2. Zakoncz przeszukiwanie"<<endl;
									cout<<"Wybor: ";
									cin>>n2;
									if(n2==1){
										go=true;
									}
									else if(n2==2){
										go=false;
									}
									else{
										go=false;
										cout<<"Dokonano zlego wyboru. Powrot do wyboru metody kryptoanalizy."<<endl;
										getch();
										cout<<endl;
									}
									if(!go){
										break;
									}
								}
								if(!go){
									break;
								}
							}
							break;
						}

						/*------------------------------------------------------------------*/
						
						/*------------------------------------------------------------------*/
						
						/*
							Wyœwietlanie s¹ litery, iloœæ ich wyst¹pieñ w szyfrogramie i ich czêstoœæ
							
							wystêpowania w jêzyku angielski, po czym u¿ytkownik na dokonuje dwóch wyborów
							
							podmiany liter np. a bêdzie przechodzi³o na b i d bêdzie przechodzi³o na w.
							
							Nastêpnie na podstawie wyborów wyliczane s¹ wspó³czynniki, które maj¹ na celu
							
							rozwi¹zanie uk³adu równañ:
							
							a*x1 + b = n1
							a*x2 + b = n2
							
							Najpierw zostanie wyliczona pierwsza wartoœæ klucza a. Je¿eli wyliczona
							
							wartoœæ a znajduje siê w tablicy kluczy, wyliczana jest drug¹ wartoœæ klucza b
							
							i odwrotnoœæ wartoœci a. Natêpnie wykonywane jest przekszta³cana z wykorzystaniem 
							
							wzoru f(x) = a^(-1)*(y-b) gdzie:
							
							a^(-1) - odwrotnosc a w ciele Z_26
							y - numer litery w alfabecie
							b - druga wartoœæ klucza
							
							Po wyœwietleniu przekszta³conego szyfrogramu wyœwietlaj¹ siê opcje
							
							sprawdzenia innej kombinacji lub zaprzestania sprawdzania.
							
							Je¿eli wyliczona wartoœæ a nie znajduje siê w tablicy kluczy, program zwraca
							
							komunikat, ¿e dla tej kombinacji kryptoanaliza jest niemo¿liwa i wyœwietla
							
							opcje sprawdzenia innej kombinacji lub zaprzestania sprawdzania.			
							 
						*/

						case 2:{
							bool go=true;
							system("cls");
							while(go){
								char lit11, lit12, lit21, lit22;
								int a1, w1, a2, w2, zes1, zes2, a, b;
								int oda=0;
								int licz=0;
								string odp=szyfrogram;
								cout<<"Litera, liczba liter; litera, czestosc wystepowania litery"<<endl;
								for(int i=0; i<32; i++){
									cout<<alfabet_32[i]<<":         "<<zlicz_alfabet_32[i]<<";            "<<alfabet_32[i]<<":        "<<czestosci_32Znaki[i]<<endl;
								}
								cout<<"Podstaw 1-sza litere."<<endl;
								cout<<"Za: ";
								cin>>lit11;
								cout<<"Podstaw: ";
								cin>>lit12;
								cout<<endl;
								cout<<"Podstaw 2-ga litere."<<endl;
								cout<<"Za: ";
								cin>>lit21;
								cout<<"Podstaw: ";
								cin>>lit22;

								for(int i=0; i<32; i++){
									if(lit11==alfabet_32[i])
										w1=i;
									if(lit12==alfabet_32[i])
										a1=i;
									if(lit21==alfabet_32[i])
										w2=i;
									if(lit22==alfabet_32[i])
										a2=i;
								}

								zes1=a2-a1;
								if(zes1<0)
									zes1=zes1+32;
								
								zes2=w2-w1;
								if(zes2<0)
									zes2=zes2+32;
								bool znal=false;
								for(int i=0; i<32; i++){
									if((zes1*i)%32==zes2){
										a=i;
										break;
									}
								}
								for(int i=0; i<16; i++){
									if(a==klucze32[i]){
										znal=true;
									}
								}
								if(znal){
									b=w1-(a1*a)%32;
									if(b<0)
										b=b+32;

									while((oda*a%32)!=1)
										oda++;	

									while(szyfrogram[licz]!=0){
										for(int k = 0; k<32; k++){
											if(szyfrogram[licz]==alfabet_32[k]&&k>=b)
												odp[licz]=alfabet_32[((k-b)*oda)%32];
												
											else if(szyfrogram[licz]==alfabet_32[k]&&k<b)
												odp[licz]=alfabet_32[((k+32-b)*oda)%32];
										}
										licz++;
									}
									system("cls");
									cout<<"Dla klucza: a = "<<a<<" i b = "<<b<<endl;
									cout<<"Odwrotnosc a: a' = "<<oda<<endl;
									cout<<endl;
									cout<<"Szyfrogram: "<<szyfrogram<<endl;
									cout<<endl;
									cout<<"String: "<<odp<<endl;
									cout<<endl;
									int n2;
									cout<<"Wybierz jedna z opcji"<<endl;
									cout<<"1. Sprobuj inna kombinacje"<<endl;
									cout<<"2. Zakoncz przeszukiwanie"<<endl;
									cout<<"Wybor: ";
									cin>>n2;
									if(n2==1){
										go=true;
									}
							
									else if(n2==2){
										go=false;
									}
							
									else{
										go=false;
										cout<<"Dokonano zlego wyboru. Powrot do wyboru metody kryptoanalizy."<<endl;
										getch();
										cout<<endl;
									}
								}
								else{
									system("cls");
									cout<<"Nie ma poprawnej kombinacji dla tej pary podstawien."<<endl;
									cout<<"Wartosc a = "<<a<<" nie da pelnego alfabetu."<<endl;
									int n2;
									cout<<"Wybierz jedna z opcji"<<endl;
									cout<<"1. Sprobuj inna kombinacje"<<endl;
									cout<<"2. Zakoncz przeszukiwanie"<<endl;
									cout<<"Wybor: ";
									cin>>n2;
									if(n2==1){
										go=true;
									}
							
									else if(n2==2){
										go=false;
									}
							
									else{
										go=false;
										cout<<"Dokonano zlego wyboru. Powrot do wyboru metody kryptoanalizy."<<endl;
										getch();
										cout<<endl;
									}
								}
							}
							break;
						}
						
						/*------------------------------------------------------------------*/
						
						case 9:{
							dzial=false;
							break;
						}
						
						default:{
							cout<<"Wybrano nie istniejaca opcje. Prosze wybrac ponownie."<<endl;
            				getch();
							break;
						}
					}
				}
				
				break;
			}
			
			/*------------------------------------------------------------------*/
			
			case 9:{
				dziala=false;
				break;
			}	

            default:{
            	cout<<"Wybrano nie istniejaca opcje. Prosze wybrac ponownie."<<endl;
            	getch();
				break;
			}
        }
    }
    return 0;
}
