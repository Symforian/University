

public class Szeregowy extends Stopnie_wojskowe{
	public Szeregowy(String Tozsamosc)
		{
			this.Imie_nazwisko = Tozsamosc;
			this.stopien = "Szeregowy";
		}
	public int Wartosc_stopnia()
		{
			return 1;
		}

}
