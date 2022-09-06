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
     * Definimos el flujo `misdat` para escribir un archivo. No obstante,
     * ahora mismo está «vacío»: todavía no le hemos asociado
     * ningún archivo...
     */
    fstream misdat;

    /*
     * Asociamos el archivo `parabola.txt` al flujo `misdat` a través
     * del método `open()` para escribir datos al archivo: no podremos
     * leerlos! El segundo argumento es del tipo `std::ios::openmode`
     * y nos permite combinar varias valores para abrir el archivo en
     * modo lectura, escritura, sobrescribirlo... Podéis encontrar más
     * información en:
     *  open() -> https://en.cppreference.com/w/cpp/io/basic_fstream/open
     *  std::ios::openmode -> https://en.cppreference.com/w/cpp/io/ios_base/openmode
     */
    misdat.open("parabola.txt", ios::out);

    /*
     * Declaramos dos variables de tipo `double`. En este caso, `x` solo
     * está declarada pero **no** inicializada. Esto implica que tendrá un
     * valor «basura» que deberemos sobrescribir inicializando la variable
     * más tarde. Por otro lado, `D` se inicializa con `1` siguiendo una
     * sintaxis un tanto particular: «direct-list-initialization». Esta sintaxis
     * solo está disponible desde C++11 (de ahí el `-std=c++11` que pasamos a
     * `gcc`). Lo positivo de esta sintaxis es que no permite «truncar» los datos.
     * Esto es, no podemos inicializar un entero (i.e. `int`) con `5.1`: el
     * truncado a `5` provoca un error de compilación quejándose de que no se puede
     * hacer un «narrowing» de un tipo a otro. Podéis encontrar más información
     * en https://en.cppreference.com/w/cpp/language/list_initialization, siendo
     * la discusión de:
     *  https://stackoverflow.com/questions/18222926/what-are-the-advantages-of-list-initialization-using-curly-braces
     * más clara y concisa.
     */
    double x, D{1};

    // Pasamos a inicializar `x` una vez ya ha sido declarado más arriba.
    x = 1;

    /*
     * Iteramos hasta que `x` sea menor que `9.1`. Nótese que emplear valores
     * de coma flotante (i.e. `float`, `double` y sus variaciones) como
     * variables de iteración puede llevar a errores sutiles. Dadas las
     * limitaciones de los sistemas de representación como el IEEE-754
     * (https://en.wikipedia.org/wiki/IEEE_754) pude no ser posible
     * predecir con exactitud el valor real que va a estar asociado a esta
     * variable en todo momento. Si las comparaciones no son estrictas, esto
     * es, si **no** se usa el operador `!=` (i.e. «distinto de»), podemos
     * asistir a una ejecución más o menos de las esperadas. Ahora bien,
     * si comparamos con un valor exacto tenemos un peligro muy serio de
     * provocar un bucle infinito... El siguiente bucle es un ejemplo
     * de ello:
     *      double y = -1;
     *      while(y != 0.1) {
     *          cout << "y = " << y << "\n";
     *          y += 0.1;
     *          if (y > 1) {
     *              cout << "Forcefully stopped loop !\n";
     *              break;
     *          }
     *      }
     * Un sitio web muy interesante para familiarizarse con el estándar IEEE-754
     * es https://www.h-schmidt.net/FloatConverter/IEEE754.html.
     */
    while(x < 9.1) {
        /*
         * En este caso, el «operador de inserción» (i.e. `<<`) se aplica
         * al flujo `misdat` en vez de al tradicional `cout`. Tal y como
         * `cout` escribía las cadenas insertadas a `stdout` (i.e. la pantalla),
         * `misdat` escribe las cadenas insertadas al archivo con el que lo
         * asociamos: `parabola.txt`. Las líneas insertadas siguen el
         * formato que se desgrana del order de inserción:
         *  <número> <espacio> <número> <espacio> <número> <nueva_línea>
         */
        misdat << x << " " << x*x << " " << D << "\n";

        // Actualizamos la variable de iteración incrementándola en 1.
        x = x + 1;
    }

    /*
     * Una vez terminemos de trabajar con el archivo debemos
     * cerrarlo para liberar los recursos asociados que se
     * nos han ido otorgando. Podéis encontrar más información
     * acerca de la función en:
     *  https://en.cppreference.com/w/cpp/io/basic_fstream/close
     */
    misdat.close();

    /*
     * A pesar de que no es «estrictamente» necesario, es una buena
     * costumbre devolver `0` para indicar a quien ha ejecutado el
     * programa que todo ha ido correctamente. Además, el prototipo
     * de `main()` (i.e. `int main()`) indica que devolveremos un
     * entero pase lo que pase...
     */
    return 0;
}
