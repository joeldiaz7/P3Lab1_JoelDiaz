#include <iostream>
#include <string.h>
#include <stdio.h>
#include <bits/stdc++.h> 
using namespace std;

void isTriangular(int);
void llenarMatriz();
void impMatriz();
void impPuntosSilla();
void combinaciones(char*);

bool t = true;
bool isT = false;
int op, num;
int menTriangular;
int matriz[5][5];

void combinaciones(char *cadena){
    int tamano=strlen(cadena);
    for(int i=0; i<tamano; ++i){
        for(int j=0; j<tamano; ++j){
            cout<<cadena[(i+j)%tamano];
        }
        cout<<endl;
        for(int p=tamano-1; p>=0; --p){
            cout<<cadena[(i+p)%tamano];
        }
    cout<<endl;
    }
}

void impPuntosSilla(){
	int pSilla=0;
    for (int x=0; x<5; ++x){
        for (int y=0; y<5; ++y){
        	int may=-9999999;
        	int men=99999999;
        	//
			for(int i=0; i<5; ++i){
				if(matriz[i][y]>may){
					may=matriz[i][y];
				}
			}
			//
			for(int j=0; j<5; ++j){
				if(matriz[x][j]<men){
					men=matriz[x][j];
				}
			}
			//
			if(matriz[x][y]==may && matriz[x][y]==men){
				cout<<"Punto silla: "<<matriz[x][y]<<" en ["<<x<<", "<<y<<"]"<<endl;
				pSilla=pSilla+1;
			}
        }
    }
    cout<<"Cantidad total de puntos silla: "<<pSilla<<endl;
}

void isTriangular(int n){
	menTriangular=1;
	for(int i=1; i<n; ++i){
		if( (i*(i+1)/2)<n ){
			menTriangular=(i*(i+1)/2);
			isT=false;
		}
		if( (i*(i+1)/2)==n){
			isT=true;
			i=n;
		}
	}
}

void llenarMatriz(){
	for(int i=0; i<5; ++i){
		for(int j=0; j<5; ++j){
			cout<<"Ingrese numero: ";
			cin>>num;
			matriz[i][j] = num;
		}
	}
}

void impMatriz(){
    for (int x=0; x<5; ++x){
        for (int y=0; y<5; ++y){
            cout<<"[" << matriz[x][y] << "]";
        }
        cout<<endl;
    } 
}

int main(){
	while(t){
		cout<<"Ingrese una opcion: "<<endl;
		cout<<"1) Ejercicio 1: Puntos de silla"<<endl;
		cout<<"2) Ejercicio 2: Numeros triangulares"<<endl;
		cout<<"3) Ejercicio 3: Secuencias"<<endl;
		cout<<"4) Salir"<<endl;
		cin>>op;
		int n=0;
		int sizeArray=0;
		switch(op){
			case 1://puntos silla
				llenarMatriz();
				impMatriz();
				cout<<endl;
				impPuntosSilla();
				cout<<endl;
				break;
			case 2://triangular
				cout<<"Ingrese un numero: "<<endl;
				cin>>n;
				isTriangular(n);
				if(isT){
					cout<<n<<" es triangular"<<endl;
				} else {
					cout<<n<<" no es triangular, el mas cercano es: "<<menTriangular<<endl;
				}
				cout<<endl;
				break;
			case 3://combinaciones
			    char cadena[20];
			    cout<<"Ingrese string: ";
			    cin>>cadena;
			    combinaciones(cadena);
				cout<<endl;
				break;
			case 4://salir
				return 0;
				break;
		}
	}
	//
	return 0;
}
