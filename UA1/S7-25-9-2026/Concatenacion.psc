Proceso Concatenacion
	
	Definir nombre, ciudad Como Caracter;
	Definir edad, anio Como Entero;
	Definir promedio Como Real;
	Definir aprobado Como Logico;
	
	nombre <- "Carlos Rodriguez";
	edad <- 22;
	promedio <- 8.5;
	anio <- 2026;
	aprobado <- Verdadero;
	ciudad <- "San José";
	
	Escribir "--- REPORTE MENSUAL";
	Escribir "";
	
	//DATOS PERSONALES
	Escribir "---DATOS PERSONALES";
	Escribir "Nombre: ", nombre;
	Escribir "Ciudad: ", ciudad;
	Escribir "Edad: ", edad, "años";
	Escribir "";
	
	//DATOS ACADÉMICOS
	Escribir "---DATOS ACADÉMIOS";
	Escribir "Promedio: ", promedio;
	Escribir "Aprobado: ", aprobado;
	Escribir "Año: ", anio;
	Escribir "";
	
	//RESUMEN COMPLETO
	Escribir "---RESUMEN";
	Escribir "El estudiante: ", nombre, " de ", edad, " años ";
	Escribir "Residente en: ", ciudad, " Tiene un prmedio de: ", promedio;
	Escribir "Y su estado de aprobación es: ", aprobado;
	Escribir "";
	
	
	
FinProceso
