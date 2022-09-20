/*
 * Define `std::cout` para escribir a pantalla (i.e. `stdout`).
 * Más información -> https://en.cppreference.com/w/cpp/header/iostream
 */
#include <iostream>

/*
 * Define `std::setprecision()`, que nos permite configurar la cantidad
 * de decimales a mostrar en un flujo determinado. En este caso se
 * aplica a `cout`, con lo que incrementamos el número de decimales de
 * loas valores a mostrar.
 * Más información -> https://en.cppreference.com/w/cpp/header/iomanip
 */
#include <iomanip>

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

/*
 * Los comentarios que se van incluyendo con el código a continuación se fundamentan
 * (y confirman) en la información de https://en.cppreference.com/w/cpp/language/types.
 * Allí se pueden encontrar los límites máximos de cada tipo de datos. En el caso
 * de variables enteras (ya sean `int` o `long int`) vienen dadas por el rango:
 *      [-2^{n-1}, -2^{n-1} - 1]; donde `n` es el número de bits.
 * La expresión anterior se deduce del sistema de representación de «complemento a dos»
 * que emplean los enteros en C++: https://en.wikipedia.org/wiki/Two%27s_complement.
 * La representación de los valores de coma flotante se basa en el estándar IEEE-754
 * https://en.wikipedia.org/wiki/IEEE_754 y, dada su complejidad, no vamos a explicar
 * cómo se obtienen los rangos que aparecen en la referencia anterior. Si alguien tiene
 * especial interés que no dude en preguntar con un correo a <pablo.collado@uam.es>.
 *
 * Como es de esperar, la precisión de los valores va ligada a su tamaño. Con el operador
 * `sizeof` (https://en.cppreference.com/w/cpp/language/sizeof) podemos saber el tamaño
 * en bytes (donde un byte son 8 bits) de cada una de las variables que vayamos definiendo.
 * Los tamaños de los tipos de datos son dependientes de la máquina en la que se ejecuta el
 * programa y para la arquitectura que se compiló. Los comentarios que se incluyen el programa
 * se asocian a mi máquina personal. No obstante, lo más probable es que sean idénticos para
 * la mayoría de vuestros equipos: casi todos tienen procesadores Intel de 64 bits :P
 *
 * Asimismo, iremos imprimiendo por pantalla los distintos valores. Debemos tener en cuenta
 * que dada la implementación de las operaciones que imprimen por pantalla veremos dígitos
 * que son totalmente ficticios ya que los tipos de las variables que los almacenan no
 * tienen capacidad para representarlos en su totalidad. Los dígitos que no coinciden con
 * los valores con los que inicializamos las variables son fruto de las limitaciones de
 * los sistemas de representación empleados (Complemento a Dos y IEEE-754) que imponen
 * una precisión finita. Podemos decir que es el «intento» de la máquina de dar sentido
 * a valores que no lo tienen.
 *
 * Por otro lado, cabe destacar el fenómeno del overflow (o underflow) que se da cuando
 * asignamos a una variable entera un valor que no puede representar. Dado que con los
 * enteros no estamos sometidos a problemas de precisión, veremos cómo el valor final
 * de la variable es tremendamente ficticio. Lo que ocurre es que una vez superamos el
 * valor máximo del tipo de variable el siguiente valor es el mínimo que pueden representar.
 * Incluimos un ejemplo de esto a continuación. Si el compilador es capaz de detectar esta
 * condición emitirá un error. Podéis encontrar más información en
 * https://en.wikipedia.org/wiki/Integer_overflow.
 */
int main() {
    /*
     * Definimos un entero con un valor dentro de su rango. En nuestro sistema
     * un valor de tipo `int` tiene un tamaño de 4 bytes (i.e. 32 bits). Por
     * tanto, puede representar valores en el rango [-2147483648, 2147483647].
     * El valor con el que inicializamos el entero pertenece a ese rango, con
     * lo que en la pantalla veremos el mismo número.
     */
    int N1 = 123456789;

    /*
     * Sacamos el valor por pantalla para verificar que, en efecto, se puede representar.
     * También incluimos el tamaño en bytes de la variable.
     */
    cout << "N1: " << N1 << " (" << sizeof(N1) << " bytes)\n";

    /*
     * Definimos un `long int` que en nuestro sistema tiene un tamaño de 8 bytes.
     * Podemos representar valores en el intervalo [-9223372036854775808, 9223372036854775807].
     * EL valor con el que hemos inicializado N2 esta dentro del rango con lo que, una vez
     * más, todo debería ir bien.
     */
    long int N2 = 1234567890123456789;
    cout << "N2: " << N2 << " (" << sizeof(N2) << " bytes)\n";

    /*
     * Esta asignación provoca un aviso del compilador porque se va a producir un
     * overflow. Dado que el mayor valor representable con un entero es 2147483647
     * si le asignamos el inmediatamente superior (i.e. 2147483647) habremos dado
     * «la vuelta» a todos los valores positivos y llegaremos al entero «más negativo».
     * Esto es, la siguiente asignación pasa a almacenar el valor -2147483648 en `N1`.
     */
    int N3 =  2147483648;
    cout << "N3: " << N3 << " (" << sizeof(N3) << " bytes)\n";

    /*
     * Antes de empezar a imprimir números racionales por pantalla vamos a manipular
     * el flujo de la salida estándar (i.e. `cout`) para que muestra más decimales
     * de los 6 que incluye por defecto. Esta modificación persiste hasta que
     * volvamos a configurar otra precisión. Podéis encontrar más información en
     * https://en.cppreference.com/w/cpp/io/manip/setprecision.
     */
    cout << setprecision(30);

    /*
     * Ahora pasamos a trabajar con valores de coma flotante que, como dijimos
     * más arriba, se representan según el estándar IEEE-754. A la hora de definir
     * este tipo de constantes podemos añadir un sufijo al literal numérico para
     * especificar el tipo del mismo:
     *      F -> Consideramos que el valor es un `float`.
     *        -> Si no añadimos un sufijo se entiende que el valor es un `double`.
     *      L -> Especificamos que el valor es un `long double`.
     * Podéis encontrar más información en:
     * https://en.cppreference.com/w/cpp/language/floating_literal.
     */

    /*
     * En este caso inicializamos un `float` con un valor cuya precisión no puede
     * representar en su totalidad. Dada la forma en la que se representan, la
     * precisión de este tipo es de 7 decimales tal y como se refleja en
     * https://en.wikipedia.org/wiki/Single-precision_floating-point_format.
     * El tamaño de este tipo es de 4 bytes en nuestra máquina.
     */
    float R1 = 0.12345678901234567890123456789F;
    cout << "R1: " << R1 << " (" << sizeof(R1) << " bytes)\n";

    /*
     * En este caso inicializamos un `double` de 8 bytes en nuestra máquina. Con ello
     * conseguimos hasta 17 decimales de precisión tal y como aparece en
     * https://en.wikipedia.org/wiki/Double-precision_floating-point_format
     */
    double R2 = 0.12345678901234567890123456789;
    cout << "R2: " << R2 << " (" << sizeof(R2) << " bytes)\n";

    /*
     * Ahora definimos un `long double` de 16 bytes en nuestro equipo. Este tipo
     * puede lograr una precisión de hasta 21 decimales tal y como se recoge en
     * https://en.wikipedia.org/wiki/Extended_precision. Existen máquinas que
     * pueden proporcionar hasta 36 decimales de precisión (no la nuestra) según
     * https://en.wikipedia.org/wiki/Quadruple-precision_floating-point_format
     */
    long double R3 = 0.12345678901234567890123456789L;
    cout << "R3: " << R3 << " (" << sizeof(R3) << " bytes)\n";

    /*
     * A pesar de que no es «estrictamente» necesario, es una buena
     * costumbre devolver `0` para indicar a quien ha ejecutado el
     * programa que todo ha ido correctamente. Además, el prototipo
     * de `main()` (i.e. `int main()`) indica que devolveremos un
     * entero pase lo que pase...
     */
    return 0;
}
