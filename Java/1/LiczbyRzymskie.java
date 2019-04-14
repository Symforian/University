//288477
//opcje kompilacji:
//-encoding utf8


public class LiczbyRzymskie
{
// tablica z wybranymi liczbami rzymskimi
	private static String[] rzymskie = 
		{"M", "CM", "D", "CD", "C","XC", "L", "XL", "X", "IX", "V", "IV", "I"};
// tablica z wybranymi liczbami arabskimi
	private static int[] arabskie = 
		{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    public static void main (String[] args)
    {
	int x;
	String napis;
	for (int i=0; i<args.length; i++)
		{
			try
			{x = new Integer(args[i]);
			if(x<1 || x>4999)
			throw new IllegalArgumentException("liczba " + x + " spoza zakresu 1-4999");
			napis = arabNaRzym(x);
}
			catch (NumberFormatException e)
			{
				System.out.println("Nie można przeprowadzić konwersji.");
				napis = "Bład konwersji";
				
			}

			System.out.println(args[i]+" "+napis);
		}
	
    }

   public static String arabNaRzym(int liczba)
	{
		String rzymska="";
		for(int k=0; k < 13 ; k++)
			{
				while(liczba>=arabskie[k])
				{
					rzymska+=rzymskie[k];
					liczba-=arabskie[k];
				}
			}
		return rzymska;
	}
}

