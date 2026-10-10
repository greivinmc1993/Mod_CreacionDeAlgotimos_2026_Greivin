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
		//NOMBRE, PRODUCTO, PRECIO, CANTIDAD
     
     
		
        //LIMITANTES
        //NUMEROS, NUMERO EN VEZ DE LETRAS, LETRAS EN VEZ DE NUMEROS
     
     
     
		
		//PROCESO
		//RECIBIR DATOS DE PRDUCTOS ACUMULAR PRECIOS DE PRDUCTOS CONSULTAR SI DESEA AGREGAR MAS PRODCUTOS LUEGO VALIDAR DESCUENTOS SEGUN SUBTOTAL, CALCULAR IVA Y LUEGO MOSTRAR TOTAL
		
		
		
		//SALIDA
        //NOMBRE, PRODUCTOS PRECIOS, SUBTOTAL, DESCUENTOS, IVA, TOTAL



Proceso GestionComprasTienda
	
	Definir nombre, producto Como Caracter;
	Definir cantidad,cantidadTotal, ciclo, contador Como Entero;
	Definir precio, precioTotal, descuento, iva, subTotalProducto, subTotal Como Real;
	
	ciclo <- 1;
	cantidadTotal <- 0;
	subTotal <- 0;
	contador <- 0;
	
	Escribir "==============================";
	Escribir "Por favor ingrese su nombre: ";
	Escribir "==============================";
	Leer nombre;
	
	Mientras ciclo = 1 Hacer
		//validacion de productos y consulta para agregar más de un producto
		Escribir "==============================";
		Escribir "Desea ingresar un producto? ";
		Escribir "        1-SI o 2-NO          ";
		Escribir "==============================";
		Leer ciclo;
		
		//bloque para agregar la info de los artiulos
		Si ciclo = 1 Entonces
			Escribir "==============================";
			Escribir "Por favor ingrese el producto: ";
			Escribir "==============================";
			Leer producto;
			
			Escribir "";
			Escribir "==============================";
			Escribir "Por favor ingrese el precio: ";
			Escribir "==============================";
			Leer precio;
			Escribir "";
			
			Mientras precio< 0 Hacer
				Escribir "==============================";
				Escribir "VALOR INVALIDO DEBE SER MAYOR A CERO: ";
				Escribir "INGRESE DE NUEVO EL VALOR";
				Escribir "==============================";
				Leer precio;
			FinMientras
			
			Escribir "==============================";
			Escribir "Por favor ingrese la cantidad: ";
			Escribir "==============================";
			Leer cantidad;
			
			Mientras cantidad < 0 Hacer
				Escribir "==============================";
				Escribir "VALOR INVALIDO DEBE SER MAYOR A CERO: ";
				Escribir "INGRESE DE NUEVO EL VALOR";
				Escribir "==============================";
				Leer cantidad;
			FinMientras
			
			subTotalProducto <- precio * cantidad;
			
			Escribir "==============================";
			Escribir "NOMBRE DEL PRODUCTO: ",producto ;
			Escribir "PRECIO DEL PRODUCTO: ",precio;
			Escribir "CANTIDAD DEL PRODUCTO: ",cantidad;
			Escribir "TOTAL DE LOS PRODUCTOS: ",subTotalProducto;
			Escribir "==============================";
			//calculo de subtotles de los productos ingresados
			cantidadTotal <- cantidadTotal + cantidad;
			subTotal <- subTotal + subTotalProducto;
			contador <- contador + 1;
		SiNo
			ciclo <- 0;
		FinSi
	FinMientras
	
	
	//CALCIULO DEL DESCUENTO EN TODAS SUS CATEGORIAS
	Si subTotal > 1000 Entonces
		descuento <- subTotal * 0.15;
	SiNo
		Si subTotal <= 1000 Y subTotal >= 500 Entonces
			descuento <- subTotal * 0.10;
		SiNo
			Si subTotal <= 500 Y subTotal >= 100 Entonces
				descuento <- subTotal * 0.05;
			SiNo
				descuento <- 0;
			FinSi
		FinSi
	FinSi
	
	//ALCULO DEL IVA
	iva <- (subTotal - descuento) * 0.13;
	
	
	//RESUMEN
	
	Escribir "==============================";
	Escribir "NOMBRE DEL CLIENTE: $",nombre ;
	Escribir "PRODUCTOS REGISTRADOS: $",cantidadTotal;
	Escribir "PRODUCTOS DIFERENTES REGISTRADOS: $",contador;
	Escribir "SUBTOTAL: $",subTotal;
	Escribir "DESCUENTOS: -$",descuento;
	Escribir "TOTAL CON DESCUENTO: $", subTotal - descuento;
	Escribir "I.V.A: $",iva;
	Escribir "TOTAL: $",subTotal-descuento+iva;
	Escribir "==============================";
	
	
	
	
FinProceso
