Algoritmo cajero
		
		Definir pin, pinCorrecto Como Entero
		Definir saldo, monto Como Real
		
		pinCorrecto <- 1234
		saldo <- 500000
		
		Escribir "Inserte su tarjeta."
		Escribir "Ingrese su PIN:"
		Leer pin
		
		Si pin = pinCorrecto Entonces
			
			Escribir "PIN correcto."
			Escribir "Ingrese el monto que desea retirar:"
			Leer monto
			
			Si monto <= saldo Entonces
				
				saldo <- saldo - monto
				
				Escribir "Retiro realizado correctamente."
				Escribir "Retire su dinero."
				Escribir "Saldo restante: ", saldo
				
			SiNo
				
				Escribir "Fondos insuficientes."
				
			FinSi
			
		SiNo
			
			Escribir "PIN incorrecto."
			
		FinSi
		
FinAlgoritmo