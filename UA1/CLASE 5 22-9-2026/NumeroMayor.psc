Algoritmo NumeroMayor
	
    Definir numero, mayor Como Entero;
	
    mayor <- 0;
	
    Repetir
		
        Escribir "Ingrese un número entero positivo:";
        Escribir "Ingrese un número negativo para terminar:";
        Leer numero;
		
        Si numero >= 0 Entonces
			
            Si numero > mayor Entonces
                mayor <- numero;
            FinSi
			
        FinSi
		
    Hasta Que numero < 0
	
    Escribir "El número mayor ingresado es: ", mayor;
	
FinAlgoritmo