Algoritmo EvaluacionColaborador
	
    Definir nombre Como Caracter;
    Definir puntualidad, calidad, equipo, promedio Como Real;
    Definir nivel Como Caracter;
	
    Escribir "Ingrese el nombre del colaborador:";
    Leer nombre;
	
    // Validar puntualidad
    Escribir "Ingrese el puntaje de puntualidad (0 a 10):";
    Leer puntualidad;
	
    Mientras puntualidad < 0 O puntualidad > 10 Hacer
        Escribir "Puntaje no valido. Debe estar entre 0 y 10.";
        Escribir "Ingrese nuevamente el puntaje de puntualidad:";
        Leer puntualidad;
    FinMientras
	
    // Validar calidad
    Escribir "Ingrese el puntaje de calidad (0 a 10):";
    Leer calidad;
	
    Mientras calidad < 0 O calidad > 10 Hacer
        Escribir "Puntaje no valido. Debe estar entre 0 y 10.";
        Escribir "Ingrese nuevamente el puntaje de calidad:";
        Leer calidad;
    FinMientras
	
    // Validar trabajo en equipo
    Escribir "Ingrese el puntaje de trabajo en equipo (0 a 10):";
    Leer equipo;
	
    Mientras equipo < 0 O equipo > 10 Hacer
        Escribir "Puntaje no valido. Debe estar entre 0 y 10.";
        Escribir "Ingrese nuevamente el puntaje de trabajo en equipo:";
        Leer equipo;
    FinMientras
	
    // Calcular promedio
    promedio <- (puntualidad + calidad + equipo) / 3;
	
    // Determinar nivel
    Si promedio >= 9 Entonces
        nivel <- "EXCELENTE";
    Sino
        Si promedio >= 7 Entonces
            nivel <- "BUENO";
        Sino
            nivel <- "NECESITA MEJORAR";
        FinSi
    FinSi
	
    // Mostrar resultados
    Escribir "==============================";
    Escribir "EVALUACION DEL COLABORADOR";
    Escribir "Nombre: ", nombre;
    Escribir "Promedio: ", promedio;
    Escribir "Nivel: ", nivel;
    Escribir "==============================";
	
FinAlgoritmo

