/*
 * Define `std::cout` para escribir a pantalla (i.e. `stdout`) y
 * `std::cin` para leer datos desde el teclado (i.e. `stdin`).
 * Más información -> https://en.cppreference.com/w/cpp/header/iostream
 */
#include <iostream>

/*
 * Esta directiva nos permite «inyectar» todos los nombres definidos
 * en el espacio de nombres que incluyamos en el espacio de nombres
 * global. Esto nos permite no tener que añadir `std::` al principio
 * de cada nombre definido en `std`, cosa que hace el código más legible.
 * No obstante, abusar de esta directiva puede llevar ambigüedades en
 * cuanto a qué es lo que queremos hacer realmente...
 * En https://en.cppreference.com/w/cpp/language/namespace podéis encontrar
 * más información al respecto.
 */
using namespace std;

int main() {
    /*
     * Definimos un entero que luego inicializaremos con un
     * número introducido desde el teclado.
     */
    int num;

    /*
     * En C++ las variables no inicializadas explícitamente contienen
     * lo que solemos llamar un valor «basura». Este valor **no** es
     * predecible, con lo que de no inicializarlo existe la posibilidad
     * (aunque remota) de que el bucle no llegue a ejecutar ni una
     * sola iteración. Dado que empleamos el valor de `num` en la
     * condición del bucle antes de inicializarlo con una extracción
     * de `cin` debemos inicializarlo explícitamente con un valor que
     * no interfiera con el funcionamiento que buscamos. Ya que solo
     * necesitamos que `num != 0` para que «entremos» en el bucle, basta
     * con emplear cualquier otro valor.
     */
    num = 1;

    /*
     * Este bucle `while` se ejecutará mientras la condición especificada
     * entre paréntesis se cumpla. La condición `num != 0` implica que
     * para detener la información de manera grácil debemos introducir
     * `0` cuando se nos presente el inductor `Escribe numero entero > `.
     * Nótese que dado el comportamiento de la extracción de `cin` (i.e.
     * `cin >>`) cualquier valor no válido para inicializar un entero
     * (como `p`) provocará el mismo efecto: en la presencia de errores
     * `num` pasará a valer `0`.
     * Es importante tener en cuenta que en C++ los números tienen un
     * valor implícito de «verdad», esto es, se pueden tratar como
     * booleanos. Para ello, se asume que `0 === false` y `!0 === true`,
     * donde `===` denota equivalencia. Esto implica que el bucle podría
     * ser sustituido por `while (num) {}` y el comportamiento sería
     * idéntico.
     */
    while (num != 0) {
        // Imprimimos un mensaje por pantalla pidiendo un entro
        cout << "Escribe numero entero > ";

        /*
         * Ahora leemos el contenido que introduzcamos por teclado para
         * inicializar `num` con él. El hecho de aplicar el operador de
         * extracción (i.e. `>>`) al flujo `cin`, que está conectado al
         * teclado, supone que la ejecución del programa se detiene hasta
         * que introduzcamos un dato y pulsemos ENTER. También debemos
         * ser conscientes de que el hecho de que estemos inicializando
         * un entero **tiene implicaciones en cuanto al valor real** con
         * el que inicialicemos la variable. La principal consecuencia es
         * la del «truncado» del valor: si introducimos `5.5` por teclado,
         * `num` se inicializará con `5` y si introducimos `4.9` con `4`.
         * Si introducimos un carácter, el valor que se almacenará en `num`
         * será `0`. Tal y como se recoge en el paso 3 de
         * https://en.cppreference.com/w/cpp/locale/num_get/get, en caso de
         * no poder convertir el valor que se extrae del flujo al tipo de
         * la variable a asignar simplemente se devuelve `0`. Para comprobarlo
         * se puede imprimir el valor directamente con `cout << num;`. Es crucial
         * saber que ante errores el flujo se «bloquea» y debemos desbloquearlo
         * manualmente a través de `cin.clear()`. Podéis encontrar más información
         * en https://en.cppreference.com/w/cpp/io/basic_ios/clear. También es
         * interesante comentar que la llamada `cin.fail()` nos permite saber
         * si la lectura a fallado (con lo que `num` será `0`) o si, de lo
         * contrario, `num` es `0` tras una lectura correcta. La condición del
         * bucle está pensada justamente para evitar que el programa «se la pegue»
         * ante un error en la extracción de datos: simplemente termina.
         */
        cin >> num;

        /*
         * Esta comprobación hace uso del operador módulo (i.e. `%`). El
         * módulo de dos números devuelve el resto de la división de uno
         * por el otro. Asumiendo que `a`, `b`, `c` y `r` son enteros:
         *  a / b = c + r -> a % b = r
         * Por tanto, la operación `a % 2` nos permite saber si `a` es par
         * o impar:
         *  a % 2 = 0 -> a es par; a % 2 = 1 -> a es impar
         * También queremos llamar la atención sobre la diferencia entre el
         * operador de asignación (i.e. `=`) y el de comparación (i.e. `==`).
         * Finalmente, nos gustaría comentar que en C++ se asume que un valor
         * de `0` es falso y todo aquello que no sea `0` es verdadero. Esto
         * implica que la comprobación `num % 2 == 0` es redundante y podría
         * ser sustituida por  `!(num % 2)`.
         */
        if(num % 2 == 0) {
            cout << "\nEl numero es par\n";
        } else {
            cout << "\nEl numero es impar\n";
        }
    }

    /*
     * A pesar de que no es «estrictamente» necesario, es una buena
     * costumbre devolver `0` para indicar a quien ha ejecutado el
     * programa que todo ha ido correctamente. Además, el prototipo
     * de `main()` (i.e. `int main()`) indica que devolveremos un
     * entero pase lo que pase...
     */
    return 0;
}
