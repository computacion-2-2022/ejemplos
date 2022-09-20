/*
 * Nosotros aprendimos a programar con C en vez de C++, con lo que
 * preferimos funciones para la salida como `printf()` en vez
 * de la alternativa nativa de C++: `cout`. Podéis encontrar
 * información adicional en https://en.cppreference.com/w/cpp/header/cstdio.
 * La función `printf()` funciona de manera «peculiar»: hay que pasarle una
 * cadena que especifica el formato de lo que se escribirá por pantalla y
 * luego debemos pasar las variables cuyos valores queremos imprimir. Cada
 * una de las variables a imprimir van asociadas a un «verbo» introducido
 * por un porcentaje (i.e. `%`). Podéis encontrar más información sobre
 * todo ello en https://en.cppreference.com/w/cpp/io/c/fprintf.
 */
#include <cstdio>

/*
 * Dado que queremos poner a prueba la función `dummyFunc` vamos a definir
 * una constante con el valor que le pasaremos (y que ella devolverá) para
 * verificar que todo funciona como esperamos sea cual sea la forma en la
 * que «juguemos» con el puntero de la función.
 */
#define DUMMY_RET 5

/*
 * Esta función simplemente devuelve el argumento que le pasamos. Es
 * tremendamente sencilla ya que lo que nos interesa no es su cometido
 * sino su dirección, cosa que pasaremos por el programa.
 */
int dummyFunc(int n) {
    return n;
}

/*
 * Esta función recibe una función por valor: en la definición del argumento
 * no incluimos `*`, con lo que podemos decir que la función no es «exactamente»
 * un puntero. No obstante, veremos que el resultado es exactamente el mismo.
 */
int funcReceiver(int func(int)) {
    /*
     * Nada más entrar en la función imprimimos el valor del parámetro de entrada
     * (i.e. `func`) como un puntero: de ahí el «verbo» `%p`. Unido a ello,
     * imprimimos tanto el parámetro como el contenido del parámetro a través del
     * operador de desreferencia (i.e. `*`). Curiosamente, el resultado es exactamente
     * el mismo: esto se debe a que siempre que hacemos referencias a funciones, ya sea
     * directa o indirectamente, recibimos el mismo resultado. El hecho de que aplicar
     * el operador `&` o `*` a una referencia a una función sea siempre el mismo nos
     * permite trabajar con referencias a funciones de manera cómoda a nivel sintáctico.
     */
    printf("funcReceiver: address of the 'func' function:\n\tRaw         : %p\n\tDereferenced: %p\n", func, *func);

    /*
     * Tras imprimir el valor del argumento `func` llamamos a la función a la que hace referencia con
     * el parámetro definido en la constante `DUMMY_RET`. Como podemos esperar, recibimos el mismo
     * valor de vuelta.
     */
    return func(DUMMY_RET);
}

/*
 * Esta función recibe la función por referencia. No obstante, tal y como comentábamos el valor
 * es el mismo que en el caso anterior.
 */
int funcPtrReceiver(int (*func)(int)) {
    // Como decíamos, esta línea imprime el mismo valor que la homóloga en la función anterior.
    printf("funcPtrReceiver: address of the 'func' function:\n\tRaw         : %p\n\tDereferenced: %p\n", func, *func);

    /*
     * Para respetar la «pureza» de la sintaxis llamamos a la función a través de la desreferencia
     * del puntero a la función (i.e. `(*func)`). Al igual que antes, vemos cómo se devuelve el
     * valor que le pasamos a la función (i.e. `DUMMY_RET`).
     */
    return (*func)(DUMMY_RET);
}

int main(void) {
    /*
     * Pasamos la función por «valor» a la función que espera
     * recibirla por valor y almacenamos el resultado en A para
     * luego verificar que siempre se devuelve lo mismo.
     */
    int a = funcReceiver(dummyFunc);

    /*
     * En este caso pasamos la función por «valor» a la función que
     * espera recibirla por referencia y, como comentábamos todo
     * sigue funcionando.
     */
    int b = funcPtrReceiver(dummyFunc);

    /*
     * Un ejemplo más: pasamos la dirección de la función (i.e. `&dummyFunc`)
     * y, como era de esperar, el valor que recibe `funcPtrReceiver` sigue
     * siendo el mismo.
     */
    int c = funcPtrReceiver(&dummyFunc);

    /*
     * Comprobamos que sea cual sea la forma en la que pasemos la referencia
     * a la función `dummyFunc` el resultado es el mismo. De lo contrario
     * lo dejamos claro con un mensaje.
     */
    if (a == b && a == c && b == c)
        printf("things look good: a == b == c == %d\n", a);
    else
        printf("something weird happened: a = %d; b = %d; c = %d\n", a, b, c);

    /*
     * Para adherirnos a las convenciones devolvemos `0`
     * indicando que todo ha ido bien.
     */
    return 0;
}
