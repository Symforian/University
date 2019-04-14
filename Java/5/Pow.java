package narzedzia;
/**	Funkcja potęgowa
*/
public class Pow extends Funkcja{
	double arg1; //baza
	double arg2; //wykladnik
	int args = 2;

	public int arność()
	{
		return 2;
	}

	public int brakująceArgumenty()
	{
		return args;
	}

	public String toString()
  	{
		return "pow";
  	}

	public void dodajArgument (double a) throws WyjątekONP
	{
		if(brakująceArgumenty() == 2)
		{
			arg1 = a;
			args--;
    		}
		else
		if(brakująceArgumenty() == 1)
		{
			arg2 = a;
			args--;
    		}
	}

	public double obliczWartość() throws WyjątekONP
	{
		logger.info("Obliczanie "+toString());
		if(brakująceArgumenty() > 0)
			throw new ONP_BłądArności();
		return Math.pow(arg1,arg2);
	}
}
