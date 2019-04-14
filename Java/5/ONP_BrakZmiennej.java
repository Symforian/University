
package narzedzia;
class ONP_BrakZmiennej extends WyjątekONP {/*...*/

    public ONP_BrakZmiennej(String message) {
        super("Brak zmiennej. "+ message);
	}
    public ONP_BrakZmiennej() {
        super("Brak zmiennej.");
    }
    
}
