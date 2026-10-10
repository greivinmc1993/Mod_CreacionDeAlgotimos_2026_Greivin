<div align="center">

<h1>📘 Portafolio de Evidencias</h1>

<h3>Nombre Completo de la Persona Estudiante</h3>

<p><strong>CSTI12010 · Diseño de algoritmos</strong> · Instituto Nacional de Aprendizaje</p>

<p>Facilitador: Giovanni Antonio Coto Calderón · Grupo <em>(número)</em> · 2026</p>

<p>
  <img src="https://img.shields.io/badge/PSeInt-Estricto-2E7D32" alt="PSeInt">
  <img src="https://img.shields.io/badge/C-C11-A8B9CC?logo=c&amp;logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/GCC-MSYS2-A42E2B?logo=gnu&amp;logoColor=white" alt="GCC">
  <img src="https://img.shields.io/badge/Git-F05032?logo=git&amp;logoColor=white" alt="Git">
  <img src="https://img.shields.io/badge/GitHub-181717?logo=github&amp;logoColor=white" alt="GitHub">
</p>

</div>

<hr>

<h2>📖 Sobre este portafolio</h2>

<p>Este repositorio reúne el trabajo que realizo en el módulo <strong>Diseño de algoritmos</strong>: primero los algoritmos en <strong>PSeInt</strong> (UA1) y después su traducción y desarrollo en <strong>lenguaje C</strong> (UA2 y UA3). Cada sesión tiene su carpeta con los archivos de trabajo y un <code>README.md</code> con la prueba de ejecución, lo que aprendí y mi autoevaluación.</p>

<blockquote>
  <p><strong>Recorrido sugerido:</strong> revisar la bitácora para ver el trabajo más reciente, luego el registro de evidencias por unidad y abrir el enlace de las sesiones que interesen.</p>
</blockquote>

<p><strong>Estado de cada sesión:</strong> ⬜ Pendiente · 🟡 En proceso · ✅ Completa</p>

<hr>

<h2>🗓 Bitácora diaria</h2>

<p>Una fila por día de clase, <strong>la más reciente arriba</strong>. Se completa al final de la jornada, antes del último <code>git push</code>.</p>

<table>
  <thead>
    <tr>
      <th align="center">Fecha</th>
      <th align="center">Sesión</th>
      <th>Qué hice hoy</th>
      <th>Pendiente para la próxima</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td align="center">dd/mm</td>
      <td align="center">S18</td>
      <td>_(ej.: traduje Aprobacion y CajeroAutomatico a C)_</td>
      <td>_(ej.: terminar credito.c)_</td>
    </tr>
    <tr>
      <td align="center">dd/mm</td>
      <td align="center">S17</td>
      <td></td>
      <td></td>
    </tr>
  </tbody>
</table>

<details>
  <summary><strong>Rutina de cada día</strong></summary>

  <pre><code>git pull                                   # 1. traer lo más reciente
# 2. trabajar en la carpeta de la sesión (UA2/S18/...) y completar su README.md
git status                                 # 3. revisar qué cambió
git add .                                  # 4. preparar los cambios
git commit -m "S18: agrega credito.c"      # 5. registrar con el formato SXX: verbo + qué
git push                                   # 6. subir a GitHub</code></pre>

  <p>Antes del último <code>push</code> del día: agregar la fila de la bitácora y actualizar el estado de la sesión en el registro de evidencias.</p>
</details>

<hr>

<h2>📁 Estructura del repositorio</h2>

<pre><code>CSTI12010-2026-nombre-apellido/
├── README.md                ← este archivo (presentación, bitácora y registro)
├── UA1/S01 … S12/           ← algoritmos en PSeInt (.psc), una carpeta por sesión
├── UA2/S14 … S22/           ← programas en C (.c), una carpeta por sesión
├── UA3/                     ← estructuras de datos
├── actividades/             ← actividades de comprobación A1, A2 y A3
└── docs/
    ├── CONVENCIONES.md      ← nombres, commits, ramas y entregas
    └── PLANTILLA_SESION.md  ← modelo del README de cada sesión</code></pre>

<p>Las capturas de pantalla van en la subcarpeta <code>capturas/</code> de cada sesión (por ejemplo <code>UA2/S17/capturas/factura.png</code>).</p>

<hr>

<h2>📋 Registro de evidencias</h2>

<details>
  <summary><strong>Unidad 1 · Elaboración de algoritmos en PSeInt</strong> (sesiones 1 a 13)</summary>

  <table>
    <thead>
      <tr>
        <th align="center">Sesión</th>
        <th>Tema</th>
        <th>Qué aprendí</th>
        <th align="center">Evidencia</th>
        <th align="center">Estado</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td align="center">S01</td>
        <td align="center">Lógica computacional, compilador e intérprete</td>
        <td align="center">Comprender la lógica computacional y el funcionamiento de los compiladores e intérpretes en C, aprendiendo a desarrollar algoritmos, organizar instrucciones y reconocer cómo se traduce y ejecuta el código para resolver problemas mediante ejercicios prácticos de programación.</td>
        <td align="center"><a href="UA1/CLASE 1 16-9-2026/S01_Presentacion_Introduccion.pdf">ver</a></td>
        <td align="center">✅</td>
      </tr>
      <tr>
        <td align="center">S02</td>
        <td align="center">Algoritmos y pseudocódigo</td>
        <td align="center">Diseñar algoritmos y representar soluciones mediante pseudocódigo utilizando PSeInt</td>
        <td align="center"><a href="UA1/S3-18-9-2026/3.Algoritmos_Presentacion2026.pdf">ver</a></td>
        <td align="center">✅</td>
      </tr>
      <tr>
        <td align="center">S03</td>
        <td align="center">Lenguajes de alto y bajo nivel</td>
        <td align="center">Identificar las diferencias entre los lenguajes de programación de alto y bajo nivel, comprendiendo sus características, ventajas y usos, así como la forma en que permiten comunicarse con la computadora y desarrollar programas según las necesidades de cada proyecto.</td>
        <td align="center"><a href="UA1/">ver</a></td>
        <td align="center">✅</td>
      </tr>
      <tr>
        <td align="center">S04</td>
        <td align="center">Metodología de solución de problemas</td>
        <td align="center">Aplicar una metodología ordenada para identificar, analizar y resolver problemas, aprendiendo a comprender las necesidades, proponer soluciones, diseñar algoritmos, realizar pruebas y corregir errores para obtener resultados eficientes mediante la lógica y el pensamiento computacional.</td>
        <td align="center"><a href="UA1/S3-18-9-2026/4.Metodologías de solución de problemas.pdf">ver</a></td>
        <td align="center">✅</td>
      </tr>
      <tr>
        <td align="center">S05</td>
        <td align="center">Entrada, proceso, salida y tipos de datos</td>
        <td align="center">Identificar y utilizar las entradas, los procesos y las salidas de un programa, comprendiendo los diferentes tipos de datos en C, como enteros, decimales y caracteres, para desarrollar programas que procesen información correctamente y resuelvan problemas mediante ejercicios prácticos de programación.</td>
        <td align="center"><a href="UA1/S3-18-9-2026/3.Algoritmos_Presentacion2026.pdf">ver</a></td>
        <td align="center">✅</td>
      </tr>
      <tr>
        <td align="center">S06</td>
        <td align="center">Constantes, variables y expresiones</td>
        <td align="center">Las variables actúan como contenedores dinámicos que aportan flexibilidad, mientras que las constantes establecen límites fijos y seguros. Las expresiones son el puente que las combina para generar acciones.</td>
        <td align="center"><a href="UA1/S3-18-9-2026/3.Algoritmos_Presentacion2026.pdf">ver</a></td>
        <td align="center">✅</td>
      </tr>
      <tr>
        <td align="center">S07</td>
        <td align="center">Contadores y acumuladores</td>
        <td align="center">En C, los contadores marcan el paso constante de nuestros bucles, mientras los acumuladores recolectan los resultados del proceso. Ambos nos enseñan una regla de oro insustituible: para sumar grandes cosas, siempre debemos empezar desde cero.</td>
        <td align="center"><a href="UA1/S3-18-9-2026/3.Algoritmos_Presentacion2026.pdf">ver</a></td>
        <td align="center">✅</td>
      </tr>
      <tr>
        <td align="center">S08</td>
        <td align="center">Expresiones aritméticas, relacionales y lógicas</td>
        <td align="center">Las expresiones son la mente de tu programa: las aritméticas calculan, las relacionales comparan y las lógicas deciden.</td>
        <td align="center"><a href="UA1/S3-18-9-2026/3.Algoritmos_Presentacion2026.pdf">ver</a></td>
        <td align="center">✅</td>
      </tr>
      <tr>
        <td align="center">S09</td>
        <td align="center">Operadores aritméticos y prioridad</td>
        <td align="center">Usar correctamente los operadores aritméticos en programación, comprendiendo las operaciones de suma, resta, multiplicación, división y módulo, así como la prioridad de los operadores para desarrollar expresiones matemáticas y resolver problemas de manera precisa en C.</td>
        <td align="center"><a href="UA1/S3-18-9-2026/3.Algoritmos_Presentacion2026.pdf">ver</a></td>
        <td align="center">✅</td>
      </tr>
      <tr>
        <td align="center">S10</td>
        <td align="center">Decisión simple y doble</td>
        <td align="center">Usar estructuras de decisión simple y doble en programación, aprendiendo a evaluar condiciones y ejecutar diferentes instrucciones según los resultados para resolver problemas de manera lógica y eficiente mediante ejercicios prácticos en C y PSeInt</td>
        <td align="center"><a href="UA1/S3-18-9-2026/S03_Presentacion_Decisiones.pdf">ver</a></td>
        <td align="center">✅</td>
      </tr>
      <tr>
        <td align="center">S11</td>
        <td align="center">Operadores lógicos, decisiones compuestas y Según</td>
        <td align="center">Usar operadores lógicos y estructuras de decisión compuestas y la instrucción Según en programación, aprendiendo a evaluar condiciones, tomar decisiones y crear soluciones más organizadas y eficientes mediante ejercicios prácticos en C.</td>
        <td align="center"><a href="UA1/S3-18-9-2026/S03_Presentacion_Decisiones.pdf">ver</a></td>
        <td align="center">✅</td>
      </tr>
      <tr>
        <td align="center">S12</td>
        <td align="center">Ciclos, validación de datos e informe</td>
        <td align="center">A utilizar ciclos y validaciones de datos en programación para controlar la repetición de instrucciones, verificar que la información ingresada sea correcta y generar informes organizados, aplicando la lógica computacional para desarrollar programas más confiables y eficientes.</td>
        <td align="center"><a href="UA1/S4-21-9-2026/Conceptos_S04_Repeticion_Estudiantes.pdf">ver</a>---<a href="UA1/S5-22-9-2026/Conceptos_S05_Para_Estudiantes.pdf">ver</a></td>
        <td align="center">✅</td>
      </tr>
      <tr>
        <td align="center">S13</td>
        <td align="center"><strong>Actividad de comprobación 1</strong></td>
        <td align="center"></td>
        <td align="center"><a href="UA1/COMPROBACION/AC1_Instrucciones_Greivin_Montero_Contreras_01-10-2026.pdf">ver</a></td>
        <td align="center">✅</td>
        </tr>
    </tbody>
  </table>
</details>

<details open>
  <summary><strong>Unidad 2 · Programación estructurada en C</strong> (sesiones 14 a 24)</summary>

  <table>
    <thead>
      <tr>
        <th align="center">Sesión</th>
        <th>Tema</th>
        <th>Qué aprendí</th>
        <th align="center">Evidencia</th>
        <th align="center">Estado</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td align="center">S14</td>
        <td align="center">Sistemas numéricos</td>
        <td align="center">A comprender y utilizar los sistemas numéricos en C, aprendiendo a representar y convertir valores entre sistemas decimal, binario, octal y hexadecimal mediante ejercicios prácticos de programación.</td>
        <td align="center"><a href="UA2/S14-5-10-2026/Sistemas-numéricosEstd.pdf">ver</a></td>
        <td align="center">✅</td></tr>
      <tr>
        <td align="center">S15</td>
        <td align="center">Control de versiones con git y GitHub</td>
        <td align="center">Utilizar Git y GitHub para gestionar el control de versiones de proyectos, aprendiendo a crear repositorios, registrar cambios, crear y cambiar entre ramas, realizar commits y compartir código, lo que me permitió mantener mis trabajos organizados y facilitar la colaboración en el desarrollo de software.</td>
        <td align="center"><a href="UA2/S15-5-10-2026/S15_Conceptos_del_dia_EstudiantesGit-G.pdf">ver</a></td>
        <td align="center">✅</td>
      </tr>
      <tr>
        <td align="center">S16</td>
        <td align="center">Formato de un programa en C y compilación</td>
        <td align="center">A estructurar programas en C y comprender el proceso de compilación, aprendiendo a utilizar bibliotecas, declarar la función principal main(), escribir instrucciones correctamente y detectar errores para convertir el código fuente en un programa ejecutable.</td>
        <td align="center"><a href="UA2/S15-5-10-2026/UA2_Guia_instalacion_entorno_C.pdf">ver</a></td>
        <td align="center">✅</td>
      </tr>
      <tr>
        <td align="center">S17</td>
          <td align="center">Variables, constantes y entrada/salida</td>
          <td align="center">A utilizar variables, constantes y operaciones de entrada y salida en programación en C, aprendiendo a almacenar datos, manejar valores que no cambian y permitir la interacción entre el usuario y el programa mediante instrucciones como printf() y scanf().</td>
          <td align="center"><a href="UA2/S17-8-10-2026/S17_Presentacion_Variables_tipos_ES.pdf">ver</a></td>
          <td align="center">✅</td>
        </tr>
      <tr>
        <td align="center">S18</td>
        <td align="center">Operadores, casting e if … else</td>
        <td align="center">A utilizar operadores, conversiones de tipos de datos (casting) y estructuras condicionales if...else en C, aprendiendo a realizar operaciones, convertir valores y tomar decisiones dentro de un programa para resolver problemas de manera lógica y eficiente.</td>
        <td align="center"><a href="UA2/S18-9-10-2026/S18_Presentacion_Operadores_if_else.pdf">ver</a></td>
        <td align="center">✅</td>
      </tr>
      <tr>
        <td align="center">S19</td>
        <td align="center">Ciclos y switch</td>
        <td align="center"></td>
        <td align="center"><a href="UA2/S19/">ver</a></td>
        <td align="center">✅</td>
      </tr>
      <tr>
        <td align="center">S20</td>
        <td align="center">Arreglos, matrices y cadenas</td>
        <td align="center"></td>
        <td align="center"><a href="UA2/S20/">ver</a></td>
        <td align="center">⬜</td>
      </tr>
      <tr>
        <td align="center">S21</td>
        <td align="center">Funciones</td>
        <td align="center"></td>
        <td align="center"><a href="UA2/S21/">ver</a></td>
        <td align="center">⬜</td>
      </tr>
      <tr>
        <td align="center">S22</td>
        <td align="center">Paso de parámetros por valor y por dirección</td>
        <td align="center"></td>
        <td align="center"><a href="UA2/S22/">ver</a></td>
        <td align="center">⬜</td>
      </tr>
      <tr>
        <td align="center">S23–S24</td>
        <td align="center"><strong>Actividad de comprobación 2</strong></td>
        <td align="center"></td>
        <td align="center"><a href="actividades/A2_Mi_primera_aplicacion/">ver</a></td>
        <td align="center">⬜</td>
      </tr>
    </tbody>
  </table>
</details>

<details>
  <summary><strong>Unidad 3 · Estructuras de datos</strong></summary>

  <table>
    <thead>
      <tr>
        <th align="center">Sesión</th>
        <th>Tema</th>
        <th>Qué aprendí</th>
        <th align="center">Evidencia</th>
        <th align="center">Estado</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td></td>
        <td>_(las filas se agregan al iniciar la UA3)_</td>
        <td></td>
        <td></td>
        <td></td>
      </tr>
    </tbody>
  </table>
</details>

<hr>

<h2>🏁 Actividades de comprobación</h2>

<table>
  <thead>
    <tr>
      <th>Actividad</th>
      <th>Carpeta</th>
      <th align="center">Versión evaluada (etiqueta)</th>
      <th align="center">Resultado</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td align="center">A1 · Análisis y solución de un problema específico</td>
      <td align="center"><a href="UA1/COMPROBACION/AC1_Instrucciones_Greivin_Montero_Contreras_01-10-2026.pdf">ver</a></td>
      <td align="center">A1-oportunidad-1</td>
      <td align="center">✅</td>
    </tr>
    <tr>
      <td align="center">A2 · Mi primera aplicación</td>
      <td align="center"><a href="actividades/A2_Mi_primera_aplicacion/">ver</a></td>
      <td align="center"><code>A2-oportunidad-1</code></td>
      <td align="center">✅</td>
    </tr>
    <tr>
      <td align="center">A3 · Sistema con almacenamiento de datos</td>
      <td align="center"><a href="actividades/A3_Sistema_almacenamiento/">ver</a></td>
      <td align="center"><code>A3-oportunidad-1</code></td>
      <td align="center">✅</td>
    </tr>
  </tbody>
</table>

<p>La persona facilitadora crea la etiqueta al cierre de cada actividad; el resultado se anota cuando se comunica.</p>

<hr>

<h2>🖼 Galería de ejecuciones</h2>

<p><em>(Sustituir por capturas propias. Se recomienda incluir de tres a seis imágenes representativas: un algoritmo en PSeInt y varios programas en
