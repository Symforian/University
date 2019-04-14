package Wyrazenia;

/**
 * Wyrażenie dwuargumentowe dzielenia.
 */
public class Podziel extends Operator2Arg
{
	public Podziel (Wyrazenie a1, Wyrazenie a2) throws IllegalArgumentException{
		super(a1,a2);
		if (a2.oblicz()==0) 
			throw new IllegalArgumentException();
	}
	/**Oblicza wartość wyrażenia.
	 * @return Zwraca iloraz arg1 przez arg2.
	*/
	public double oblicz () {
		return arg1.oblicz()/arg2.oblicz();
	}
	/**
	 * Wypisuje wyrażenie.
	 * @return Zwraca String, który opisuje to wyrażenie.
	*/
	public String toString () {
		return "("+arg1+" / "+arg2+")";
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

