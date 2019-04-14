
package narzedzia;
class ONP_BłądArności extends WyjątekONP {/*...*/

    public ONP_BłądArności(String message) {
        super("Błąd. "+ message);
    }
    public ONP_BłądArności() {
        super("Nieprawidłowa liczba argumentów.");
    }
}
