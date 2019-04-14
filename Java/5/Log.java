package narzedzia;
/**	Funkcja logarytm
*/
public class Log extends Funkcja{
	double arg1; //baza 
	double arg2; //wykl?
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
		return "log";
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
		if(arg2!=1)
			return Math.log(arg2) / Math.log(arg1);
		else 
		throw new ONP_DzieleniePrzez0();
	}
}
