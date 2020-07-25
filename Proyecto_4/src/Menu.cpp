#include "Menu.h"
#include <string.h>
#include <windows.h>

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}
bool Menu::Agregar(Libro libro){
     if(!Llena()){
        l[contador++] = libro;
        return true;}
    else
        return false;
}

bool Menu::Vacia(){
    if(contador == 0)
        return true;
    else
        return false;
}

bool Menu::Llena(){
    if(contador == 99)
        return true;
    else
        return false;
}

bool Menu::Elimina(string _isbn){
    int pos;
    pos=compararISBN(_isbn);
    if (pos >= 0 && pos < contador) {
        for (pos; pos < contador-1; pos++) {
            l[pos] = l[pos+1];
        }
        contador--;
        return true;
    }
    return false;
}

Libro Menu::Primer(){
    return l[0];
}

Libro Menu::Ultimo(){
    return l[contador-1];
}

Libro Menu::Anterior(int pos){
    return l[pos-1];
}

Libro Menu::Siguiente(int pos){
    return l[pos+1];
}

int Menu::Localiza(string buscado){
    for(int i=0; i<contador;i++){
        if(buscado == l[i].getNombre()){
            return i;
        }
        else if(buscado== l[i].getAutor()){
            return i;
        }
        else if(buscado == l[i].getIsbn()){
            return i;
        }
    }
    return -1;

}

Libro Menu::Recupera(int pos){
    return l[pos];

}

void Menu::Imprimir(){
    for (int i = 0; i<contador; i++){
        cout<<l[i].toString()<<endl;
    }
    system("pause");
}

void Menu::Borra()
{
    setContador(0);
}

int Menu::MenuPrincipal(){
    int respuesta;
    cout<<"\t\tLIBRERIA\n_______________________________________"<<endl;
    cout<<"[1] Agregar Nuevo\n[2] Lista Vacia?\n[3] Lista Llena?\n[4] Eliminar Libro\n[5] Mostrar Primer Libro\n[6] Mostrar Ultimo Libro\n[7] Mostrar Libro Anterior\n[8] Mostrar Libro Siguiente\n[9] Localizar Libro\n[10] Recuperar Libro\n[11] Imprimir Catalogo\n[12] Borrar Todo\n[13] Ordenar Libros\n[14] Cargar 10 Libros\n[15] Ventas\n[0] Salir"<<endl;
    cout<<"Opcion: ";
    cin>>respuesta;
    return respuesta;
}

void Menu::setContador(int numero){
    contador=numero;
}

int Menu::getContador(){
    return contador;
}

int Menu::compararISBN(string _isbn){
    for(int i=0;i<contador;i++){
        if(_isbn==l[i].getIsbn())
            return i;
    }
    return -1;
}

void Menu::Ordenar(){
    int opc;
    cout<<"Elija Forma a Ordenar"<<endl;
    cout<<"[1] Ordenar por Nombre"<<endl;
    cout<<"[2] Ordenar por Autor"<<endl;
    cout<<"[3] Ordenar por Categoria"<<endl;
    cout<<"[4] Ordenar por Ranking"<<endl;
    cin>>opc;
    switch(opc){
        case 1:{
            Libro aux;
            cout<<"\tBubbleSort,"<<endl;
            for(int i=getContador()-1;i>0;i--){
                for(int j=0;j<getContador()-1;j++){
                    if(l[j].getNombre()>l[j+1].getNombre()){
                        aux=l[j+1];
                        l[j+1]=l[j];
                        l[j]=aux;
                    }
                }
            }
            break;
        }
        case 2:{
            cout<<"\tInsertionSort"<<endl;
            Libro aux;
            int j;
            for(int i=1;i<=getContador()-1;i++){
                aux=l[i];
                j=i;
                while(j>0 && l[j-1].getAutor()>aux.getAutor()){
                    l[j]=l[j-1];
                    j--;
                }
                if(i!=j){
                    l[j]=aux;
                }
            }
            break;
        }
        case 3:{
            cout<<"\tSelectionSort"<<endl;
            int menor;
            Libro aux;
            for(int i=0;i<=getContador()-1;i++){
                menor=i;
                for(int j=i;j<=getContador()-1;j++){
                    if(l[j].getCategoria()<l[menor].getCategoria())
                        menor=j;
                }
                aux=l[i];
                l[i]=l[menor];
                l[menor]=aux;
            }
            break;
        }
        case 4:{
            Libro aux;
            cout<<"\tBubbleSort,"<<endl;
            for(int i=getContador()-1;i>0;i--){
                for(int j=0;j<getContador()-1;j++){
                    if(l[j].getRank()>l[j+1].getRank()){
                        aux=l[j+1];
                        l[j+1]=l[j];
                        l[j]=aux;
                    }
                }
            }
            break;
        }
    }
}

void Menu::Ventas(int cantidad,int indice){
    if(cantidad>l[indice].getExistencia()){
        cout<<"Existencias Insuficientes"<<endl;
    }
    else{
        l[indice].setExistencia(l[indice].getExistencia()-cantidad);
        l[indice].setRank(l[indice].getRank()+cantidad);
        cout<<"Realizando Transaccion"<<endl;
    }
    return;
}
