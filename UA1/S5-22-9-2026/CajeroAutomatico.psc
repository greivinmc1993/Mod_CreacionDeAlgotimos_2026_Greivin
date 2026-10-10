proceso CajeroAutomatico
		
		Definir saldo, monto Como Real;
		Definir opcion Como Entero;
		
		saldo <- 1000;
		
		Repetir
			
			Escribir "==========================";
			Escribir "     CAJERO AUTOMATICO";
			Escribir "==========================";
			Escribir "1. Depositar dinero";
			Escribir "2. Retirar dinero"
			Escribir "3. Consultar saldo"
			Escribir "4. Salir"
			Escribir "Seleccione una opción:"
			Leer opcion
			
			Segun opcion Hacer
				
				1:
					Escribir "Ingrese el monto a depositar:"
					Leer monto
					
					saldo <- saldo + monto
					
					Escribir "Depósito realizado correctamente."
					Escribir "Nuevo saldo: $", saldo
					
				2:
					Escribir "Ingrese el monto a retirar:"
					Leer monto
					
					Si monto <= saldo Entonces
						saldo <- saldo - monto
						Escribir "Retiro realizado correctamente."
						Escribir "Nuevo saldo: $", saldo
					SiNo
						Escribir "Fondos insuficientes."
					FinSi
					
				3:
					Escribir "Su saldo actual es: $", saldo
					
				4:
					Escribir "Gracias por utilizar el cajero."
					
				De Otro Modo:
					Escribir "Opción no válida."
					
			FinSegun
			
		Hasta Que opcion = 4
		
Finproceso
