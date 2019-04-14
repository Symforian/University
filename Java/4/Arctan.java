
package Wyrazenia;


import static java.lang.Math.*;
/**
 * Wyrażenie jednoargumentowe arcustangens.
 */
public class Arctan extends Operator1Arg
{
	public Arctan (Wyrazenie a1) {
		super(a1);
	}
	/** Zwraca wartość wyrażenia.
	 * @return Zwraca wynik funkcji atan z Math dla wyrażenia.
	*/
	public double oblicz () {
		return atan(arg1.oblicz());
	}
	/**
	 * Wypisuje wyrażenie.
	 * @return Zwraca String, który opisuje to wyrażenie.
	*/
	public String toString () {
		return "arctan("+arg1+")";
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

