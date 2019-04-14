package narzedzia;
/**	Funkcja logarytm naturalny
*/
public class Ln extends Funkcja{
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
		return "ln";
  	}

	public void dodajArgument (double a) throws WyjątekONP
	{
		logger.info("Obliczanie "+toString());
		if(brakująceArgumenty() == 1)
		{
			arg = a;
			args--;
    		}
	}

	public double obliczWartość() throws WyjątekONP
	{
		if(brakująceArgumenty() > 0)
			throw new ONP_BłądArności();
		return Math.log(arg);
	}
}
