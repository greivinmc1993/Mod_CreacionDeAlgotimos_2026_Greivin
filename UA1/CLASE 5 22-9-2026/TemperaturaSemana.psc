Algoritmo TemperaturaSemana
		
		Definir temperatura Como Real
		Definir diasCalurosos, diasFrios, i Como Entero
		
		diasCalurosos <- 0
		diasFrios <- 0
		
		Para i <- 1 Hasta 7 Hacer
			
			Escribir "Ingrese la temperatura del día ", i, ":"
			Leer temperatura
			
			Si temperatura > 30 Entonces
				diasCalurosos <- diasCalurosos + 1
			SiNo
				Si temperatura <= 15 Entonces
					diasFrios <- diasFrios + 1
				FinSi
			FinSi
			
		FinPara
		
		Escribir "Cantidad de días calurosos: ", diasCalurosos
		Escribir "Cantidad de días fríos: ", diasFrios
		
FinAlgoritmo
