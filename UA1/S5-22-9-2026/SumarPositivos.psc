proceso SumarPositivos
	
    Definir numero, suma Como Real;
    Definir i Como Entero;
	
    suma <- 0;
	
    Para i <- 1 Hasta 12 Hacer
		
        Escribir "Ingrese el número ", i, ":";
        Leer numero;
		
        Si numero > 0 Entonces
            suma <- suma + numero;
        FinSi
		
    FinPara
	
    Escribir "La suma de los números positivos es: ", suma;
	
Finproceso