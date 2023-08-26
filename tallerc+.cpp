#include<stdio.h>

int main(void){
  int i, buscar, lista[100], mitad;
  int a = 0;
  int b = 100;
  int contadorA = 0;
  int contadorB = 0;

  printf("====================================================\n\n");
  //se llena el arreglo
  for( i = 0; i <= 100; i++){
    lista[i] = i * 2;
  }//fin for

//se muestra el arreglo en pantalla
  for(i = 0; i <= 100; i++){
    printf("%d  ", lista[i]);
    if( i % 10 == 0 && i != 0)
      printf("\n");
  }
  printf("\n\n====================================================\n");

  printf("Ingresa un numero a buscar: ");
  scanf("%d", &buscar);

  while (a <= b){
    contadorA++;
    mitad = (a + b) / 2;

    if(buscar > 200){
      printf("Numero no encontrado\n");
      break;
    }

    if(buscar == lista[mitad]){
      printf("Numero %d encontrado en posicion %d\n", lista[mitad], mitad);
      break;
    }
    else if(buscar < lista[mitad]){
      b = mitad -1;
    }
    else{
      a = mitad + 1;
    }
    contadorB++;

  }//fin while

if(contadorA == contadorB){
  printf("Numero no encontrado\n");
}

return 0;

}

