#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int menu();

char** crearMatriz(int, int);

void liberarMatriz(char**, int);

void imprimirMatriz(char**, int, int);

void contar(char**,int, int);

int main(){
	int opcion = 0;
	cout<<"Ingrese el número de columnas: ";
        int filas,columnas;
        cin>> columnas;
        cout<<"Ingrese el número de filas: ";
        cin>> filas;
	char** matriz = NULL;
	do{
		opcion = menu();
		while(opcion<1 || opcion >4){
			cout<<"El número que ha ingresafo no es válido."<<endl;
			opcion = menu();
		}
		if(opcion == 1){
			cout<<"------------------------------------"<<endl;
			matriz = crearMatriz(filas,columnas);
			cout<<"Matríz creada exitosamente"<<endl;
			cout<<"------------------------------------"<<endl;
		}
		if(opcion == 2){
			cout<<"------------------------------------"<<endl;
			imprimirMatriz(matriz, filas, columnas);
			cout<<"------------------------------------"<<endl;
		}
		if(opcion == 3){
			cout<<"------------------------------------"<<endl;
			contar(matriz,filas,columnas);	
			cout<<"------------------------------------"<<endl;
		}	
	}while(opcion != 4);
	liberarMatriz(matriz,filas);
	return 0;
}

int menu(){
	cout<<"		Menu"<<endl;
	cout<<"1.- Crear la matriz"<<endl
		<<"2.- Mostrar la matriz"<<endl
		<<"3.- Mostrar el número de azulejos seguros"<<endl
		<<"4.- Salir"<<endl;
	cout<<"		Ingrese una opción: ";
	int opcion;
	cin>>opcion;
	return opcion;
}

char** crearMatriz(int filas, int columnas){
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
			}else{
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

void liberarMatriz(char** mat, int filas){
        for(int i = 0; i<filas; i++){
                delete[] mat[i];
        }
        delete[] mat;
}

void imprimirMatriz(char** mat, int filas, int columnas){
	for(int i = 0; i<filas; i++){
		for(int j = 0; j<columnas; j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

void contar(char** mat, int filas, int columnas){
	int cont = 0;
	for(int i = 0; i<filas; i++){
		for(int j = 0; j<columnas; j++){
			if(mat[i][j] == '.'){
				cont++;
			}
		}
	}
	cout<<"El número de azulejos seguros es: "<<cont<<endl;
}
