#include <algorithm>
#include <iostream>

using namespace std;

void selekcja(int tab[],int n)
{
	int mn_index;
	for(int i=0;i<n-1;i++)
	{
		mn_index = i;
		for(int j=i+1;j<n;j++)
			if(tab[j]<tab[mn_index])
				mn_index = j;
		swap(tab[i], tab[mn_index]);  
		//zamiana  najmniejszego elementu w biorze z i zamieniamy z pierwszą nieposortowaną pozycją
	}
}

void wstawianie(int *tab, int n)
{
	int buf, j;
	for(int i=1; i<n; i++)
	{
		//wstawienie elementu w odpowiednie miejsce
		buf = tab[i]; 
		//ten element będzie wstawiony w odpowiednie miejsce
		j = i-1;
		while(j>=0 && tab[j]>buf)
		{
			tab[j+1] = tab[j];
			 //przesuwanie elementów
			--j;
		}
		tab[j+1] = buf;
     }
}

void babelkowe(int tab[],int n)
{
	for(int i=0;i<n;i++)
		for(int j=1;j<n-i;j++)
		if(tab[j-1]>tab[j])
		 //porównywanie ze sobą 2 elementów i przy warunku gdy 1 liczba większa od 2, zamiana ich miejscami

    swap(tab[j-1], tab[j]);
}

int *buf; //bufor

void scal(int tab[], int lewy, int srodek, int prawy) 
 //scalenie posortowanych podtablic
{
	int i = lewy, j = srodek + 1;

  	for(int i = lewy;i<=prawy; i++)
    	buf[i] = tab[i];

	//scalenie dwóch podtablic pomocniczych i zapisanie ich we właściwej tablicy
	for(int k=lewy;k<=prawy;k++)
	if(i<=srodek)
    if(j <= prawy)
         if(buf[j]<buf[i])
             tab[k] = buf[j++];
         else
             tab[k] = buf[i++];
    else
        tab[k] = buf[i++];
  else
      tab[k] = buf[j++];
}
void scalanie(int tab[],int lewy, int prawy)
{
	if(prawy<=lewy) return; 
	 //gdy mamy jeden element, to jest on już posortowany
	int srodek = (prawy+lewy)/2;
	//znajdujemy srodek podtablicy
	scalanie(tab, lewy, srodek);
	//dzielimy tablice na część lewą i część prawą
	scalanie(tab, srodek+1, prawy);
	scal(tab, lewy, srodek, prawy); 
	//scalamy dwie już posortowane tablice
}

void szybkie(int *tab, int lewy, int prawy)
{
	if(prawy <= lewy) return;

	int i = lewy - 1, j = prawy + 1,
	piv = tab[(lewy+prawy)/2]; 
	//wybieramy punkt odniesienia

	while(true)
	{
		while(piv>tab[++i]);
		//szukam elementu wiekszego lub rownego piv stojacego po prawej stronie wartosci piv
		while(piv<tab[--j]);
		//analogicznie szukamy elementy mniejsze lub rowne piv stojacego po lewej stronie wartosci piv

		if( i <= j)
			swap(tab[i],tab[j]);
			//funkcja swap zamienia wartosciami tab[i] z tab[j]
		else
			break;
	}
	if(j > lewy)
	szybkie(tab, lewy, j);
	if(i < prawy)
	szybkie(tab, i, prawy);
}

void sprawdz(int tab[],int n) 
// funkcja sprawdzająca poprawność działania algorytmu
{
	for(int i=0; i<n-1; i++)
    {
		if(tab[i]>tab[i+1])
		{
			cout<<"Ciag liczb nie jest  uporzadkowany"<<endl;
			return; 
		}
    }
	cout<<"ciag liczb jest uporzadkowany"<<endl;
}


