package narzedzia;
/** Klasa obliczająca wartość bezwzględną funkcji
 */
public class Abs extends Funkcja implements Funkcyjny{
	double arg;
	private int args = 1;

	public int arność ()
	{
		return 1;
	}
	public int brakująceArgumenty ()
	{
		return args;
	}
	public double obliczWartość () throws WyjątekONP
	{
		logger.info("Obliczanie "+toString());
		if(brakująceArgumenty() > 0)
			throw new ONP_BłądArności();
		if(arg >= 0)
			return arg;
		return -arg;
	}
	public void dodajArgument (double a) throws WyjątekONP
	{
		//logger.info("Dodawanie argumentów");
		if(brakująceArgumenty() == 1)
		{
			arg = a;
			args--;
		}
	}
	public String toString()
	{
		return "abs";
	}
}
