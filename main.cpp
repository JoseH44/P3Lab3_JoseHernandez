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



int main() {
	int opcion = 0;
	while(opcion != 3){
		cout<<"Bienvenido al Juego de la vida de Conway "<<endl<<"1.Jugar con Matriz Random "<<endl<<"2.Jugar con Matriz Predefinida "<<endl<<"3.Salir "
		<<endl<<"Ingrese la opcion a ejecutar: ";
		
		cin >> opcion;
		
		switch(opcion){
			case 1:{
				break;
			}
			
			case 2:{
				//dimensiones de la matriz
				int x = 20;
				int y = 20;
				
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
	cout<<endl;
}

void freeMatrix(int** mat,int y){
	
	for(int i = 0;i < y;i++){
		delete[] mat[i];
	}
	
	//liberamos el arreglo de apuntadores
	delete[] mat;
}


