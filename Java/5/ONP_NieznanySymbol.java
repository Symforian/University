
package narzedzia;
class ONP_NieznanySymbol extends WyjątekONP {/*...*/

    public ONP_NieznanySymbol(String message) {
        super("Nieznany symbol. "+ message);
    }
    public ONP_NieznanySymbol()
	{
		super("Nieznany symbol.");
	}
}
