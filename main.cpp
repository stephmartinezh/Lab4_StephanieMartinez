#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//                        cout<<"------------------------------------"<<endl
int menu();

int main(){
	int opcion = 0;
	do{
		opcion = menu();
		while(opcion<1 || opcion >5){
			cout<<"El número que ha ingresafo no es válido."<<endl;
			opcion = menu();
		}
			
	}while(opcion != 5);
	return 0;
}

int menu(){
	cout<<"		Menu"<<endl;
	cout<<"1.- Crear la matriz"<<endl
		<<"2.- Descifrar los azulejos"<<endl
		<<"3.- Mostrar la matriz"<<endl
		<<"4.- Mostrar el número de azulejos seguros"<<endl
		<<"5.- Salir"<<endl;
	cout<<"		Ingrese una opción: ";
	int opcion;
	cin>>opcion;
	return opcion;
}
