package Wyrazenia;

public class Main{

	public static void main(String[] args) 
	{
		Zmienna X = new Zmienna("x",-1.618);
		Zmienna Y = new Zmienna("y",8);
		//TESTY Z ZADANIA 
		Wyrazenie w = new Dodaj
					(new Liczba(7)
					,new Pomnoz
						(
						X,
						new Liczba(5)
						)
					);		
		System.out.println(w+" = "+w.oblicz());
		w = new Dodaj
				(new Liczba(3),new Liczba(5));
		System.out.println(w+" = "+w.oblicz());
		w = new Dodaj
				(new Liczba(2)
				,new Pomnoz
					(
					X
					,new Liczba(7)
					)
				);
		System.out.println(w+" = "+w.oblicz());
		w = new Podziel
				(new Odejmij
					(new Pomnoz
						(new Liczba(3),
						new Liczba(11))
					,new Liczba(1)
					)
				,new Dodaj
					(
					new Liczba(7),
					new Liczba(5)
					)
				);
		System.out.println(w+" = "+w.oblicz());
		w = new Arctan(
				new Podziel(
					new Pomnoz(
						new Dodaj(
							X
							,new Liczba(13)
							)
						,X
						)
					,new Liczba(2)
					)
			      );
		System.out.println(w+" = "+w.oblicz());
		w = new Pomnoz(
				new Dodaj(
					new Potega(
						new Liczba(2)
						,new Liczba(5)
						)
					,X
					)
				,new Logarytm(
						new Liczba(2)
						,Y
						)
				);
		System.out.println(w+" = "+w.oblicz());
	//KONIEC TESTOW Z ZADANIA 
		System.out.println("Testy własne\n");
		w = new WartBezwzgl(
					new Przeciwna(new Liczba(3))
				);
		Wyrazenie z = new Liczba(3);
		System.out.println(w+" = "+w.oblicz());
		System.out.println(z+" = "+z.oblicz());
		System.out.println(w+" = "+z+"\n^"+w.equals(z)+"^"+z.equals(w)+"^"+(z==w)+"\n");

		w = new WartBezwzgl(
				new Pomnoz(
					new Przeciwna(new Liczba(3))
					,X
					)
				);
		z = new Pomnoz(
				new Liczba(3)
				,X
				);
		System.out.println(w+" = "+w.oblicz());
		System.out.println(z+" = "+z.oblicz());
		System.out.println(w+" = "+z+"\n^"+w.equals(z)+"^"+z.equals(w)+"^"+(z==w)+"\n");
		w = new Minimum(
				new Liczba(0)
				,new Liczba(1)
				);
		z = new Maximum(
				new Liczba(3)
				,X
				);
		System.out.println(w+" = "+w.oblicz());
		System.out.println(z+" = "+z.oblicz());
		System.out.println(w+" = "+z+"\n^"+w.equals(z)+"^"+z.equals(w)+"^"+(z==w)+"\n");
		w = new Odwrotna(
				new Pomnoz(
					new Liczba(2)
					,new Liczba(4)
					)
				);
		z = new Podziel(
				new Liczba(1)
				,Y
				);
		System.out.println(w+" = "+w.oblicz());
		System.out.println(z+" = "+z.oblicz());
		System.out.println(w+" = "+z+"\n^"+w.equals(z)+"^"+z.equals(w)+"^"+(z==w)+"\n");

		w = new Dodaj(
				new Liczba(5)
				,new Pomnoz(
					new Liczba(2)
					,new Liczba(4)
					)
				);
		z = new Dodaj(
				new Pomnoz(
					new Liczba(2)
					,new Liczba(4)
					)
				,new Liczba(5)
				);
		System.out.println(w+" = "+w.oblicz());
		System.out.println(z+" = "+z.oblicz());
		System.out.println(w+" = "+z+"\n^"+w.equals(z)+"^"+z.equals(w)+"^"+(z==w)+"\n");
		w = new Pomnoz(
				new Logarytm( 
					new Liczba(5)
					,new Liczba(25)
						)
				,new Dodaj(
					new Liczba(2)
					,new Liczba(4)
					)
				);
		z = new Dodaj(
				new Pomnoz(
					new Liczba(16)
					,new Liczba(5)
					)
				,new Sinus(
					new Liczba(4)
					)
				);
		System.out.println(w+" = "+w.oblicz());
		System.out.println(z+" = "+z.oblicz());
		System.out.println(w+" = "+z+"\n^"+w.equals(z)+"^"+z.equals(w)+"^"+(z==w)+"\n");




		w = new Pomnoz(
				new Odwrotna(
					new Liczba(4)
					)
				,new Dodaj(
					new Liczba(7)
					,new Potega(
						new Liczba(3)
						,new Liczba(2)
						)
				)
				);
		z = new Dodaj(
				new Liczba(2)
				,new Pomnoz(
					new Liczba(0)
					,new Liczba(1000)
					)
				);
		System.out.println("\n"+w+" = "+w.oblicz());
		System.out.println(z+" = "+z.oblicz());
		System.out.println("\n("+w+")+("+w+")+("+z+") = "+Wyrazenie.sumuj(w,w,z));
		System.out.println("\n("+w+")*("+w+")*("+z+") = "+Wyrazenie.pomnoz(w,w,z));

	z = new Logarytm(new Zmienna("a",1),new Zmienna("b",1));
	Zmienna.zmienne.ustal(new Para(2,"b"));
	Zmienna.zmienne.ustal(new Para(2,"a"));
	System.out.println(z+" = "+z.oblicz());

	}


}
