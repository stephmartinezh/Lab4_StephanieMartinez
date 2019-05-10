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
	char** mat = new char*[filas];
	for(int i = 0; i<filas; i++){
		mat[i] = new char[columnas];
	}
	for(int i = 0; i<1; i++){
		for(int j = 0; j<columnas; j++){
		char c;
		cout<< "Ingrese un caracter: ";
		cin>> c;
		mat[i][j] = c;
		}

	}
	for(int i = 1; i<filas; i++){
		for(int j = 0; j<columnas; j++){
			char let1, let2, let3;
			if(j-1<0){
				let1 = '.';
			}else{
				let1 = mat[i-1][j-1];
			}
			if(j+1>columnas){
				let3 = '.';
				let3 = mat[i-1][j+1];
			}
			let2 = mat[i-1][j];
			if(let1== '^' && let2 == '^' && let3 == ','){
				mat[i][j] = '^';
			} else if(let1 == '.' && let2 == '^' && let3 == '^'){
				mat[i][j] = '^';
			} else if(let1 == '^' && let2 == '.' && let3 == '.'){
				mat[i][j] = '^';
			} else if(let1 == '.' && let2 == '.' && let3 == '^'){
				mat[i][j] = '^';
			} else{
				mat[i][j] = '.';
			}
		}
	}
	return mat;
}

/*void liberarMatriz(char** mat, int filas, int columnas){
        for(int i = 0; i<size; i++){
                delete[] mat[i];
        }
        delete[] mat;
}*/
 

