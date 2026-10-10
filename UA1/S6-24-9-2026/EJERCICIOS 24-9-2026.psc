Algoritmo CALCULO_CONSTANTES
	
	//DECLARACION DE CONSTANTES
	Definir PII, TASA_IMPUESTO Como Real;
	
	PII <- 3.14;
	TASA_IMPUESTO <- 0.13;
	
	//VARIABLES SENCILLAS (NO CONSTANTES)
	Definir radio, opcion, numEntero, numRecuperado, edad, num, textoSalida Como Entero;
	Definir area, precio, impuesto, total, peso Como Real;
	Definir numTexo, caract, nombre, numEntrada  Como Caracter;
	Definir ejercicio, esMayor como logico;
	
	ejercicio <- Verdadero;
	edad <- 25;
	peso <- 75.5;
	nombre <- "Carlos";
	esMayor <- Verdadero;
	
	
	
	
	
	
	
	//Repetir
		//ejercicio <- Verdadero;
		
		Escribir "";
		Escribir "";
		Escribir "CUAL EJERCICIO DE CLASE DESEA REALIZAR";
		Escribir " 1- El del área de un circulo.";
		Escribir " 2- Pasar número a texto con ConvertirATexto(num)";
		Escribir " 3- Pasar texto a número con ConvertirANumero(numEntrada)";
		Escribir "";
		Escribir " 4- Salir.";
		Leer opcion;
		
		Segun opcion Hacer
			1:
				Escribir "--- CÁLCULO DE ÁREA DEL CÍRCULO ---";
				Escribir " RADIO (CM): ";
				Leer radio;
				
				area <- PII*radio^2;
				
				Escribir area;
			2:
				Escribir "Ingrese números en texto. OJO DEBE SER NÚMEROS";
				Leer num;
				caract <- ConvertirATexto(num);
				Escribir "Número como entero: ", num;
				Escribir "Número como texto: ", caract;
			3:
				Escribir "Ingrese números. OJO DEBE SER NUMEROS";
				Leer numEntrada;
				textoSalida <- ConvertirANumero(numEntrada);
				Escribir "El texto convertido es: ", textoSalida;
				Escribir "";
			4:
				ejercicio <- Falso;
		FinSegun
		
		
	//Hasta Que ejercicio = Falso;
	
	
	
	
	
FinAlgoritmo
