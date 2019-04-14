package narzedzia;
/**	Funkcja znak
*/
public class Sgn extends Funkcja{
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
		return "sgn";
  	}

	public void dodajArgument (double a) throws WyjątekONP
	{
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
		if(arg<0)
			return -1;
		return 1;
	}
}
