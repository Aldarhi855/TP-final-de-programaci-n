#include<iostream>
#include <ctime>
#include <cstdlib>
#include <conio2.h>

using namespace std;

class Juego
{
protected:
	int puntaje, *dirp;
	char pantalla[100][100];
public:
	void play();
	void mostrarPantalla();
	void Jugar();
	void Salir();
	Juego();
};


Juego::Juego()
{
	dirp=&puntaje;
}

void Juego::play()
{
	//que se muestre un men� con la pantalla verde, la puntuaci�n m�xima alcanzada
	//en la �ltima ronda y 2 opciones: Jugar y Salir
}

void Juego::mostrarPantalla()
{
	for(int i=0;i<15;i++)
	{
		for(int k=0;k<32;k++)
		{
			cout<<tablero[i][k];
		}
		cout<<endl;
	}
}


int main (int argc, char *argv[]) 
{
	Juego p;
	p.play();
	
	return 0;
}

