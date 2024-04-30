#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int TareaID;         // Numérico autoincremental comenzando en 1000
    char *Descripcion;   // Descripción de la tarea
    int Duracion;        // Duración de la tarea (entre 10 y 100)
} Tarea;

// Definición de la estructura Nodo
struct Nodo {
    Tarea T;
    struct Nodo *Siguiente;  // Puntero al siguiente nodo
};
typedef struct Nodo* Lista;

Lista listaVacia(){
    return NULL;
}

Lista agregarTarea(Lista pendientes, Tarea tarea){
    Lista nuevoNodo = (Lista)malloc(sizeof(struct Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }
    nuevoNodo->T = tarea;
    nuevoNodo->Siguiente = pendientes;
    return nuevoNodo;
}

void mostrarPendientes(Lista pendientes){
    while (pendientes != NULL) {
        printf("ID: %d, Descripcion: %s, Duracion: %d\n", pendientes->T.TareaID, pendientes->T.Descripcion, pendientes->T.Duracion);
        pendientes = pendientes->Siguiente;
    }
}

int main(){

    Tarea tarea1 = {1000, "agregue papeles", 10};
    Tarea tarea2 = {1001, "ordene papeles", 20};

    Lista pendientes = listaVacia();

    pendientes = agregarTarea(pendientes, tarea1); 
    pendientes = agregarTarea(pendientes, tarea2);

    mostrarPendientes(pendientes);

    return 0;
}