package narzedzia;
/**	Funkcja część ułamkowa
*/
public class Frac extends Funkcja{
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
		return "frac";
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
				//{logger.warning("Błąd arności");
				throw new ONP_BłądArności();//}
		if(arg>0)
			return arg-Math.floor(arg);
		if(arg<0)
			return Math.ceil(arg) - arg;
		else 
		return 0;
	}
}
