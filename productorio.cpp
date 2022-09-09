/*
 * Define `std::cout` para escribir a pantalla (i.e. `stdout`).
 * Más información -> https://en.cppreference.com/w/cpp/header/iostream
 */
#include <iostream>

/*
 * Define, entre otras, la función `double sin(double)`. En ella también
 * podemos encontrar otras funciones y utilidades relacionadas con el
 * cálculo numérico. Esta librería pertenecía originalmente a C y se
 * importaba con `#include <math.h>.
 * Más información -> https://en.cppreference.com/w/cpp/header/cmath
 */
#include <cmath>

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
     * Declaramos e inicializamos un par de variables que emplearemos
     * en el productorio. En el primer caso, inicializamos `x` con
     * «inicialización directa». Este método de inicialización resulta más
     * permisivo que la «inicialización por copia» (la siguiente), pero
     * su importancia empieza a ser más notable cuando trabajemos con constructores
     * de instancias de clases en el ámbito de la programación orientada a objetos.
     * En el segundo caso usamos la «inicialización por copia», que es la más frecuente
     * y la que hemos venido usando en todos los demás ejemplos. Lo importante es
     * tener claro que tras ejecutar esta sentencia veremos cómo `x` valdrá `6.2` y
     * `prod` valdrá `1` (el elemento neutro del producto). Es importante señalar que
     * en este caso el compilador **no** interpreta la coma (i.e. `,`) como el operador coma
     * (i.e. https://en.cppreference.com/w/cpp/language/operator_other), sino como
     * varias «sentencias declaratorias». Este tema resulta tremendamente abstracto y
     * casi innecesario: no hace falta conocerlo para poder declarar e inicializar
     * variables con total confianza, pero creemos que resulta curioso... Podéis encontrar
     * más información en https://en.cppreference.com/w/cpp/language/declarations.
     */
    double x(6.2), prod = 1;

    /*
     * En este caso aplicamos una «inicialización directa por lista». La ventaja de este
     * método es que provocará fallos de compilación si el dato con el que inicializamos
     * la variable debe ser convertido para poder inicializar la propia variable. En
     * cualquier caso, lo importante esa saber que tras esta sentencia, `N` vale `10`.
     * Podéis encontrar más información acerca de este método de inicialización en
     * https://en.cppreference.com/w/cpp/language/list_initialization.
     */
    int N{10};

    /*
     * Este bucle es el que implementa el productorio. Fíjate en cómo no hacen falta
     * llaves (i.e. `{}`) al estar el cuerpo del bucle compuesto tan solo por una línea.
     * El bucle iterará `N = 10` veces y en cada iteración actualizará el valor de
     * `prod` multiplicándolo por `sin(6.2 / i)`, donde `i` tomará los valores `1...10`.
     * En el ejemplo hemos optado por usar el operador `*=`, pero también podríamos haber
     * escrito:
     *  prod = prod * sin(x / double(i));
     * Si bien nuestra elección puede resultar más críptica resulta mucho más legible e
     * idiomática. El bucle se controla a través del entero `i` que tomará los valores que
     * hemos indicado. La condición del bucle se compone de 3 partes bien diferenciadas:
     *  Inicialización: `int i = 1` -> Damos un valor inicial a la variable de control.
     *  Condición de parada: `i <= N` -> Si no se cumple, el bucle se detiene.
     *  Incremento -> `i++` -> La transformación que le aplicamos a la variable de control en
     *                         cada iteración. También podríamos haber escrito `i = i + 1`,
     *                         `i += 1` e incluso `++i`: todas son válidas.
     */
    for (int i = 1; i <= N; i++)
        prod *= sin(x / double(i));

    // Una vez calculado el productorio lo imprimimos por pantalla.
    cout << "Productorio = " << prod << "\n";

    /*
     * A pesar de que no es «estrictamente» necesario, es una buena
     * costumbre devolver `0` para indicar a quien ha ejecutado el
     * programa que todo ha ido correctamente. Además, el prototipo
     * de `main()` (i.e. `int main()`) indica que devolveremos un
     * entero pase lo que pase...
     */
    return 0;
}
