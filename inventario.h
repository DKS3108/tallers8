//Dereck Perez/Taller s8
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <stdio.h>
#include <string.h>

// lo que hacemos aqui es definir un limite de productos 
#define productos 100

// aqui ponemos las variables para los productos 
typedef struct {
    char nombre[50];
    int cantidad;
    float precio;
} Producto;

// aqui ponemos las funciones para ingresar un producto al inventario
void ingresarProducto(Producto inventario[], int *contador) {
    if (*contador >= productos) {
        printf("El inventario está lleno.\n");
        return;
    }

    printf("Ingrese el nombre del producto: ");
    getchar(); 
    fgets(inventario[*contador].nombre, sizeof(inventario[*contador].nombre), stdin);
    inventario[*contador].nombre[strcspn(inventario[*contador].nombre, "\n")] = 0; 

    printf("Ingrese la cantidad: ");
    scanf("%d", &inventario[*contador].cantidad);

    printf("Ingrese el precio: ");
    scanf("%f", &inventario[*contador].precio);

    (*contador)++;
    printf("Producto agregado con éxito.\n");
}

// aqui esta la funcion para editar un producto 
void editarProducto(Producto inventario[], int contador) {
    if (contador == 0) {
        printf("El inventario está vacío.\n");
        return;
    }

    for (int i = 0; i < contador; i++) {
        printf("%d. %s\n", i + 1, inventario[i].nombre);
    }

    int index;
    printf("Seleccione el número del producto a editar: ");
    scanf("%d", &index);

    if (index > 0 && index <= contador) {
        index--; 
        printf("Editar producto: %s\n", inventario[index].nombre);

        printf("Ingrese el nuevo nombre del producto: ");
        getchar(); 
        fgets(inventario[index].nombre, sizeof(inventario[index].nombre), stdin);
        inventario[index].nombre[strcspn(inventario[index].nombre, "\n")] = 0;

        printf("Ingrese la nueva cantidad: ");
        scanf("%d", &inventario[index].cantidad);

        printf("Ingrese el nuevo precio: ");
        scanf("%f", &inventario[index].precio);

        printf("Producto editado con éxito.\n");
    } else {
        printf("Número de producto no válido.\n");
    }
}

// aqui ponemos la funcion  para eliminar un producto del inventario
void eliminarProducto(Producto inventario[], int *contador) {
    if (*contador == 0) {
        printf("El inventario está vacío.\n");
        return;
    }

    for (int i = 0; i < *contador; i++) {
        printf("%d. %s\n", i + 1, inventario[i].nombre);
    }

    int index;
    printf("Seleccione el número del producto a eliminar: ");
    scanf("%d", &index);

    if (index > 0 && index <= *contador) {
        index--; 
        for (int i = index; i < *contador - 1; i++) {
            inventario[i] = inventario[i + 1];
        }
        (*contador)--;
        printf("Producto eliminado con éxito.\n");
    } else {
        printf("Número de producto no válido.\n");
    }
}

// funcion para la lista de inventarios 
void listarProductos(Producto inventario[], int contador) {
    if (contador == 0) {
        printf("El inventario está vacío.\n");
        return;
    }

    printf("\n=== Lista de Productos ===\n");
    for (int i = 0; i < contador; i++) {
        printf("%d. Nombre: %s, Cantidad: %d, Precio: %.2f\n",
               i + 1, inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
    }
}
#endif // INVENTARIO_H