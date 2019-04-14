
import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.awt.List;

public class Main{
    public static void main(String[] args) {

         System.out.println("Hierarchia stopni wojskowych.");
        ArrayList<Stopnie_wojskowe> woj = new ArrayList<Stopnie_wojskowe>();
        
		woj.add(new Starszy_Kapral("Jan Kowalski"));
		woj.add(new Szeregowy("Jan Malinowski"));
		woj.add(new Szeregowy("Alina Kowalska"));
		//woj.add(new Kapral("Tomasz Judym"));
		
		Collections.sort(woj);		
//for(Stopnie_wojskowe t : woj) System.out.println(t);
    }

}
