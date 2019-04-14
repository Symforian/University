package Wyrazenia;
/**
 * Para (klucz, wartość).
 */
public class Para {

	public final String klucz;
	private double wartość;
	public Para()
	{
		wartość = 0;
		klucz = "";
	}
	public Para(double value, String key)
	{
		wartość = value;
		klucz = key;
	}
	/**
	 * Wypisuje parę.
	 * @return Zwraca String, który zawiera wartość i klucz.
	*/
	public String toString()
	{
		return "Wartość = "+wartość+" Klucz = "+klucz;
	}
	/**
	 * Porównuje dwie pary.
	 * @return true gdy pary mają taki sam klucz false w przeciwnym wypadku.
	*/
	public boolean equals(Object b)
	{
		if(this.getClass() == b.getClass())
			if( klucz.equals(((Para)b).klucz))
				return true;
		return false;
	}
	public double getWartość()
	{
		return wartość;
	}
	public void setWartość(double x)
	{
		wartość = x;
	}
	
}
