package algorithms;


class Main
{
  public static void main(String[] args) 
  {
/*/BEGINING OF INTEGER TESTS
	BST<Integer> Tree = new BST<Integer>();
	System.out.println(Tree);
	try{
	Tree.insert(50);
	}
	catch(NullPointerException e)
	{
		throw e;
	}
	System.out.println(Tree);
	Tree.insert(3);
	Tree.insert(23);
	Tree.insert(13);
	System.out.println("----------------\n"+Tree+"\tSize: "+Tree.size());
	Tree.insert(3234);
	Tree.insert(232);
	Tree.insert(1);
	System.out.println("----------------\n"+Tree+"\tSize: "+Tree.size());
	
	Tree.remove(232);
	System.out.println("----------------\n"+Tree+"\tSize: "+Tree.size());
	for(int i = 55; i<71; i++)
		{
		Tree.insert(i);
		Tree.insert(i-30);
		}
	System.out.println("----------------\n"+Tree+"\tSize: "+Tree.size()+" "+Tree.min()+" "+Tree.max());
	Tree.remove(50);
	System.out.println("----------------\n"+Tree+"\tSize: "+Tree.size()+"\nThere is 70: "+Tree.search(70));
	for(int i = 0; i<100; i+=10)
		Tree.remove(i);
	System.out.println("----------------\n"+Tree+"\tSize: "+Tree.size()+"\nThere is 70: "+Tree.search(70));
	Tree.clear();
	System.out.println("----------------\n"+Tree+"\tSize: "+Tree.size()+"\nThere is 70: "+Tree.search(70));
	Tree.insert(70);
	Tree.insert(6);
	Tree.insert(-70);
Tree.insert(-780);
Tree.insert(-7590);
	Tree.insert(0);
	System.out.println("----------------\n"+Tree+"\tSize: "+Tree.size()+"\nThere is 70: "+Tree.search(70));
	Tree.remove(-780);
	System.out.println("----------------\n"+Tree+"\tSize: "+Tree.size()+"\nThere is 70: "+Tree.search(70));
	Tree.clear();
	//Tree.min();
	System.out.println("----------------\n"+Tree+"\tSize: "+Tree.size()+"\nThere is 70: "+Tree.search(70));
System.out.println("----------------\n");
System.out.println("----------------\n");
System.out.println("----------------\n");

//END OF INTEGER TESTS*/
//BEGINNING OF STRING TESTS
	BST<String> Tree = new BST<String>();
	System.out.println(Tree);
	try{
	Tree.insert("Adam");
	}
	catch(NullPointerException e)
	{
		throw e;
	}
	System.out.println(Tree);
	Tree.insert("zx3");
	Tree.insert("a23");
	Tree.insert("bxvvx");
	System.out.println("----------------\n"+Tree+"\tSize: "+Tree.size());
	Tree.insert("3");
	Tree.insert("ds232");
	Tree.insert("1");
	System.out.println("----------------\n"+Tree+"\tSize: "+Tree.size());
	
	Tree.remove("Adam");
	System.out.println("----------------\n"+Tree+"\tSize: "+Tree.size());
	System.out.println("----------------\n"+Tree+"\tSize: "+Tree.size()+" "+Tree.min()+" "+Tree.max());
	Tree.remove("zx3");
	System.out.println("----------------\n"+Tree+"\tSize: "+Tree.size()+"\nThere is zx3: "+Tree.search("zx3"));
	Tree.clear();
	System.out.println("----------------\n"+Tree+"\tSize: "+Tree.size()+"\nThere is zx3: "+Tree.search("zx3"));
	Tree.insert("zx3");
	Tree.insert("435");
	Tree.insert("Adam");
	System.out.println("----------------\n"+Tree+"\tSize: "+Tree.size()+"\nThere is adam: "+Tree.search("adam"));
System.out.println("----------------\n");
//END OF STRING TESTS

  }
}
