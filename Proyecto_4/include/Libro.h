#ifndef LIBRO_H
#define LIBRO_H
#include <string>

using namespace std;

class Libro
{
private:
    string nombre;
    string autor;
    string editorial;
    string categoria;
    string isbn;
    int existencia;
    int precio;
    int Rank;

public:
    Libro();
    Libro(string nombre, string autor, string isbn, string categoria, string editorial, int existencia,int precio);
    string getNombre() ;
    void setNombre(string);
    string getAutor() ;
    void setAutor(string);
    string getEditorial() ;
    void setEditorial(string);
    string getCategoria() ;
    void setCategoria(string);
    string getIsbn() ;
    void setIsbn(string);
    int getExistencia() ;
    void setExistencia(int value);
    string toString();
    int getRank() ;
    void setRank(int value);
};

#endif // LIBRO_H
