Algoritmo validacion
	
	Definir password, input Como Caracter
	Definir intentos Como Entero
	intentos <- 3
	password <- "1234"

	Repetir
		
		Escribir "Ingrese Contraseña"
		Leer input
		
		Si input = password Entonces
			Escribir "!Contraseña Correcta!"
			intentos <- 0
		SiNo
			intentos <- intentos - 1
			
			Si intentos = 1 Entonces
				Escribir "Te queda un último intento"
			SiNo
				Escribir "Contraseña Incorrecta te queda ", intentos , " Intentos"
			Fin Si
			
			Si intentos = 0 Entonces
				Escribir "Cuenta Bloqueada"
			Fin Si
			
		Fin Si
	Hasta Que intentos = 0
	
FinAlgoritmo
