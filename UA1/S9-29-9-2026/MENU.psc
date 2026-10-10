Proceso MENU
	
	Definir ciclo, opcion, adicional, cantidadTotal Como Entero;
	Definir cantidad Como Entero;
	Definir nombre Como Caracter;
	Definir totalArticulos, subtotal, descuento, iva, servicio, total, subtotalDescuento Como Real;
	ciclo <- 1;
	cantidadTotal <- 0;
	subtotal <- 0;
	
	
	Escribir "Pedido a nombre de: ";
	Leer nombre;
	
	
	Mientras ciclo <> 0 Hacer
		Escribir "Qué combo desea?: ";
		Escribir "";
		Escribir "1- CASADO 3500: ";
		Escribir "2- GALLO PINTO 2000: ";
		Escribir "3- REFRESCO 1000: ";
		Escribir "0- TERMINAR";
		Escribir "";
		Leer opcion;
		
		
		Segun opcion Hacer
			0:
				ciclo <- 0;
				
			1:
				Escribir "Ingrese la cantidad del combo: ";
				Leer cantidad;
				
				
				Mientras cantidad < 1 O cantidad > 20 Hacer
					Escribir "Valor no valido: ";
					Escribir "Ingrese nuevamente el valor: ";
					Leer cantidad;
				FinMientras
				
				totalArticulos <- cantidad * 3500;
				Escribir "CASADOS: ", cantidad, " Und";
				Escribir "Precio: 3500 Colones";
				Escribir "Para un total de: ", totalArticulos;
				
				Escribir "Desea agregar algo más?";
				Escribir "1- SI";
				Escribir "2- NO";
				Leer adicional;
				
				Si adicional = 1 Entonces
					ciclo <- 1;
					cantidadTotal <- cantidadTotal + cantidad;
					subtotal <- subtotal + totalArticulos;
				SiNo
					ciclo <- 0;
					cantidadTotal <- cantidadTotal + cantidad;
					subtotal <- subtotal + totalArticulos;
				FinSi
				
				
				
				
				
			2:	
				Escribir "Ingrese la cantidad del combo: ";
				Leer cantidad;
				
				
				Mientras cantidad < 1 O cantidad > 20 Hacer
					Escribir "Valor no valido: ";
					Escribir "Ingrese nuevamente el valor: ";
					Leer cantidad;
				FinMientras
				
				totalArticulos <- cantidad * 2000;
				Escribir "GALLOPINTO: ", cantidad, " Und";
				Escribir "Precio: 2000 Colones";
				Escribir "Para un total de: ", totalArticulos;
				
				Escribir "Desea agregar algo más?";
				Escribir "1- SI";
				Escribir "2- NO";
				Leer adicional;
				
				Si adicional = 1 Entonces
					ciclo <- 1;
					cantidadTotal <- cantidadTotal + cantidad;
					subtotal <- subtotal + totalArticulos;
				SiNo
					ciclo <- 0;
					cantidadTotal <- cantidadTotal + cantidad;
					subtotal <- subtotal + totalArticulos;
				FinSi
				
				
				
			3:
				
				Escribir "Ingrese la cantidad del combo: ";
				Leer cantidad;
				
				
				Mientras cantidad < 1 O cantidad > 20 Hacer
					Escribir "Valor no valido: ";
					Escribir "Ingrese nuevamente el valor: ";
					Leer cantidad;
				FinMientras
				
				totalArticulos <- cantidad * 1000;
				Escribir "REFRESCO: ", cantidad, " Und";
				Escribir "Precio: 1000 Colones";
				Escribir "Para un total de: ", totalArticulos;
				
				Escribir "Desea agregar algo más?";
				Escribir "1- SI";
				Escribir "2- NO";
				Leer adicional;
				
				Si adicional = 1 Entonces
					ciclo <- 1;
					cantidadTotal <- cantidadTotal + cantidad;
					subtotal <- subtotal + totalArticulos;
				SiNo
					ciclo <- 0;
					cantidadTotal <- cantidadTotal + cantidad;
					subtotal <- subtotal + totalArticulos;
				FinSi
				
			De Otro Modo:
				Escribir "===============";
				Escribir "CODIGO INVALIDO";
				Escribir "===============";
				
		FinSegun
		
	FinMientras
	
	Si subtotal >= 10000 Entonces
		descuento <- subtotal * 0.10;
	SiNo
		descuento <- 0;
	FinSi
	
	subtotalDescuento <- subtotal - descuento;
	iva <- subtotalDescuento * 0.13;
	servicio <- subtotalDescuento * 0.10;
	total <- subtotalDescuento + iva + servicio;
	
	
	
	Escribir "";
	Escribir "subtotal de: ", subtotal;
	Escribir "Descuento de: ", descuento;
	Escribir "I.V.A :" , iva;
	Escribir "Servicio: ", servicio;
	Escribir "Total: ", total;
	
	
	
FinProceso
