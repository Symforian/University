package Wyrazenia;

import static java.lang.Math.*;
/**
 * Wyrażenie jednoargumentowe cosinus.
 */
public class Cosinus extends Operator1Arg
{
	public Cosinus (Wyrazenie a1) {
		super(a1);
	}
	/** Zwraca wartość wyrażenia.
	 * @return Zwraca wynik funkcji cos z Math dla wyrażenia.
	*/
	public double oblicz () {
		return cos(arg1.oblicz());
	}
	/**
	 * Wypisuje wyrażenie.
	 * @return Zwraca String, który opisuje to wyrażenie.
	*/
	public String toString () {
		return "cos("+arg1+")";
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

