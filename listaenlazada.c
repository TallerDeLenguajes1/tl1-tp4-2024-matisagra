#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Tarea{
int TareaID;//Numérico autoincremental comenzando en 1000
char *Descripcion; //
int Duracion; // entre 10 – 100
}Tarea;

struct Nodo{
Tarea T;
struct Nodo *Siguiente;
}; typedef struct Nodo * Lista;

int crearId(Lista L){
    int id;
    if (L == NULL)
    {
        return 1000;
    }else{
        while (L != NULL)
        {
            id = L->T.TareaID;
            L = L->Siguiente;
            
        }
        id++;
        return id;
        
    }
    
    
}
Lista crearListaVacia(){
    return NULL;
}

Lista agregarTareas(Lista L,Tarea tarea){
    Lista nuevoNodo = (Lista *)malloc(sizeof(struct Nodo));
    nuevoNodo->T = tarea;
    nuevoNodo->Siguiente=L;

    return nuevoNodo;

}

void mostrarTareas(Lista L){
    while (L != NULL)
    {
        printf("\nID: %d Descripcion: %s Duracion: %d\n\n",L->T.TareaID,L->T.Descripcion,L->T.Duracion);
        L = L->Siguiente;
    }
    
}

Tarea marcarRealizadas(Lista L){
    int id;
    int buscado;
    printf("Ingrese el ID de la tarea realizada: ");
    scanf("%d",&id);

    while (L != NULL)
    {
        if (L->T.TareaID == id)
        {
            buscado = 1;
            
            break;
        }
        L=L->Siguiente;
        
    }

    if (buscado == 1)
    {
        return L->T;
    }
    
}

Lista borrar(Lista L, Tarea tarea) {
    Lista actual = L;
    Lista anterior = NULL;

    while (actual != NULL) {
        if (actual->T.TareaID == tarea.TareaID) {
            if (anterior == NULL) {
                // Si el nodo a eliminar es el primero
                L = actual->Siguiente;
            } else {
                // Si el nodo a eliminar está en medio o al final
                anterior->Siguiente = actual->Siguiente;
            }
            free(actual); // Liberar memoria del nodo eliminado
            break; // Salir del bucle luego de eliminar el nodo
        }
        // Avanzar al siguiente nodo
        anterior = actual;
        actual = actual->Siguiente;
    }
    return L; // Devolver la lista actualizada
} 


void buscador(Lista pendientes, Lista realizadas){
    int eleccion;
    int id;
    char palabra;
    printf("Ingrese el id o palabra clave (1/2): ");
    scanf("%d",&eleccion);

    if (eleccion == 1)
    {
        printf("Ingrese el id: ");
        scanf("%d",&id);

        while (pendientes != NULL)
        {
            if (pendientes->T.TareaID == id)
            {
                printf("ID: %d Descripcion: %s Duracion: %d y pertenece a la lista de pendientes\n",pendientes->T.TareaID,pendientes->T.Descripcion,pendientes->T.Duracion);
                break;
            }
            pendientes=pendientes->Siguiente;
        }

        while (realizadas != NULL)
        {
            if (realizadas->T.TareaID == id)
            {
                printf("ID: %d Descripcion: %s Duracion: %d y pertenece a la lista de realizadas\n",realizadas->T.TareaID,realizadas->T.Descripcion,realizadas->T.Duracion);
                break;
            }
            realizadas=realizadas->Siguiente;
            
        }
        

         
    }else{
        printf("Ingrese la palabra clave: ");
        gets(palabra);

        while (pendientes != NULL)
        {
            if (pendientes->T.Descripcion == palabra)
            {
                printf("ID: %d Descripcion: %s Duracion: %d y pertenece a la lista de pendientes\n",pendientes->T.TareaID,pendientes->T.Descripcion,pendientes->T.Duracion);
                break;
            }
            pendientes = pendientes->Siguiente;
            
        }

        while (realizadas != NULL)
        {
            if (realizadas->T.Descripcion == palabra)
            {
                printf("ID: %d Descripcion: %s Duracion: %d y pertenece a la lista de pendientes\n",realizadas->T.TareaID,realizadas->T.Descripcion,realizadas->T.Duracion);
                break;
            }
            realizadas=realizadas->Siguiente;
            
        }
    }

   
    

}

int main(){

    Lista listaPendientes = crearListaVacia();
    Lista listaRealizadas = crearListaVacia();

    Tarea tarea1 = {crearId(listaPendientes),"agregar caca",10};
    listaPendientes = agregarTareas(listaPendientes,tarea1);

    Tarea tarea2 = {crearId(listaPendientes),"agregar papeles",20};
    listaPendientes = agregarTareas(listaPendientes,tarea2);

    mostrarTareas(listaPendientes);

    Tarea buscada = marcarRealizadas(listaPendientes);

    listaRealizadas= agregarTareas(listaRealizadas,buscada);

    listaPendientes = borrar(listaPendientes,buscada);

    mostrarTareas(listaRealizadas);

    mostrarTareas(listaPendientes);

    buscador(listaPendientes,listaRealizadas);



}