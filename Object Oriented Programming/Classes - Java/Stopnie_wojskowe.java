
public abstract class Stopnie_wojskowe implements Comparable<Stopnie_wojskowe>
{
	public String Imie_nazwisko;
	protected String stopien;
	
	public abstract int Wartosc_stopnia();
	
	public int compareTo(Stopnie_wojskowe Soldier_value)
	{
		if(Soldier_value.Wartosc_stopnia() == this.Wartosc_stopnia()) return 0;
		else if(Soldier_value.Wartosc_stopnia() > this.Wartosc_stopnia()) return 1;
		else return -1;
	}
	
	public String toString() {
        return  stopien + " " + Imie_nazwisko + "\n";
    }
}
