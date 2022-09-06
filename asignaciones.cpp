/*
 * Define `std::cout` para escribir a pantalla (i.e. `stdout`)
 * Más información -> https://en.cppreference.com/w/cpp/header/iostream
 */
#include <iostream>

/*
 * Define el tipo «cadena» (i.e. `string`) para poder definirlas
 * y trabajar con ellas. Más información:
 *  https://en.cppreference.com/w/cpp/header/string
 */
#include <string>

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
    // Declaramos la cadena que vamos a inicializar a continuación.
    string s;

    /*
     * Inicializamos el la variable `s` con una «cadena literal».
     * En este caso, al incluir dos cadenas diferentes en la misma
     * línea sin ninguna operación entre medias estas cadenas serán
     * concatenadas durante la compilación. Podéis encontrar más
     * información acerca de este comportamiento en:
     *  - https://en.cppreference.com/w/cpp/language/string_literal
     * Recomendamos prestar especial atención a la sección
     * titulada «Concatenation».
     */
    s = "Hola ¿Qué tal?" " Muy bien ¿Y tú?";

    /*
     * Imprimimos la cadena que acabamos de inicializar por
     * pantalla. Tal y como se deduce del comentario anterior
     * lo que se imprimirá es:
     *  Hola ¿Qué tal? Muy bien ¿Y tú?
     */
    cout << s << endl;

    /*
     * Ahora declaramos una variable de tipo carácter para
     * después inicializarla. Nótese que esto ocurre en
     * dos sentencias diferentes que aparecen delimitadas
     * por `;`. Esto es, podríamos haber escrito la línea
     * inferior en dos distintas. También podríamos haber
     * declarado e inicializado la variable en una sola
     * sentencia con:
     *  char c = 'T';
     * También es importante señalar que los caracteres
     * literales se señalan con comillas simples (i.e. `'`)
     * en vez de comillas dobles (i.e. `"`), que se emplean
     * para definir cadenas literales.
     */
    char c; c = 'T';

    // Imprimimos el carácter `c` por pantalla. Esto imprime una T.
    cout << c << endl;

    /*
     * En este caso imprimimos una cadena literal por pantalla.
     * Lo que cabe destacar es el uso de secuencias de escape
     * introducidas por la contrabarra (i.e. `\`). Existe una
     * lista completa en:
     *  - https://en.cppreference.com/w/cpp/language/escape
     * Las principales secuencias son:
     *      \n -> Nueva línea.
     *          En Windows se suele sustituir por \r\n. En Unix
     *          se ejecuta un retorno de carro implícito.
     *      \r -> Retorno de carro.
     *          Esta secuencia devuelve el cursor al inicio de la
     *          línea.
     *      \t -> Tabulación horizontal.
     *      \\ -> Inclusión de una contrabarra en el texto.
     *      \" -> Inclusión de comillas dobles dentro de una cadena literal.
     *      \? -> Prevención de la sustitución de «trigraphs».
     * Quizá lo más curioso de lo anterior son los trigraphs. Hace mucho
     * tiempo algunos teclados no tenían caracteres como `#` o `{`. Para
     * «solucionar» el problema se empleaban secuencias de tres caracteres
     * como `??=` que en una fase muy temprana de la compilación se sustituían
     * por el carácter correspondiente. El «trigraph» sería sustituido por
     * `#`, por ejemplo. El problema es que dado lo pronto que se aplica esta
     * transformación corremos el peligro de que las cadenas literales no contengan
     * lo esperado. Al escapar una `?` con `\` evitamos la transformación por
     * completo y, dado que `\` es la secuencia de escape, no se incluye en la
     * cadena literal. Sin embargo, los «trigraphs» se han eliminado en C++17.
     * Esto implica que, en nuestro caso, la secuencia de escape no es necesaria.
     * Podéis encontrar más información en:
     *  - https://en.cppreference.com/w/cpp/language/operator_alternative
     * Aplicando todo lo anterior, la siguiente línea producirá la salida:
     *  Hola ¿Qué tal?
     *  Muy bien ¿Y tú??        También bien.
     * Nótese que mostramos la tabulación como 8 espacios. Es el tamaño
     * estándar de la mayoría de terminales...
     */
    cout << "Hola ¿Qué tal\?\nMuy bien ¿Y tú?\tTambién bien.\n";

    /*
     * Declaramos dos enteros para luego inicializarlos.
     */
    int i, j;

    /*
     * Esta inicialización hace uso del operador coma (i.e. `,`).
     * El operador coma sigue el formato `E1, E2` donde `E1` y `E2`
     * son expresiones. En este caso:
     *  E1 = `j = 2` y E2 = `j + 10`
     * El orden de evaluación es E1 -> E2. En nuestro caso, se le asigna
     * el valor `2` a `j` y luego se «devuelve» el valor `j + 10 = 2 + 10 = 12`.
     * Normalmente decimos que la expresión se evalúa a `12`. Toda la expresión
     * relacionada con el operador coma va entre paréntesis debido a que
     * la preferencia del mismo es la más baja de todas. De no existir, la
     * expresión global sería la del operador coma donde:
     *  E1 = `i = j = 2` y E2 = `j + 10`
     * Dado que el operador de asignación (i.e. `=`) «devuelve» lo asignado
     * veríamos que el valor final de `i` sería `2`. Además, el compilador
     * nos avisaría de que el resultado de la expresión coma (i.e. `12`)
     * no va a ser utilizado. Podéis encontrar más información en:
     *  Preferencia de operadores -> https://en.cppreference.com/w/cpp/language/operator_precedence
     *  Operador coma -> https://en.cppreference.com/w/cpp/language/operator_other
     *  Operador asignación -> https://en.cppreference.com/w/cpp/language/operator_assignment
     */
    i = ( j = 2, j + 10 );

    /*
     * Mostramos el resultado de `i` por pantalla
     * para comprobar que es, efectivamente, 12.
     */
    cout << i << endl;

    /*
     * A pesar de que no es «estrictamente» necesario, es una buena
     * costumbre devolver `0` para indicar a quien ha ejecutado el
     * programa que todo ha ido correctamente. Además, el prototipo
     * de `main()` (i.e. `int main()`) indica que devolveremos un
     * entero pase lo que pase...
     */
    return 0;
}
