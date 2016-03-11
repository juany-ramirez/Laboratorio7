#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "racional.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

using std::cin;
using std::cout;


void imprimirMenu();
void eliminarVector(vector<Racional*>);
void imprimirLista(vector<Racional*>);
Racional simplificar(int, int);

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
	vector<Racional*> lista;
	int opcionMenu;
/*
	lista.push_back(a);
	lista.push_back(b);
	lista.push_back(c);
*/
	int opRacional1,opRacional2;
	do{
		imprimirMenu();
		cin >> opcionMenu;
		int numerador, denominador;
		if(opcionMenu == 1){
            cout<< "Ingrese el numerador: ";
            cin >> numerador;
            cout<< "Ingrese el denominador: ";
            cin >> denominador;
            lista.push_back(new Racional(simplificar(numerador,denominador)));
        }else if(opcionMenu == 2){
        	imprimirLista(lista);
        	cout<< "Ingrese el primer racional: ";
            cin >> opRacional1;
            cout<< "Ingrese el segundo racional: ";
            cin >> opRacional2;

        }else if(opcionMenu == 3){
        	imprimirLista(lista);
        	cout<< "Ingrese el primer racional: ";
            cin >> opRacional1;
            cout<< "Ingrese el segundo racional: ";
            cin >> opRacional2;

        }else if(opcionMenu == 4){
        	imprimirLista(lista);
        	cout<< "Ingrese el primer racional: ";
            cin >> opRacional1;
            cout<< "Ingrese el segundo racional: ";
            cin >> opRacional2;

        }else if(opcionMenu == 5){
        	imprimirLista(lista);
        	cout<< "Ingrese el primer racional: ";
            cin >> opRacional1;
            cout<< "Ingrese el segundo racional: ";
            cin >> opRacional2;

        }else if(opcionMenu == 6){
        	imprimirLista(lista);
        	cout<< "Ingrese el primer racional: ";
            cin >> opRacional1;
            cout<< "Ingrese el segundo racional: ";
            cin >> opRacional2;

        }
	}while(opcionMenu!=7);
	eliminarVector(lista);
	return 0;
}

void imprimirLista(vector<Racional*> arreglo){
	cout<< "---------------------RACIONALES---------------------"<< endl;
	for (int i = 0; i < arreglo.size(); ++i){
		//
		cout << i+1 << ". ";
		cout << arreglo.at(i) -> toString();
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
    cout<< "7. Salir"<<endl;

}

void eliminarVector(vector<Racional*> arreglo){
	for(int i=0;i<arreglo.size();i++){
        delete arreglo.at(i);
    }
	return;
} 


Racional simplificar(int num, int den){
	if(den<0){
		num *= -1;
	}
	if(den<0 && num<0){
		den *= -1;
		num *= -1;
	}
	int menor = num;
	if(menor>den){
		menor = num;
	}
	for (int i = 2; i < menor; i++){
		if(num%i==0 && den%2==0){
			num = num/i;
			den = den/i;
		}
	}
	Racional rac(num, den);
	return rac;
}


