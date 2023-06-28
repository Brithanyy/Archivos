#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <strings.h>
///VARIBALE GLOBAL:
const int DIM = 100;
///ESTRUCTURAS:
typedef struct {
int legajo;
char nombreYapellido [30];
int edad;
int anio;
}Alumno;

///PROTOTIPADO DE FUNCIONES:
void crearalumStrucvo(char nombrealumStruc[]);
void mostraralumStruc(char nombrealumStruc[]);
int cantidadRegistrosalumStruc(char nombrealumStruc[]);
void cargaralumStrucEstruct(char nombrealumStruc[]);
Alumno cargarUnAlumno();
void mostraralumStrucStruct(char nombrealumStruc[]);
void mostrarAlumno(Alumno alumno);
void agregarNuevosDatosStruct(char nombrealumStruc[]);
void pasarAPilaMayoresDeEdad(char nombrealumStruc[], Pila *pila);
int contarAlumnosBaseASuEdad(char nombrealumStruc[], int edad);
int mostrarAlumnosSegunRango(char nombrealumStruc[], int rango1, int rango2);
int buscarAlumnoMayorEdad(char nombrealumStruc[]);
void mostrarEdadMayor(char nombrealumStruc[]);
int cantidadAlumnosConAnioCursada(char nombrealumStruc[], int anioCursada);
void cargarArrAlum(char nombreArchi[], Alumno alumStruc[DIM]);
void filtradoAnioCursada(char nombreArchi[], int filtrado);
int contabilizarRegistros(char nobmreArchi[]);
void mostrandoEseRegistro(char nombreArchi[], int registro);
void sobreescribir(char nombreArchi[]);
void modificarUnSoloAlumno(char nombreArchi[], int numDeAlumno);

int main()
{
///VARIABLES ANTES DEL SWICH:
char nombreArchi[30] = {"alumStruc.bin"};
///Punto 1:
    char nombrealumStruc[30];
///Punto 4:
    Alumno alumno;
///Punto 7:
Pila pila;
inicpila(&pila);
char si;
///Punto 8:
int edad;
int cantidad;
///Punto 9:
int rango1;
int rango2;
int total;
///Punto 11:
int anioCursada;
int cantAlumAnio;
///Punto 12:
Alumno alumArr[DIM];
int filtrado;
///Punto 13:
int cantRegistrados;
///Punto 14:
int registroEspecifico;
int flag = 0;
///Punto 15:
int cantRegis;
int numRegistroAModificar;

    int salirMenu = 0;
    int eleccion;
    char continuar = 's';


    while(continuar == 's'){
        mostrarMenu(); ///Mostrando los ejercicios
        printf("\n");
        printf("Introduzca el numero correspondiente a cada ejercicio: ");
        fflush(stdin);
        scanf("%i", &eleccion);
        printf("\n");
///SWICH:
switch(eleccion){
        case 0:
            ///El case 0 esta para cuando queremos salir del menu.
        break;
        case 1:
            crearalumStrucvo("archivito.bin");
        break;

        case 2:
            mostraralumStruc("archivito.bin");
        break;

        case 3:
            cantidadRegistrosalumStruc("archivito.bin");
        break;

        case 4:
            cargaralumStrucEstruct(nombreArchi);
        break;

        case 5:
            mostraralumStrucStruct(nombreArchi);
        break;

        case 6:
            agregarNuevosDatosStruct(nombreArchi);
        break;

        case 7:
            pasarAPilaMayoresDeEdad(nombreArchi, &pila);
            printf("\nSi desea ver los legajos de los alumnos mayores pulsa 's': ");
            fflush(stdin);
            scanf("%c", &si);
            if(si == 's'){
                mostrar(&pila);
            }

        break;

        case 8:
            printf("Ingrese una edad y le dire la cantidad de alumnos desde esa edad: ");
            fflush(stdin);
            scanf("%i", &edad);
            cantidad = contarAlumnosBaseASuEdad(nombreArchi, edad);
            if(cantidad != 0){
                printf("\nLa cantidad de alumnos con la edad %i es de: %i", edad, cantidad);
                printf("\n\n");
            }else{
                printf("\nNo hay alumnos registrados con esa edad. Ingrese otra edad.\n");
                printf("\n");
            }
        break;

        case 9:
            printf("Ingrese el primer rango de edad para mostrar alumnos: ");
            fflush(stdin);
            scanf("%i", &rango1);
            printf("\n");
            printf("Ingrese el segundo rango de edad para mostrar alumnos: ");
            fflush(stdin);
            scanf("%i", &rango2);
            printf("\n");
            total = mostrarAlumnosSegunRango(nombreArchi, rango1, rango2);
            if(total == 0){
                printf("\nNo hay alumnos con el rango definido. Intente con otro.\n");
            }

        break;

        case 10:
            printf("\nMostrando el alumno con mayor edad\n");
            mostrarEdadMayor(nombreArchi);
        break;

        case 11:
            printf("\nIngrese el anio de cursada y le dire la cantidaded de alumnos de ese anio:");
            fflush(stdin);
            scanf("%i", &anioCursada);
            cantAlumAnio = cantidadAlumnosConAnioCursada(nombreArchi, anioCursada);
            if(cantAlumAnio != 0){
                printf("\nLa cantidad de alumnos con ese anio es: %i", cantAlumAnio);
                printf("\n\n");
            }else{
                printf("\nNo hay alumnos registrados de ese anio. Intente con otro\n\n");
            }
        break;

        case 12:
            //cargarArrAlum("alumStruc.bin", alumArr);
            printf("Que anio de cursada desea filtrar: ");
            fflush(stdin);
            scanf("%i", &filtrado);
            filtradoAnioCursada(nombreArchi, filtrado);
        break;

        case 13:
            cantRegistrados = contabilizarRegistros(nombreArchi);
            printf("\nLa cantidad de alumnos registrados son: %i ", cantRegistrados);
            printf("\n");
        break;

        case 14:
            do{
                printf("Ingrese un registro del 1 al 9: ");
                fflush(stdin);
                if(scanf("%i", &registroEspecifico) == 1){
                    flag = 1;
                    if(registroEspecifico >= 1 && registroEspecifico <= 9){
                    flag = 1;
                }else{
                    printf("\nEl numero sobrepasa los limites. Intente nuevamente. \n\n");
                    flag = 0;
                }
                }else{
                    printf("\n\nNumero no valido. Asegurese de estar ingresando un numero entero.\n\n");
                    flag = 0;
                }

            }while(flag == 0);
            mostrandoEseRegistro(nombreArchi, registroEspecifico);
        break;

        case 15:
            printf("Si desea sobreescribir todos los alumnos pulsa 's' sino pulse otra letra para modificar un solo alumno: ");
            printf("\n\n");
            fflush(stdin);
            scanf("%c", &continuar);
            if(continuar == 's'){
                sobreescribir(nombreArchi);

            }else{
                cantRegis = contabilizarRegistros(nombreArchi);
                printf("Hay un total de %i alumnos registrados, cual desea modificar: ", cantRegis);
                fflush(stdin);
                scanf("%i", &numRegistroAModificar);
                modificarUnSoloAlumno(nombreArchi, numRegistroAModificar);
            }
        break;

        case 16:
        break;

        default:
        printf("\nNumero ingresado invalido\n");
        break;
        }

        printf("\nPulsa 0 si desea salir del menu: ");
        fflush(stdin);
        scanf("%i", &salirMenu);

        printf("\n\nPulsa 's' si desea seguir en el menu: ");
        fflush(stdin);
        scanf("%c", &continuar);

    }


}
///FUNCION DE MOSTRAR MENU:
void mostrarMenu(){
    printf("\n1) Hacer una funcion con que agregue un elemento al final de un alumStrucvo.\n");
    printf("\n2) Hacer una funcion que muestre por pantalla el contenido de un alumStrucvo.\n");
    printf("\n3) Hacer una funcion que retorne la cantidad de registros que contiene un alumStrucvo.\n");
    printf("\n4) Crear una funcion que cargue un alumStrucvo de alumnos. Abrirlo de manera tal de verificar si elalumStrucvo ya esta creado previamente. Cargar el alumStrucvo con 5 datos. Cerrarlo dentro de la funcion\n");
    printf("\n5) Crear una funcion que muestre por pantalla los registros de un alumStrucvo de alumnos.Modularizar.\n");
    printf("\n6) Crear una funcion que permita agregar de a un elemento al final del alumStrucvo. O sea, se debeabrir el alumStrucvo, se piden los datos (se llena una variable de tipo struct alumno), se escribeen el alumStrucvo y se cierra.\n");
    printf("\n7) Crear una funcion que pase a una pila los numeros de legajo de los alumnos mayores deedad.\n");
    printf("\n8) Dado un alumStrucvo de alumnos, hacer una funcion que cuente la cantidad de alumnosmayores a edad específica que se envia por parametro.\n");
    printf("\n9) Dado un alumStrucvo de alumnos, mostrar por pantalla el nombre de todos los alumnos entre unrango de edades especifico (por ejemplo, entre 17 y 25 anios). Dicho rango debe recibirsepor parametro. Modularizar\n");
    printf("\n10) Dado un alumStrucvo de alumnos, mostrar los datos del alumno de mayor edad. Modularizar.\n");
    printf("\n11) Crear una funcion que retorne la cantidad de alumnos que cursan un determinado anio. El anio buscado se pasa por parametro.\n");
    printf("\n12) Crear una funcion que reciba como parametro un arreglo de tipo alumno y lo copie en elalumStrucvo. Asimismo, realice otra funcion que pase los elementos del alumStrucvo a un arreglo dealumnos, filtrando los estudiantes de un año en particular.\n");
    printf("\n13) Crear una funcion que retorne la cantidad de registros que tiene el alumStrucvo. Usar fseek yftell. Puede pensar la funcion para uso generico, que sirva para averiguar la cantidad deregistros de cualquier alumStrucvo.\n");
    printf("\n14) Dado un alumStrucvo de alumnos, que tenga al menos 10 registros, hacer una funcion quemuestre el contenido de un registro, cuyo número (entre 0 y 9) se pase por parametro.Controlar no sobrepasar los limites del alumStrucvo.\n");
    printf("\n15) Realice una (o varias) funciones que permitan modificar un registro existente en el alumStrucvo de alumnos. La misma debe permitir modificar uno o todos los campos de la estructura y sobreescribir el registro existente en el alumStrucvo.\n");
    printf("\n16) Dado un alumStrucvo de alumnos, hacer una funcion que invierta los elementos del mismo. Nose puede usar otro alumStrucvo auxiliar ni un arreglo auxiliar. Debe trabajar sobre el alumStrucvo.Puede utilizar variables de tipo alumno auxiliares.\n");
}

///PUNTO 1:
void crearalumStrucvo(char nombrealumStruc[]){
    int num;
    FILE *punto1;

    punto1 = fopen(nombrealumStruc, "ab");

    if(punto1 != NULL){
        printf("Ingrese un numero: ");
        fflush(stdin);
        scanf("%i",&num);
        fwrite(&num, sizeof(int),1,punto1);
        fclose(punto1);
    }
}
///PUNTO 2:
void mostraralumStruc(char nombrealumStruc[]){
    int num;
    FILE *punto1;

    punto1 = fopen(nombrealumStruc, "rb");

    if(punto1 != NULL){
        while(!feof(punto1)){
            fread(&num, sizeof(int),1, punto1);
            if(!feof(punto1)){
                printf("Numero: %i", num);
            }
        }
        fclose(punto1);
    }
}
///PUNTO 3:
int cantidadRegistrosalumStruc(char nombrealumStruc[]){
    int num;
    FILE *punto1;
    punto1 = fopen(nombrealumStruc, "rb");
    int i = 0;

    if(punto1 != NULL){
        while(!feof(punto1)){
            fread(&num,sizeof(int),1,punto1);
            if(!feof(punto1)){
                i++;
            }
        }
    }
return i;
}
///PUNTO 4:
void cargaralumStrucEstruct(char nombrealumStruc[]){
    Alumno alumno;
    FILE *alumStruc;
    alumStruc = fopen(nombrealumStruc, "ab");
    char eleccion = 's';

    if(alumStruc != NULL){
        while(eleccion == 's')    {
        alumno = cargarUnAlumno();
        fwrite(&alumno, sizeof(Alumno),1,alumStruc);
        printf("Pulsa 's' si desea cargar otro alumno: ");
        fflush(stdin);
        scanf("%c", &eleccion);
        printf("\n");
        }
         fclose(alumStruc);
    }
}

Alumno cargarUnAlumno(){
    Alumno nuevoAlumno;

    printf("Ingrese numero de legajo: ");
    fflush(stdin);
    scanf("%i", &nuevoAlumno.legajo);
    printf("\n");
    printf("Ingrese su nombre y apellido: ");
    fflush(stdin);
    gets(nuevoAlumno.nombreYapellido);
    printf("\n");
    printf("Ingrese su edad: ");
    fflush(stdin);
    scanf("%i", &nuevoAlumno.edad);
    printf("\n");
    printf("Ingrese el anio que cursa: ");
    fflush(stdin);
    scanf("%i", &nuevoAlumno.anio);
    printf("\n");
    return nuevoAlumno;

}
///PUNTO 5:
void mostraralumStrucStruct(char nombrealumStruc[]){
    Alumno alumno;
    FILE *alumStruc;
    alumStruc = fopen(nombrealumStruc, "rb");
    if(alumStruc != NULL){
        while(!feof(alumStruc)){
            fread(&alumno, sizeof(Alumno),1,alumStruc);
            if(!feof(alumStruc)){
            mostrarAlumno(alumno);
            }
        }
        fclose(alumStruc);
    }
}
void mostrarAlumno(Alumno alumno){
    printf("----------------------------------------\n");
    printf("Legajo: %i", alumno.legajo);
    printf("\n");
    printf("Nombre y Apellido: %s", alumno.nombreYapellido);
    printf("\n");
    printf("Edad: %i", alumno.edad);
    printf("\n");
    printf("Anio cursada: %i", alumno.anio);
    printf("\n");
    printf("----------------------------------------\n");

}
///PUNTO 6:
void agregarNuevosDatosStruct(char nombrealumStruc[]){
    Alumno alumno;
    FILE *alumStruc;
    alumStruc = fopen(nombrealumStruc, "ab+");

    if(alumStruc != NULL){
        alumno = cargarUnAlumno();
        fwrite(&alumno, sizeof(Alumno),1,alumStruc);
        fclose(alumStruc);
    }
}
///PUNTO 7:
void pasarAPilaMayoresDeEdad(char nombrealumStruc[], Pila *pila){
    Alumno alumno;
    FILE *alumStruc;
    alumStruc = fopen(nombrealumStruc, "rb");

    if(alumStruc != NULL){
        while(!feof(alumStruc)){
            fread(&alumno, sizeof(Alumno),1,alumStruc);
            if(!feof(alumStruc)){
                if(alumno.edad >= 18){
                    apilar(pila, alumno.legajo);
                }
            }
        }
        fclose(alumStruc);
    }
    printf("\nLegajos de alumnos mayores de 18 pasados correctamente.\n\n");
}
///Punto 8:
int contarAlumnosBaseASuEdad(char nombrealumStruc[], int edad){
    Alumno alumno;
    int i = 0;
    FILE *alumStruc;
    alumStruc = fopen(nombrealumStruc, "rb");
    if(alumStruc != NULL){
        while(!feof(alumStruc)){
            fread(&alumno,sizeof(Alumno),1,alumStruc);
            if(!feof(alumStruc)){
                if(alumno.edad >= edad){
                    i++;
                }
            }
        }
        fclose(alumStruc);
    }
    return i;
}
///Punto 9:
    int mostrarAlumnosSegunRango(char nombrealumStruc[], int rango1, int rango2){
    int flag = 0;
    Alumno alumnos;
    FILE *alumStruc;
    alumStruc = fopen(nombrealumStruc, "rb");
    if(alumStruc != NULL){
        while(!feof(alumStruc)){
            fread(&alumnos, sizeof(Alumno),1,alumStruc);
            if(!feof(alumStruc)){
                if(alumnos.edad >= rango1 && alumnos.edad <= rango2){
                        flag = 1;
                        //mostrarAlumno(alumnos);
                        printf("\n---------------------------\n");
                        printf("Nombre: %s ", alumnos.nombreYapellido);
                        printf("\n---------------------------\n");

                }
            }
        }
        fclose(alumStruc);
    }
    return flag;
}

///Punto 10:
int buscarAlumnoMayorEdad(char nombrealumStruc[]){
    Alumno alumno;
    int mayor = 10  ;
    FILE *alumStruc;
    alumStruc = fopen(nombrealumStruc,"rb");
    if(!feof(alumStruc)){
        while(!feof(alumStruc)){
            fread(&alumno,sizeof(Alumno),1,alumStruc);
            if(!feof(alumStruc)){
                if(alumno.edad > mayor){
                    mayor = alumno.edad;
                }
            }
        }
        fclose(alumStruc);
    }
    return mayor;
 }
 void mostrarEdadMayor(char nombrealumStruc[]){
     Alumno alumno;
     FILE *alumStruc;
     alumStruc = fopen(nombrealumStruc, "rb");
     int mayor = buscarAlumnoMayorEdad(nombrealumStruc);
     if(alumStruc != NULL){
        while(!feof(alumStruc)){
                fread(&alumno,sizeof(Alumno),1,alumStruc);
            if(!feof(alumStruc)){
                if(alumno.edad == mayor){
                    mostrarAlumno(alumno);
                }
            }
        }
     }
 }
///Punto 11:
int cantidadAlumnosConAnioCursada(char nombrealumStruc[], int anioCursada){
    Alumno alumno;
    FILE *alumStruc;
    alumStruc = fopen(nombrealumStruc, "rb");
    int i = 0;
    if(alumStruc != NULL){
        while(!feof(alumStruc)){
                fread(&alumno,sizeof(Alumno),1,alumStruc);
            if(!feof(alumStruc)){
                if(alumno.anio == anioCursada){
                    i++;
                }
            }
        }
        fclose(alumStruc);
    }
    return i;
}
///Punto 12:
void cargarArrAlum(char nombreArchi[], Alumno alumStruc[DIM]){
    FILE *alum;
    alum = fopen(nombreArchi, "ab");

    if(alum != NULL){
        alumStruc[0].legajo = 10;
        strcpy(alumStruc[0].nombreYapellido, "Carlos Carpaneto");
        alumStruc[0].edad = 33;
        alumStruc[0].anio = 1;
        fwrite(&alumStruc[0], sizeof(Alumno),1,alum);

        alumStruc[1].legajo = 11;
        strcpy(alumStruc[1].nombreYapellido, "Carlos Suarez");
        alumStruc[1].edad = 30;
        alumStruc[1].anio = 2;
        fwrite(&alumStruc[1], sizeof(Alumno),1,alum);

        alumStruc[2].legajo = 12;
        strcpy(alumStruc[2].nombreYapellido, "Maria Colino");
        alumStruc[2].edad = 42;
        alumStruc[2].anio = 2;
        fwrite(&alumStruc[2], sizeof(Alumno),1,alum);

         fclose(alum);
    }
    printf("\nAlumnos cargados con exito.\n");
}
/// Punto 2: segunda parte
void filtradoAnioCursada(char nombreArchi[], int filtrado){
    Alumno alumStruc[DIM];
    Alumno auxAlumArr[DIM];
    FILE *alum;
    int i;
    int filteredIndex = 0;

    alum = fopen(nombreArchi, "rb");
    if (alum != NULL) {
        i = 0;
        while (!feof(alum)) {
            fread(&alumStruc[i], sizeof(Alumno), 1, alum);
            if (!feof(alum)) {
                if (alumStruc[i].anio == filtrado) {
                    auxAlumArr[filteredIndex].legajo = alumStruc[i].legajo;
                    strcpy(auxAlumArr[filteredIndex].nombreYapellido, alumStruc[i].nombreYapellido);                    auxAlumArr[filteredIndex].edad = alumStruc[i].edad;
                    auxAlumArr[filteredIndex].anio = alumStruc[i].anio;
                    filteredIndex++;
                }
                i++;
            }
        }
        fclose(alum);
    }
    printf("\n\nFiltrado realizado correctamente.\n\n");
}
///Punto 13:
int contabilizarRegistros(char nombreArchi[]) {
    int tamanioRegistro = 0;
    int cantidadRegistros = 0;
    int tamanio;
    Alumno alumno;
    FILE *alum;
    alum = fopen(nombreArchi, "rb");

    if (alum != NULL) {

        if(fseek(alum, 0, SEEK_END) != 0) {

            printf("Error al moverse al final del archivo.\n");
            fclose(alum);
            return;  // Se sale de la función en caso de error
        }

        tamanio = ftell(alum);

        if (tamanio < 0) {
            printf("Error al obtener el tamanio del archivo.\n");
            fclose(alum);
            return;  // Se sale de la función en caso de error
        }

         tamanioRegistro = sizeof(Alumno);
         cantidadRegistros = tamanioRegistro / tamanio;

        fclose(alum);

    }

    return cantidadRegistros;
}
///PUNTO 14:
void mostrandoEseRegistro(char nombreArchi[], int registro){

    int tamanioStruc = sizeof(Alumno);
    Alumno alumno;
    FILE *alum;
    alum = fopen(nombreArchi, "rb");

    if(alum != NULL){

        if(fseek(alum,(registro - 1) * tamanioStruc, SEEK_SET) != 0){
            printf("Error al moverse al inicio del archivo");
            fclose(alum);
            return;
        }
        fread(&alumno,sizeof(Alumno),1,alum);
        mostrarAlumno(alumno);
        fclose(alum);
    }
}
///Punto 15:
void sobreescribir(char nombreArchi[]){
    Alumno alumno;
    FILE *alum;
    alum = fopen(nombreArchi, "wb");
    char eleccion = 's';

    if(alum != NULL){
        while(eleccion == 's'){
        alumno = cargarUnAlumno();
        fwrite(&alumno, sizeof(Alumno),1,alum);
        printf("Pulsa 's' si desea cargar otro alumno: ");
        fflush(stdin);
        scanf("%c", &eleccion);
        printf("\n");
        }
         fclose(alum);
    }
}
///segunda parte punto 15:
void modificarUnSoloAlumno(char nombreArchi[], int numDeAlumno){
    int tamanioStruc = sizeof(Alumno);
    Alumno alumno;
    FILE *alum;
    alum = fopen(nombreArchi, "wb");
    if(alum != NULL){
        fseek(alum,(numDeAlumno - 1) * tamanioStruc, SEEK_SET);
        alumno = cargarUnAlumno();
        fwrite(&alumno,sizeof(Alumno),1,alum);
        mostrarAlumno(alumno);
        fclose(alum);
    }
}
