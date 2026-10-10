Algoritmo PromedioNotas
		
		Definir cantidad Como Entero
		Definir nota Como Real
		Definir sumaAprobadas, sumaReprobadas Como Real
		Definir cantidadAprobadas, cantidadReprobadas Como Entero
		Definir promedioAprobadas, promedioReprobadas Como Real
		
		sumaAprobadas <- 0
		sumaReprobadas <- 0
		cantidadAprobadas <- 0
		cantidadReprobadas <- 0
		
		Escribir "Ingrese la cantidad de alumnos:"
		Leer cantidad
		
		Para i <- 1 Hasta cantidad Hacer
			
			Escribir "Ingrese la nota del alumno ", i, " (0 a 100):"
			Leer nota
			
			Si nota >= 70 Entonces
				Escribir "Alumno aprobado"
				sumaAprobadas <- sumaAprobadas + nota
				cantidadAprobadas <- cantidadAprobadas + 1
			SiNo
				Escribir "Alumno reprobado"
				sumaReprobadas <- sumaReprobadas + nota
				cantidadReprobadas <- cantidadReprobadas + 1
			FinSi
			
		FinPara
		
		Si cantidadAprobadas > 0 Entonces
			promedioAprobadas <- sumaAprobadas / cantidadAprobadas
			Escribir "Promedio de notas aprobadas: ", promedioAprobadas
		SiNo
			Escribir "No hubo alumnos aprobados."
		FinSi
		
		Si cantidadReprobadas > 0 Entonces
			promedioReprobadas <- sumaReprobadas / cantidadReprobadas
			Escribir "Promedio de notas reprobadas: ", promedioReprobadas
		SiNo
			Escribir "No hubo alumnos reprobados."
		FinSi
		
FinAlgoritmo