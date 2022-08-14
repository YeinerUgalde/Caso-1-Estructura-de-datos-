-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Caso #1-Estructura-de-datos-
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Esta es la solución que yo hice del caso #1 de estructura de datos
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Dado un mapa de "x" regiones/zonas el algoritmo devolvera una posible conbinacion de colores
que demuestren que el teorema es correcto por medio de un "cout" que tendra la forma:

Cantidad de regiones x:

Region x: Roja

Region x: Azul

Region x: Verde

Region x: Amarilla


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
-Expliación de la solución:
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Para probar el teorema utilice una matriz de adyacencia para suministrar la estructura de regiones colindantes, de esta manera si una region colinda con otra, solo se debe de poner un "1" para definirlo, de otra manera sera "0" por defecto.

Debido a que todas las regiones no tienen un color cuando son suministradas el algoritmo empieza dandole uno a la primer region, pero antes de esto valida en la matriz de adyacencia que ninguna de las regiones que son adyacentes a esta region tenga el mismo color, por ejemplo: Se tienen cuatro colores, el algoritmo al tomar la primer region le intenta asignar el "color #1", pero antes de asignarselo verifica en la matriz de adyacencia los colores de las regiones que contengan un "1" en su fila, ya que es la primer region, se lo asignara sin problema, pero en el caso donde alguna region ya lo tenga, simplemete pasara al siguiente color y volvera a validar que las regiones adyacentes no lo tengan.
Para almacenar los colores de las regiones se utiliza un arreglo del largo de la cantidad de regiones original, difinida en el #define, es por esto que es importante definirlo junto a la matriz, en este arreglo la posicion "0" del arreglo es la region "0" del mapa, y el elemento en esa posicion sera un numero del "1" al "4", donde cada numero representara un color, siendo el "1" el "rojo", el "2" el "azul", el "3" el "verde" y el "4" el "amarillo".

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
-Metodo de uso:
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
La manera para suministrar el mapa es dando una matriz de adyacencia de las zonas y definiendo estas mismas.

Para definir la cantidad de zonas se debe de modificar el "x" en la siguiente linea del codigo:
-----------------------------------------------------------------------------------------------

#define Cantidad_de_regiones "X"


La cantidad de regiones debe de ser la misma que la cantidad de filas y columnas de la matriz de adyacencia.

Para suministrar la matriz de adyacencia se debe de cambiar la siguiente linea en el codigo:
--------------------------------------------------------------------------------------------
int mAdyacencia[Cantidad_de_regiones][Cantidad_de_regiones]={ "Aca se coloca la matriz de adyacencia del mapa que se quiere probar" }

Un ejemplo de una matriz de adyacencia que se puede suministrar es esta:

    {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
    {0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1},
    {0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0}
    
Las regiones en la matriz van de la numero "0" a la cantidad suministrada "-1"; por lo que si coloca "Cantidad_de_regiones = 11" seran de las reiones/zonas del "0" hasta el "10"
Las regiones correspondientes se alinean con la matriz, siendo la region "0" la fila y columna "0" de la matriz.
Ejemplo:

         0  1  2  3  4  5  6  7  8  9 10 

    0   {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    1   {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    2   {1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    3   {1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    4   {0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
    5   {0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1},
    6   {0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0},
    7   {0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0},
    8   {0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1},
    9   {0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1},
    10  {0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0}
 
Para decidir si una region/zona es adyacente/colinda con otra, se debe de colocar un "1"; ejemplo:
La region/zona "0" es adyacente a la region/zona "1" en la matriz anterior.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

  
