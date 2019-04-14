package narzedzia;
/** Klasa liczby w ONP 
 */
public class Liczba extends Operand implements Obliczalny {

	double Wartość;
	public Liczba()
	{
		Wartość = 0;
	}
	public Liczba(double W)
	{	
		
		Wartość = W;
	}

	public double obliczWartość () throws WyjątekONP
	{
		//logger.info("Zwracanie wartości liczby ");
		return Wartość;
	}
	public String toString()
	{
		return String.valueOf(Wartość);
	}
}
