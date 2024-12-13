//Dereck Perez/Taller s8
#include "inventario.h"

int main() {
    Producto inventario[productos];
    int contador = 0;
    int opciones;

    do {
        printf("\n=== Sistema de Inventarios ===\n");
        printf("presione 1 para ingrear un producto \n");
        printf("presione 2 para editar un producto\n");
        printf("presione 3 para eliminar un producto\n");
        printf("presione 4 para lista de productos\n");
        printf("presione 5 para salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opciones);

        switch (opciones) {
            case 1:
                ingresarProducto(inventario, &contador);
                break;
            case 2:
                editarProducto(inventario, contador);
                break;
            case 3:
                eliminarProducto(inventario, &contador);
                break;
            case 4:
                listarProductos(inventario, contador);
                break;
            case 5:
                printf("Saliendo del sistema. ¡Hasta luego!\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    } while (opciones != 5);

    return 0;
}