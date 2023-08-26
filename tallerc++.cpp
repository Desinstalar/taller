#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
 
struct direc
{
char nombre[30];
char calle[40];
char ciudad[20];
char estado[3];
char codigo[10];
struct direc *sig; //puntero a la siguiente entrada
struct direc *ante; //puntero al registro anterior
}entrada_lista;
 
struct direc *ppio; //puntero a la primera entrada de la lista
struct direc *final; //puntero a la ultima entrada de la lista
struct direc *buscar(char *); //puntero a una funcion
 
void intro(void),buscar(void),guardar(void);
void cargar(void),listar(void);
void borrar(struct direc **,struct direc **);
void dl_insert(struct direc *i,struct direc **ppio, struct direc **final);
void leecad(char *,char *,int),mostrar(struct direc *);
int menu (void);
 
main()
{
ppio=final=NULL; //inicializar los punteros
for(;;)
{
switch (menu())
{
case 1:intro();
break;
case 2:borrar(&ppio,&final);
break;
case 3:listar();
getch();
break;
case 4:buscar(); //encuentra un nombre
getch();
break;
case 5:guardar(); //guarda la lista en un disco
break;
case 6:cargar(); //lee del disco
break;
case 7:exit(0); //fin de programa
}
}
}
 
//seleccionar una operacion
int menu(void)
{
char s[80];
int c;
printf("\n1. introducir un nombre\n");
printf("2. borrar un nombre\n");
printf("3. listar el archivo\n");
printf("4. buscar\n");
printf("5. guardar el archivo\n");
printf("6. cargar el archivo\n");
printf("7. salir\n");
do
{
printf("\nintroduzca su opcion: ");
gets(s);
c=atoi(s);
}while(c<0 || c>7);
return(c);
}
 
//introducir nombres y direcciones
void intro(void)
{
struct direc *info;
for (;;)
{
info=(struct direc *)malloc (sizeof(entrada_lista)); //new(entrada_lista)
if (!info)
{
printf("\nno hay memoria");
return;
}
leecad("introduzca nombre: ",info->nombre,30);
if (!info->nombre[0])break; //terminar
leecad("introduzca calle: ",info->calle,40);
leecad("introduzca ciudad: ",info->ciudad,20);
leecad("introduzca provincia: ",info->estado,3);
leecad("introduzca codigo: ",info->codigo,10);
dl_insert(info,&ppio,&final);
} //bucle de entrada
}
 
//esta funcion lee una cadena de longitud maxima cont.
//previene el desbordamiento de la cadena y visualiza un mensaje indicativo
 
void leecad(char *indic,char *s,int cont)
{
char p[255];
do
{
printf(indic);
gets(p);
if (strlen(p)>cont)
{
printf("\ndemasiado largo\n");
printf("La longitud permitida es %i\n",cont);
}
}while(strlen(p)>cont);
strcpy(s,p);
}
 
//crea una lista doblemente enlazada ordenadamente
 
void dl_insert(
struct direc *i, //nuevo elemento
struct direc **ppio, //primer elemento de la lista
struct direc **final //ultimo elemento de la lista
)
{
struct direc *ant,*p;
if (*final==NULL) //primer elemento de la lista
{
i->sig=NULL;
i->ante=NULL;
*final=i;
*ppio=i;
return;
}
 
p=*ppio; //principio de la lista
ant=NULL;
while (p)
{
if(strcmp(p->nombre,i->nombre)<=0)
{
ant=p;
p=p->sig;
}
else
{
if(p->ante)
{
p->ante=i;
i->sig=p;
i->ante=ant; //p->ante;
ant->sig=i; //p->ante=i;
return;
}
i->sig=p; //nuevo primer elemento
i->ante=NULL;
p->ante=i;
*ppio=i;
return;
}
}
ant->sig=i; //ponerlo en el final
i->sig=NULL;
i->ante=ant;
*final=i;
}
 
//elimina un elemento de la lista
void borrar(struct direc **ppio, struct direc **final)
{
struct direc *info, *buscar(char *nombre);
char s[80];
 
printf("introduzca nombre: ");
gets(s);
info=buscar(s);
if(info)
{
if(*ppio==info)
{
*ppio=info->sig;
if (*ppio)
(*ppio)->ante=NULL;
else
*final=NULL;
}
else
{
info->ante->sig=info->sig;
if (info!=*final)
info->sig->ante= info->ante;
else
*final=info->ante;
}
free(info); //devolver memoria al sistema
}
}
 
//buscar una direccion
struct direc *buscar(char *nombre)
{
struct direc *info;
info=ppio;
while(info)
{
if(!strcmp(nombre,info->nombre))
return info;
info=info->sig; //obtener siguiente direccion
}
printf("nombre no encontrado\n");
return NULL; //no encontrado
}
 
//mostrar la lista entera
void listar(void)
{
struct direc *info;
 
info=ppio;
if (!info)
{
printf("\n Lista Vacía\n");
return;
}
while(info)
{
mostrar(info);
info=info->sig; //obtener siguiente direccion
}
printf("\n Fin de Lista\n");
}
 
//esta funcion imprime realmente los campos de cada direccion
void mostrar(struct direc *info)
{
printf("%s ",info->nombre);
printf("%s ",info->calle);
printf("%s ",info->ciudad);
printf("%s ",info->estado);
printf("%s \n",info->codigo);
}
 
//buscar un nombre en la lista
void buscar(void)
{
char nombre[40];
struct direc *info, *buscar(char *nombre);
 
printf("introduzca nombre: ");
gets(nombre);
info=buscar(nombre);
if (!info)
printf("no encontrado\n");
else
mostrar(info);
}
 
//guardar el archivo en disco
void guardar(void)
{
struct direc *info;
FILE *fp;
 
fp=fopen("listac","wb");
if (!fp)
{
printf("no se puede abrir el archivo\n");
exit(1);
}
printf("\nguardando el archivo");
 
info=ppio;
while(info)
{
fwrite(info,sizeof(struct direc),1,fp);
info=info->sig; //obtiene la siguiente direccion
}
fclose(fp);
}
 
//cargar el archivo de direcciones
void cargar()
{
struct direc *info;
FILE *fp;
 
fp=fopen("listac","rb");
if (!fp)
{
printf("no se puede abrir el archivo\n");
exit(1);
}
//liberar cualquier memoria previamente dispuesta
while (ppio)
{
info=ppio->sig;
free(info);
ppio=info;
}
//reinicializar los punteros
ppio=final=NULL;
 
printf("\ncargando el archivo\n");
while(!feof(fp))
{
info=(struct direc *)malloc(sizeof(struct direc));
if (!info)
{
printf("no hay memoria");
return;
}
if (1!=fread(info, sizeof(struct direc), 1,fp)) break;
dl_insert(info,&ppio,&final);
}
fclose(fp);
}
