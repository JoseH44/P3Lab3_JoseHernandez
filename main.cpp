#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//funcion del juego
void conway(int**,int,int,int);

//funcion que imprime la matriz
void printMatrix(int**,int,int);

//funcion para liberar una matriz de enteros
void freeMatrix(int**,int);

//funcion que crea la matriz random
int** CreateMatriz(int**,int,int);



int main() {
	int opcion = 0;
	while(opcion != 3){
		cout<<"Bienvenido al Juego de la vida de Conway "<<endl<<"1.Jugar con Matriz Random "<<endl<<"2.Jugar con Matriz Predefinida "<<endl<<"3.Salir "
		<<endl<<"Ingrese la opcion a ejecutar: ";
		
		cin >> opcion;
		
		switch(opcion){
			case 1:{
				int x,y,turnos;
				cout <<"Ingrese el valor de y (Que representan las filas): ";
				cin >> y;
				//validacion
				while(y <= 0){
					cout << endl <<"El numero debe ser mayor que 0"<<endl;
					cout <<"Ingrese el valor de y (Que representan las filas): ";
					cin >> y;
				}
				cout <<endl << "Ingrese el valor de x (Que representan las Columnas): ";
				cin >> x;
				//validacion
				while(x <= 0){
					cout << endl <<"El numero debe ser mayor que 0"<<endl;
					cout <<"Ingrese el valor de x (Que representan las filas): ";
					cin >> x;
				}
				cout<<endl<<"Ingrese los Numeros de Turnos: ";
				cin >> turnos;
				//validacion
				while(turnos <= 0){
					cout << endl <<"El numero debe ser mayor que 0"<<endl;
					cout <<"Ingrese los Numeros de Turnos: ";
					cin >> turnos;
				}
				
				//matriz de punteros instanciada
				int** matriz = NULL;
				matriz = new int*[y];
				
				for(int i = 0;i < y; i++){
					matriz[i] = new int[x];
				}
				
				//lenado de numeros del 0-1
				matriz = CreateMatriz(matriz,y,x);
				
				//imprime la matriz
				printMatrix(matriz,y,x);
				
				//libera la memoria
				freeMatrix(matriz,y);
				matriz = NULL;
				
				
				break;
			}
			
			case 2:{
				//dimensiones de la matriz
				int x = 20;
				int y = 20;
				int turnos;
				cout<<endl<<"Ingrese los Numeros de Turnos: ";
				cin >> turnos;
				//matriz en duro 
				int temp_mat [20][20] = {
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,0,0},
					{0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,1,0},
					{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
					};
					
				//matriz de punteros
				int ** matrix = new int*[y];
				for(int i = 0; i < y ; i++){
					matrix[i] = new int[x];
					for(int j = 0; j < x ; j++){
						matrix[i][j] = temp_mat[i][j];
					}//fin del for interior
				}//fin del for exterior
				
				//imprime la matriz
				printMatrix(matrix,y,x);
				
				//limpia la matriz
				freeMatrix(matrix,y);
				matrix = NULL;
				

				break;
			}
			
			case 3:{
				cout << "Espero le haya gustado. Vuelva Pronto";
				break;
			}
		}
	}
	
	
	return 0;
}//fin del main


void conway(int** mat,int y,int x,int turnos){
	
}

void printMatrix(int** mat,int y,int x){
	//for para imprimir un marco superior
	cout<< endl;
	for(int i = 0; i < x; i++){
		cout << "$ ";
	}
	cout<<endl;
	
	for(int i = 0;i < y; i++){
		for(int j = 0; j < x; j++){
			
			if(mat[i][j] == 1){
				cout << "o ";
			}else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	
	//for para imprimir un marco inferior
	for(int i = 0; i < x; i++){
		cout << "$ ";
	}
	cout<<endl<<endl;
}

void freeMatrix(int** mat,int y){
	
	for(int i = 0;i < y;i++){
		delete[] mat[i];
	}
	
	//liberamos el arreglo de apuntadores
	delete[] mat;
}

int** CreateMatriz(int** mat,int y ,int x){
	int num_random;
	srand(time(NULL));
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			num_random = 0 + rand() % (2-0);
			mat[i][j] = num_random;
		}
	}
	
	return mat;
}


