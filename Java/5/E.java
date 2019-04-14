package narzedzia;
/**	Stała matematyczna E
*/

public class E extends Funkcja{


	public int arność()
	{
		return 0;
	}

	public int brakująceArgumenty()
	{
		return 0;
	}

	public String toString()
  	{
		return "e";
  	}

	public void dodajArgument (double a) throws WyjątekONP
	{

	}

	public double obliczWartość() throws WyjątekONP
	{
		logger.info("Obliczanie "+toString());
		return Math.E;
	}
}
