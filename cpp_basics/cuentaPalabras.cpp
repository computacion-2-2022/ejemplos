/*
 * Define `std::cout` para escribir a pantalla (i.e. `stdout`)
 * Más información -> https://en.cppreference.com/w/cpp/header/iostream
 */
#include <iostream>

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
     * Definimos el flujo `mif` para leer un archivo. No obstante,
     * ahora mismo está «vacío»: todavía no le hemos asociado
     * ningún archivo...
     */
    fstream mif;

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
     * Declaramos las variables que emplearemos para ir leyendo las palabras
     * y llevar la cuenta de cuántas hemos leído.
     */
    string palabra; int n_palabras;

    /*
     * Inicializamos el valor de la cuenta: ¡hasta ahora solo tenía basura!
     * También podríamos haber declarado e inicializado la variable en la
     * misma línea.
     */
    n_palabras = 0;

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
    while (!mif.eof()) {
        // Mientras quede archivo por leer seguimos extrayendo palabras...
        mif >> palabra;

        /*
         * Y cada vez que extraigamos una vamos actualizando la cuenta total.
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
    }

    /*
     * En este punto estamos seguros de haber leído el archivo por
     * completo. Solo nos queda imprimir por pantalla la cuenta total
     * de palabras. Nótese que para añadir una nueva línea al final
     * podemos usar la cadena `"\n"` o, como en este caso, `endl`.
     */
    cout << "Número de palabras = " << n_palabras << endl;

    /*
     * Una vez terminemos de trabajar con el archivo debemos
     * cerrarlo para liberar los recursos asociados que se
     * nos han ido otorgando. Podéis encontrar más información
     * acerca de la función en:
     *  https://en.cppreference.com/w/cpp/io/basic_fstream/close
     */
    mif.close();

    /*
     * A pesar de que no es «estrictamente» necesario, es una buena
     * costumbre devolver `0` para indicar a quien ha ejecutado el
     * programa que todo ha ido correctamente. Además, el prototipo
     * de `main()` (i.e. `int main()`) indica que devolveremos un
     * entero pase lo que pase...
     */
    return 0;
}
