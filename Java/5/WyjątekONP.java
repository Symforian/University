
package narzedzia;
class WyjątekONP extends Exception {

    public WyjątekONP(String message) {
        super("Wyjątek ONP "+ message);
    }
}
