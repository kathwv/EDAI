#include <stdio.h>    //Incluye la biblioteca estándar
int a[5] = {2, 4, 6, 8, 10}  //se declara un arreglo de 5 enteros
int *p = a;    // p apunta al primer elemento del arreglo: a[0]

printf("1) a[1] = %d\n", a[1];    //imprime el segundo elemento del arreglo: 4
printf("2) *(a+3) = %d\n", *(a+3));  //a+3 apunta a a[3]: 8
printf("3) *p++ = %d\n", *p++);   // imprime el valor apuntado por p (a[0]= 2),luego apunta p a a[1
printf("4) *++p = %d\n", *++p);    //incrementa p a a[2]), luego imprime el valor de la posición: 6
printf("5) p[1] = %d\n", p[1]);   //p apunta a a[2], así que p[1] es a[3]=8
printf("6) *(p+=2) = %d\n", *(p+=2));   //p incrementa 2 posiciones, apunta a a[4] = 10
printf("7) p - a = %ld\n", p - a);   //calcula la diferencia de posiciones entre p (a[4]) y a (a[0])

return 0;  //termina el programa
