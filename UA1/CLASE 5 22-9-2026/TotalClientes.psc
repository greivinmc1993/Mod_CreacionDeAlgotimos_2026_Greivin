Algoritmo TotalClientes
	
    Definir precio, cantidad, total Como Real;
    Definir i Como Entero;
	
    Para i <- 1 Hasta 5 Hacer
		
        Escribir "Cliente ", i;
        Escribir "Ingrese el precio del producto:";
        Leer precio;
		
        Escribir "Ingrese la cantidad comprada:";
        Leer cantidad;
		
        total <- precio * cantidad;
		
        Si cantidad > 5 Entonces
            total <- total - (total * 0.10);
        FinSi
		
        Escribir "Total a pagar por el cliente ", i, ": ", total;
        Escribir "-----------------------------";
		
    FinPara
	
FinAlgoritmo