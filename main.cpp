#include <cstdlib> //we introduce the cstdlib library for the ability to use the rand function/wprowadzamy biblioteke cstdlib dla mozliwosci udźycja funkcji rand
#include <chrono> //library used to count the sorting time of particular algorithms/biblioteka wykorzystywana do zliczania czasu sortowania poszczegolnych algorytmow
#include <time.h>  //library to get current unix time/biblioteka do dostania obecnego unixowego czasu
#include <windows.h> //the library is used for the sleep function/biblioteka wykorzystana jest do funkcji sleep
#include "algorytmy.h" //header/tresc w naglowku

using namespace std;

int wylosuj(int min, int max)
{
	return rand()%max+min;
}

int main()
{
	srand(time(NULL)); //Set the seed to the current unix time/Ustawiamy seed na obecny czas unixowy
	int *tab, n, k;
	printf("Podaj ilosc cyfr do posortowania\n");
	cin>>n;
	tab = new int [n];
    buf = new int[n];
	for(int i=0;i<n;i++)
	{
		tab[i]=wylosuj(1, 1000); //reading numbers using the rand function in the min - max range (1 - 1000)/wczytywanie liczb za pomoca funkcji rand mieszczacych sie w zakresie min - max ( 1 - 1000)
	}
	printf("\nWybierz sortowanie: \n");
	printf("1 - przez wybor\n");
	printf("2 - przez wstawianie\n");
	printf("3 - babelkowe\n");
	printf("4 - przez scalanie\n");
	printf("5 - szybkie\n");

	int p;
	cin>>p;
	auto start = std::chrono::high_resolution_clock::now();

	switch(p)
	{
		case 1:
			selekcja(tab,n);
		break;
		case 2:
			wstawianie(tab,n);
		break;
		case 3:
			babelkowe(tab,n);
		break;
		case 4:
			scalanie(tab,0,n);
		break;
		case 5:
			szybkie(tab,0, n);
		break;
		default:
			printf("nie ma takiej opcji\n");
		break;
	}
	std::cout << "Czas dla sortowania : " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count() << "ms \n";
	sprawdz (tab,n); //a function to check the correctness of the algorithm/wywolanie funkcji sprawdzajacej poprawnosc algorytmu
	Sleep (1000); //the sleep command allows you to uncle the program for a second/komenda Sleep pozwala udycle program na sekunde

	for(int i=0;i<n;i++)
		cout<<tab[i]<<" "; //wypisanie posortowanych elementĂłw tablicy

	printf("\n");
	return 0;
}
