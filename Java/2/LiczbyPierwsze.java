

public final class LiczbyPierwsze
{
	private LiczbyPierwsze(){};

	private final static int POTEGA2 = 21 ;

	private final static int[] SITO = new int[1<<POTEGA2] ;
	// ... potrzebny jest blok inicjalizacyjny dla sita ...
	static
	{

		int k=0;	
		SITO[0]=2;
		SITO[1]=3;
		SITO[2]=5;

		for(int i=3; i<=(1<<POTEGA2)-1;i++)
		{	
			k=0;
			for(; SITO[k]*SITO[k]<=((i*2)+1);k++)
			{
				if(((i*2)+1)%SITO[k]==0)
						break;
			}

			if(SITO[k]*SITO[k]>((i*2)+1))
				SITO[i]=((i*2)+1);
			else
				SITO[i]=SITO[k];

		}
	}
	public static boolean czyPierwsza (long x)
	{ 
		//((1<<POTEGA2)-1)*2+1
		// jesli nie jest w sicie
		if(x>(((1<<(POTEGA2+1))-1)))
		{
			//czy ma dzielniki w sicie
			for(long i=0; i<=(1<<POTEGA2)-1; i++)
			{
				if(x%SITO[Math.toIntExact(i)]==0)
					return false;
					
			}
			//czy ma dzielniki poza sitem
			for(long i=(((1<<(POTEGA2+1))+1)); i*i<= x; i+=2)
			{

				if(x%i==0)
					return false;
				//czy nie wyjdziemy poza zakres long w kolejnym kroku 
				if( i+2>=Math.floor(Math.sqrt(Long.MAX_VALUE)))
					return true;
			}
		}
		// jesli jest w sicie
		else if(x<=(((1<<(POTEGA2+1))-1)) && x>=2)
			{
				if(x==SITO[Math.toIntExact(((x-1)/2))])
					return true;
				else
					return false;
			}
		else if(x == 1 || x== -1 || x==0)
			return false;
		// jesli jest long min
		else if(x==-x)
			return false;
		else if(x<0)
		return czyPierwsza(-x);

		return true;
	}

	public static long[] naCzynnikiPierwsze (long x)
	{ 


		if(x == 1 || x== -1 || x==0)
			return new long[] {x};

		int indeks=0;
		long [] rozklad= new long[66];

		if(x<0)
		{

			x=-x;
			rozklad[indeks]=-1;
			indeks++;
			//jesli jest long min
			if(x<0 && x%2==0)
			{
				rozklad[indeks]=2;
				indeks++;
				x/=-2;	
			}
		}
		/*if(x%2==0)
		{
			rozklad[indeks]=2;
			x/=rozklad[indeks];
			indeks++;
		}*/
		if(czyPierwsza(x))
		{
			rozklad[indeks]=x;
			x=1;
		}
		while(x!=1)
		{
			
			if(x%2==0)
			{
				rozklad[indeks]=2;
				x/=rozklad[indeks];
				indeks++;
			}
			else if(x<(((1<<(POTEGA2+1))-1)))
			{
				rozklad[indeks]=SITO[Math.toIntExact(((x-1)/2))];
				x/=rozklad[indeks];
				indeks++;
			}
			else
			{
				long k=3;
				for(;k<((1<<POTEGA2)-1);k++)
				{
					if(x%SITO[Math.toIntExact(k)]==0)
						break;
				}
				if(k==((1<<POTEGA2)-1))
				{
					k=((1<<(POTEGA2+1))-1);
					while(x%k!=0 && k<Math.floor(Math.sqrt(Long.MAX_VALUE)) && k*k<=x)
						k+=2;
				}
				if(k<((1<<POTEGA2)-1) && x%SITO[Math.toIntExact(k)]==0)
				{
					rozklad[indeks]=SITO[Math.toIntExact(k)];
					x/=rozklad[indeks];
					indeks++;
				}
				else if(x%k==0)
				{
					rozklad[indeks]=k;
					x/=rozklad[indeks];
					indeks++;
				}
				else	
				{
					rozklad[indeks]=x;
					x=1;
				}
			}
			

		}
		return rozklad;

	}
}
//-9223372036854775808
//9223372036854775783
