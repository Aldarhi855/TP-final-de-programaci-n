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
	void comidaInicial();
};

class Snake:public Comida
{
protected:
	int cuerpo[200][2], n=1, tam=3, xp=10, yp=12, dir=3;
public:
	void mostrarCuerpo();
	void borrar();
	void posicion();
	void dibujar();
	void moverse();
	void comer();
	bool chocar();
};

class Juego:public Snake
{
private:
	int puntaje=0, racha=0, tamp=3, *dirp, velocidad=100, x=1;
	bool opcion;
	char tecla;
public:
	void gotoxy(int, int);
	void mostrarPantalla();
	void mostrarPuntaje();
	void configVel();
	void sumarPuntos();
	void opciones();
	bool Salir();
	void play();
};


void Comida::ponerComida()
{
	srand(time(NULL));
	xc=rand()%114+4;
	yc=rand()%23+4;
	gotoxy(xc, yc);
	cout<<(char)42;
}

void Comida::comidaInicial()
{
	gotoxy(xc, yc);
	cout<<(char)42;
}

void Snake::mostrarCuerpo()
{
	borrar();
	posicion();
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
}

void Snake::moverse()
{
	int tecla;
	if(kbhit())
	{
		tecla=getch();
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
		yp--;
	}
	 if(dir==2)
	{
		yp++;
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
		ponerComida();
	}
}

bool Snake::chocar()
{
	if(yp==2||yp==26||xp==3||xp==116)
	{
		gotoxy(55, 13);
		cout<<"¡Perdiste!";
		return true;
	}
	for(int i=(tam-1);i>0;i--)
	{
		if(cuerpo[i][0]==xp&&cuerpo[i][1]==yp)
		{
			gotoxy(55, 13);
			cout<<"¡Perdiste!";
			return true;
		}
	}
	return false;
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
	for(int j=2; j < 25; j++)
	{
		gotoxy(2,j);
		cout<<((char) 186);
		gotoxy(116,j);
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

void Juego::configVel()
{
	if(puntaje==x*20)
	{
		velocidad-=10;
		x++;
	}
}

void Juego::sumarPuntos()
{
	if(tam>tamp)
	{
		puntaje+=10;
		tamp++;
	}
}

void Juego::opciones()
{
	system("color a0");
	mostrarPantalla();
	gotoxy(54,12);
	cout<<"[1] Jugar";
	gotoxy(54,14);
	cout<<"[2] Salir";
	gotoxy(51,16);
	cout<<"Controles: flechas"<<endl;
	gotoxy(53,17);
	cout<<"de dirección.";
	tecla=getch();
	switch(tecla)
	{
	case 49:
		opcion=true;
		system("cls");
		play();
		break;
	case 50:
		opcion=false;
		gotoxy(0, 26);
	}
}

void Juego::play()
{
	system("color a0");
	mostrarPantalla();
	comidaInicial();
	while(chocar()==false&&opcion==true)
	{
		mostrarCuerpo();
		moverse();
		comer();
		chocar();
		sumarPuntos();
		mostrarPuntaje();
		configVel();
		Sleep(velocidad);
	}
	gotoxy(0, 26);
	system("pause");
	gotoxy(0, 26);
}


int main (int argc, char *argv[]) 
{
	Juego p;
	
	p.opciones();
	
	return 0;
}

