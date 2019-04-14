
package geometria;
import java.lang.Math.*;

	public class Punkt implements Przeksztalcenia
	{
	
		private double x,y;

			
		public Punkt(double a, double b)
		{
			x = a;
			y = b;
		}
		public void przesun(Wektor v)
		{
			x += v.dx;
			y += v.dy;
		}
		public void odbij(Prosta p) throws PunktPrzecieciaRownoleglych
		{
			double a,b,c;
			a = -p.B;
			b = p.A;
			c = -1* (a*x+b*y);
			Prosta l = new Prosta(a,b,c);

			if(Prosta.czyRownolegle(p,l))
				throw new PunktPrzecieciaRownoleglych("Brak punktu przeciecia prostych rownoleglych");
			else
			{
			Punkt s = Prosta.punktPrzeciecia(p,l);
			Wektor v = new Wektor(s.x-x,s.y-y);
			s.przesun(v);
			x=s.x;
			y=s.y;
			}

		}
		public void obroc(Punkt p, double kat)
		{
			
			kat = kat % 360;
			kat = Math.toRadians(kat);
			double x1;
			x1 = (x - p.x)*Math.cos(kat) - (y- p.y)* Math.sin(kat) + p.x;
			double y1;
			y1 = (x - p.x)*Math.sin(kat) + (y- p.y)* Math.cos(kat) + p.y;
			x = x1;
			y = y1;
		}
		public static boolean czyRozne(Punkt a, Punkt b)
		{
			if(a.x == b.x && a.y == b.y)
				return false;
			else
				return true;
		}
		public double odleglosc(Punkt a)
		{
			return Math.sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));
		}
		public String toString()
		{
			return "x="+x+", y ="+y;
		}
		
	}

