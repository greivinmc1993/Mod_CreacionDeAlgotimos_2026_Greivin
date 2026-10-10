Proceso conversion
	
	Definir FACTOR_CELSIUS, FACTOR_FAHRENHEIT, AJUSTE Como Real;
	
	FACTOR_CELSIUS <- 9/5;
	FACTOR_FAHRENHEIT <- 5/9;
	AJUSTE <- 32;
	
	Definir clasificacion Como Caracter;
	Definir validar Como Logico;
	Definir temperatura, resultado Como Real;
	Definir opcion Como Entero;
	
	validar <- Verdadero;
	clasificacion <- "";
	
	Escribir "";
	Escribir "Coversor";
	Escribir "1. C a F";
	Escribir "2. F a C";
	Escribir "Qué desea hacer?";
	Leer opcion;
	
	Escribir "Ingrese la temperatura";
	Leer temperatura;
	
	Segun opcion Hacer
		1:
			Si temperatura > -90 O temperatura < 60 Entonces
				resultado <- (temperatura * FACTOR_CELSIUS) + 32;
				Escribir "La temp en F: ", resultado;
				
 			SiNo
				Escribir "La temp no es realista";
			FinSi
			
			Si temperatura < 5 Entonces
				clasificacion <- "Frio";
				
				SiNo
					Si temperatura > 5 y temperatura < 35 Entonces
						clasificacion <- "templado";
					SiNo
						clasificacion <- "caliente";
					FinSi
					
			FinSi
			
			
			Escribir "La temperatura en F es de: ", resultado, " Con clasificación: ", clasificacion;
			
			
		2:
			Si temperatura > -90 O temperatura < 60 Entonces
				resultado <- (temperatura - AJUSTE) * FACTOR_FAHRENHEIT;
				Escribir "La temp en C: ", resultado;
				
 			SiNo
				Escribir "La temp no es realista";
			FinSi
			
			Si temperatura < 5 Entonces
				clasificacion <- "Frio";
				
			SiNo
				Si temperatura > 5 y temperatura < 35 Entonces
					clasificacion <- "templado";
				SiNo
					clasificacion <- "caliente";
				FinSi
				
			FinSi
			
			
			Escribir "La temperatura en F es de: ", resultado, " Con clasificación: ", clasificacion;

	FinSegun
	
	
	
	
	
FinProceso
