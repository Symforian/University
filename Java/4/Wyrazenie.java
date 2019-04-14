/**
 * Klasa wyrażenia.
 * @author Adrian Kamiński
 */
package Wyrazenia;
/**
 * Wyrażenie.
 */
public abstract class Wyrazenie {
	// ...
	public abstract double oblicz();
	/** metoda sumująca wyrażenia 
	 * @param wyr 	wyrażenia do dodania.
	 * @return Zwraca sumę wyrażeń.	
	*/
	public static double sumuj (Wyrazenie... wyr) {
	double sum = 0;
	for(int i=0; i<wyr.length; i++)
		sum += wyr[i].oblicz();
	return sum;
	}
	
	/** metoda mnożąca wyrażenia 
	 * @param wyr 	wyrażenia do pomnożenia.
	 * @return Zwraca iloczyn wyrażeń.	
	*/
	public static double pomnoz (Wyrazenie... wyr) {
	double ilo = 1;
	for(int i=0; i<wyr.length; i++)
		ilo *= wyr[i].oblicz();
	return ilo;
	}


}

