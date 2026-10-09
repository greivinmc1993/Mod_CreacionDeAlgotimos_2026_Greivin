Algoritmo ClasificarEdades
	
    Definir cantidad, edad, i Como Entero;
    Definir menores, adultos, adultosMayores Como Entero;
	
    menores <- 0;
    adultos <- 0;
    adultosMayores <- 0;
	
    Escribir "¿Cuántas personas se van a registrar?";
    Leer cantidad;
	
    Para i <- 1 Hasta cantidad Hacer;
		
        Escribir "Ingrese la edad de la persona ", i, ":";
        Leer edad;
		
        Si edad < 18 Entonces
            menores <- menores + 1;
        SiNo
            Si edad < 60 Entonces
                adultos <- adultos + 1;
            SiNo
                adultosMayores <- adultosMayores + 1;
            FinSi
        FinSi
		
    FinPara
	
    Escribir "Menores de edad: ", menores;
    Escribir "Adultos: ", adultos;
    Escribir "Adultos mayores: ", adultosMayores;
	
FinAlgoritmo
