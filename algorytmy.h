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
		//swap the smallest element in the set with and swap with the first unsorted item/zamiana  najmniejszego elementu w biorze z i zamieniamy z pierwszą nieposortowaną pozycją
	}
}

void wstawianie(int *tab, int n)
{
	int buf, j;
	for(int i=1; i<n; i++)
	{
		//insert the item in the correct place/wstawienie elementu w odpowiednie miejsce
		buf = tab[i]; 
		//this item will be inserted in the correct place/ten element będzie wstawiony w odpowiednie miejsce
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
		 //comparing 2 elements with each other and, under the condition that 1 number is greater than 2, swapping their places/porównywanie ze sobą 2 elementów i przy warunku gdy 1 liczba większa od 2, zamiana ich miejscami

    swap(tab[j-1], tab[j]);
}

int *buf; //bufor

void scal(int tab[], int lewy, int srodek, int prawy) 
 //merge sorted subarrays/scalenie posortowanych podtablic
{
	int i = lewy, j = srodek + 1;

  	for(int i = lewy;i<=prawy; i++)
    	buf[i] = tab[i];

	//merging the two auxiliary subarrays and storing them in the proper array/scalenie dwóch podtablic pomocniczych i zapisanie ich we właściwej tablicy
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
	 //when we have one element, it is already sorted/gdy mamy jeden element, to jest on już posortowany
	int srodek = (prawy+lewy)/2;
	//we find the middle of the subarray/znajdujemy srodek podtablicy
	scalanie(tab, lewy, srodek);
	//divide the tables into left and right parts/dzielimy tablice na część lewą i część prawą
	scalanie(tab, srodek+1, prawy);
	scal(tab, lewy, srodek, prawy); 
	//we merge two already sorted arrays/scalamy dwie już posortowane tablice
}

void szybkie(int *tab, int lewy, int prawy)
{
	if(prawy <= lewy) return;

	int i = lewy - 1, j = prawy + 1,
	piv = tab[(lewy+prawy)/2]; 
	//we choose a reference point/wybieramy punkt odniesienia

	while(true)
	{
		while(piv>tab[++i]);
		//I am looking for an element greater than or equal to piv to the right of piv/szukam elementu wiekszego lub rownego piv stojacego po prawej stronie wartosci piv
		while(piv<tab[--j]);
		//Similarly, we search for elements less than or equal to piv to the left of piv/analogicznie szukamy elementy mniejsze lub rowne piv stojacego po lewej stronie wartosci piv

		if( i <= j)
			swap(tab[i],tab[j]);
			//swap function replaces tab[i] with tab[j]/funkcja swap zamienia wartosciami tab[i] z tab[j]
		else
			break;
	}
	if(j > lewy)
	szybkie(tab, lewy, j);
	if(i < prawy)
	szybkie(tab, i, prawy);
}

void sprawdz(int tab[],int n) 
//a function that checks the correctness of the algorithm/funkcja sprawdzająca poprawność działania algorytmu
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


