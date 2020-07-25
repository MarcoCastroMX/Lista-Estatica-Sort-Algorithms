#ifndef MENU_H
#define MENU_H
#include "Libro.h"
#include <iostream>
#include <sstream>

using namespace std;

class Menu
{
    private:
        Libro l[100];
        int contador;

    public:
        Menu();
        int MenuPrincipal();
        bool Agregar(Libro);
        bool Vacia();
        bool Llena();
        bool Elimina(string);
        Libro Primer();
        Libro Ultimo();
        Libro Anterior(int);
        Libro Siguiente(int);
        int Localiza(string);
        Libro Recupera(int);
        void Imprimir();
        void Borra();
        void setContador(int);
        int getContador();
        int compararISBN(string);
        void Ordenar();
        void Ventas(int,int);
        virtual ~Menu();
};

#endif // MENU_H
