


public class Rozklad
{
    public static void main (String[] args)
    {
		if(args.length==0)
			System.err.println("Błąd! Wywołano program bez parametru.");
	long[] rozklad; 
	for(int i=0; i< args.length; i++)
        	{
			//LiczbyPierwsze A= new LiczbyPierwsze();
			//System.out.println(LiczbyPierwsze.czyPierwsza(Long.valueOf(args[i])));
			rozklad = LiczbyPierwsze.naCzynnikiPierwsze(Long.valueOf(args[i]));
			System.out.print(Long.valueOf(args[i])+" = ");
			for(int j=0; j< rozklad.length; j++)
			{
				System.out.print(rozklad[j]);
				if((j+1)<rozklad.length)
					{
						if(rozklad[j+1]==0)
							break;
						System.out.print("*");
					}
			}
			System.out.println();
		}
	//for(int i=0; i<=20; i++)
		//	System.out.println(((i*2)+1)+"\t"+LiczbyPierwsze.SITO[i]);
	

    }
}
