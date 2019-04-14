
package narzedzia;
class ONP_PustaLista extends WyjątekONP {/*...*/

    public ONP_PustaLista(String message) {
        super("Pusta lista. "+ message);
    }
    public ONP_PustaLista() {
        super("Pusta lista.");
    }
}
