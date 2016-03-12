
#include "racional.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <string>
#include <stdlib.h>

using std::string;
using std::stringstream;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::cin;
using std::cout;
using std::ostream;

void imprimirMenu();
void imprimirLista(vector<Racional>);

int main(int argc, char const *argv[]){
	
	/*Racional a(0,0), b(2,-1), c(4,4), d(-5, 0);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	cout << "Favor ingrese un complejo: ";
	cin >> d;
	cout << "La suma de " << a << " y " << d << " es: " << a + d << endl;
*/
	vector<string> historial;
	vector<Racional> lista;
	int opcionMenu;
/*
	lista.push_back(a);
	lista.push_back(b);
	lista.push_back(c);
*/
	int opRacional1,opRacional2;
	stringstream ss;//aqui se guarda el codigo del historial. primer numero tipo de operacion, segundo posicion, terceroo posicion2
	int pos1, pos2;// esta es la conversion de char a int 
	do{
		imprimirMenu();
		cin >> opcionMenu;
		int numerador, denominador;
		if(opcionMenu == 1){
            cout<< "Ingrese el numerador: ";
            cin >> numerador;
            cout<< "Ingrese el denominador: ";
            cin >> denominador;
            lista.push_back(Racional(numerador,denominador));
        }
        else if(opcionMenu == 2){
        	imprimirLista(lista);
        	cout<< "Ingrese el primer racional: ";
            cin >> opRacional1;
            cout<< "Ingrese el segundo racional: ";
            cin >> opRacional2;
            
            ss<<1<<opRacional1<<opRacional2;
            historial.push_back(ss.str());
            ss.str("");
			
            cout<< lista[opRacional1] << " + " << lista[opRacional2] << " = "; 
            cout<< lista[opRacional1]+lista[opRacional2]; 
            cout<< endl;
        }else if(opcionMenu == 3){
        	imprimirLista(lista);
        	cout<< "Ingrese el primer racional: ";
            cin >> opRacional1;
            cout<< "Ingrese el segundo racional: ";
            cin >> opRacional2;

            ss<<2<<opRacional1<<opRacional2;
            historial.push_back(ss.str());
            ss.str("");
			
            cout<< lista[opRacional1] << " - " << lista[opRacional2] << " = "; 
            cout<< (lista[opRacional1]-lista[opRacional2]); 
            cout<< endl;

        }else if(opcionMenu == 4){
        	imprimirLista(lista);
        	cout<< "Ingrese el primer racional: ";
            cin >> opRacional1;
            cout<< "Ingrese el segundo racional: ";
            cin >> opRacional2;	
           
            ss<<3<<opRacional1<<opRacional2;
            historial.push_back(ss.str());
            ss.str("");
			

            cout<< lista[opRacional1] << " * " << lista[opRacional2] << " = "; 
            cout<< (lista[opRacional1]*lista[opRacional2]); 
            cout<< endl;


        }else if(opcionMenu == 5){
        	imprimirLista(lista);
        	cout<< "Ingrese el primer racional: ";
            cin >> opRacional1;
            cout<< "Ingrese el segundo racional: ";
            cin >> opRacional2;

            ss<<4<<opRacional1<<opRacional2;
            historial.push_back(ss.str());
            ss.str("");
			if(lista[opRacional1].getNum() == 0){
                cout<< "Error";
            }else
            cout<< lista[opRacional1] << " / " << lista[opRacional2] << " = ";
            cout << (lista[opRacional1]/ lista[opRacional2]);
            cout<< endl;
        }else if(opcionMenu == 6){
        	cout<< "---------------------historial---------------------"<< endl;
			for (int i = 0; i < historial.size(); ++i){
				cout << i+1 << ". ";
				
				if((historial.at(i))[0] == '1'){
					pos1 = (historial.at(i))[1]-'0';
					pos2 = (historial.at(i))[2]-'0';
					cout<< lista[pos1] << " + " << lista[pos2] << " = " << (lista[pos1]+ lista[pos2]).toString()<< endl;
				}
				if((historial.at(i))[0] == '2'){
					pos1 = (historial.at(i))[1]-'0';
					pos2 = (historial.at(i))[2]-'0';
					cout<< lista[pos1] << " - " << lista[pos2] << " = " << (lista[pos1]- lista[pos2]).toString()<< endl;
				}
				if((historial.at(i))[0] == '3'){
					pos1 = (historial.at(i))[1]-'0';
					pos2 = (historial.at(i))[2]-'0';
					cout<< lista[pos1] << " * " << lista[pos2] << " = " << (lista[pos1]* lista[pos2]).toString()<< endl;
				}
				if((historial.at(i))[0] == '4'){
					pos1 = (historial.at(i))[1]-'0';
					pos2 = (historial.at(i))[2]-'0';
					cout<< lista[pos1] << " / " << lista[pos2] << " = " << (lista[pos1]/ lista[pos2]).toString()<< endl;
				}
			}
        }
        if(opcionMenu == 7){
        	imprimirLista(lista);

        }
 	}while(opcionMenu!=8);
	return 0;
}

void imprimirLista(vector<Racional> arreglo){
	cout<< "---------------------RACIONALES---------------------"<< endl;
	for (int i = 0; i < arreglo.size(); ++i){
		cout << i << ". ";
		cout << arreglo.at(i).toString();
		cout << endl;
	}
}

void imprimirMenu(){
	cout<< "---------------------MENU---------------------"<< endl;
    cout<< "Ingresar opcion del menu:"<< endl;
    cout<< "1. Crear racionales"<<endl;
    cout<< "2. Suma de racionales"<<endl;
    cout<< "3. Resta de racionales"<<endl;
    cout<< "4. Multiplicacion de racionales"<<endl;
    cout<< "5. Division de racionales"<<endl;
    cout<< "6. Ver historial de operaciones"<<endl;
    cout<< "7. Imprimir Menu"<<endl;
    cout<< "8. Salir"<<endl;

}

