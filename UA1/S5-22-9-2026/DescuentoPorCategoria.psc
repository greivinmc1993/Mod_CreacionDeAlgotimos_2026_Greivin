PROCESO DescuentoPorCategoria
	
    Definir precio, descuento, precioFinal Como Real;
    Definir categoria Como Entero;;
	
    Escribir "Ingrese el precio original del producto:";
    Leer precio;
	
    Escribir "Ingrese la categoria del cliente (1 = A, 2 = B o 3 = C):";
    Leer categoria;
	
    descuento <- 0;
    precioFinal <- precio;
	
    Segun categoria Hacer
		
        1:
            descuento <- precio * 0.30;
            precioFinal <- precio - descuento;
            Escribir "Categoria A: 30% de descuento";
			
        2:
            descuento <- precio * 0.20;
            precioFinal <- precio - descuento;
            Escribir "Categoria B: 20% de descuento";
			
        3:
            descuento <- precio * 0.10;
            precioFinal <- precio - descuento;
            Escribir "Categoria C: 10% de descuento";
			
        De Otro Modo:
            Escribir "Advertencia: la categoria ingresada no existe.";
			
    FinSegun
	
    Si categoria = 1 O categoria = 2 O categoria = 3 Entonces
        Escribir "Monto del descuento: ", descuento;
        Escribir "Precio final a pagar: ", precioFinal;
    FinSi
	
FinProceso
