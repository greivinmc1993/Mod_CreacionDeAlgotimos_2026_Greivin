Proceso SODA_ESCOLAR
	
//Registra los pedidos del día: por cada pedido, el tipo de combo (1, 2 o 3, cada uno con su 
//precio) y la cantidad (1 a 10). Si el pedido supera ?10 000, se aplica un 5 % de descuento. 
//Al digitar 0 como combo, se muestra la cantidad de pedidos, cuántos tuvieron descuento y 
//el total vendido. 
	
	Definir combo, cantidad, pedidos, pedidosDescuento, opcion, ciclo, seguir Como Entero;
	Definir precio, subtotal, descuento, totalPedido, totalVendido Como Real;
	
	pedidos <- 0;
	cantidad <- 0;
	pedidosDescuento <- 0;
	
	Repetir
		
		Escribir "||||||||||||||||||||||||||||||||||||||||||";
		Escribir "||              Soda escolar            ||";
		Escribir "||        INGRESE EL COMBO DESEADO      ||";
		Escribir "||                                      ||";
		Escribir "||      1.   COMBO-1 --->  3000 CRC     ||";
		Escribir "||      2.   COMBO-2 --->  4500 CRC     ||";
		Escribir "||      3.   COMBO-2 --->  5500 CRC     ||";
		Escribir "||                                      ||";
		Escribir "||||||||||||||||||||||||||||||||||||||||||";
		Leer opcion;
		
		Segun opcion Hacer
			1:
				Escribir "Ingrese cuantos combos deseas: ";
				Leer cantidad;
				precio <- precio + (cantidad * 3000);
				
				Si precio >= 10000 Entonces
					descuento <- precio *0.05;
					subtotal <- precio - descuento;
				SiNo
					subtotal <- precio;
				FinSi
			2:
				Escribir "Ingrese cuantos combos deseas: ";
				Leer cantidad;
				precio <- precio + (cantidad * 4500);
				
				Si precio >= 10000 Entonces
					descuento <- precio *0.05;
					subtotal <- precio - descuento;
				SiNo
					subtotal <- precio;
					FinSi
			3:
				Escribir "Ingrese cuantos combos deseas: ";
				Leer cantidad;
				precio <- precio + (cantidad * 5500);
				
				Si precio >= 10000 Entonces
					descuento <- precio *0.05;
					subtotal <- precio - descuento;
				SiNo
					subtotal <- precio;
				FinSi
				
			0:
				Escribir "";
				Escribir "El total del día es: ";
				Escribir "";
				Escribir "El total de pedidios es: ", pedidos;

				
				
		FinSegun
		
		
		
		Escribir "";
		Escribir "";
		Escribir "";
		Escribir "";
		Escribir "Desea agregar otro combo?";
		Escribir "1-Si o 2-NO";
		Escribir "";
		Leer ciclo;
		
		Si ciclo >= 1 Entonces
			ciclo <- 1;
			
			Escribir "";
			Escribir "Es parte del mismo combo?";
			Escribir "1-Si o 2-NO";
			Leer seguir;
			
			precio <- 0;
			subtotal <- 0;
			totalPedido <- 0;
			descuento <- 0;
			
			Si seguir = 1 Entonces
				Escribir "";
				Escribir "Muy bien!";
				Escribir "";
			SiNo
				pedidos <- pedidos + 1;
				Si precio >= 10000 Entonces
					descuento <- precio *0.05;
					subtotal <- precio - descuento;
				SiNo
					acciones_por_falso
				FinSi
			FinSi
		SiNo
			ciclo <- 2;
		FinSi
		
	Hasta Que ciclo = 2
	
	
	
	
	
	
FinProceso
