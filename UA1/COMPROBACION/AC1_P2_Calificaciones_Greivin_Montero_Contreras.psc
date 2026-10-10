		// ====================================================
		//                 PORTADA DEL PROYECTO
		// ====================================================
		//=====================================================
		//                                     
		//             INSTITUTO NACIONAL DE APRENDIZAJE 
		//                  NÚCLEO PROCESO Y SERVICIOS      
		//                       DESARROLLO WEB                    
		//       CURSO       : Diseño de Algoritmos               
		//       PROYECTO    : Actividad de comprobación 1
		//       ESTUDIANTE  : Greivin Montero Contreras               
		//       PROFESOR    : Giovanni Antonio Coto Calderón           
		//       FECHA       : 01 de Octubre, 2026         
		//                                                    
		// "=====================================================
		
		
		// ======================================================
		//                      INICIO DEL CÓDIGO 
		// ======================================================
		
		
        //DATOS DE ENTRADA
		//3NOTAS, NOMBRE
     
     
		
        //LIMITANTES
        //NUMEROS NEGATIVOS, NUMEROS FUERA DEL RANGO, LETRAS EN VEZ DE NUMEROS
     
     
     
		
		//PROCESO
		//RECIBIR NOMBRE Y 3 NOTAS, SUMARLAS Y DIVIDIRLAS ENTRE 3 CLASIFICARLAS EGUN SU PROMEDIO MOSTRAR SI APROBÓ O NO
		
		
		
		//SALIDA
        //NOTAS, PROMEDIO, NOMBRE, APROBADO O REPROBADO, CONDICION




Proceso ValidacionDeNotas
	
	Definir nombre, condicion Como Caracter;
	Definir nota1, nota2, nota3, promedio Como Real;
	
	Escribir "==============================";
	Escribir "Por favor ingrese su nombre: ";
	Escribir "==============================";
	Leer nombre;
	
	
	//INGRESO DE NOTA 1 Y VALIDACION CON MIENTRAS
	Escribir "==============================";
	Escribir "Por favor ingrese NOTA 1: ";
	Escribir "==============================";
	Leer nota1;
	
	Mientras nota1 > 100 O nota1 < 0 Hacer
		Escribir "==============================";
		Escribir "Valor invalido ingrese un valor entre 0 y 100: ";
		Escribir "==============================";
		Escribir "";
		Escribir "==============================";
		Escribir "Vuelva a ingresar la nota por favor: ";
		Escribir "==============================";
		Leer nota1;
	FinMientras
	
	
	//INGRESO NOTA 2 CON VALIDACION
	Escribir "==============================";
	Escribir "Por favor ingrese NOTA 2: ";
	Escribir "==============================";
	Leer nota2;
	
	Mientras nota2 > 100 O nota2 < 0 Hacer
		Escribir "==============================";
		Escribir "Valor invalido ingrese un valor entre 0 y 100: ";
		Escribir "==============================";
		Escribir "";
		Escribir "==============================";
		Escribir "Vuelva a ingresar la nota por favor: ";
		Escribir "==============================";
		Leer nota2;
	FinMientras
	
	
	//INGRESO NOTA 3 CON VALIDACION 
	Escribir "==============================";
	Escribir "Por favor ingrese NOTA 3: ";
	Escribir "==============================";
	Leer nota3;
	
	Mientras nota3 > 100 O nota3 < 0 Hacer
		Escribir "==============================";
		Escribir "Valor invalido ingrese un valor entre 0 y 100: ";
		Escribir "==============================";
		Escribir "";
		Escribir "==============================";
		Escribir "Vuelva a ingresar la nota por favor: ";
		Escribir "==============================";
		Leer nota3;
	FinMientras
	
	
	//CALCULO DE PROMEDIO DE NOTAS
	promedio <- (nota1 + nota2 + nota3) / 3;
	
	
	//ASIGNACION DE CONDICION
	Si promedio >= 70 Entonces
		condicion <- "APROBADO";
	SiNo
		Si promedio >= 60 Y promedio < 70 Entonces
			condicion <- "EN RIESGO";
		SiNo
			condicion <- "REPROBADO";
		FinSi
	FinSi
	
	
	//RESUMEN DE NOTAS
	Escribir "==============================";
	Escribir "RESUMEN DE NOTAS para :", nombre;
	Escribir "Calificación 1: ", nota1;
	Escribir "Calificación 2: ", nota2;
	Escribir "Calificación 3: ", nota3;
	Escribir "Su promedio es de: ", promedio;
	Escribir "CONDICIÓN: ", condicion;
	Escribir "==============================";
	
	
FinProceso
