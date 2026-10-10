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
		//NOMBRE, SALARIO
     
     
		
        //LIMITANTES
        //NUMEROS NEGATIVOS, LETRAS EN VEZ DE NUMEROS
     
     
     
		
		//PROCESO
		//RECIBIR NOMBRE Y USUARIO SACAR LAS DEDUCCIONES PORCENTUALES A LO MONTOS BASE Y VALIDAR SI PAGA IMPUESTOS
		
		
		
		//SALIDA
        //NOMBRE, SALARIO, DESCUENTOS Y SALARIO NETO.



Proceso SistemaCalculoNomina
	
	Definir nombre Como Caracter;
	Definir salario, ccss, ass, impuesto, salarioNeto Como Real;
	
	//INGRESO DE LA INFORMACION POR BLOQUES
	Escribir "==============================";
	Escribir "Por favor ingrese su nombre: ";
	Escribir "==============================";
	Leer nombre;
	
	
	Escribir "==============================";
	Escribir "Por favor ingrese su salario: ";
	Escribir "==============================";
	Leer salario;
	
	//CLACULOS DE REBAJOS Y DEMÁS
	ccss <- salario * 0.095;
	ass <- salario * 0.025;
	
	Si salario > 800 Entonces
		impuesto <- salario * 0.10;
	SiNo
		impuesto <- 0;
	FinSi
	
	salarioNeto <- salario - ccss - ass - impuesto;
	
	//RESUMEN DEL SALARIO
	Escribir "==============================";
	Escribir "         ", nombre, "         ";
	Escribir "Su salario bruto es de: $", salario;
	Escribir "CCSS 9.5%: $", ccss;
	Escribir "ASS 2.5%: $", ass;
	Escribir "RENTA 10% SI SALARIO MAYOR A 800$: $", impuesto;
	Escribir "Salario neto: $", salarioNeto;
	Escribir "==============================";
	
FinProceso
