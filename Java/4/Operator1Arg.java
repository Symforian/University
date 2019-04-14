package Wyrazenia;
/**
 * Wyrażenie jednoargumentowe.
 */
public abstract class Operator1Arg extends Wyrazenie
{
	/**
	* Pierwszy argument wyrażenia.
	*/
    	protected final Wyrazenie arg1;

    	public Operator1Arg (Wyrazenie a1) {
       		 if (a1==null) 
			throw new IllegalArgumentException();
   	     arg1 = a1;
  	}
}

