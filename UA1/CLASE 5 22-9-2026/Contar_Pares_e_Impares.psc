Algoritmo Contar_Pares_e_Impares
	Definir pares, impares, num, operacion Como Entero
	Para i<-1 Hasta 10 Con Paso 1 Hacer
		Escribir 'ingrese el numero ', i
		Leer num

		Si (num MOD 2=0) Entonces
			pares <- pares+1
		SiNo
			impares <- impares+1
		FinSi
		
	FinPara
	
	Escribir 'Pares en total ', pares
	Escribir 'Impares en total ', impares
FinAlgoritmo
