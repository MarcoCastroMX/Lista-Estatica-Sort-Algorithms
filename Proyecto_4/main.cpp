#include <iostream>
#include "Libro.h"
#include "Menu.h"
#include <windows.h>

using namespace std;

int main()
{
    int opc,numero,res,precio;
    string nombre,autor,isbn,categoria,editorial,Buscar;
    bool buu;
    Menu m;
    m.setContador(0);
    do{
    system("cls");
    opc=m.MenuPrincipal();
    switch(opc)
    {
        case 1:{
            system("cls");
            cout<<"\t\tAGREGAR"<<endl;
            cout<<"_______________________________________"<<endl;
            cin.ignore();
            cout<<"Ingresa el Nombre: "<<endl;
            getline(cin,nombre);
            cout<<"Ingresa el Autor: "<<endl;
            getline(cin,autor);
            cout<<"Ingresa el ISBN: "<<endl;
            getline(cin,isbn);
            res=m.compararISBN(isbn);
            if(res!=-1){
                cout<<"ISBN YA EXISTENTE"<<endl;
                Sleep(1000);
                break;
            }
            else{
                cout<<"Ingresa la Categoria: "<<endl;
                getline(cin,categoria);
                cout<<"Ingresa el Editorial: "<<endl;
                getline(cin,editorial);
                cout<<"Ingresa la Exitencia: "<<endl;
                cin>>numero;
                cout<<"Ingresa el Precio: "<<endl;
                cin>>precio;
                Libro book(nombre,autor,isbn,categoria,editorial,numero,precio);
                buu=m.Agregar(book);
                numero=m.getContador();
                if(buu==true){
                    cout<<"LIBRO AGREGADO CON EXITO"<<endl;
                    Sleep(1000);
                    m.setContador(numero++);
                    break;
                }
                else{
                    cout<<"ERROR EN EL PROCESO"<<endl;
                    Sleep(1000);
                    m.setContador(numero--);
                    break;
                }
            }
        }
        case 2:{
            system("cls");
            cout<<"\t\tVACIA"<<endl;
            cout<<"_______________________________________"<<endl;
            buu=m.Vacia();
            if(buu==true){
                cout<<"LISTA VACIA"<<endl;
                Sleep(1000);
                break;
            }
            else{
                cout<<"LISTA NO VACIA"<<endl;
                Sleep(1000);
                break;
            }
        }
        case 3:{
            system("cls");
            cout<<"\t\tLLENA"<<endl;
            cout<<"_______________________________________"<<endl;
            buu=m.Llena();
            if(buu==true){
                cout<<"LISTA LlENA"<<endl;
                Sleep(1000);
                break;
            }
            else{
                cout<<"LISTA NO LLENA"<<endl;
                Sleep(1000);
                break;
            }
        }
        case 4:{
            system("cls");
            cout<<"\t\tELIMINAR"<<endl;
            cout<<"_______________________________________"<<endl;
            if (m.Vacia()== true) {
                cout<<"LISTA VACIA"<<endl;
                Sleep(1000);
                break;
            }
            else{
                cout<<"Escriba ISBN a Eliminar: "<<endl;
                cin>>isbn;
                m.Elimina(isbn);
                Sleep(1000);
                break;
            }
        }
        case 5:{
            system("cls");
            cout<<"\tMOSTRAR EL PRIMER ELEMENTO"<<endl;
            cout<<"_______________________________________"<<endl;
            if (m.Vacia()== true) {
                cout<<"LISTA VACIA"<<endl;
                Sleep(1000);
                break;
            }
            else{
                cout<<"Primer Libro: "<<m.Primer().toString()<<endl;
                Sleep(1000);
                break;
            }
        }
        case 6:{
            system("cls");
            cout<<"\tMOSTRAR EL ULTIMO ELEMENTO"<<endl;
            cout<<"_______________________________________"<<endl;
            if (m.Vacia()== true) {
                cout<<"LISTA VACIA"<<endl;
                Sleep(1000);
                break;
            }
            else{
                cout<<"Ultimo Libro: "<<m.Ultimo().toString()<<endl;
                Sleep(1000);
                break;
            }
        }
        case 7:{
            int pos;
            system("cls");
            cout<<"\tMOSTRAR EL LIBRO ANTERIOR"<<endl;
            cout<<"_______________________________________"<<endl;
            if (m.Vacia()== true) {
                cout<<"LISTA VACIA"<<endl;
                Sleep(1000);
                break;
            }
            else{
                cout<<"Escriba Pocision a Mostrar: "<<endl;
                cin>>pos;
                if(pos<1||pos>m.getContador()){
                    cout<<"Valor No Valido"<<endl;
                    Sleep(1000);
                    break;
                }
                else{
                   cout<<"Libro Anterior: "<<m.Anterior(pos).toString()<<endl;
                    Sleep(1000);
                    break;
                }
            }
        }
        case 8:{
            int pos;
            system("cls");
            cout<<"\tMOSTRAR EL LIBRO SIGUIENTE"<<endl;
            cout<<"_______________________________________"<<endl;
            if (m.Vacia()== true) {
                cout<<"LISTA VACIA"<<endl;
                Sleep(1000);
                break;
            }
            else{
                cout<<"Escriba Pocision a Mostrar: "<<endl;
                cin>>pos;
                if(pos<0||pos>=m.getContador()-1){
                    cout<<"Valor No Valido"<<endl;
                    Sleep(1000);
                    break;
                }
                else{
                   cout<<"Libro Siguiente: "<<m.Siguiente(pos).toString()<<endl;
                    Sleep(1000);
                    break;
                }
            }
        }
        case 9:{
            int eleccion;
            system("cls");
            cout<<"\t\tLOCALIZAR"<<endl;
            cout<<"_______________________________________"<<endl;
            if (m.Vacia()== true) {
                cout<<"LISTA VACIA"<<endl;
                Sleep(1000);
                break;
            }
            else{
                cout<<"Elija de que Forma Buscarlo:\n[1] Nombre\n[2] Autor\n[3] ISBN "<<endl;
                cin>>eleccion;
                if(eleccion==1){
                    cout<<"Escribe Nombre A Buscar: "<<endl;
                    cin>>nombre;
                    res=m.Localiza(nombre);
                    if(res!=-1){
                        cout<<"Pocision: "<<m.Localiza(nombre)<<endl;
                        Sleep(1000);
                        break;
                    }
                    else{
                        cout<<"Nombre Inexistente"<<endl;
                        Sleep(1000);
                        break;
                    }
                }
                else if(eleccion==2){
                    cout<<"Escribe Autor A Buscar: "<<endl;
                    cin>>autor;
                    res=m.Localiza(autor);
                    if(res!=-1){
                        cout<<"Pocision: "<<m.Localiza(autor)<<endl;
                        Sleep(1000);
                        break;
                    }
                    else{
                        cout<<"Autor Inexistente"<<endl;
                        Sleep(1000);
                        break;
                    }
                }
                else if(eleccion==3){
                    cout<<"Escribe ISBN A Buscar: "<<endl;
                    cin>>isbn;
                    res=m.Localiza(isbn);
                    if(res!=-1){
                        cout<<"Pocision: "<<m.Localiza(isbn)<<endl;
                        Sleep(1000);
                        break;
                    }
                    else{
                        cout<<"ISBN Inexistente"<<endl;
                        Sleep(1000);
                        break;
                    }
                }
                else{
                    cout<<"Opcion No Valida"<<endl;
                    Sleep(1000);
                    break;
                }
            }
        }
        case 10:{
            int pocision;
            system("cls");
            cout<<"\t\tRECUPERAR"<<endl;
            cout<<"_______________________________________"<<endl;
            if (m.Vacia()== true) {
                cout<<"LISTA VACIA"<<endl;
                Sleep(1000);
                break;
            }
            else{
                cout<<"Escriba Pocision a Recuperar: "<<endl;
                cin>>pocision;
                if(pocision<0 || pocision>=m.getContador()){
                    cout<<"Valor No Valiido"<<endl;
                    Sleep(1000);
                    break;
                }
                else{
                    cout<<"Datos Optenidos: "<<m.Recupera(pocision).toString()<<endl;;
                    Sleep(1000);
                    break;
                }
            }
        }
        case 11:{
            system("cls");
            cout<<"\t\tCATALOGO"<<endl;
            cout<<"_______________________________________"<<endl;
            m.Imprimir();
            break;
        }
        case 12:{
            system("cls");
            cout<<"\t\tBorrar Todo"<<endl;
            cout<<"_______________________________________"<<endl;
            m.Borra();
            break;
        }
        case 13:{
            system("cls");
            cout<<"\t\tORDENAMIENTOS"<<endl;
            cout<<"_______________________________________"<<endl;
            if (m.Vacia()== true) {
                cout<<"LISTA VACIA"<<endl;
                Sleep(1000);
                break;
            }
            m.Ordenar();
            system("pause");
            break;
        }
        case 14:{
            if(m.getContador()<10)
            {
                Libro l1("Narraciones Extraordinarias","Edgar Allan Poe","001","Horror","Leyenda",5,120);
                m.Agregar(l1);
                Libro l2("1984","George Orwell","002","Ciencia Ficcion","EPOCA",19,120);
                m.Agregar(l2);
                Libro l3("Dracula","Bram Stoker","003","Horror","Leyenda",2,200);
                m.Agregar(l3);
                Libro l4("El Retrato de Dorian Gray","Oscar Wilde","004","Ficcion Gotica","Leyenda",8,100);
                m.Agregar(l4);
                Libro l5("El Principito","Antonie de Saint Exupery","005","Fabula","Leyenda",9,60);
                m.Agregar(l5);
                Libro l6("Dialogos","Platon","006","Novela historica","Leyenda",1,180);
                m.Agregar(l6);
                Libro l7("El Principe","Nicolas Maquiavelo","007","No Ficcion","Leyenda",21,70);
                m.Agregar(l7);
                Libro l8("Un Mundo Feliz","Aldous Huxley","008","Ciencia ficcion","Edhasa",20,140);
                m.Agregar(l8);
                Libro l9("El Cantar del Mio Cid","Anonimo","009","Cantar de Gesta","Tomo",11,20);
                m.Agregar(l9);
                Libro l10("120 Dias de Sodoma","Marques de Sade","010","Literatura Erotica","Tomo",2,20);
                m.Agregar(l10);
            }
            else
            {
                cout<<"\tLibros Ya Agregados"<<endl;
                Sleep(1000);
            }
            break;

        }
        case 15:{
            system("cls");
            int busqueda,cantidad,indice;
            if (m.Vacia()== true) {
                cout<<"LISTA VACIA"<<endl;
                Sleep(1000);
                break;
            }
            cout<<"Forma de Busqueda:\n[1] ISBN\n[2] Nombre"<<endl;
            cin>>busqueda;
            if(busqueda==1)
            {
                cout<<"Ingrese ISBN: "<<endl;
                cin>>Buscar;
                indice=m.Localiza(Buscar);
                if(indice!=-1){
                    cout<<"Cantidad de Copias:"<<endl;
                    cin>>cantidad;
                    m.Ventas(cantidad,indice);
                }
            }
            else if(busqueda==2)
            {
                cin.ignore();
                cout<<"Ingrese El Nombre: "<<endl;
                getline(cin,Buscar);
                indice=m.Localiza(Buscar);
                if(indice!=-1){
                    cout<<"Cantidad de Copias:"<<endl;
                    cin>>cantidad;
                    m.Ventas(cantidad,indice);
            }
            else
            {
                cout<<"Opcion no valida"<<endl;
                Sleep(1000);
                break;
            }
            system("pause");
            break;
        }
        }
        case 0:{
            system("cls");
            cout<<"\t\tCERRANDO"<<endl;
            cout<<"_______________________________________"<<endl;
            break;
        }
    }
    }while(opc!=0);

    return 0;
}
