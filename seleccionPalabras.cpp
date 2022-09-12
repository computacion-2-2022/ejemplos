/*
 * Define `std::cout` para escribir a pantalla (i.e. `stdout`) y
 * `std::cin` para leer datos desde el teclado (i.e. `stdin`).
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
 * Define `std::fstream` para trabajar con archivos como si fueran flujos.
 * Más información ->  https://en.cppreference.com/w/cpp/header/fstream
 */
#include <fstream>

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
    /*
     * Definimos los flujos `mif` y `fsalida` para leer contenidos de un archivo y
     * escribirlos a otro, respectivamente. Ahora mismo están «vacíos»: todavía no
     * les hemos asociado ningún archivo...
     */
    fstream mif, fsalida;

    /*
     * Asociamos el archivo `libro.txt` al flujo `mif` a través
     * del método `open()` para leer datos del archivo: no podremos
     * escribirlos! El segundo argumento es del tipo `std::ios::openmode`
     * y nos permite combinar varias valores para abrir el archivo en
     * modo lectura, escritura, sobrescribirlo... Podéis encontrar más
     * información en:
     *  open() -> https://en.cppreference.com/w/cpp/io/basic_fstream/open
     *  std::ios::openmode -> https://en.cppreference.com/w/cpp/io/ios_base/openmode
     */
    mif.open("libro.txt", ios::in);

    /*
     * Asociamos el archivo `parte_libro.txt` al flujo `fsalida` a través
     * del método `open()` para escribir datos al archivo: no podremos
     * leerlos! El segundo argumento es del tipo `std::ios::openmode`
     * y nos permite combinar varias valores para abrir el archivo en
     * modo lectura, escritura, sobrescribirlo... Podéis encontrar más
     * información en:
     *  open() -> https://en.cppreference.com/w/cpp/io/basic_fstream/open
     *  std::ios::openmode -> https://en.cppreference.com/w/cpp/io/ios_base/openmode
     */
    fsalida.open("parte_libro.txt", ios::out);

    /*
     * Declaramos las variables que emplearemos para ir leyendo las palabras
     * y llevar la cuenta de cuántas hemos leído y las que seleccionaremos para
     * escribir al archivo de salida. La cadena no está explícitamente inicializada,
     * pero los enteros están declarados e inicializados.
     */
    string palabra;
    int n_palabras = 0, select = 2;

    /*
     * Empleamos el operador de «extracción» de flujos para extraer una
     * palabra del flujo asociado al archivo de entrada. El operador
     * `>>` extrae palabras ya que, por defecto, detiene su acción
     * al encontrar espacio en blanco en el flujo.
     */
    mif >> palabra;

    /*
     * Como queremos leer todo el archivo, iteraremos con la condición
     * de haber llegado hasta el final del mismo. Dado que los archivos
     * se presentan como una sucesión de caracteres somos conscientes de
     * que, al leerlo, eventualmente llegaremos al final del mismo. Cuando
     * ese evento tiene lugar decimos que hemos llegado al EOF (i.e. End
     * of File) del archivo. Dada su utilidad, la instancia del flujo
     * asociado al archivo (i.e. `mif`) cuenta con una función que nos
     * indica justamente si hemos leído el archivo completo o no. La función
     * devuelve un booleano (i.e. `bool`) que será verdadero si hemos leído
     * todo el archivo y falso si todavía nos queda algo por leer. Dado que
     * el bucle se detiene cuando la condición de control es falsa y que
     * nosotros queremos detener el bucle cuando `eof()` sea verdadero, tenemos
     * que «invertir» el valor devuelto por `eof()` con el operador lógico
     * de negación (i.e. `!`). Por tanto, la condición del bucle se leería
     * como: «itera mientras no hayamos llegado al EOF del archivo». Podéis
     * encontrar más información del método `eof()` en:
     *  https://en.cppreference.com/w/cpp/io/basic_ios/eof
     */
    while(!mif.eof()) {
        /*
         * Y cada vez que extraigamos una vamos actualizando la cuenta total.
         * El hecho de que este incremento sea el primer paso de la iteración
         * implica que la cuenta es exacta: cuando hagamos la primera comprobación
         * todos los valores son correctos.
         * Nótese que este incremento podría haberse hecho de otras maneras:
         *  n_palabras = n_palabras + 1;
         *  n_palabras += 1;
         *  ++n_palabras;
         * Si bien el resultado final de cada una de las opciones anteriores es
         * el mismo, la preferencia con la que ocurre el incremento **no** es
         * la misma. Se puede predecir el resultado aplicando las reglas que
         * aparecen en: https://en.cppreference.com/w/cpp/language/operator_precedence
         */
        n_palabras++;

        /*
         * Para seleccionar palabras iremos aplicando la operación módulo (i.e. `%`)
         * con el valor de `select` que, ahora mismo, es `2`. Esta comprobación acaba
         * por comprobar que la cantidad de palabras leídas hasta ahora son pares. Si
         * es el caso, se incluirá en el archivo de salida. De lo contrario, pasaremos
         * a leer la siguiente en la próxima iteración. Dado el valor implícito de verdad
         * de los enteros, donde `0 === false` y `!0 === true` (significando `===`
         * equivalencia) esta comprobación puede pasar a ser:
         *  !(n_palabras % select)
         * No obstante, la opción que hemos escogido es mucho más legible.
         */
        if (n_palabras % select == 0)
            fsalida << palabra << endl;

        // Mientras quede archivo por leer seguimos extrayendo palabras...
        mif >> palabra;
    }

    /*
     * Una vez terminemos de trabajar con los archivos debemos
     * cerrarlos para liberar los recursos asociados que se
     * nos han ido otorgando. Podéis encontrar más información
     * acerca de la función en:
     *  https://en.cppreference.com/w/cpp/io/basic_fstream/close
     */
    mif.close();
    fsalida.close();

    /*
     * A pesar de que no es «estrictamente» necesario, es una buena
     * costumbre devolver `0` para indicar a quien ha ejecutado el
     * programa que todo ha ido correctamente. Además, el prototipo
     * de `main()` (i.e. `int main()`) indica que devolveremos un
     * entero pase lo que pase...
     */
    return 0;
}
