package geometria;


public class Main {

    public static void main(String[] args) {
		Punkt A = new Punkt (1,1);
		Punkt B = new Punkt (0,4);
		Punkt C = new Punkt (4,0);
		trzyPunktyCzyMoznaOdcinkiCzyMoznaTrojkat(A,B,C);
		obrotPunktu(new Punkt (1,1), new Punkt(0,0),180);
		obrotyOdcinkowTrojkata(A,B,C,new Punkt(0,0),90);
		testWektorow(new Wektor(1,0),new Wektor(-10,1));
		testyProstych(new Prosta(3,4,0),new Prosta(1,1,-2)); //rownolegle 1,0,0 2,0,-2 prostopadle 0,2,0 2,0,-2
		A = new Punkt (1,1);
		B = new Punkt (0,4);
		C = new Punkt (4,0);
		testPrzesuniec(A,B,C,new Prosta(1,1,1),new Wektor(1,3));
		testOdbic(A,B,C,new Prosta(1,0,1));

    }



	public static void trzyPunktyCzyMoznaOdcinkiCzyMoznaTrojkat(Punkt A, Punkt B, Punkt C)
	{
		System.out.println("-----------Test czy mozna zbudowac:\n");
		System.out.println("A = "+A.toString());
		System.out.println("B = "+B.toString());
		System.out.println("C = "+C.toString());
		System.out.println();
		try{
		Odcinek AB = new Odcinek (A,B);
		System.out.println("AB = "+AB.toString());
		}
		catch(IllegalArgumentException e)
		{
			System.out.println("Nie mozna zbudowac odcinka z podanych punktow A i B");
		}
		try{
		Odcinek AC = new Odcinek (A,C);
		System.out.println("AC = "+AC.toString());
		}
		catch(IllegalArgumentException e)
		{
			System.out.println("Nie mozna zbudowac odcinka z podanych punktow A i C");
		}
		try{
		Odcinek CB = new Odcinek (C,B);
		System.out.println("CB = "+CB.toString());
		}
		catch(IllegalArgumentException e)
		{
			System.out.println("Nie mozna zbudowac odcinka z podanych punktow C i B");
		}
		System.out.println();
		try{
		Trojkat ABC = new Trojkat(A,B,C);
		System.out.println("ABC = "+ABC.toString());
		}
		catch(IllegalArgumentException e)
		{
			System.out.println("Nie mozna zbudowac trojkata z podanych punktow A B i C");
		}
		catch(PunktPrzecieciaRownoleglych e)
		{
			System.out.println("Nie mozna znalezc punktu przeciecia");
		}
	}
	public static void obrotPunktu(Punkt Obr, Punkt O, double Ok)
	{
		System.out.println("-----------Test obrotow punktow:");
		System.out.println("Przed obroceniem "+Obr.toString());
		System.out.println();
		Obr.obroc(O,Ok);
		System.out.println("Po obroceniu "+Obr.toString());
		Obr.obroc(O,-Ok);
		System.out.println();
		System.out.println("Po obroceniu o ten sam kat ze zmienionym znakiem  "+Obr.toString());
	}
	public static void obrotyOdcinkowTrojkata(Punkt A, Punkt B, Punkt C, Punkt O, double kat)
	{
		System.out.println("-----------Testy obrotow odcinkow, trojkata:");
		System.out.println();
		try{
		Odcinek AB = new Odcinek (A,B);
		AB.obroc(O,kat);
		System.out.println("AB = "+AB.toString());
		}
		catch(IllegalArgumentException e)
		{
			System.out.println("Nie mozna zbudowac odcinka z podanych punktow A i B");
		}
		try{
		Odcinek AC = new Odcinek (A,C);
		AC.obroc(O,kat);
		System.out.println("AC = "+AC.toString());
		}
		catch(IllegalArgumentException e)
		{
			System.out.println("Nie mozna zbudowac odcinka z podanych punktow A i C");
		}
		try{
		Odcinek CB = new Odcinek (C,B);
		CB.obroc(O,kat);
		System.out.println("CB = "+CB.toString());
		}
		catch(IllegalArgumentException e)
		{
			System.out.println("Nie mozna zbudowac odcinka z podanych punktow C i B");
		}
		System.out.println();
		try{
		Trojkat ABC = new Trojkat(A,B,C);
		ABC.obroc(O,kat);
		System.out.println("ABC = "+ABC.toString());
		}
		catch(IllegalArgumentException e)
		{
			System.out.println("Nie mozna zbudowac trojkata z podanych punktow A B i C");
		}
		catch(PunktPrzecieciaRownoleglych e)
		{
			System.out.println("Nie mozna znalezc punktu przeciecia");
		}
	}
	public static void testWektorow(Wektor v, Wektor u)
	{
		System.out.println("-----------Test skladania wektorow");
		System.out.println("v = "+v.toString());
		System.out.println("u = "+u.toString());
		Wektor vu = Wektor.zlozDwaWektory(v,u);
		System.out.println("vu = "+vu.toString());

	}
	public static void testyProstych(Prosta p, Prosta l)
	{
		System.out.println("-----------Test prostych");
		System.out.println(p.toString());
		System.out.println(l.toString());
		System.out.println("Czy prostopadle?");
		System.out.println(Prosta.czyProstopadle(p,l));
		System.out.println("Czy rownolegle?");
		System.out.println(Prosta.czyRownolegle(p,l));
		System.out.println("Punkt przeciecia:");
		try{
		System.out.println(Prosta.punktPrzeciecia(p,l));}
		catch(PunktPrzecieciaRownoleglych e)
		{
			System.out.println("Brak punktu przeciecia rownoleglych prostych");
		}
	}
	public static void testPrzesuniec(Punkt A, Punkt B, Punkt C, Prosta p, Wektor v)
	{
		System.out.println("-----------Test przesuniec:");
		System.out.println("A = "+A.toString());
		System.out.println("B = "+B.toString());
		System.out.println("C = "+C.toString());
		System.out.println("v = "+v.toString());
		A.przesun(v);
		System.out.println("A' = "+A.toString());
		Odcinek BC = new Odcinek(B,C);
		System.out.println("BC = "+BC.toString());
		BC.przesun(v);
		System.out.println("BC' = "+BC.toString());
		try{
		Trojkat ABC = new Trojkat(A,B,C);
		System.out.println("ABC = "+ABC.toString());
		ABC.przesun(v);
		System.out.println("ABC' = "+ABC.toString());
		}
		catch(IllegalArgumentException e)
		{
			System.out.println("Nie mozna zbudowac trojkata z podanych punktow A B i C");
		}
		catch(PunktPrzecieciaRownoleglych e)
		{
			System.out.println("Nie mozna znalezc punktu przeciecia");
		}
		System.out.println("p := "+p.toString());
		System.out.println("p' := "+Prosta.przesun(p,v).toString());
	}
	public static void testOdbic(Punkt A, Punkt B, Punkt C, Prosta p)
	{
		System.out.println("-----------Test odbic:");
		System.out.println("A = "+A.toString());
		System.out.println("B = "+B.toString());
		System.out.println("C = "+C.toString());
		System.out.println("p = "+p.toString());
		try {
		A.odbij(p);
		}
		catch(PunktPrzecieciaRownoleglych e)
		{
			System.out.println("Nie mozna znalezc punktu przeciecia");
		}

		System.out.println("A' = "+A.toString());
		Odcinek BC = new Odcinek(B,C);
		System.out.println("BC = "+BC.toString());
		try {
		BC.odbij(p);
		}
		catch(PunktPrzecieciaRownoleglych e)
		{
			System.out.println("Nie mozna znalezc punktu przeciecia");
		}
		System.out.println("BC' = "+BC.toString());
		try{
		Trojkat ABC = new Trojkat(A,B,C);
		System.out.println("ABC = "+ABC.toString());
		ABC.odbij(p);
		System.out.println("ABC' = "+ABC.toString());
		}
		catch(IllegalArgumentException e)
		{
			System.out.println("Nie mozna zbudowac trojkata z podanych punktow A B i C");
		}
		catch(PunktPrzecieciaRownoleglych e)
		{
			System.out.println("Nie mozna znalezc punktu przeciecia");
		}

	}
}


