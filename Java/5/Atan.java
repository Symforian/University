package narzedzia;
/**	Funkcja arcustangens
*/
public class Atan extends Funkcja{
	double arg;
	int args = 1;

	public int arność()
	{
		return 1;
	}

	public int brakująceArgumenty()
	{
		return args;
	}

	public String toString()
  	{
		return "atan";
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

	public double obliczWartość() throws WyjątekONP
	{
		logger.info("Obliczanie "+toString());
		if(brakująceArgumenty() > 0)
			throw new ONP_BłądArności();
		return Math.atan(arg);
	}
}
