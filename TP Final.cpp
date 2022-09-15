#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio2.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

//Ancho = 80   Alto = 25  (de la consola)

class Juego
{
protected:
	int puntaje=0, *dirp;
	char pantalla[80][25], arriba=72, izquierda=75, derecha=77, abajo=80, esc=27, tecla;
public:
	Juego();
	void play();
	void gotoxy(int, int);
	void mostrarPantalla();
	void OcultaCursor();
	void opciones();
	void mostrarPuntaje();
	void x();
};


Juego::Juego()
{
	dirp=&puntaje;
}

void Juego::play()
{
	while(tecla!=esc)
	{
		system("color a0");
		OcultaCursor();
		mostrarPantalla();
		mostrarPuntaje();
		opciones();
		Sleep(100);
	}
}

void Juego::mostrarPantalla()
{
	// Líneas horizontales
	for(int i=3; i < 116; i++){
		gotoxy (i, 1); printf ("%c", 205);
		gotoxy(i, 25); printf ("%c", 205);
	}
	//Líneas verticales
	for(int v=2; v < 25; v++){
		gotoxy (2,v);  printf ("%c", 186);
		gotoxy(116,v);  printf ("%c", 186);
	}
	// Esquinas
	gotoxy  (2,1);    printf ("%c", 201);
	gotoxy (2,25);    printf ("%c", 200);
	gotoxy (116,1);    printf ("%c", 187);
	gotoxy(116,25);    printf ("%c", 188);
}

void Juego::gotoxy(int x, int y)
{
	HANDLE hCon;
	COORD dwPos;
	
	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
}

void Juego::OcultaCursor() 
{
	CONSOLE_CURSOR_INFO cci = {100, FALSE}; 
	
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void Juego::mostrarPuntaje()
{
	gotoxy(2,27);
	cout<<"Puntaje: "<<puntaje<<endl;
}

void Juego::opciones()
{
	gotoxy(57,12);
	cout<<"Jugar";
	gotoxy(57,13);
	cout<<"Salir";
}


class Comida:public Juego
{
private:
	int xc,yc;
public:
	Comida();
	void ponerComida();
	void coords(int _x, int _y);
	int x();
	int y();
};

void Comida::coords(int _x, int _y) 
{
	xc = _x;
	yc = _y;
}

void Comida::ponerComida()
{
	gotoxy(xc,yc); printf("%c",4);
}

int Comida::x()
{
	return xc;
}

int Comida::y()
{
	return yc;
}


class Snake:public Juego
{
private:
	int cuerpo[200][2], n=1, tam=3, x=10, y=12;
public:
	Snake();
	void mostrarCuerpo();
	void borrar();
	void dibujar();
	void posicion();
};

void Snake::posicion()
{
	cuerpo[n][0]=x;
	cuerpo[n][1]=y;
	n++;
	if(n==tam)
	{
		n=1;
	}
	x++;
}

void Snake::dibujar()
{
	for(int i=1;i<tam;i++)
	{
	gotoxy(cuerpo[i][0], cuerpo[i][1]);
		cout<<"°";
	}
}

void Snake::borrar()
{
	gotoxy(cuerpo[n][0], cuerpo[n][1]);
	cout<<" ";
}


int main (int argc, char *argv[]) 
{
	Juego p;
	p.play();
	
	return 0;
}

