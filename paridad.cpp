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
     * se puede imprimir el valor directamente con `cout << num;`.
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
     * Asimismo, es interesante señalar que cuando solo se incluye una
     * sentencia no son necesarias las llaves (i.e. `{}`).
     * También queremos llamar la atención sobre la diferencia entre el
     * operador de asignación (i.e. `=`) y el de comparación (i.e. `==`).
     * Finalmente, nos gustaría comentar que en C++ se asume que un valor
     * de `0` es falso y todo aquello que no sea `0` es verdadero. Esto
     * implica que la comprobación `num % 2 == 0` es redundante y podría
     * ser sustituida por  `!(num % 2)`.
     */
    if (num % 2 == 0)
        cout << "\nEl numero es par \n";
    else
        cout << "\nEl numero es impar \n";

    /*
     * A pesar de que no es «estrictamente» necesario, es una buena
     * costumbre devolver `0` para indicar a quien ha ejecutado el
     * programa que todo ha ido correctamente. Además, el prototipo
     * de `main()` (i.e. `int main()`) indica que devolveremos un
     * entero pase lo que pase...
     */
    return 0;
}
