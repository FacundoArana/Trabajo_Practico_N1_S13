#include <stdio.h> 
#include <string.h> 

// Definicion de constantes

#define PRECIO_GENERALES 5000
#define PRECIO_MENORES 2000
#define PRECIO_JUBILADOS 0
#define PRECIO_ESTUDIANTES 0

// Definicion de variables globales
 
int entradas_generales = 0; 
int entradas_menores = 0; 
int entradas_jubilados = 0; 
int entradas_estudiantes = 0; 


// Funcion menu: Muestra en pantalla los tipos de entrada a la venta con su precio y deja seleccionar al usuario el tipo de entrada
// que quiera comprar, devuelve el tipo de entrada que selecciono el usuario.

int menu(){ 
    int tipo_entrada; 

    printf("\n1. Venta entrada general - $5.000\n\n2. Venta entrada menores - $2.000\n\n3. Venta entrada jubilados - Gratis\n\n4. Venta entrada estudiantes - Gratis\n\n0. Finalizar dia y muestra de resultados\n\nSeleccione una opcion: "); 

    scanf("%d", &tipo_entrada); 
        
    return(tipo_entrada); 

} 

// Procedimiento facturacion_menores: Recibe un parametro por copia, el cual luego utilizamos para calcular la facturacion total
// de entradas de menores vendidas

void facturacion_menores(int entradas_menores){ 

    printf("\nLa facturacion de las entradas menores fue de: %d$", entradas_menores * PRECIO_MENORES); 

} 


// Procedimiento comparar_menos_vendida: Chequea la entrada menos vendida y actualiza las variables menor y menos_vendida
// recibe 4 parametros, de los cuales 3 son punteros, ya que se necesita cambiar el valor de los mismos.

void comparar_menos_vendida(int cantidad_ventas_x_entrada, char* texto, char* menos_vendida, int *menor){
        // Cantidad de Entradas Menores < Entradas Generales
    if (cantidad_ventas_x_entrada < *menor) { //  Si la cantidad de ventas de la entrada que llega por parametro es menor al valor 
                                            // actual de la variable menor, define dicha entrada como el nuevo menor y remplaza el
                                            // contenido de la string "menos_vendida" al texto que llega por parametro.
        *menor = cantidad_ventas_x_entrada; 
        strcpy(menos_vendida, texto); // Reemplaza la string por el texto que entre
    } else if (cantidad_ventas_x_entrada == *menor) {   // En caso de que la cantidad de ventas sea igual a la actual minima
                                                        // la concatena a la string menos_vendida
        strcat(menos_vendida, ", ");
        strcat(menos_vendida, texto); 
    }
}

// Procedimiento actualizar_venta_menor: Muestra en pantalla, las entradas menos vendidas con la cantidad de las mismas luego
// de ser comparadas en el procedimiento comparar_menos_vendida.

void actualizar_venta_menor(int entradas_generales, int entradas_menores, int entradas_jubilados, int entradas_estudiantes) { 
    int menor = entradas_generales; 
    char menos_vendida[100] = "Entrada General";  

    comparar_menos_vendida(entradas_menores, "Entrada Menor", menos_vendida, &menor);
    comparar_menos_vendida(entradas_jubilados, "Entrada Jubilado", menos_vendida, &menor);
    comparar_menos_vendida(entradas_estudiantes, "Entrada Estudiante", menos_vendida, &menor);

    printf("\nLa cantidad de entradas que menos se vendieron fueron %s con una cantidad de %d ventas", menos_vendida, menor); 
}

  
// Procedimiento porcentaje_entradas: Obtien el porcentaje de entradas genereales vendidas sobre el total de las demas
// entradas

void porcentaje_entradas(int entradas_generales, int entradas_menores, int entradas_jubilados, int entradas_estudiantes){ 


    float contador_entradas = entradas_estudiantes + entradas_generales + entradas_jubilados + entradas_menores; 

    float division = (entradas_generales / contador_entradas) * 100; 

    printf("\nEl porcentaje de entradas generales es de %f", division); 

} 

  
// Procedimiento contador:Se utilizo un caso.
// Recibe 1 parametro por copia y 4 por referencia, agrega una venta al tipo de entrada que llega por
// parametro, 

void contador(int opcion, int *entradas_generales, int *entradas_menores, int *entradas_jubilados, int *entradas_estudiantes){ 
   
    switch(opcion){ 

        case 1: 
            *entradas_generales += 1; 
            break; 

        case 2: 
            *entradas_menores  += 1; 
            break; 

        case 3: 
            *entradas_jubilados += 1; 
            break; 

        case 4:  
            *entradas_estudiantes += 1;
            break; 

        default: 
            break; 
    } 

} 

  

int main(){ 

    while(1){
        int opcion = menu(); // Llama a la funcion menu y guarda el valor que introduce el usuario (tipo de entrada seleccionada)
                            //  y lo guarda en la variable opcion

        if (opcion == 0){ // En el caso que el usuario seleccione la opcion 0 (Finalizar), interrumpe el bucle. A
            break;  
        } 
        
        // Llama al procedimiento contador
        contador(opcion,&entradas_generales, &entradas_menores, &entradas_jubilados, &entradas_estudiantes); 
    } 

    // Llama al procedimiento facturacion_menores
    facturacion_menores(entradas_menores); 
    // Llama al procedimiento  porcentaje_entradas
    porcentaje_entradas(entradas_generales, entradas_menores, entradas_jubilados, entradas_estudiantes); 
    // Llama al procedimiento actualizar_venta_menor
    actualizar_venta_menor(entradas_generales, entradas_menores, entradas_jubilados, entradas_estudiantes); 


    return 0; 

} 

 

 