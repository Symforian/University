
package narzedzia;
class ONP_PustaKolejka extends WyjątekONP {/*...*/

    public ONP_PustaKolejka(String message) {
        super("Pusta kolejka. "+ message);
    }
    public ONP_PustaKolejka() {
        super("Pusta kolejka.");
    }
}
