package Wyrazenia;

/**
 * Wyrażenie dwuargumentowe odejmij.
 */
public class Odejmij extends Operator2Arg
{
	public Odejmij (Wyrazenie a1, Wyrazenie a2) {
		super(a1,a2);
	}
	/**Oblicza wartość wyrażenia.
	 * @return Zwraca różnicę arg1 i arg2.
	*/
	public double oblicz () {
		return arg1.oblicz()-arg2.oblicz();
	}
	/**
	 * Wypisuje wyrażenie.
	 * @return Zwraca String, który opisuje to wyrażenie.
	*/
	public String toString () {
		return "("+arg1+" - "+arg2+")";
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

