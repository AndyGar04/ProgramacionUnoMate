/* Escribe un programa en C++ que permita manipular una matriz cuadrada de tamaño nxn. El programa deberá
presentar un menú interactivo que permita al usuario elegir entre diferentes opciones para realizar diversas
tareas con la matriz.*/

#include <iostream>
#include <ctime>
using namespace std;

const int n=3;

/* 
• Cargar la matriz:
➢ Con números aleatorios en el rango de 1 a 100.
➢ De forma manual, ingresando los valores uno por uno. 
*/

void cargarMatriz(int m[n][n]){

    int menu=0;
    bool fin=false;
   do{
     switch(menu){
        case 0:
         cout << "1. Cargar matriz manual" << endl;
         cout << "2. Cargar matriz automaticamente" << endl;
         cin >> menu;
        break;
        case 1:
         cout << "Cargar matriz de forma manual" << endl; 
         for (int i=0; i<n; i++){
           for (int j=0; j<n; j++){
             cin >> m[i][j];
           }
         }
         fin=true;
        break;
        case 2:
         cout << "Cargando matriz automaticamente" << endl; 
         for (int i=0; i<n; i++){
          for (int j=0; j<n; j++){
            m[i][j]=rand()%100+1;
          }
         }
         fin=true;
        break;
        default:
         cout << "Ingresaste un valor incorrecto, intenta nuevamente" << endl;
         menu=0;
        break;
     }   
    }while(fin==false); 

    cout << "Matriz cargada" << endl;

}

/* 
• Mostrar los valores de la matriz.
*/

void mostrarMatriz(int m[n][n]){
     for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << m[i][j] << "\t";
        }
        cout << endl;
     }
}

/*
• Buscar un valor específico ingresado por el usuario dentro de la matriz.
*/

void buscarValor(int m[n][n]){
  int buscado, count=0;
  bool encontrado=false;
  cout << "Que numero desea buscar?" << endl;
  cin >> buscado;

 for (int i = 0 ; i < n ; i++){
     for (int j = 0 ; j < n ; j++){
         if (m[i][j] == buscado){
            cout << "Se ha encontrado";
            cout << " en la posicion " << i << " " << j << endl;
            encontrado = true;
            count++;
         }else{
            encontrado = false;
         }
     }
    }

    if (encontrado == false && count==0){
      cout << "No se encontro, intente nuevamente" << endl;
    }
}

/*
• Devolver el valor máximo o mínimo de la matriz.
*/

void numMayor_numMenor(int m[n][n]){
  int vMayor=0;
  int vMenor=100;
     for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if (m[i][j] < vMenor){
          vMenor=m[i][j];
        }else if (m[i][j] > vMayor){
          vMayor=m[i][j];
        }
      }
     }
  cout << "El mayor valor mostrado es: " << vMayor << endl;
  cout << "El menor valor mostrado es: " << vMenor << endl;    
}

/*
• Ordenar los valores de la matriz de forma ascendente.
*/

void OrdenarMatrizAscendente(int m[n][n]){
    int pos, tmp, count = 0;
    int valorDelArray=n*n;
    int array[valorDelArray];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            array[j + count] = m[i][j];
        }
        count = count + n;
    }

    for (int i = 0; i < valorDelArray; i++) {
        pos = i;
        while ((pos > 0) && (array[pos - 1] > array[pos])) {
            tmp = array[pos];
            array[pos] = array[pos - 1];
            array[pos - 1] = tmp;
            pos--;
        }
    }

    count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = array[j + count];
        }
        count = count + n;
    }

    cout << "Ordenando de menor a mayor" << endl;
}

/* 
• Ordenar los valores de la matriz de forma descendente.
*/

void OrdenarMatrizDescendente(int m[n][n]){
    int pos, tmp, count = 0;
    int valorDelArray=n*n;
    int array[valorDelArray];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            array[j + count] = m[i][j];
        }
        count = count + n;
    }

    for (int i = 0; i < valorDelArray; i++) {
        pos = i;
        while ((pos > 0) && (array[pos - 1] < array[pos])) {
            tmp = array[pos];
            array[pos] = array[pos - 1];
            array[pos - 1] = tmp;
            pos--;
        }
    }

    count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = array[j + count];
        }
        count = count + n;
    }

    cout << "Ordenando de mayor a menor" << endl;
}

int main(){
  int Matriz[n][n];
  int menu=0;
  bool cargada=false;
  srand(time(NULL));

  do{
    switch(menu){
      case 0:
       cout << "1. Cargar matriz" << endl;
       cout << "2. Mostrar matriz" << endl;
       cout << "3. Buscar valor" << endl;
       cout << "4. Mostrar numero mayor y numero menor" << endl;
       cout << "5. Ordenar matriz ascendente" << endl;
       cout << "6. Ordenar matriz descendente" << endl;
       cout << "7. Salir" << endl;
       cin >> menu; 
        if (menu !=1 && cargada==false){
          cout << "Por favor primero cargue la matriz" << endl;
          menu=0;
        }else{
          cargada=true;
        }
      break;
      case 1:
       cargarMatriz(Matriz);
       menu=0;
      break; 
      case 2:
       mostrarMatriz(Matriz);
       menu=0;
      break;
      case 3: 
       buscarValor(Matriz);
       menu=0;
      break;
      case 4: 
       numMayor_numMenor(Matriz);
       menu=0;
      break;
      case 5: 
       OrdenarMatrizAscendente(Matriz);
       menu=0;
      break; 
      case 6:
       OrdenarMatrizDescendente(Matriz);
       menu=0;
      case 7:
      break;
      default:
       cout << "Ingresaste un valor invalido, por favor vuelva a intentarlo" << endl;
       menu=0;
      break;  
    }
  }while(menu!=7);

  cout << "Saliste, gracias por usar el menu!" << endl;
}