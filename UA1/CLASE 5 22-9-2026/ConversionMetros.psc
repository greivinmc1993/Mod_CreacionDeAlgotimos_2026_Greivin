proceso ConversionMetros
	
    Definir metros, resultado Como Real;
    Definir opcion Como Entero;
	
    Escribir "Ingrese la cantidad en metros:";
    Leer metros;
	
    Escribir "-----------------------------";
    Escribir "MENU DE CONVERSION";
    Escribir "1. Convertir a centimetros";
    Escribir "2. Convertir a kilometros";
    Escribir "3. Convertir a pulgadas";
    Escribir "-----------------------------";
    Escribir "Seleccione una opcion (1, 2 o 3):";
    Leer opcion;
	
    Segun opcion Hacer
		
        1:
            resultado <- metros * 100;
            Escribir "El resultado es: ", resultado, " centimetros";
			
        2:
            resultado <- metros / 1000;
            Escribir "El resultado es: ", resultado, " kilometros";
			
        3:
            resultado <- metros * 39.37;
            Escribir "El resultado es: ", resultado, " pulgadas";
			
        De Otro Modo:
            Escribir "Opcion no valida. Debe elegir 1, 2 o 3.";
			
    FinSegun
	
Finproceso