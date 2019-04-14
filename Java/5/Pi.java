package narzedzia;
/**	Stała matematyczna Pi
*/
public class Pi extends Funkcja{


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
		return "pi";
  	}

	public void dodajArgument (double a) throws WyjątekONP
	{

	}

	public double obliczWartość() throws WyjątekONP
	{

		return Math.PI;
	}
}
