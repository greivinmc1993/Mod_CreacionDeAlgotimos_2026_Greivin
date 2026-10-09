Algoritmo InventarioBodega
	
    Definir nombre Como Caracter;
    Definir cantidad, i Como Entero;
	
    Para i <- 1 Hasta 8 Hacer
		
        Escribir "Producto ", i;
        Escribir "Ingrese el nombre del producto:";
        Leer nombre;
		
        Escribir "Ingrese la cantidad actual en stock:";
        Leer cantidad;
		
        Si cantidad < 5 Entonces
            Escribir "ALERTA: El producto ", nombre, " requiere reposición urgente.";
        FinSi
		
    FinPara
	
FinAlgoritmo