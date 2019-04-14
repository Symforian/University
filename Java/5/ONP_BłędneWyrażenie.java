
package narzedzia;
class ONP_BłędneWyrażenie extends WyjątekONP {/*...*/

    public ONP_BłędneWyrażenie(String message) {
        super("Błędne wyrażenie. "+ message);
	}
    public ONP_BłędneWyrażenie() {
        super("Błędne wyrażenie.");
    }
    
}
