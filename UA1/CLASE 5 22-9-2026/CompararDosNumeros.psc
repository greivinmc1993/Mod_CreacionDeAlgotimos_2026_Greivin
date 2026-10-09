	Algoritmo CompararDosNumeros
		
		Definir num1, num2 Como Real
		
		// 1. Pedir dos números al usuario
		Escribir "Ingrese el primer número:"
		Leer num1
		
		Escribir "Ingrese el segundo número:"
		Leer num2
		
		// 2. Comparar cuál es el mayor
		Si num1 > num2 Entonces
			
			// 3. Mostrar el valor mayor
			Escribir "El número mayor es: ", num1
			
		SiNo
			
			Si num2 > num1 Entonces
				
				// 3. Mostrar el valor mayor
				Escribir "El número mayor es: ", num2
				
			SiNo
				
				// 4. Si son iguales
				Escribir "Los números son iguales."
				
			FinSi
			
		FinSi
		
		// 5. Verificar si ambos son positivos
		Si num1 > 0 Y num2 > 0 Entonces
			Escribir "Ambos números son positivos."
		FinSi
		
		// Verificar si al menos uno es mayor que 100
		Si num1 > 100 O num2 > 100 Entonces
			Escribir "Al menos uno de los números es mayor que 100."
		FinSi
		
FinAlgoritmo