package algorithms;

public class BST <T extends Comparable<T>> implements Dict<T>{

    private class Node <T extends Comparable<T>>{
        Node<T> left, right, parent;
        T data;
        
        Node(){
            left = null;
            right = null;
            parent = null; 
            
        }
       /* T getValue(){
            return data;
        }
        
        void setValue(T newVal){
            data = newVal;
        }
        */
        boolean search(T x){
            if(data.compareTo(x) == 0)
            {
                return true;
            }
            else
                if(data.compareTo(x) > 0)
                {
                    if(left == null)
                        return false;
                    else
                        return left.search(x);
                }
                else 
                {
                    if(right == null)
                        return false;
                    else
                        return right.search(x);
                }
        }
        //min
     T min(){
     if(left == null)
        return data;
     Node<T> smaller = left;
     while(smaller.left != null)
        {
            smaller = smaller.left;
        }
        return smaller.data;
    }
//max
     T max(){
     if(right == null)
        return data;
     Node<T> bigger = right;
     while(bigger.right != null)
        {
            bigger = bigger.right;
        }
        return bigger.data;
    }
    
    int count()
    {
        if(right!= null && left != null)
            return 2 + right.count() + left.count();
        if(right != null)
            return 1 + right.count();
        if(left != null)
            return 1 + left.count();
         return 0;
    }
    String nextOne (String path){
        if(left!=null && right != null)
            return path+"L: "+left.data+" "+path+"R: "+right.data+"\n"+left.nextOne(path+"L")+right.nextOne(path+"R");
        else if(left!=null)
            return path+"L: "+left.data+"\n"+left.nextOne(path+"L");
        else if(right!=null)
            return path+"R: "+right.data+"\n"+right.nextOne(path+"R");
        else return "";
    }
    /*     void clear()
    {
        if(left!=null)
            {
                if(left.left != null)
                        left.left.clear();

                 if(left.right != null)
                        left.right.clear();


                 left.parent = null;
                 left = null;
            }
              if(right!=null)
            {
                if(right.left != null)
                        right.left.clear();

                 if(right.right != null)
                        right.right.clear();

                right.parent = null;
                right = null;

            }

    }*/
// ...
    }

    private Node<T> root = null;

    public BST()
    {
        root = null;
    }

// ... metody słownikowe
/**
	Searches value.
	@param value value to search.
	@return True if given value is in BST otherwise False.
*/
    public boolean search(T value){
        if(root == null)
            return false;
        return root.search(value);
    }
/**
	Insertes value.
	@param value value to insert.
*/
    public void insert(T value) throws NullPointerException{
        if(value == null)
            throw new NullPointerException();
        if(root == null)
            {
                root = new Node<T>();
                root.data = value; //root.data = value;
            }
        else
        {
            Node<T> buff = root;
            boolean NotPlaced = true;
            while(NotPlaced)
            {
                if(buff.data.compareTo(value)>0)
                    {
                        if(buff.left == null)
                            {
                                buff.left = new Node<T>();
                                buff.left.data = value;
                                buff.left.parent = buff;
                                NotPlaced = false;
                            }
                         else
                            buff = buff.left;
                    }
                 else if(buff.data.compareTo(value)<0)
                    {
                        if(buff.right == null)
                            {
                                buff.right = new Node<T>();
                                buff.right.data = value;
                                buff.right.parent = buff;
                                NotPlaced = false;
                            }
                         else
                            buff = buff.right;
                    }
                 else if(buff.data.compareTo(value)==0)
                        break;
            }
        }
    }
/**
	Removes value.
	@param value value to remove.
*/
    public void remove(T value){
        if(search(value))
        {Node<T> buff = root;
        if(buff.data.compareTo(value)==0)
        {
            if(buff.right == null && buff.left == null)
                root = null;
            else if(buff.right == null)
                {
                    buff.left.parent = null;
                    root = buff.left;
                }
            else if(buff.left == null)
                {
                    buff.right.parent = null;
                    root = buff.right;
                }
            else
                {
                    
                    T newRootVal = buff.right.min();
                    remove(newRootVal);
                    root.data = newRootVal;
                }
        }
        else{
            boolean NotRemoved = true;
            while(NotRemoved)
            {
                if(buff.data.compareTo(value)>0)
                    {
                        if(buff.left!=null)
                        {
                            if(buff.left.data.compareTo(value)==0)
                                {
                                    if(buff.left.right == null && buff.left.left == null)
                                        {
                                            buff.left.parent = null;
                                            buff.left = null;
                                            NotRemoved = false;
                                        }
                                    else if(buff.left.right == null)
                                        {
                                            buff.left = buff.left.left;
                                            buff.left.parent = buff;
                                            NotRemoved = false;
                                        }
                                    else if(buff.left == null)
                                        {
                                            buff.left = buff.left.right;
                                            buff.left.parent = buff;
                                            NotRemoved = false;
                                        }
                                    else
                                        {
                                            T newRootVal = buff.left.right.min();
                                            remove(newRootVal);
                                            buff.left.data = newRootVal;
                                            NotRemoved = false;
                                        }
                                }
                             else
                                buff = buff.left;
                        }
                    }
                    else if(buff.data.compareTo(value)<0)
                    {
                        if(buff.right!=null)
                        {
                            if(buff.right.data.compareTo(value)==0)
                                {
                                    if(buff.right.right == null && buff.right.left == null)
                                        {
                                            buff.right.parent = null;
                                            buff.right = null;
                                            NotRemoved = false;
                                        }
                                    else if(buff.right.right == null)
                                        {
                                            buff.right = buff.right.left;
                                            buff.right.parent = buff;
                                            NotRemoved = false;
                                        }
                                    else if(buff.right == null)
                                        {
                                            buff.right = buff.right.right;
                                            buff.right.parent = buff;
                                            NotRemoved = false;
                                        }
                                    else
                                        {
                                            T newRootVal = buff.right.right.min();
                                            remove(newRootVal);
                                            buff.right.data = newRootVal;
                                            NotRemoved = false;
                                        }
                                }
                             else
                                buff = buff.right;
                        }
                    }
            }
        }
        
    }
    }
/**	Returns smallest value in BST.
	@return min value in a BST. Of type T.
*/
    public T min() throws NullPointerException{
        if(root == null)
            throw new NullPointerException("No min in empty BST");
        return root.min();
    }
/**	Returns largest value in BST. 
	@return max value in a BST. Of type T.
*/
    public T max()throws NullPointerException{
        if(root == null)
            throw new NullPointerException("No max in empty BST");
        return root.max();
    }

	/**
	@return String which represent BST
	*/
    public String toString () {
        if(root!=null)
            return "Root:"+root.data+"\n"+root.nextOne("");
        return "Root: null\n";
    }
    /**
	Count size of BST tree.
	@return Size of BST tree.
    */
    public int size()
    {
        if(root == null)
        return 0;
        if(root.right != null && root.left != null)
        return 3 + root.right.count() + root.left.count();
        if(root.right != null)
        return 2 + root.right.count();
        if(root.left != null)
        return 2 + root.left.count();
        else
        return 1;
    }
    /**
	Clearing whole BST.
    */
    public void clear()
    {
        
       // if(root!=null)
      //  {
      //      root.clear();
            root = null;
     //   }

    }


}

//size
//clear
