//Lukasz Halbiniak
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void sleep() //Generalnie aplikacja wyglada lepiej
{
	system("pause");
	system("CLS");
}
class osoba //Klasa z danymi
{
public:
	string imie;
	string nazwisko;
	int staz;
	string adres;
};
class prezes :public osoba //Prezes z 2 funkcjami
{
public:
	void dodaj_0()
	{
		cout << "Podaj imie: " << endl;
		cin >> imie;
		cout << "Podaj nazwisko: " << endl;
		cin >> nazwisko;
		cin.ignore();
		cout << "Podaj adres: " << endl;
		getline(cin, adres);
		cout << "Podaj staz: " << endl;
		cin >> staz;
	}
	void wyswietl0()
	{
		cout << imie << " " << nazwisko << endl;
	}

};
class kierownik :public osoba
{
public:
	int numer;
	void dodaj_1()
	{
		cout << "Podaj imie: " << endl;
		cin >> imie;
		cout << "Podaj nazwisko: " << endl;
		cin >> nazwisko;
		cin.ignore();
		cout << "Podaj adres: " << endl;
		getline(cin, adres);
		cout << "Podaj staz: " << endl;
		cin >> staz;
		cout << "Podaj numer kierownika:" << endl;
		cin >> numer;
	}
	void wyswietl1()
	{
		cout << imie << " " << nazwisko << endl;
	}
};
class pracownik :public osoba
{
public:
	int kierownik_nr;
	void dodaj_2()
	{
		cout << "Podaj imie: " << endl;
		cin >> imie;
		cout << "Podaj nazwisko: " << endl;
		cin >> nazwisko;
		cin.ignore();
		cout << "Podaj adres: " << endl;
		getline(cin, adres);
		cout << "Podaj staz: " << endl;
		cin >> staz;
		cout << "Podaj numer kierownika opiekuna" << endl;
		cin >> kierownik_nr;
	}
	void wyswietl2()
	{
		cout << imie << " " << nazwisko << endl;
	}
};
class portier :public osoba
{
public:
	int kierownik_nr;
	void dodaj_3()
	{
		cout << "Podaj imie: " << endl;
		cin >> imie;
		cout << "Podaj nazwisko: " << endl;
		cin >> nazwisko;
		cin.ignore();
		cout << "Podaj adres: " << endl;
		getline(cin, adres);
		cout << "Podaj staz: " << endl;
		cin >> staz;
		cout << "Podaj numer kierownika opiekuna" << endl;
		cin >> kierownik_nr;
	}
	void wyswietl3()
	{
		cout << imie << " " << nazwisko << endl;
	}
};
int main()
{
	int a;
	vector <prezes> prezesi;
	vector <kierownik> kierownicy; 
	vector <pracownik> pracownicy;
	vector <portier> portierzy;
	do
	{
		cout << "Witaj w systemie ksiegowym. Wybierz teraz jedna z funkcji programu" << endl << "1. Dodaj pracownika" << endl << "2. Zapisz do piku"
			<< endl << "3. Wczytaj baze z pliku" << endl << "4. Dane o firmie" << endl << "5. Usun pracownika" << endl << "6.Wyjdz z programu" << endl;
		cin >> a;
		system("CLS"); // Menu powitalne z czyszczeniem ekranu
		switch (a)
		{
		case 1:
		{
				  cout << "Wybierz numerycznie jakiego pracownika chcesz dodac" << endl;
				  cout << "1. Prezes" << endl << "2. Kierownik" << endl << "3. Pracownik" << endl << "4. Portier" << endl;
				  int d;
				  cin >> d; //Dodawanie pracownika
				  switch (d)
				  {
				  case 1:
				  {
							prezes prezes_0;
							prezes_0.dodaj_0();
							prezesi.push_back(prezes_0);
							break;
				  }
				  case 2:
				  {
							kierownik kierownik_0;
							kierownik_0.dodaj_1();
							kierownicy.push_back(kierownik_0);

							break;
				  }
				  case 3:
				  {
							pracownik pracownik_0;
							pracownik_0.dodaj_2();
							pracownicy.push_back(pracownik_0);
							break;
				  }
				  case 4:
				  {
							portier portier_0;
							portier_0.dodaj_3();
							portierzy.push_back(portier_0);
							break;
				  }
				  }

				  cout << "Dodano osobe" << endl;
				  sleep();
				  break;
		}
		case 2:
		{
				  ofstream plik;
				  plik.open("Baza.txt", ios::trunc);
				  plik.close();
				  plik.open("Baza.txt");
				  int ilosc = prezesi.size(); //Zapis bazy danych. Trunc powoduje czyszczenie pliku baza na zapis danych
				  for (int c = 0; c < ilosc; c++)
				  {
					  if (c == 0)
					  {
						  plik << "0" << endl; //Kazdy pracownik ma swoj numer ktory mowi kim jest. W tym przypadku np. numer 0 to prezes
					  }//Na podstawie tych danych dochodzi do klasyfikacji danych z bazy
					  else
					  {
						  plik << endl << "0" << endl;
					  }
					  plik << prezesi[c].imie << endl;
					  plik << prezesi[c].nazwisko << endl;
					  plik << prezesi[c].adres << endl;
					  plik << prezesi[c].staz;
				  }
				  ilosc = kierownicy.size();
				  for (int c = 0; c < ilosc; c++)
				  {
					  plik << endl << "1" << endl;
					  plik << kierownicy[c].imie << endl;
					  plik << kierownicy[c].nazwisko << endl;
					  plik << kierownicy[c].adres << endl;
					  plik << kierownicy[c].staz << endl;
					  plik << kierownicy[c].numer;
				  }
				  ilosc = pracownicy.size();
				  for (int c = 0; c < ilosc; c++)
				  {
					  plik << endl << "2" << endl;
					  plik << pracownicy[c].imie << endl;
					  plik << pracownicy[c].nazwisko << endl;
					  plik << pracownicy[c].adres << endl;
					  plik << pracownicy[c].staz << endl;
					  plik << pracownicy[c].kierownik_nr;
				  }
				  ilosc = portierzy.size();
				  for (int c = 0; c < ilosc; c++)
				  {
					  plik << endl << "3" << endl;
					  plik << portierzy[c].imie << endl;
					  plik << portierzy[c].nazwisko << endl;
					  plik << portierzy[c].adres << endl;
					  plik << portierzy[c].staz << endl;
					  plik << portierzy[c].kierownik_nr;
				  }
				  plik.close();
				  cout << "Zapisano pomyslnie baze";
				  sleep();
				  break;
		}
		case 3:
		{
				  ifstream plik;
				  plik.open("Baza.txt");
				  int ident;
				  while (!plik.eof())//Odczyt danych 
				  {
					  plik >> ident;
					  if (ident == 0)
					  {
						  prezes prezes;
						  string lol;
						  plik >> prezes.imie;
						  plik >> prezes.nazwisko;
						  plik.seekg(2, ios::cur);//Program zapetlal sie w tym miejscu
						  getline(plik, lol);//Wystarczylo przesunac "karetke" o 2 pozycje do przodu, gdyz getline wczytywal koniec wiersza nazwisko 
						  prezes.adres = lol;
						  plik >> prezes.staz;
						  prezesi.push_back(prezes);
						 
					  }
					  if (ident == 1)
					  {
						  kierownik kierownik;
						  string lol;
						  plik >> kierownik.imie;
						  plik >> kierownik.nazwisko;
						  plik.seekg(2, ios::cur);
					      getline(plik, lol);
						  kierownik.adres = lol;
						  plik >> kierownik.staz;
						  plik >> kierownik.numer;
						  
						  kierownicy.push_back(kierownik);
					  }
					  if (ident == 2)
					  {
						  pracownik pracownik;
						  string lol;
						  plik >> pracownik.imie;
						  plik >> pracownik.nazwisko;
						  plik.seekg(2, ios::cur);
						  getline(plik, lol);
						  pracownik.adres = lol;
						  plik >> pracownik.staz;
						  plik >> pracownik.kierownik_nr;
						  pracownicy.push_back(pracownik);

					  }
					  if (ident == 3)
					  {
						  portier portier;
						  string lol;
						  plik >> portier.imie;
						  plik >> portier.nazwisko;
						  plik.seekg(2, ios::cur);
						  getline(plik, lol);
						  portier.adres = lol;
						  plik >> portier.staz;
						  plik >> portier.kierownik_nr;
						  portierzy.push_back(portier);
					  }

				  }
				  plik.close();
				  cout << "Pomyslnie wczytano z pliku" << endl;
				  sleep();
				  break;
		}
		case 4:
		{
				  int suma[5];
				  for (int t = 0; t < 5; t++) // To tutaj zapisywane sa wyniki 
				  {
					  suma[t] = 0;
				  } 
				 
				  int wynik = prezesi.size();
				  for (int q= 0; q < wynik; q++)
				  {
					  cout << "PREZES: ";
					  cout << q << "." << endl << "Imie: " << prezesi[q].imie << endl;
					  cout << "Nazwisko: " << prezesi[q].nazwisko << endl;
					  cout << "Adres: " << prezesi[q].adres << endl;
					  cout << "Staz: " << prezesi[q].staz << endl;
					  cout << "Pensja: " << 20000 << endl;
					  cout << " " << endl;
					  suma[0] = suma[0] + 20000;
				  }
				  wynik = kierownicy.size();
				  cout << " " << endl;
				  for (int q = 0; q < wynik; q++)
				  {
					  cout << "KIEROWNIK: ";
					  int dodatkowo = pracownicy.size() + portierzy.size();
					  int pensja = 5000 + (100 * kierownicy[q].staz) + 50 * dodatkowo;
					  cout << q << "." << endl << "Imie: " << kierownicy[q].imie << endl;
					  cout << "Nazwisko: " << kierownicy[q].nazwisko << endl;
					  cout << "Adres: " << kierownicy[q].adres << endl;
					  cout << "Staz: " << kierownicy[q].staz << endl;
					  cout << "Pensja: " << pensja << endl;
					  cout << " " << endl;
					  suma[1] = suma[1] + pensja;
				  }
				  wynik = pracownicy.size();
				  cout << " " << endl;
				  for (int q = 0; q < wynik; q++)
				  {
					  string napis;
					  napis = "Poznan";
					  cout << "PRACOWNIK: ";
					  if (pracownicy[q].adres.find(napis) != 0)
					  {
						  int pensja = 2000 + (75 * pracownicy[0].staz) + 100;
						  cout << q << "." << endl << "Imie: " << pracownicy[q].imie << endl;
						  cout << "Nazwisko: " << pracownicy[q].nazwisko << endl;
						  int e = kierownicy.size();
						  int numerek;
						  for (int y = 0; y < e; y++) //Znajdowanie numeru vectora odpowiedniego kierownika
						  {
							  if (kierownicy[y].numer == pracownicy[q].kierownik_nr)
							  {
								  numerek = y;
							  }
						  }
						  cout << "Adres: " << pracownicy[q].adres << endl;
						  cout << "Staz: " << pracownicy[q].staz << endl;
						  cout << "Kierownik: " << kierownicy[numerek].imie << " Nazwisko: " << kierownicy[numerek].nazwisko << endl;
						  cout << "Pensja: " << pensja << endl;
						  cout << " " << endl;
						  suma[2] = suma[2] + pensja;
					  }
				  }
				  wynik = portierzy.size();
				  cout << " " << endl;
				  for (int q = 0; q < wynik; q++)
				  {
					  cout << "PORTIER: ";
					  cout << q << "." << endl << "Imie: " << portierzy[0].imie << endl;
					  cout << "Nazwisko: " << portierzy[q].nazwisko << endl;
					  cout << "Adres: " << portierzy[q].adres<< endl;
					  cout << "Staz: " << portierzy[q].staz << endl;
					  int e = kierownicy.size();
					  int numerek;
					  for (int y = 0; y < e; y++)
					  {
						  if (kierownicy[y].numer == portierzy[q].kierownik_nr)
						  {
							  numerek = y;
						  }
					  }
					  cout << "Kierownik portiera: " << kierownicy[numerek].imie << " Nazwisko: " << kierownicy[numerek].nazwisko << endl;
					  cout << "Pensja: 1500" << endl;
					  cout << " " << endl;
					  suma[3] = suma[3] + 1500;
				  }
				  cout << " " << endl;
				  cout << " " << endl;
				  suma[4] = suma[0] + suma[1] + suma[2] + suma[3]; //Dane ogolne
				  cout << "Suma dla Prezesow: " << suma[0] << endl;
				  cout << "Suma dla Kierownikow: " << suma[1] << endl;
				  cout << "Suma dla Pracownikow: " << suma[2] << endl;
				  cout << "Suma dla Portierow: " << suma[3] << endl;
				  cout << "Calosciowa suma:" << suma[4] << endl;
				  cout << "By zakonczyc wyswietlanie nacisnij dowolny przycisk:" << endl;
				  cin.ignore();
				  sleep();
				  break;
		}
		case 5:
		{
				  cout << "Usuwanie. Wpisz numer osoby ktora chcesz usunac oraz numer identyfikacji." << endl<< "Numery 1. Prezes 2. Kierownik 3.Pracownik 4. Portier" << endl;
				  int prezes = prezesi.size();
				  int kierownik = kierownicy.size();
				  int pracownik = pracownicy.size();
				  int portier = portierzy.size();
				  for (int w = 0; w < prezes; w++)
				  {
					  cout << "Prezes:" << endl;
					  cout << w << ". ";
					  prezesi[w].wyswietl0();
				  }
				  for (int w = 0; w < kierownik; w++)
				  {
					  cout << "Kierownik" << endl;
					  cout << w << ". ";
					  kierownicy[w].wyswietl1();
				  }
				  for (int w = 0; w < pracownik; w++)
				  {
					  cout << "Pracownik" << endl;
					  cout << w << ". ";
					  pracownicy[w].wyswietl2();
				  }
				  for (int w = 0; w < portier; w++)
				  {
					  cout << "Portier" << endl;
					  cout << w << ". ";
					  portierzy[w].wyswietl3();
				  }
				  cout << "Numer identyfikacji: " << endl;
				  int d, h;
				  cin >> d;
				  cout << "Numer osoby: " << endl;
				  cin >> h;
				  switch (d)
				  {
				  case 1:
				  {
							prezesi.erase(prezesi.begin() + h);
							break;
				  }
				  case 2:
				  {
							kierownicy.erase(kierownicy.begin() + h);
							break;
				  }
				  case 3:
				  {
							pracownicy.erase(pracownicy.begin() + h);
							break;
				  }
				  case 4:
				  {
							portierzy.erase(portierzy.begin() + h);
							break;
				  }
				  }
				  cout << "Usunieto osobe" << endl;
				  sleep();
				  break;
				  
		}
		}
	} while (a != 6);
	cout << "Dziekuje za prace." << endl;
	return 0;
}