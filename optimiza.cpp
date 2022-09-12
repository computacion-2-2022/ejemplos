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
 * Dado que vamos a iterar siempre 2000000000 veces en cada uno de los
 * bucles vamos a definir una constante para controlar las iteraciones
 * de manera centralizada. Esta constante se «desenvuelve» en la primera
 * fase del proceso de compilación: el preprocesado. Lo que ocurre
 * «por detrás» es que en cualquier lugar en el que hayamos escrito
 * `N` se sustituye el valor `2000000000`. En otras palabras, el uso de la
 * directiva `#define` equivale a escribir «a mano» `2000000000` allá donde
 * veamos `N`. Lo bueno de todo esto es que no tenemos que hacerlo
 * nosotros :). Tradicionalmente, los nombres de estas constantes
 * se escriben íntegramente en mayúsculas. Podéis encontrar más
 * información en https://en.cppreference.com/w/cpp/preprocessor/replace.
 * En cualquier caso, el número de iteraciones es tremendamente alto para
 * provocar que la ejecución del programa se demore un tiempo suficientemente
 * alto como para apreciar diferencias entre las versiones con distintos
 * niveles de optimización.
 */
#define N 2000000000

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
     * Definimos un par de `double`s. El primero de ellos (`suma`)
     * nos valdrá para ir acumulando los resultados parciales de
     * las sumas que iremos haciendo en los bucles. El segundo
     * contiene el valor de la constante Pi calculado indirectamente
     * a través del 'arcoseno'. Si bien es cierto que podemos definir
     * Pi a través de una directiva `#define` (como hemos hecho con `N`),
     * resulta muy cómodo obtener su valor de esta manera para no
     * incluir dependencias adicionales.
     */
    double suma = 0, pi = acos(-1);

    /*
     * En este caso iteramos `N = 2000000000` veces y en cada
     * una de ellas incrementamos `suma` en `pi / i`. Dado que
     * el bucle solo tiene una línea las llaves (i.e. `{}`) no
     * son necesarias. Asimismo, el incremento que se le aplica
     * a `i` se define como `i += 1`. También se puede definir
     * como `i++`, como veremos a continuación. Asimismo, el
     * cambio de tipo de `i` a `double` (era un `int`) no es
     * estrictamente necesario: C++ convierte `i` a un `double`
     * de manera implícita para poder resolver el cociente.
     */
    for (int i = 1; i <= N; i += 1)
        suma = suma + pi / double(i);

    // Reiniciamos la suma para volver a repetir un proceso parecido.
    suma = 0;

    /*
     * En este caso vamos a incrementar `i` en `1` en cada iteración
     * con `i++` en vez de `i += 1`: el resultado es el mismo y,
     * aunque en este caso no tiene efecto, la prioridad de cada una
     * de las operaciones es diferente. También empleamos el operador
     * `+=` para incrementar la suma en vez de incluir `suma` en ambos
     * lados de la asignación (i.e. `=`). También comentamos que ahora
     * iremos acumulando `sqrt(pi) / i` en vez de `pi / i`, cosa que
     * alargará el tiempo de ejecución del bucle al completo.
     */
    for (int i = 1; i <= N; i++)
        suma += sqrt(pi) / i;

    /*
     * A pesar de que no es «estrictamente» necesario, es una buena
     * costumbre devolver `0` para indicar a quien ha ejecutado el
     * programa que todo ha ido correctamente. Además, el prototipo
     * de `main()` (i.e. `int main()`) indica que devolveremos un
     * entero pase lo que pase...
     */
    return 0;
}
