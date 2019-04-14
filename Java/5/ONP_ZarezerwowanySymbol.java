
package narzedzia;
class ONP_ZarezerwowanySymbol extends WyjątekONP {/*...*/

    public ONP_ZarezerwowanySymbol(String message) {
        super("Błąd. "+ message);
    }
    public ONP_ZarezerwowanySymbol() {
        super("Symbol zarezerwowany.");
    }
}
