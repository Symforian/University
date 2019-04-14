package Wyrazenia;
/**
 * Liczba
 */
public class Liczba  extends Wyrazenie{
	// ...
	protected final double wartość;
	public Liczba( double a)
	{
		wartość = a;
	}
	/**Zwraca wartość liczby.
	* @return Wartość liczby.
	*/
	public double oblicz()
	{
		return wartość;
	}
	/**
	 * Wypisuje wartość.
	 * @return Zwraca wartość liczby.
	*/
  	public String toString () {
		return String.valueOf(wartość);
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

