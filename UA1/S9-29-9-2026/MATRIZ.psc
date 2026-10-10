Proceso matrices
	
	Definir notas Como Real;
	Definir fila, columna, i , x Como Entero;
	i <- 0;
	x <- 0;
	
	Dimensionar notas[2,3];
	
	notas[0, 0] <- 60;
	notas[0, 1] <- 70;
	notas[0, 2] <- 80;

	notas[1, 0] <- 90;
	notas[1, 1] <- 100;
	notas[1, 2] <- 50;
	
	Mientras i < 2 Hacer
		Mientras x < 3 Hacer
			Escribir "la posicion de la matriz: ", notas[i,x];
			x <- x + 1;
		FinMientras
		i <- i + 1;
		x <- 0;
	FinMientras
 	
FinProceso
