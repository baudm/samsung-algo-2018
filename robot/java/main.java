import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class main {
	private static int N;
    private static char message[];
    private static char presses[] = new char[400001];

	public static void main(String[] args) throws FileNotFoundException {
	    System.setIn(new FileInputStream("sample_input.txt"));
	    Scanner sc = new Scanner(System.in);
	    int T = sc.nextInt();

	    long time = System.currentTimeMillis();

	    for(int case_num=1; case_num<=T; case_num++) {
	    	N = sc.nextInt();
	    	message = sc.next().toCharArray();
	    	
	    	int ret = mysolution.solve(N, message, presses);
	    	
			System.out.print(ret);
			System.out.print(' ');
	    	for(int i=0; i<ret; i++)
	    		System.out.print(presses[i]);
	    	System.out.println();
	    }

	    time = (System.currentTimeMillis() - time);
	    System.out.println("execution_time:" + time);

	    sc.close();
	}
}
