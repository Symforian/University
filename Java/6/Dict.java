package algorithms;
public interface Dict <T extends Comparable<T>>
{
// ... metody słownikowe
//search
public boolean search(T value);
//insert
public void insert(T value);
//remove
public void remove(T value);
//min
public T min();
//max
public T max();
}
