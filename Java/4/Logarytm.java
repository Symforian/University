package Wyrazenia;

import static java.lang.Math.*;
/**
 * Wyrażenie dwuargumentowy logarytm.
 */
public class Logarytm extends Operator2Arg
{
	public Logarytm (Wyrazenie a1, Wyrazenie a2){
		super(a1,a2);
		
	}
	/** Oblicza wartość wyrażenia.
	 * Zamienia log o podstawie a z b na ln z b / ln z a.
	 * @return Zwraca wynik funkcji log z Math dla wyrażenia.
	*/
	public double oblicz ()  throws IllegalArgumentException{
		if(arg1.oblicz()==1)
			throw new IllegalArgumentException("Preventing division by 0");
		return log(arg2.oblicz())/log(arg1.oblicz());
	}
	/**
	 * Wypisuje wyrażenie.
	 * @return Zwraca String, który opisuje to wyrażenie.
	*/
	public String toString () {
		return "log("+arg1+" , "+arg2+")";
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

