#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int menu();

char** crearMatriz();

void liberarMatriz(char**, int, int);

int main(){
	int opcion = 0;
	do{
		opcion = menu();
		while(opcion<1 || opcion >5){
			cout<<"El número que ha ingresafo no es válido."<<endl;
			opcion = menu();
		}
		if(opcion == 1){
			cout<<"------------------------------------"<<endl;
			char** matriz = NULL;
			matriz = crearMatriz();

			cout<<"------------------------------------"<<endl;
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

char** crearMatriz(){
	cout<<"Ingrese el número de filas: ";
	int filas,columnas;
	cin>> filas;
	cout<<"Ingrese el número de columnas: ";
	cin>> columnas;
	char** matriz = new char*[filas];
	for(int i = 0; i<filas; i++){
		matriz[i] = new char[columnas];
	}
	for(int i = 0; i<1; i++){
		for(int j = 0; j<columnas; j++){
		char c;
		cout<< "Ingrese un caracter: ";
		cin>> c;
		matriz[i][j] = c;
		}

	}
	return matriz;
}

/*void liberarMatriz(char** mat, int filas, int columnas){
        for(int i = 0; i<size; i++){
                delete[] mat[i];
        }
        delete[] mat;
}*/
 

