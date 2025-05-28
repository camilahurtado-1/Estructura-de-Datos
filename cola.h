Cabezera de la clase
#include "StdAfx.h"
#include "Colae.h"
#include <iostream>

using namespace std;

Colae::Colae(void)
{	ini = 0; 
	fin = 0; 
}

bool Colae::ColaVacia (void) 
{	bool b_aux; 
	if (ini == fin) 
		b_aux = true; 
	else b_aux = false; 
	return b_aux; 
}

bool Colae::Encolar(int Valor) 
{ bool error; 
  if (fin == MAX) 
		error = true; 
  else 
  { error = false;
	info [fin] = Valor;
	fin++; } 
return error; 
}

bool Colae::PrimeroCola (int &Valor) 
{ bool error; 
	if (ColaVacia() ) 
		error = true; 
	else 
{	error = false; 
	Valor = info[ini]; } 
	return error; }

bool Colae::Desencolar (void) 
{	bool error; 
	if (ColaVacia() ) 
		error = true;
	else 
	{ error = false; 
	ini++; } 
return error; }

void Colae::mostrar()
{
	for (int i=ini;i<fin;i++)
		cout<<"["<<info[i]<<"]="<<endl;
	cout<<endl<<endl;
}
Incrementacion
#pragma once
#define MAX 100

class Colae
{ private: 
	int info[MAX]; 
	int ini, fin;
 public: 
	Colae (void); 
	bool Encolar (int Valor); 
	bool Desencolar (void); 
	bool PrimeroCola (int &Valor); 
	bool ColaVacia (void);
	void mostrar (void);
};
Main
#include "stdafx.h"
#include <iostream>
#include "Colae.h"
#define MAX 100

using namespace std;


void main()
{
	Colae cola;
	int Valor, opc;
	do {
		cout << "******* MENU ******* " << endl;
		cout << "1. LA COLA ESTA VACIA " << endl;
		cout << "2. ENCOLAR " << endl;
		cout << "3. DESENCOLAR " << endl;
		cout << "4. MOSTRAR " << endl;
		cout << "5. PRIMERO DE LA COLA " << endl;
		cout << "0. FINALIZAR " << endl;
		cin >> opc;
		switch (opc) {
		case 1:
			if (cola.ColaVacia())
				cout << " La cola esta vacia" << endl;
			else
				cout << " Tiene valores en la cola" << endl;
			break;
		case 2:
			cout << " Ingrese el dato " << endl;
			cin >> Valor;
			if (!cola.Encolar(Valor))
				cout << " Error no se encolo " << endl;
			else
				cout << "Ingresado con exito" << endl;
			break;
		case 3:
			if (cola.Desencolar())
				cout << "Error no se desencolo" << endl;
			else
				cout << "Desencolado con exito" << endl;
			break;
		case 4:
			cola.mostrar();
			break;
		case 5:
			if (cola.PrimeroCola(Valor))
				cout << "Cola Vacia" << endl;
			else
				cout << "El primero en la cola es" << Valor;
			break;
		case 0:
			cout << "Salir ";
			break;

		default:
			cout << "Error de opcion";
		}
	} while (opc != 0);
}
/*
	for (int j=1;j<10;j++)
		if (!cola.Encolar(j)) 
			cola.mostrar();
		else
			cout<<"Error";
	cout<<endl<<"Desencolar"<<endl;
	if (!cola.Desencolar())
		cola.mostrar();
	else
		cout<<"Error";
	if (!cola.PrimeroCola(Valor))
		cout<<"Valor: "<<Valor;
	getch();
}
*/
