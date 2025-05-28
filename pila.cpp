#include "Pila.h"
#include <iostream>
#include <string>

using namespace std;

void Pila::push() {
    int valor;
    string valor2;
    Nodo* aux = new Nodo;
    // ubica espacio de memoria para crear una instancia del Nodo: operator new (Nodo))
   // y entonces construye un objeto en el nuevo espacio ubicado
    system("cls");
    cout << "Ingresa el nombre de la cancion: ";
    getline(cin, valor);
    cout << "Ingresa el artista: ";
    getline(cin, valor2);
    aux->dato = valor;
    aux->nombre = valor2;
    aux->sig = NULL;
    //Accede al elemento dato de Nodo y le asigna valor.
    if (inicio != NULL)
        aux->sig = inicio;
    inicio = aux;
    cout << "Cancion agregada\n";
    system("pause");
}

void Pila::pop() {
    Nodo* temp = new Nodo;
    if (inicio == NULL) {
        system("cls");
        cout << "\nLa Playlist esta vacia!\n\n";
        system("pause");
    }
    else {
        temp = inicio;
        inicio = inicio->sig;
        system("cls");
        cout << "\nLa cancion eliminada es: " << temp->dato << " - " << temp->nombre << "\n" << endl;
        delete temp;
        system("pause");
    }
}

void Pila::show() {
    Nodo* aux1 = inicio;
    if (inicio == NULL) {
        system("cls");
        cout << "\nLa Playlist esta vacia!\n\n";
        system("pause");
    }
    else {
        system("cls");
        cout << "Canciones:\n" << endl;
        while (aux1 != NULL) {
            cout << aux1->dato << " - " << aux1->nombre << "\n" << endl;
            aux1 = aux1->sig;
        }
        system("pause");
    }
}

void Pila::top() {
    Nodo* aux1 = inicio;
    if (inicio == NULL) {
        system("cls");
        cout << "\nLa Playlist esta vacia!\n\n";
        system("pause");
    }
    else {
        system("cls");
        cout << "Ultima cancion:\n" << endl;
        cout << aux1->dato << " - " << aux1->nombre << "\n" << endl;
        system("pause");
    }
}

void Pila::size() {
    Nodo* aux1 = inicio;
    if (inicio == NULL) {
        system("cls");
        cout << "\nLa Playlist esta vacia!\n\n";
        system("pause");
    }
    else {
        int contador = 0;
        while (aux1) {
            contador++;
            aux1 = aux1->sig;
        }
        system("cls");
        cout << "El tamano de la Playlist es: '" << contador << "'\n" << endl;
        system("pause");
    }
}
