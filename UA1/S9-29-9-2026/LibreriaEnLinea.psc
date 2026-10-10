Algoritmo LibreriaEnLinea
	
    Definir titulo Como Caracter;
    Definir precio, subtotal, totalLibros, descuento, impuesto, envio, totalPagar Como Real;
    Definir cantidad, totalUnidades Como Entero;
	
    totalLibros <- 0;
    totalUnidades <- 0;
	
    Escribir "================================";
    Escribir "       LIBRERIA EN LINEA";
    Escribir "================================";
    Escribir "Digite FIN como titulo para terminar.";
    
    Escribir "Ingrese el titulo del libro:";
    Leer titulo;
	
    Mientras titulo <> "FIN" Hacer
		
        // Validar precio
        Escribir "Ingrese el precio del libro:";
        Leer precio;
		
        Mientras precio <= 0 Hacer
            Escribir "El precio debe ser positivo.";
            Escribir "Ingrese nuevamente el precio:";
            Leer precio;
        FinMientras
		
        // Validar cantidad
        Escribir "Ingrese la cantidad:";
        Leer cantidad;
		
        Mientras cantidad <= 0 Hacer
            Escribir "La cantidad debe ser positiva.";
            Escribir "Ingrese nuevamente la cantidad:";
            Leer cantidad;
        FinMientras
		
        // Calcular subtotal
        subtotal <- precio * cantidad;
		
        Escribir "Subtotal de ", titulo, ": ", subtotal;
		
        // Acumular total de libros y unidades
        totalLibros <- totalLibros + subtotal;
        totalUnidades <- totalUnidades + cantidad;
		
        Escribir "--------------------------------";
        Escribir "Ingrese el titulo del siguiente libro:";
        Leer titulo;
		
    FinMientras
	
    // Calcular descuento
    descuento <- 0;
	
    Si totalUnidades >= 5 Entonces
        descuento <- totalLibros * 0.10;
    FinSi
	
    // Calcular envio utilizando el total antes del descuento
    Si totalLibros < 50 Entonces
        envio <- 8;
    Sino
        Si totalLibros < 150 Entonces
            envio <- 4;
        Sino
            envio <- 0;
        FinSi
    FinSi
	
    // Calcular impuesto sobre total menos descuento
    impuesto <- (totalLibros - descuento) * 0.13;
	
    // Calcular total a pagar
    totalPagar <- totalLibros - descuento + impuesto + envio;
	
    // Mostrar resumen
    Escribir "";
    Escribir "================================";
    Escribir "        RESUMEN DEL PEDIDO";
    Escribir "================================";
    Escribir "Total de libros: ", totalLibros;
    Escribir "Unidades compradas: ", totalUnidades;
    Escribir "Descuento: ", descuento;
    Escribir "Impuesto: ", impuesto;
    Escribir "Envio: ", envio;
    Escribir "Total a pagar: ", totalPagar;
    Escribir "================================";
	
FinAlgoritmo
