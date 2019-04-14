package narzedzia;
/**  Klasa funkcji w ONP 
 */
public abstract class Funkcja extends Symbol implements Funkcyjny
{
	/**	Metoda obliczająca wartość odpowiedniej funkcji
		@return wartość funkcji
	*/
	public double obliczWartość() throws WyjątekONP
	{
		return this.obliczWartość();
	}
	/**	@return Arność funkcji
	*/
	public int arność ()
	{
		return this.arność();
	}
	/**	@return Brakujące argumenty funkcji
	*/
	public int brakujaceArgumenty ()
	{
		return this.brakująceArgumenty();
	}
	/**	Dodaje argument do funkcji
		@param a Argument dodawany do funkcji
	*/
	public void dodajArgument (double a) throws WyjątekONP
	{
		this.dodajArgument(a);
	}

}
