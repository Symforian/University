package narzedzia;
/** Klasa zmiennej w ONP 
 */
public class Zmienna extends Operand implements Obliczalny {

//"\\p{Alpha} a-z, A-Z \\p{Alnum}*"  a-z A-Z, 0 - 9 * 
	//static Pattern P = Pattern.compile("\\p{Alpha}\\p{Alnum}*");
	private String NazwaZmiennej;
	private double Wartość;
	public Zmienna(String Nazwa) throws WyjątekONP
	{
	if(Nazwa.equals("E") || Nazwa.equals("Pi") )
		throw new ONP_ZarezerwowanySymbol("Pi, E są zarezerwowane dla stałych matematycznych");
		NazwaZmiennej = Nazwa;
		Wartość = 0;
	}

	public void ustalWartość (double wart)
	{
		Wartość = wart;
	}
	public double obliczWartość () throws WyjątekONP
	{
		return Wartość;
	}
	public String nazwa()
	{
		return NazwaZmiennej;
	}
	public boolean equals(Object obj)
	{
	if (this == obj)
		return true;
	if (obj == null)
		return false;
	if (getClass() != obj.getClass())
	      return false;
	Zmienna z = (Zmienna) obj;
	if(nazwa().matches(z.nazwa()))
		return true;
	return false;
	}
	//public void usuń(Zmienna a){
	//}
}
