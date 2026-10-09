Proceso AlquilerDeAutos
	
	Definir nombre Como Caracter;
	Definir dias, km Como Entero;
	Definir subtotal, seguro, desc, precioDias, precioKm, total Como Real;
	
	
	
	Escribir "================================";
    Escribir "       CALCULO A PAGAR";
    Escribir "================================";
	Escribir "";
	Escribir "Ingrese su nombre: ";
	Leer nombre;
	
	
	
	Escribir "Ingrese la cantidad de dias de alquiler por favor";
	Leer dias;
	
	
	
	Mientras dias <= 0 Hacer
		Escribir "Valor invalido ingrese un valor correcto ( MAYOR A CERO)";
		Escribir "Ingrese el valor nuevamente por favor";
		Leer dias;
	FinMientras
	
	
	
	Escribir "Ingrese la cantidad de KM recorridos por favor";
	Leer km;
	
	
	
	Mientras km <= 0 Hacer
		Escribir "Valor invalido ingrese un valor correcto ( MAYOR A CERO)";
		Escribir "Ingrese el valor nuevamente por favor";
		Leer km;
	FinMientras
	
	
	
	precioDias <- dias * 30;
	precioKm <- km * 0.25;
	subtotal <- precioDias + precioKm;
	
	
	
	Si dias > 7 Entonces
		desc <- subtotal * 0.15;
		seguro <- (subtotal - desc)*0.10;
	SiNo
		Escribir "NO SE APLICA DESCUENTO";
		seguro <- subtotal*0.10;
		desc <- 0;
	FinSi
	
	
	
	
	total <- subtotal - desc + seguro;
	
	
	
	
	Escribir "";
	Escribir "El total a pagar para: ", nombre, " es de: ", ;
	Escribir "Subtotal: ", subtotal;
	Escribir "Descuento(-15%): ", desc;
	Escribir "Seguro(+10%): ", seguro;
	Escribir "Total: ", total;
	

	
	
	
FinProceso
