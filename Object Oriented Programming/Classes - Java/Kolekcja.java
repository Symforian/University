
class Kolekcja <V, T extends Comparable<T>>
{
	V val; T key;
	Kolekcja<V, T> next;
	
	public Kolekcja(V val, T key)
	{
		this.val = val;
		this.key = key;
		this.next = null;
	}

	public Kolekcja() {}
	
	public Kolekcja<V, T> GetElement()
	{
		Kolekcja<V, T> ptr = this.next;
		if(this.next != null) 
			this.next = this.next.next;
		return ptr;
	}
	
	public void AddToCollection(V val, T key)
	{
		if(this.next != null)
		{
			if (this.next.key.compareTo(key)>=0)
			{
 				Kolekcja<V,T> k=this.next;
 				this.next=new Kolekcja<V,T>(val, key);
 				this.next.next=k;
			}
			else this.next.AddToCollection(val, key);
		}
		else this.next=new Kolekcja<V,T>(val, key);
	}
	
	public void PrintElements()
	{
 		if (this.next != null)
 		{
 			System.out.println("[ " + this.next.val + " " + this.next.key + " ]");
 			this.next.PrintElements();
 		}
 	}
}
