# Ejercicio 2 · Facturación de datos móviles

**Instituto Nacional de Aprendizaje (INA)**  
**Módulo:** CSTI12010 · Diseño de algoritmos  
**Actividad:** Taller del método · Hoja de trabajo en grupo  
**Archivo del programa:** `datos.c`

## Paso 1 · Entender el problema

Crear un programa en C que permita registrar de 1 a 10 clientes de telefonía, solicitando el número telefónico, el plan contratado y los GB consumidos. El programa debe validar los datos, calcular el cobro de GB adicionales cuando corresponda y limitar cada factura a ₡25 000. Al final, debe mostrar los datos de cada cliente, el total facturado, el cliente que más pagó y cuántos alcanzaron el tope.

## Paso 2 · Identificar los datos

| Categoría | Datos |
|---|---|
| **Entradas** | Cantidad de clientes (1 a 10), número telefónico (una palabra), plan (1, 2 o 3) y GB consumidos (0 a 100, con decimales). |
| **Salidas** | Tabla con número telefónico, GB consumidos y monto; total facturado; cliente con la factura mayor; cantidad de clientes que llegaron al tope. |
| **Constantes** | Máximo 10 clientes; Básico: 5 GB por ₡6 000; Medio: 10 GB por ₡9 000; Plus: 20 GB por ₡14 000; ₡1 200 por GB adicional; tope ₡25 000. |
| **Restricciones** | Los datos fuera de rango deben solicitarse nuevamente; el plan solo puede ser 1, 2 o 3; consumo entre 0 y 100 GB; ninguna factura supera ₡25 000. |

## Paso 3 · Resolver un ejemplo a mano

| Número | Plan | GB usados | Cálculo | Regla especial | Resultado |
|---|---|---:|---|---|---:|
| 88881111 | Básico | 4 | 6 000 + 0 | No tiene GB extra | ₡6 000 |
| 88882222 | Medio | 12.5 | 9 000 + (2.5 × 1 200) | 2.5 GB extra | ₡12 000 |
| 88883333 | Básico | 20 | 6 000 + (15 × 1 200) | 15 GB extra | ₡24 000 |
| 88884444 | Plus | 35 | 14 000 + (15 × 1 200) = 32 000 | Se aplica el tope | ₡25 000 |

**Resultado esperado:**

- **Total facturado:** ₡67 000.
- **Cliente con factura mayor:** 88884444.
- **Factura mayor:** ₡25 000.
- **Clientes que llegaron al tope:** 1.

## Paso 4 · Dividir en tareas

| N.º | Tarea (verbo + qué) | ¿Se repite? |
|---:|---|---|
| 1 | Solicitar y validar la cantidad de clientes. | Si el dato es inválido. |
| 2 | Registrar y validar los datos de cada cliente. | Sí, por cliente. |
| 3 | Obtener el plan y calcular cada factura. | Sí, por cliente. |
| 4 | Sumar facturas, encontrar la mayor y contar los topes. | Sí, por factura. |
| 5 | Mostrar la tabla y el resumen de resultados. | Una vez al finalizar. |

## Paso 5 · Elegir las herramientas

| Necesidad | Qué usar | Por qué / para qué | Cómo (ejemplo) |
|---|---|---|---|
| Definir valores fijos | `#define` | Establecer límites y costos. | `#define TOPE_FACTURA 25000` |
| Leer datos | `printf`, `scanf` | Pedir información al usuario. | `scanf("%d", &plan);` |
| Validar entradas | `do-while` | Repetir una solicitud inválida. | `do { ... } while (plan < 1 || plan > 3);` |
| Registrar varios clientes | `for` | Repetir tareas por cliente. | `for (i = 0; i < cantidad; i++)` |
| Guardar datos | Arreglos y cadenas | Conservar números, consumos y montos. | `float facturas[10];` |
| Elegir el plan | `switch` | Asignar precio y GB incluidos. | `switch (plan)` |
| Aplicar reglas | `if` | Cobrar extras y respetar el tope. | `if (total > TOPE_FACTURA)` |
| Dividir tareas | Funciones | Organizar y reutilizar código. | `calcularFactura(...)` |
| Modificar variables | Punteros | Actualizar valores desde funciones. | `*precio = 6000;` |
| Mostrar resultados | `printf` | Presentar tabla y resumen. | `printf("%.2f", total);` |

## Paso 6 · Comparar formas y elegir

| Forma | Descripción | A favor | En contra |
|---|---|---|---|
| **A** | Programar todo dentro de `main()` con ciclos y condiciones. | Es fácil de comenzar. | El código queda largo y es más difícil de probar por partes. |
| **B** | Separar en funciones, utilizando arreglos y punteros. | Organiza tareas, evita repeticiones y facilita las pruebas. | Requiere comprender parámetros y punteros. |
| **C** | Utilizar estructuras (`struct`) y funciones. | Agrupa los datos de cada cliente. | Es más avanzado para este nivel. |

**Forma elegida: B.** Utilizamos funciones, arreglos y punteros porque el código se entiende mejor, cada regla queda en un lugar, no se repiten instrucciones y se pueden probar las funciones por separado.

## Paso 7 · Algoritmo y prueba de escritorio

### Algoritmo (como una receta)

1. Solicitar la cantidad de clientes (1 a 10).
2. Registrar el número telefónico, plan y GB consumidos de cada cliente.
3. Validar los datos y repetir la solicitud cuando sean incorrectos.
4. Obtener el precio y los GB incluidos según el plan.
5. Calcular el cobro de los GB adicionales, si existen.
6. Aplicar el límite de ₡25 000 por factura.
7. Guardar los datos y el monto de cada factura.
8. Sumar las facturas, buscar la mayor y contar cuántas llegaron al tope.
9. Mostrar la tabla y el resumen.
10. Finalizar el programa.

### Prueba de escritorio

La tabla sigue las variables del ciclo que procesa las facturas. `posicionMayor` comienza en 0 y representa el índice del cliente con la factura más alta.

| Vuelta | `facturas[i]` | `totalFacturado` | `posicionMayor` | `cantidadTope` | `i` |
|---|---:|---:|---:|---:|---:|
| 0 (inicio) | — | 0 | 0 | 0 | — |
| 1 | 6000 | 6000 | 0 | 0 | 0 |
| 2 | 12000 | 18000 | 1 | 0 | 1 |
| 3 | 24000 | 42000 | 2 | 0 | 2 |
| 4 | 25000 | 67000 | 3 | 1 | 3 |

**Comprobación:** El total es ₡67 000; la posición 3 corresponde al cliente 88884444, cuya factura es ₡25 000; un cliente llegó al tope.

## Paso 8 · Programar, probar y documentar

El programa se guarda en `datos.c` y utiliza funciones para solicitar la cantidad, validar el plan y consumo, obtener los datos del plan, registrar clientes, calcular y procesar facturas y mostrar resultados.

### Casos de prueba

| Caso | Datos | Resultado esperado | Resultado obtenido | ¿Correcto? |
|---|---|---|---|---|
| Normal | 1 cliente: 88882222, plan 2, 12.5 GB | Factura de ₡12 000. | Pendiente de ejecutar. | Pendiente. |
| Límite | 1 cliente: 88884444, plan 3, 35 GB | Factura de ₡25 000 por el tope. | Pendiente de ejecutar. | Pendiente. |
| Inválido | 1 cliente: 88883333, plan 1, −2 GB | Mostrar error y volver a solicitar el consumo. | Pendiente de ejecutar. | Pendiente. |

> **Nota:** Los resultados obtenidos y la columna «¿Correcto?» deben completarse después de ejecutar las pruebas; no se presentan como verificadas.

### Compilación y ejecución

En la terminal, dentro de la carpeta que contiene `datos.c`:

```bash
gcc -Wall -Wextra datos.c -o datos
```

En Windows:

```bash
.\datos.exe
```

En Linux o macOS:

```bash
./datos
```

### Entrega

- [ ] Programa `datos.c` comentado y compilado sin advertencias.
- [ ] Pruebas normal, límite e inválida ejecutadas y registradas.
- [ ] Captura de pantalla de la ejecución.
- [ ] `README.md` con los ocho pasos.
- [ ] Archivos guardados en `UA3/Taller_Metodo/` del repositorio y cambios enviados con Git.

---

**Conclusión:** Dividir el programa en funciones permite registrar y validar los clientes, calcular las facturas y obtener el resumen de forma ordenada y fácil de comprender.
