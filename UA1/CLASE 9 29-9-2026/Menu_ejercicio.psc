Proceso Menu_ejercicio
	Definir ciclo, opcion, casados, cantidadCasados, cantidadGallo, cantidadRefrescos, cantidad, totalcantidad Como Entero;
	Definir totalCasados, totalGallos, totalRefrescos, subTotal, descuento, iva, servicio, total, subTotalDesc Como Real;
	Definir nombre Como Caracter;
	ciclo <- 100;
	cantidadCasados <- 0;
	cantidadGallo <- 0;
	cantidadRefrescos <- 0;
	
	Escribir "PEDIDO A NOMBRE DE: ";
	Leer nombre;
	
	Mientras ciclo <> 0 Hacer
		Escribir "Qué combo desea?: ";
		Escribir "";
		Escribir "1- CASADO 3500¢: ";
		Escribir "2- GALLO PINTO 2000¢: ";
		Escribir "3- REFRESCO 1000¢: ";
		Escribir "0- TERMINAR";
		Escribir "";
		Leer opcion;
		
		Segun opcion Hacer
			0:
				ciclo <- 0;
			1:
				Escribir "Ingrese cuantos CASADOS quieres: ";
				Leer cantidad;
				
				Mientras cantidad <= 0 O cantidad > 20 Hacer
					Escribir "Valor invalido";
					Escribir "Ingrese nuevamente el valor (1 al 20)";
					Leer cantidad;
				FinMientras
				
				cantidadCasados <- cantidadCasados + cantidad;
			2:
				Escribir "Ingrese cuantos GALLO PINTOS quieres: ";
				Leer cantidad;
				
				Mientras cantidad <= 0 O cantidad > 20 Hacer
					Escribir "Valor invalido";
					Escribir "Ingrese nuevamente el valor (1 al 20)";
					Leer cantidad;
				FinMientras
				
				cantidadGallo <- cantidadGallo + cantidad;
			3:
				Escribir "Ingrese cuantos REFRESCOS quieres: ";
				Leer cantidad;
				
				Mientras cantidad <= 0 O cantidad > 20 Hacer
					Escribir "Valor invalido";
					Escribir "Ingrese nuevamente el valor (1 al 20)";
					Leer cantidad;
				FinMientras
				
				cantidadRefrescos <- cantidadRefrescos + cantidad;
				
			De Otro Modo:
				Escribir "Opcion invalida";
		FinSegun
		
	FinMientras
	
	totalCasados <- cantidadCasados * 3500;
	totalGallos <- cantidadGallo * 2000;
	totalRefrescos <- cantidadRefrescos * 1000;
	
	subTotal <- totalCasados + totalGallos + totalRefrescos;
	
	totalcantidad <- cantidadCasados + cantidadGallo + cantidadRefrescos;
	
	Si subTotal >= 10000 Entonces
		descuento <- subTotal * 0.10;
	SiNo
		descuento <- 0;
	FinSi
	
	subTotalDesc <- subTotal - descuento;
	
	iva <- subTotalDesc * 0.13;
	
	servicio <- subTotalDesc * 0.10;
	
	total <- subTotal + iva + servicio - descuento;
	
	Escribir "";
	Escribir "==================";
	Escribir "Resumen del pedido";
	Escribir "     ",nombre,"     ";
	Escribir "==================";
	Escribir "Cantidad de articulos: ", totalcantidad;
	Escribir "Subtotal de: ¢", subTotal;
	Escribir "Descuento de: ¢", descuento;
	Escribir "13% I.V.A: ", iva;
	Escribir "10% SERVICIO: ", servicio;
	Escribir "Total de: ", total;	
	
FinProceso