package Wyrazenia;
/**
 * Zmienna.
 */
public class Zmienna  extends Wyrazenie{


	private String nazwa;
	public static final Zbior zmienne;

	static
	{
		zmienne = new Zbior();
	}

	public Zmienna( String n)
	{
		zmienne.sprawdzPojemnosc();
		zmienne.wstaw(new Para(0,n));
		nazwa = n;
	}

	public Zmienna( String n, double x)
	{
		zmienne.sprawdzPojemnosc();
		zmienne.wstaw(new Para(x,n));
		nazwa = n;
	}

	public Zmienna( String n, double x, int rozmiar)
	{
		zmienne.sprawdzPojemnosc();
		zmienne.wstaw(new Para(x,n));
		nazwa = n;
	}
	/**Zwraca wartość zmiennej
	 * @return Wartość zmiennej.
	*/
	public double oblicz() throws IllegalArgumentException
	{
		return zmienne.czytaj(nazwa);
	}
	/**
	 * Wypisuje nazwę zmiennej.
	 * @return Zwraca nazwę zmiennej.
	*/
	public String toString()
	{
		return nazwa;
	}
	/**
	 * Porównuje wartość dwóch wyrażeń.
	 * @return true gdy wyrażenia mają taką samą wartość false w przeciwnym wypadku.
	*/
	public boolean equals(Object a2)
	{

		if(this.oblicz()==((Wyrazenie)a2).oblicz())
			return true;
		else
			return false;

	}
}

