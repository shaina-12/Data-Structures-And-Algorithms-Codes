import java.util.Scanner;
class Node 
{
	public int data;
	Node next;
	public Node(int num)
	{
		this.data = num;
	}
}
class SinglyLinkedList 
{
	private Node head;
	public int size()
	{
		int len = 0;
		Node temp = head;
		if(temp == null)
		{
			//System.out.println("List Is Empty.");
			return 0;
		}
		while (temp != null)
		{
			len++;
			temp = temp.next;
		}
		return len;
	}
	public void insert(int data,int index)
	{
		int len = size();
		if(index > len)
		{
			System.out.println("Wrong Index.");
			return;
		}
		Node newNode = new Node(data);
		if(head == null)
		{
			head = newNode;
			return;
		}
		if(index == 0)
		{
			newNode.next = head;
			head = newNode;
		}
		else
		{
			int ctr = 0;
			Node temp = head;
			while(temp != null && ctr < index-1)
			{
				temp = temp.next;
				ctr ++;
			}
			if(temp != null)
			{
				Node a =  temp.next;
				temp.next = newNode;
				newNode.next = a;
			}
		}
	}
	public void delete(int index)
	{
		int len = size();
		if(len == 0)
		{
			System.out.println("List Is Empty.");
			return;
		}
		if(index >= len)
		{
			System.out.println("Wrong Index.");
			return;
		}
		if(len == 1)
		{
			head = null;
			return;
		}
		if(index == 0)
		{
			Node a = head;
			head = head.next;
			a = null;
		}
		else 
		{
			int ctr = 0;
			Node temp = head;
			while(temp.next != null && ctr < index-1)
			{
				temp = temp.next;
				ctr ++;
			}
			if(temp.next != null)
			{
				Node a =  temp.next;
				temp.next = a.next;			
				a.next = null;
				a = null;
			}
		}
	}
	public void display()
	{
		Node temp = head;
		if(temp == null)
		{
			System.out.println("List Is Empty.");
			return;
		}
		System.out.print("The list is: ");
		while(temp != null)
		{
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
		System.out.print("\n");
	}
	public void reverse()
	{
		Node curr = head;
		if(curr == null)
		{
			System.out.println("List Is Empty.");
			return;
		}
		System.out.print("The reverse of the list is: ");
		if(curr.next == null)
		{
			return;
		}
	    Node prev = null;
	    Node n = curr.next;
	    while(curr != null)
	    {
	        curr.next = prev;
	        prev = curr;
	        curr = n;
	        if(curr != null)
	        {
	        	n = curr.next;
	        }
	    }
	    head = prev;
	}
}
public class SLLUse 
{
	public static void main(String[] args) 
	{
		SinglyLinkedList l = new SinglyLinkedList();
		Scanner inp = new Scanner(System.in);
		int ch;
		int data;
		int ind1,ind2;
		int length;
		while(true)
		{
			System.out.println("Main Menu");
			System.out.println("1.Insert");
			System.out.println("2.Delete");
			System.out.println("3.Size");
			System.out.println("4.Display");
			System.out.println("5.Reverse");
			System.out.println("6.Exit");
			System.out.print("Enter your choice: ");
			ch = inp.nextInt();
			switch(ch)
			{
				case 1: System.out.print("Enter the data: ");
						data = inp.nextInt();
						System.out.print("Enter the index: ");
						ind1 = inp.nextInt();
						l.insert(data,ind1);
						l.display();
				break;
				case 2: System.out.print("Enter the index: ");
						ind2 = inp.nextInt();
						l.delete(ind2);
						l.display();
				break;
				case 3: length = l.size();
						System.out.println("The size of the list is: " + length);
				break;
				case 4: l.display();
				break;
				case 5: l.reverse();
						l.display();
				break;
				case 6: System.exit(0);
				break;
			}
		}
	}
}
