/*
 * Define `std::cout` para escribir a pantalla (i.e. `stdout`).
 * Más información -> https://en.cppreference.com/w/cpp/header/iostream
 */
#include <iostream>

/*
 * Dado que vamos a iterar siempre 10 veces en cada uno de los bucles
 * vamos a definir una constante para controlar las iteraciones de
 * manera centralizada. Esta constante se «desenvuelve» en la primera
 * fase del proceso de compilación: el preprocesado. Lo que ocurre
 * «por detrás» es que en cualquier lugar en el que hayamos escrito
 * `N` se sustituye el valor `10`. En otras palabras, el uso de la
 * directiva `#define` equivale a escribir «a mano» `10` allá donde
 * veamos `N`. Lo bueno de todo esto es que no tenemos que hacerlo
 * nosotros :). Tradicionalmente, los nombres de estas constantes
 * se escriben íntegramente en mayúsculas. Podéis encontrar más
 * información en https://en.cppreference.com/w/cpp/preprocessor/replace
 */
#define N 10

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
     * `suma` valdrá `0` (el elemento neutro de la suma). Es importante señalar que
     * en este caso el compilador **no** interpreta la coma (i.e. `,`) como el operador coma
     * (i.e. https://en.cppreference.com/w/cpp/language/operator_other), sino como
     * varias «sentencias declaratorias». Este tema resulta tremendamente abstracto y
     * casi innecesario: no hace falta conocerlo para poder declarar e inicializar
     * variables con total confianza, pero creemos que resulta curioso... Podéis encontrar
     * más información en https://en.cppreference.com/w/cpp/language/declarations.
     * Asimismo, señalamos que podríamos haber inicializado `suma` con cualquiera de los
     * siguientes ejemplos:
     *  `suma = 0`
     *  `suma = 0.0`
     *  `suma = 0.0e+0`
     * Dado que `suma` es un `double` podemos inicializarlo con un entero (`0`), o con un
     * doble (`0.0` y `0.0e+0`). Al tener la variable a inicializar una precisión mayor o
     * igual que los valores inicilizadores no generamos ningún aviso en la compilación.
     * Si la situación fuera al revés, esto es, si inicializáramos un entero con un doble
     * sí que se generarían avisos (aunque en la práctica una sentencia como `int f = 0.0`
     * no genera errores: `f` puede representar `0.0` sin impacto en la precisión). En cualquier
     * caso, es interesante saber que tipo tienen los literales numéricos que podemos escribir:
     *  float       -> `0.1f`
     *  double      -> `0.1`, `0.1e+0`
     *  long double -> `0.1L`
     */
    double x(6.2), suma = 0;

    /*
     * Este bucle es el que implementa el sumatorio. Fíjate en cómo no hacen falta
     * llaves (i.e. `{}`) al estar el cuerpo del bucle compuesto tan solo por una línea.
     * El bucle iterará `N = 10` veces y en cada iteración actualizará el valor de
     * `suma` sumando `x / double(i)`, donde `i` tomará los valores `1...10`.
     * En el ejemplo hemos optado por usar el operador `+=`, pero también podríamos haber
     * escrito:
     *  suma = suma + x / double(i);
     * Si bien nuestra elección puede resultar más críptica resulta mucho más legible e
     * idiomática. El bucle se controla a través del entero `i` que tomará los valores que
     * hemos indicado. La condición del bucle se compone de 3 partes bien diferenciadas:
     *  Inicialización: `int i = 1` -> Damos un valor inicial a la variable de control.
     *  Condición de parada: `i <= N` -> Si no se cumple, el bucle se detiene.
     *  Incremento -> `i++` -> La transformación que le aplicamos a la variable de control en
     *                         cada iteración. También podríamos haber escrito `i = i + 1`,
     *                         `i += 1` e incluso `++i`: todas son válidas.
     * En este caso convertimos el tipo de `i` explícitamente de `int` a `double` a través de
     * la conversión `double(i)`. Sin embargo, esta no es necesaria: C++ convertirá `i` a un
     * `double` de manera implícita para poder llevar a cabo el cociente ya que `x` es un
     * `double`. En otras palabras, vemos como el tipo de los operandos viene dado por el
     * tipo con más precisión de los dos. Si `x` hubiera sido un entero la división siempre
     * habría resultado en un numero entero, cosa que genera errores tremendos en el cálculo.
     * En el siguiente sumatorio obviaremos la conversión para ver cómo, efectivamente, el
     * resultado es el mismo.
     */
    for (int i = 1; i <= N; i++)
        suma += x / double(i);

    // Una vez calculado imprimimos el resultado por pantalla.
    cout << "Sumatorio = " << suma << "\n";

    // Antes de comenzar la siguiente suma reiniciamos el acumulador.
    suma = 0;

    /*
     * A pesar de que la variable de control del bucle anterior era `i`, la
     * declaración se ha hecho dentro del ámbito del bucle `for` (con el `int i = 1).
     * En este ámbito (i.e. el de `main()`) NO EXISTE. Es por ello que debemos declarar
     * `i` como un entero para poder iterar sobre él.
     */
    int i = 1;

    /*
     * Al igual que hacíamos con el bucle `for` anterior, ahora iteraremos `10` veces
     * para calcular el mismo sumatorio pero con un bucle `while`. En este caso la
     * inicialización de la variable de control es externa al bucle y la actualización
     * de la misma es parte del propio bucle. Como comentábamos, el efecto es sin embargo
     * idéntico.
     */
    while (i <= N) {
        /*
         * En este caso vamos a prescindir de la conversión de `i` a `double`
         * y también respetaremos la sintaxis más larga para expresar la
         * actualización del sumatorio.
         */
        suma = suma + x / i;

        // Como comentábamos, tenemos que actualizar la variable de control...
        i = i + 1;
    }

    // Una vez calculado imprimimos el resultado por pantalla.
    cout << "Sumatorio = " << suma << "\n";

    // Volvemos a reiniciar el sumatorio...
    suma = 0;

    /*
     * En este caso, como ya hemos declarado `i` en el ámbito de la función
     * `main()` podemos simplemente asignarle el valor `1` pero sin necesidad
     * de redeclararla: fíjate en que la inicialización del bucle es `i = 1` y
     * no `int i = 1`. Por lo demás el bucle es idéntico al anterior. Hemos
     * decidido incluir las llaves y cambiar el incremento de la variable de
     * control para demostrar variaciones del mismo bucle. Nótese que podemos
     * emplear el operador `+=` porque su preferencia es menor que la del
     * cociente (i.e. `/`) tal y como se recoge en
     * https://en.cppreference.com/w/cpp/language/operator_precedence
     */
    for (i = 1; i <= N; ++i) {
        suma += x / i;
    }

    // Una vez calculado imprimimos el resultado por pantalla.
    cout << "Sumatorio = " << suma << "\n";

    // Volvemos a reiniciar el valor del sumatorio...
    suma = 0;

    // ... y el de la variable de control.
    i = 1;

    /*
     * Este bucle es una variación del bucle `while` en la que SIEMPRE
     * ejecutaremos una iteración y en el que la condición de parada se
     * evalúa después de la ejecución de la iteración y no antes. También
     * es importante recordar el punto y coma (i.e. `;`) final :P
     */
    do {
        // Incrementamos la suma...
        suma = suma + x / double(i);

        // ... y la variable de control.
        i++;
    } while(i <= N);

    // Una vez calculado imprimimos el resultado por pantalla.
    cout << "Sumatorio = " << suma << "\n";

    /*
     * A pesar de que no es «estrictamente» necesario, es una buena
     * costumbre devolver `0` para indicar a quien ha ejecutado el
     * programa que todo ha ido correctamente. Además, el prototipo
     * de `main()` (i.e. `int main()`) indica que devolveremos un
     * entero pase lo que pase...
     */
    return 0;
}
