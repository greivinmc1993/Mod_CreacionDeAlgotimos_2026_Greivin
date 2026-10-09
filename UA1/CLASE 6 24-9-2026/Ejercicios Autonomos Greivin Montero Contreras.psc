Algoritmo Ejercicios
	Definir opcion Como Entero;
	
	Escribir "";
	Escribir "";
	Escribir "CUAL EJERCICIO DE CLASE DESEA REALIZAR";
	Escribir " 1- EJERCICIO 1: Declaración de Variables (Básico)";
	Escribir " 2- EJERCICIO 2: Uso de Constantes (Básico-Intermedio)";
	Escribir " 3- EJERCICIO 3: Conversión de Tipos (Intermedio) ";
	Escribir " 4- EJERCICIO 4: Validación de Tipos (Intermedio)";
	Escribir " 5- EJERCICIO 5: Cálculo de Cuota Mensual (Intermedio-Avanzado) ";
	Escribir " 6- EJERCICIO 6: Generador de Contraseña (Intermedio-Avanzado)  ";
	Escribir " 7- EJERCICIO 7: Sistema de Calificaciones (Avanzado) ";
	Escribir " 8- EJERCICIO 8: Conversor de Unidades (Muy Avanzado) ";
	Escribir "";
	Escribir " 9- Salir.";
	Leer opcion;
	
	Segun opcion Hacer
		1:
			Escribir "";
			Escribir "EJERCICIO 1";
			Escribir "Crear un programa que declare variables para almacenar información de un libro: título (Carácter), autor ";
			Escribir "(Carácter), año de publicación (Entero), y precio (Real). Luego, asigne valores y muestre la información formateada.";
			Escribir "";
			
			//SE DEFINEN VARIABLES PARA GUARDAR LOS DATOS REQUERIDOS
			Definir titulo, autor Como Caracter;
			Definir year Como Entero;
			Definir precioLibro Como Real;
			
			Escribir "Agrega el Título del libro.";
			Leer titulo;
			Escribir "Agrega el Autor del libro";
			Leer autor;
			Escribir "Agrea el Año del libro.";
			Leer year;
			Escribir "Para finalizar agrega el Precio";
			Leer precioLibro;
			
			Escribir "Se agregó el libro.";
			Escribir titulo;
			Escribir "De: ", autor;
			Escribir "Del año: ", year;
			Escribir "Con precio de: ", precioLibro;
			
			
		2:
			Escribir "";
			Escribir "EJERCICIO 2: Uso de Constantes (Básico-Intermedio)";
			Escribir "Crear un programa que utilice constantes para calcular el presupuesto de un viaje. Use constantes para el precio";
			Escribir "de la gasolina por litro, tarifa de hotel por noche, y costo de comidas. Calcule el costo total.";
			Escribir "";
			
			//DEFINICION DE CONSTANTES
			Definir CostoGasolina Como Real;
			Definir NochesHotel, DiasComida Como Entero;
			//INICIALIZACION DE CONSTANTES
			CostoGasolina <- 800*0.056;
			NochesHotel <- 80;
			DiasComida <- 30;
			
			//DEFINICION DE VARIABLES NORMALES
			Definir Litros, CosumoTotal como real;
			Definir Noches, Dias como entero;
			
			Escribir "";
			Escribir "Ingrese litros de gasolina. ";
			Leer Litros;
			Escribir "Ingrese noches de hospedaje. ";
			Leer Noches;
			Escribir " Ingrese los días de alimentacion. ";
			Leer Dias;
			Escribir "";
			Escribir "Su detalle total es de: ";
			Escribir "";
			Escribir "Litros de gasolina: $800 * ", Litros;
			Escribir "Noches de hospedaje: $80 * ", Noches;
			Escribir "Días de alimentación: $30 * ", Dias;
			Escribir "";
			CosumoTotal <- (Litros*CostoGasolina) + (Noches*NochesHotel) + (Dias*DiasComida);
			Escribir "Para un total de $", CosumoTotal;
			
			
			
		3:	
			Escribir "";
			Escribir "EJERCICIO 3: Conversión de Tipos (Intermedio) ";
			Escribir "Crear un programa que lea un número como texto, lo convierta a número entero, realice cálculos, y luego ";
			Escribir "convierta el resultado de vuelta a texto para mostrar un mensaje final.";
			Escribir "";
			
			//DEFINICION DE VARIABLES
				Definir numeroTexto, resultadoTexto Como Caracter;
				Definir numero3, resultado Como Entero;
				
				Escribir "Ingrese un numero como texto:";
				Leer numeroTexto;
				
				numero3 <- ConvertirANumero(numeroTexto);
				
				resultado <- numero3 * 3;
				resultado <- resultado + 10;
				
				resultadoTexto <- ConvertirATexto(resultado);
				
				Escribir "El numero ingresado fue: ", numeroTexto;
				Escribir "El resultado final es: ", resultadoTexto;
				
				
		4:	
			Escribir "";
			Escribir "EJERCICIO 4: Validación de Tipos (Intermedio)  ";
			Escribir "Crear un programa que valide si un número entero ingresado está dentro de un rango específico. Use variables";
			Escribir "lógicas para almacenar resultados de comparaciones. ";
			Escribir "";
			
			//DEFINICION DE CONSTANTES
			Definir MINIMO, MAXIMO Como Entero;
			MINIMO<- 0;
			MAXIMO <- 100;
			//DEFINICION DE VARIABLES
			Definir limiteInferior, limiteSuperior, rango Como Logico;
			Definir numero4 Como Entero;
			
			Escribir "";
			Escribir "Ingrese un número entero";
			Leer numero4;
			
			limiteSuperior <- numero4 >= MINIMO;
			limiteInferior <- numero4 <= MAXIMO;
			
			rango <- limiteInferior Y limiteSuperior;
			
			Si rango Entonces
				Escribir "El número es valido. Está dentro del rango ", numero4;
			SiNo
				Escribir "El número no es valido. Está fuera del rango ", numero4;
			FinSi
			
			
		5:
			Escribir "";
			Escribir "EJERCICIO 5: Cálculo de Cuota Mensual (Intermedio-Avanzado) ";
			Escribir "Crear un programa que calcule la cuota mensual de un préstamo. El usuario ingresa el monto del préstamo, la ";
			Escribir "tasa de interés anual y el plazo en meses. Calcule la cuota mensual usando la fórmula apropiada.";
			Escribir "";
			
			//DEFINICION DE VARIABLES
			Definir prestamo, tasaAnual, tasaMensual, cuota Como Real;
			Definir plazo Como Entero;
			
			Escribir "Ingrese el monto del prestamo:";
			Leer prestamo;
			
			Escribir "Ingrese la tasa de interes anual (%):";
			Leer tasaAnual;
			
			Escribir "Ingrese el plazo en meses:";
			Leer plazo;
			
			tasaMensual <- (tasaAnual / 100) / 12;
			
			cuota <- prestamo * (tasaMensual / (1 - (1 + tasaMensual) ^ (-plazo)));
			
			cuota <- Redon(cuota * 100) / 100;
			
			Escribir "-----------------------------";
			Escribir "CALCULO DEL PRESTAMO";
			Escribir "Monto del prestamo: ", prestamo;
			Escribir "Tasa anual: ", tasaAnual, "%";
			Escribir "Plazo: ", plazo, " meses";
			Escribir "Cuota mensual: ", cuota;
			Escribir "-----------------------------";
			
			
		6:
			Escribir "";
			Escribir "EJERCICIO 6: Generador de Contraseña (Intermedio-Avanzado)  ";
			Escribir "Crear un programa que genere una contraseña combinando el nombre de usuario (Carácter), una constante de  ";
			Escribir "prefijo, el año actual (Entero), y un número especial (Entero)";
			Escribir "";
			
			//DEFINICION DE VARIABLES
			Definir PREFIJO Como Caracter;
			Definir usuario, contrasena Como Caracter;
			Definir anio, numeroEspecial Como Entero;
			
			PREFIJO <- "#PELUCA-";
			
			Escribir "Ingrese el nombre de usuario:";
			Leer usuario;
			
			Escribir "Ingrese el año:";
			Leer anio;
			
			Escribir "Ingrese el numero especial:";
			Leer numeroEspecial;
			
			contrasena <- PREFIJO + usuario + "_" + ConvertirATexto(anio) + "_" + ConvertirATexto(numeroEspecial);
			
			Escribir "-----------------------------";
			Escribir "CONTRASEÑA GENERADA";
			Escribir contrasena;
			Escribir "-----------------------------";
			
			
		7:
			Escribir "";
			Escribir "EJERCICIO 7: Sistema de Calificaciones (Avanzado) ";
			Escribir "Crear un programa que procese calificaciones de estudiantes. Lee nombre (Carácter), 3 calificaciones (Real),  ";
			Escribir "calcula promedio, determina si pasó/reprobó (Lógico) y asigna una letra de calificación (Carácter). ";
			Escribir "";
			
			//DEFINICION DE VARIABLES
			Definir nombre, letra Como Caracter;
			Definir nota1, nota2, nota3, promedio Como Real;
			Definir aprobado Como Logico;
			
			Definir MINIMA Como Real;
			MINIMA <- 6.0;
			
			Escribir "Ingrese el nombre del estudiante:";
			Leer nombre;
			
			Escribir "Ingrese la primera calificacion del 1 al 10 de: ", nombre;
			Leer nota1;
			
			Escribir "Ingrese la segunda calificacion del 1 al 10 de: ", nombre;
			Leer nota2;
			
			Escribir "Ingrese la tercera calificacion del 1 al 10 de: ", nombre;
			Leer nota3;
			
			promedio <- (nota1 + nota2 + nota3) / 3;
			
			aprobado <- promedio >= MINIMA;
			
			Si promedio >= 9 Entonces
				letra <- "A";
			Sino
				Si promedio >= 7 Entonces
					letra <- "B";
				Sino
					Si promedio >= 6 Entonces
						letra <- "C";
					Sino
						letra <- "D";
					FinSi;
				FinSi;
			FinSi;
			
			Escribir "-----------------------------";
			Escribir "REPORTE DEL ESTUDIANTE";
			Escribir "Nombre: ", nombre;
			Escribir "Nota 1: ", nota1;
			Escribir "Nota 2: ", nota2;
			Escribir "Nota 3: ", nota3;
			Escribir "Promedio: ", promedio;
			Escribir "Calificacion: ", letra;
			
			Si aprobado Entonces
				Escribir "Estado: APROBADO";
			Sino
				Escribir "Estado: REPROBADO";
			FinSi;
			
			
		8:	Escribir "";
			Escribir "EJERCICIO 8: Conversor de Unidades (Muy Avanzado) ";
			Escribir "Crear un programa que convierta temperaturas entre Celsius y Fahrenheit. Use constantes para las fórmulas de ";
			Escribir "conversión, y cree un programa que determine si es frío, templado o caliente basándose en rangos de temperatura. ";
			Escribir "";
			
			//CONSTANTES
			Definir FACTOR_CELSIUS, FACTOR_FAHRENHEIT, AJUSTE Como Real;
			
			FACTOR_CELSIUS <- 9/5;
			FACTOR_FAHRENHEIT <- 5/9 ;
			AJUSTE <- 32;
			
			Definir temperatura, resultadoTemp  Como Real;
			Definir opcion8 Como Entero;
			Definir valida Como Logico;
			Definir clasificacion Como Caracter;
			
			valida <- Verdadero;
			
			Escribir "CONVERSOR DE TEMPERATURAS";
			Escribir "1. Celsius a Fahrenheit";
			Escribir "2. Fahrenheit a Celsius";
			Escribir "Seleccione una opcion:";
			Leer opcion8;
			
			
			Escribir "Ingrese la temperatura:";
			Leer temperatura;
			
			//valida <- Verdadero;
			
			Segun opcion8 Hacer
				1:
					// Validacion de Celsius
					Si temperatura < -90 O temperatura > 60 Entonces
						valida <- Falso;
					FinSi
					
					Si valida = Verdadero Entonces
						
						resultadoTemp <- (temperatura * FACTOR_CELSIUS) + AJUSTE;
						
						Escribir "Temperatura en Fahrenheit: ", resultadoTemp;
						
						// Clasificacion en Celsius
						Si resultadoTemp < ((15 * FACTOR_CELSIUS) + AJUSTE) Entonces
							clasificacion <- "F";
						Sino
							Si resultadoTemp <= ((25 * FACTOR_CELSIUS) + AJUSTE) Entonces
								clasificacion <- "T";
							Sino
								clasificacion <- "C";
							FinSi
						FinSi
						
					Sino
						Escribir "La temperatura no esta dentro de un rango realista.";
					FinSi
				2:
					// Validacion de Fahrenheit
					Si temperatura < -130 O temperatura > 140 Entonces
						valida <- Falso;
					FinSi
					
					Si valida = Verdadero Entonces
						
						resultadoTemp <- (temperatura - AJUSTE) * FACTOR_FAHRENHEIT;
						
						Escribir "Temperatura en Celsius: ", resultadoTemp;
						
						// Clasificacion en Celsius
						Si resultadoTemp < 15 Entonces
							clasificacion <- "F";
						Sino
							Si resultadoTemp <= 34 Entonces
								clasificacion <- "T";
							Sino
								clasificacion <- "C";
							FinSi
						FinSi
						
					Sino
						Escribir "La temperatura no esta dentro de un rango realista.";
					FinSi
			FinSegun
			
			// Mostrar clasificacion
			Si valida = Verdadero Entonces
				
				Si clasificacion = "F" Entonces
					Escribir "Clasificacion: Frio";
				Sino
					Si clasificacion = "T" Entonces
						Escribir "Clasificacion: Templado";
					Sino
						Escribir "Clasificacion: Caliente";
					FinSi
				FinSi
				
			FinSi
			
			
			
			
		9:
			Escribir "CHAO CHAO";
	FinSegun
	
	
FinAlgoritmo
