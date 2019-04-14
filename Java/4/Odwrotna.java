package Wyrazenia;

/**
 * Wyrażenie jednoargumentowe odwrotność.
 */
public class Odwrotna extends Operator1Arg
{
	public Odwrotna (Wyrazenie a1) throws IllegalArgumentException {
		super(a1);
		if (a1.oblicz()==0) 
			throw new IllegalArgumentException();
	}
	/**Oblicza wartość wyrażenia.
	 * @return Zwraca odwrotność arg1.
	*/
	public double oblicz () {
		return 1/arg1.oblicz();
	}
	/**
	 * Wypisuje wyrażenie.
	 * @return Zwraca String, który opisuje to wyrażenie.
	*/
	public String toString () {
		return "odwr("+arg1+")";
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

