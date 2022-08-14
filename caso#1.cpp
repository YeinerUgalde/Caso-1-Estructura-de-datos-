#include <iostream>
#include <string>
#include <stdlib.h> 
#include<algorithm>

using namespace std; 

/*---------------------------------------------------------------------------------------------------
En el readme del github se encuentra la expliacaion de la solucion y el metodo de uso
---------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------
La cantidad de regiones debe de ser la misma que la de filas y columnas de la matriz suministrada
---------------------------------------------------------------------------------------------------*/
#define Cantidad_de_regiones 11 //*****
//---------------------------------------------------------------------------------------------------

void mostrarMat(int pMat[Cantidad_de_regiones][Cantidad_de_regiones]){
    for (int i=0; i<Cantidad_de_regiones;++i){
        for (int j=0; j<Cantidad_de_regiones;j++){
            cout << pMat[i][j] << " ";
        }
    cout << endl;
    }
    cout << endl;
}

void mostrarArr(int pArr[Cantidad_de_regiones]){
    for (int i=0; i<Cantidad_de_regiones;++i){cout << pArr[i] << " ";}
    cout << endl;}


//Esta funcion solo es para generar adyacentes en caso de que no se suministre un mapa
void adyacentes(int pAdyacencia[Cantidad_de_regiones][Cantidad_de_regiones]){
    for (int i=0;i<Cantidad_de_regiones;++i){
        for (int j=0;j<(Cantidad_de_regiones-(rand() % Cantidad_de_regiones)*1.5)+1;++j){
            int nRand = rand() % Cantidad_de_regiones;
            pAdyacencia[i][nRand]={1};
            pAdyacencia[nRand][i]={1};
        }
    }
}

bool Esta (int elem,int arr [Cantidad_de_regiones]){
    for (int i = 0;i<Cantidad_de_regiones;++i){
        if (elem==arr[i]){
            return 1;
        }
    }
    return 0;
}

void fourColor(int pAdyacencia[Cantidad_de_regiones][Cantidad_de_regiones],int color_de_regiones[Cantidad_de_regiones]){
    for (int i=0;i<Cantidad_de_regiones;++i)
    {
        if (!color_de_regiones[i]){
            int adyacentes[Cantidad_de_regiones]={};
            for (int j=0;j<Cantidad_de_regiones;++j){
                if (pAdyacencia[i][j]==1){
                    adyacentes[j]=1;
                    }
                }
            int colores [Cantidad_de_regiones]={};
            int cero = 0;
            for(int j=0;j<Cantidad_de_regiones;++j){
                if(adyacentes[j]==1){
                    colores[++cero]=color_de_regiones[j];
                    }
                }
            for (int j=1;j<5;++j){
                bool esta = Esta(j,colores);
                if(!esta){
                    color_de_regiones[i]={j};
                    break;
                    }
                }
            }
    }
    cout << "Color de las regiones" << endl;
    mostrarArr(color_de_regiones);
}

int main(){
    string Colores[4] = { "Roja", "Azul", "Verde", "Amarilla" };
    int mAdyacencia[Cantidad_de_regiones][Cantidad_de_regiones]={/*Aca se coloca una matriz similar a la de abajo*/};
    /*{0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
    {0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1},
    {0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0}*/
    
    int color_de_regiones[Cantidad_de_regiones]={};

    //La siguiente funcion genera una matriz como la que sirve de ejemplo en las lineas anteriores
    //esta funcion depende del #define cantidad de regiones, en las primeras lineas
    //Sirve para crear varios casos de prueba para el teorema

    //adyacentes(mAdyacencia); //--------------> Para Generar adyacencias automaticamente

    mostrarMat(mAdyacencia);
    fourColor(mAdyacencia,color_de_regiones);
    cout << endl << "Regiones Colindantes: " << "\n";
    for(int i = 0; i < Cantidad_de_regiones;++i){
        cout << "Region: " << i << ": ";
        for (int j =0; j<Cantidad_de_regiones;++j){
            if (mAdyacencia[i][j]){
                cout << j <<" ";
                }
            }
        cout << endl;}
    cout << endl << "Color de las regiones/zonas: " << endl;;
    for(int i = 0; i < Cantidad_de_regiones;++i){
        cout << "Region: " << i << " "<< Colores[color_de_regiones[i]-1] << endl;
        }
    
}