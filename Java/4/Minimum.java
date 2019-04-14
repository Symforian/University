package Wyrazenia;

import static java.lang.Math.*;
/**
 * Wyrażenie dwuargumentowe minimum.
 */
public class Minimum extends Operator2Arg
{
	public Minimum (Wyrazenie a1, Wyrazenie a2) {
		super(a1,a2);
	}
	/**Oblicza wartość wyrażenia.
	 * @return Zwraca wynik funkcji min z Math dla argumentów arg1,arg2 wyrażenia.
	*/
	public double oblicz () {
		return min(arg1.oblicz(),arg2.oblicz());
	}
	/**
	 * Wypisuje wyrażenie.
	 * @return Zwraca String, który opisuje to wyrażenie.
	*/
	public String toString () {
		return "min("+arg1+" , "+arg2+")";
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

