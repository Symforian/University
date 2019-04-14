
package narzedzia;
class Wyrażenie
{
	private Kolejka<Symbol>  kolejka; // kolejka symboli (elementy typu Symbol)
	private Stos<Double> stos; // stos z wynikami pośrednimi (elementy typu double)
	private Lista<Zmienna>  zmienne; // lista zmiennych (pary String-double)
	public Wyrażenie (String onp, Lista<Zmienna> zm) throws WyjątekONP {
	String[] rozbiór = onp.trim().split("\\s+");
	kolejka = new Kolejka<Symbol>();
	stos = new Stos<Double>();
	zmienne = zm;
	wpisz(rozbiór);
}
	private void wpisz(String[] rozbiór) throws WyjątekONP
{

    for(int i = 1; i < rozbiór.length; i++)
    {
        if(rozbiór[i].matches("[-+]?\\d*\\.?\\d+") && !rozbiór[i].isEmpty())
		kolejka.dodaj(new Liczba(Double.parseDouble(rozbiór[i])));

        else if(rozbiór[i].equals("+"))
		kolejka.dodaj(new Add());

        else if(rozbiór[i].equals("-"))
		kolejka.dodaj(new Sub());

        else if(rozbiór[i].equals("/"))
		kolejka.dodaj(new Div());

        else if(rozbiór[i].equals("*"))
		kolejka.dodaj(new Mul());

        else if(rozbiór[i].equals("max"))
		kolejka.dodaj(new Max());

        else if(rozbiór[i].equals("min"))
		kolejka.dodaj(new Min());

        else if(rozbiór[i].equals("log"))
		kolejka.dodaj(new Log());

        else if(rozbiór[i].equals("pow"))
		kolejka.dodaj(new Pow());

        else if(rozbiór[i].equals("abs"))
		kolejka.dodaj(new Abs());

        else if(rozbiór[i].equals("sgn"))
		kolejka.dodaj(new Sgn());

        else if(rozbiór[i].equals("floor"))
		kolejka.dodaj(new Floor());

        else if(rozbiór[i].equals("ceil"))
		kolejka.dodaj(new Ceil());

        else if(rozbiór[i].equals("frac"))
		kolejka.dodaj(new Frac());

        else if(rozbiór[i].equals("sin"))
		kolejka.dodaj(new Sin());

        else if(rozbiór[i].equals("cos"))
		kolejka.dodaj(new Cos());

        else if(rozbiór[i].equals("acot"))
		kolejka.dodaj(new Acot());

        else if(rozbiór[i].equals("atan"))
		kolejka.dodaj(new Atan());

        else if(rozbiór[i].equals("ln"))
         	kolejka.dodaj(new Ln());

        else if(rozbiór[i].equals("exp"))
         	kolejka.dodaj(new Exp());

	else if(rozbiór[i].matches("pi"))
		kolejka.dodaj(new Pi());

	else if(rozbiór[i].matches("e"))
		kolejka.dodaj(new E());

        else if(rozbiór[i].matches("\\p{Alpha}\\p{Alnum}*"))
		kolejka.dodaj(new Zmienna(rozbiór[i]));
        else
          throw new ONP_NieznanySymbol(rozbiór[i]);
    }
  }
  public double oblicz() throws WyjątekONP
  {
	int size = kolejka.rozmiar();
	for(int i = 0; i < size; i++)
	{
		Symbol s = kolejka.usuń();

	if(s.getClass() == Liczba.class)
	{
		stos.dodaj(((Liczba)s).obliczWartość());
	}

	else if(s.getClass() == Zmienna.class)
	{
		Zmienna r = (Zmienna) s;
		try
		{
		r = zmienne.znajdź(r);
		stos.dodaj(r.obliczWartość());
		}
		catch(WyjątekONP e)
		{
			System.out.println("Nie znalezionio zmiennej " + r.nazwa());
		}
	}

	else
	{
	Funkcja f = (Funkcja) s;
        if (f.arność() > stos.rozmiar())
		throw new ONP_BłądArności("Funkcja "+f.toString() + " nie otrzymała wszystkich argumentów");

	while(f.brakująceArgumenty() > 0)
        {
		f.dodajArgument(stos.usuń());
        }
	stos.dodaj(f.obliczWartość());
      }
    }
	if(stos.rozmiar() > 1)
		throw new ONP_BłędneWyrażenie("Na stosie pozostały wartości.");
	return stos.usuń();
  }
}

