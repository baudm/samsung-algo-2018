import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class main {
	private static int N;
	private static int D[] = new int[100000];

	public static void main(String[] args) throws FileNotFoundException {
	    System.setIn(new FileInputStream("sample_input.txt"));
	    Scanner sc = new Scanner(System.in);
	    int T = sc.nextInt();

	    long time = System.currentTimeMillis();

	    for(int case_num=1; case_num<=T; case_num++) {
	    	N = sc.nextInt();
	    	for(int i=0; i<N; i++)
	    		D[i] = sc.nextInt();
	    	
	    	int ret = mysolution.solve(N,D);
	    	System.out.println(ret);
	    }

	    time = (System.currentTimeMillis() - time);
	    System.out.println("execution_time:" + time);

	    sc.close();
	}
}
