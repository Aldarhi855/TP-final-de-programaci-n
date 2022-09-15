#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio2.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

class Comida
{
protected:
	int xc=30, yc=15;
public:
	void ponerComida();
};

class Snake:public Comida
{
protected:
	int cuerpo[200][2], n=1, tam=3, xp=10, yp=12, dir=3;
public:
	void mostrarCuerpo();
	void borrar();
	void dibujar();
	void posicion();
	void moverse();
	void comer();
	bool chocar();
};

class Juego:public Snake
{
private:
	int puntaje=0, *dirp;
	char tecla;
public:
	void gotoxy(int, int);
	void OcultaCursor();
	void mostrarPantalla();
	void mostrarPuntaje();
	void opciones();
	void play();
};


void Comida::ponerComida()
{
	gotoxy(xc, yc);
	cout<<(char)167;
}

void Snake::mostrarCuerpo()
{
	borrar();
	dibujar();
}

void Snake::borrar()
{
	gotoxy(cuerpo[n][0], cuerpo[n][1]);
	cout<<" ";
}

void Snake::dibujar()
{
	for(int i=1;i<tam;i++)
	{
	gotoxy(cuerpo[i][0], cuerpo[i][1]);
		cout<<"O";
	}
}


void Snake::posicion()
{
	cuerpo[n][0]=xp;
	cuerpo[n][1]=yp;
	n++;
	if(n==tam)
	{
		n=1;
	}
	xp++;
}

void Snake::moverse()
{
	int tecla;
	if(kbhit())
	{
		tecla=getch();
		switch(tecla)
		{
		case 72:
			if(dir!=2)
			{
				dir=1;
			}
			break;
		case 80:
			if(dir!=1)
			{
				dir=2;
			}
			break;
		case 77:
			if(dir!=4)
			{
				dir=3;
			}
			break;
		case 75:
			if(dir!=3)
			{
				dir=4;
			}
			break;
		}
	}
	if(dir==1)
	{
		yp++;
	}
	 if(dir==2)
	{
		yp--;
	}
	if(dir==3)
	{
		xp++;
	}
	if(dir==4)
	{
		xp--;
	}
}

void Snake::comer()
{
	if(xp==xc&&yp==yc)
	{
		tam++;
	}
}

bool Snake::chocar()
{
	if(yp==1||yp==25||xp==2||xp==116)
	{
		return true;
	}
	else 
	{
		return false;
	}
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

void Juego::mostrarPantalla()
{
	// Líneas horizontales
	for(int i=3; i < 116; i++)
	{
		gotoxy(i, 1); 
		cout<<((char) 205);
		gotoxy(i, 25);
		cout<<((char) 205);
	}
	//Líneas verticales
	for(int v=2; v < 25; v++)
	{
		gotoxy(2,v);
		cout<<((char) 186);
		gotoxy(116,v);
		cout<<((char) 186);
	}
	// Esquinas
	gotoxy(2,1);
	cout<<((char) 201);
	gotoxy(2,25);
	cout<<((char) 200);
	gotoxy(116,1);
	cout<<((char) 187);
	gotoxy(116,25);
	cout<<((char) 188);
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

void Juego::play()
{
	
	system("color a0");
	OcultaCursor();
	mostrarPantalla();
	while(tecla!=27&&chocar()==false)
	{
		mostrarPuntaje();
		opciones();
		borrar();
		posicion();
		dibujar();
		moverse();
		comer();
		Sleep(100);
	}
}


int main (int argc, char *argv[]) 
{
	Juego p;
	
	p.play();
	
	return 0;
}

