# Ejemplos de introducción a C++
Este repositorio contiene varios ejemplos de C++ que irán introduciendo conceptos útiles para
clases posteriores.

Todos estos ejemplos contienen gran cantidad de comentarios exhaustivos para facilitar la
comprensión de los mismos. También se busca atraer la atención hacia sutilezas que podrían
pasar desapercibidas pero que no por ello son menos importantes.

Como se ha visto en la clase de teoría, hay que *compilar* el código fuente para poder
*ejecutar* los *binarios* generados. Este proceso suele suponer la ejecución de `g++`
junto a una serie de argumentos como el nombre de los archivos fuente. No obstante,
hemos decidido incluir un `Makefile` que automatiza todo este proceso. A continuación
incluimos ejemplos de cómo usar `make` y cómo ejecutar los programas que éste genera.
También comentamos cómo compilarlos a través de invocaciones directas de `g++`.

Cada uno de los ejemplos intenta ahondar en varios aspectos de C++. Es por ello que recomendamos
leerlos todos: ¡cada uno contiene información única! El orden en el que aparecen no es rígido,
pero sí que intenta ir incrementando la complejidad paulatinamente. Además, hemos intentado
agruparlos por «temas» en función del grado de relación entre los contenidos de cada uno.

- `sumatorio.cpp`: Este ejemplo implementa varios sumatorios a través de bucles. Lo más interesante
es que para ello empleamos varios tipos de bucle, mostrando las diferencias y similitudes entre cada
uno de ellos.

- `productorio.cpp`: Este programa implementa un la «operación» productorio a través de bucles. Además,
muestra la inicialización directa de variables.

- `asignaciones.cpp`: Incluye ejemplos de inicializaciones de variables, el uso del operador
coma e información de las secuencias de escape en cadenas.

- `valores.cpp`: Este ejemplo muestra las limitaciones de los tipos de datos así como las precisiones
que pueden llegar a manejar. Esto resulta crucial de cara a poder estimar y suavizar errores que puedan
originarse por estas pequeñas pérdidas de fidelidad.

- `optimiza.cpp`: Este programa incluye un par de bucles computacionalmente costosos que se
repiten muchísimas veces. Al compilarlo con diferentes niveles de optimización se aprecian
diferencias muy notables en cuanto al tiempo de ejecución. Podéis usar el «objetivo» `test-optimization`
del `Makefile` para hacer la prueba y comprobar los resultados. En la siguiente sección hay
más información acerca del `Makefile` y temas relacionados.

- `paridad.cpp`: Este programa hace uso del operador módulo (i.e. `%`) para comprobar si un número
es par o no. Además, pide el número a comprobar de manera interactiva.

- `paridadBucle.cpp`: Este programa extiende el anterior y pide varios números hasta que introducimos
un `0`. Para ello se hace uso de bucles y una inicialización con cautela.

- `creaDatos.cpp`: Muestra cómo abrir archivos para escribir así como el uso de bucles. También
se muestra el uso de inicializaciones por directas por lista.

- `cuentaPalabras.cpp`: Incluye la apertura y lectura de archivos así como el uso de bucles con
contadores. Este programa ofrece funcionalidad incluida en
[`wc(1)`](https://www.man7.org/linux/man-pages/man1/wc.1.html). Podéis comprobar que la salida del
programa es la misma que la de `wc --words libro.txt`.

- `selecciónPalabras.cpp`: Este ejemplo muestra cómo abrir un archivo para luego filtrar y escribir
los resultados a otro distinto. Este ejemplo incluye bucles, manejo de flujos de archivos, el operador
módulo...

- `funcPtrs.cpp`: Este ejemplo versa sobre funciones y punteros a funciones. Por ahora seguro que
resulta bastante críptico, pero en un tiempo seguro que lo encontráis útil o, al menos, interesante.

## ¿Makefile?
[GNU Make](https://www.gnu.org/software/make/) es un programa que facilita la generación de
ejecutables a partir de archivos de código fuente como los `*.cpp` que iréis escribiendo.

Además de eso, `make` se suele usar para otro tipo de proyectos que no son necesariamente
programas «tradicionales» como documentos de [LaTeX](https://www.latex-project.org).

Para emplear el `Makefile` que hemos preparado solamente hay que ejecutar el comando
`make` desde una terminal ubicada en este directorio. Para instalar `make` podemos hacer:

    # En Ubuntu
    sudo apt-install build-essential

    # En macOS
    brew install make

Una vez hecho eso, al ejecutar `make` deberíais ver:

    collado@hoth:0:~/Repos/cpp_samples$ make
    Objetivos disponibles:
        - all: Compila todos los programas y genera el ejecutable *.ex correspondiente.
        - asignaciones: Compila el ejemplo de asignaciones y genera el ejecutable asignaciones.ex.
        - creaDatos: Compila el ejemplo de asignaciones y genera el ejecutable creaDatos.ex
        - cuentaPalabras: Compila el ejemplo de asignaciones y genera el ejecutable cuentaPalabras.ex
        - funcPtrs: Compila el ejemplo de asignaciones y genera el ejecutable funcPtrs.ex
        - paridad: Compila el ejemplo de asignaciones y genera el ejecutable paridad.ex
        - paridadBucle: Compila el ejemplo de asignaciones y genera el ejecutable paridadBucle.ex
        - productorio: Compila el ejemplo de asignaciones y genera el ejecutable productorio.ex
        - seleccionPalabras: Compila el ejemplo de asignaciones y genera el ejecutable seleccionPalabras.ex
        - sumatorio: Compila el ejemplo de asignaciones y genera el ejecutable sumatorio.ex
        - valores: Compila el ejemplo de asignaciones y genera el ejecutable valores.ex
        - optimiza-0: Compila el ejemplo de optimización sin optimización alguna y genera el ejecutable optimiza-0.ex
        - optimiza-2: Compila el ejemplo de optimización con optimización-2 y genera el ejecutable optimiza-2.ex

        - clean: Elimina todos los ejecutables y archivos intermedios.
        - test-optimization: Ejecuta ambos programas de optimización mostrando los tiempos de ejecución.

        - info: Muestra esta información. Este objetivo también se ejecutará si no se explicita uno.

Tal y como se muestra en el mensaje, podemos emplear varios *objetivos* (i.e. *targets*) para compilar
cada uno de los ejemplos por separado o todos a la vez. Asimismo, podemos emplear otros para limpiar todos
los archivos ejecutables o para ejecutar las pruebas de optimización, por ejemplo. Para invocar cada uno
de esos objetivos basta con ejecutar `make <objetivo>`. Por ejemplo:

    collado@hoth:0:~/Repos/cpp_samples$ make all
    g++ -o  asignaciones.ex asignaciones.cpp -Wall -Wextra -std=c++11
    g++ -o  creaDatos.ex creaDatos.cpp -Wall -Wextra -std=c++11
    g++ -o  cuentaPalabras.ex cuentaPalabras.cpp -Wall -Wextra -std=c++11
    g++ -o  funcPtrs.ex funcPtrs.cpp -Wall -Wextra -std=c++11
    g++ -o  paridad.ex paridad.cpp -Wall -Wextra -std=c++11
    g++ -o  paridadBucle.ex paridadBucle.cpp -Wall -Wextra -std=c++11
    g++ -o  productorio.ex productorio.cpp -Wall -Wextra -std=c++11
    g++ -o  seleccionPalabras.ex seleccionPalabras.cpp -Wall -Wextra -std=c++11
    g++ -o  sumatorio.ex sumatorio.cpp -Wall -Wextra -std=c++11
    g++ -o  valores.ex valores.cpp -Wall -Wextra -std=c++11
    valores.cpp:99:15: warning: implicit conversion from 'long' to 'int' changes value from 2147483648 to -2147483648 [-Wconstant-conversion]
        int N3 =  2147483648;
            ~~    ^~~~~~~~~~
    1 warning generated.
    g++ -o optimiza-0.ex -O0 optimiza.cpp -Wall -Wextra -std=c++11
    g++ -o optimiza-2.ex -O2 optimiza.cpp -Wall -Wextra -std=c++11
    Se han compilado todos los ejecutables.

Tal y como se incluye en los comentarios de `valores.cpp` es normal que se genere un *warning*.

## Ejecutando los ejemplos
Una vez compilados los programas, ya sea con `make` o con una invocación directa de `g++` los podemos ejecutar
con `./<nombre-del-programa>`. Por ejemplo:

    collado@hoth:0:~/Repos/cpp_samples$ ./valores.ex 
    N1: 123456789 (4 bytes)
    N2: 1234567890123456789 (8 bytes)
    N3: -2147483648 (4 bytes)
    R1: 0.12345679104328155517578125 (4 bytes)
    R2: 0.1234567890123456773698862321 (8 bytes)
    R3: 0.123456789012345678901321800736 (16 bytes)

## Dudas y preguntas
Para cualquier duda o pregunta acerca de los ejemplos o de los contenidos del repositorio en general
no dudéis en poneros en contacto con @pcolladosoto.
