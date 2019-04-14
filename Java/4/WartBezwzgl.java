package Wyrazenia;

import static java.lang.Math.*;
/**
 * Wyrażenie jednoargumentowe wartość bezwzględna.
 */
public class WartBezwzgl extends Operator1Arg
{
	public WartBezwzgl (Wyrazenie a1) {
		super(a1);
	}
	/**Oblicza wartość wyrażenia.
	 * @return Zwraca wynik funkcji abs z Math dla wyrażenia.
	*/
	public double oblicz () {
        	return abs(arg1.oblicz());
    	}
	/**
	 * Wypisuje wyrażenie.
	 * @return Zwraca String, który opisuje to wyrażenie.
	*/
    	public String toString () {
        	return "|"+arg1+"|";
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

