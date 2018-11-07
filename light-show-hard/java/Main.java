import java.util.Scanner;


public class Main {
	
	static int N,M;
	static int[] L;
	static int[][] B;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
	    int T = sc.nextInt();
	    L = new int[100000];
	    B = new int[100000][50];

	    for(int case_num=1; case_num<=T; case_num++) {
	    	N = sc.nextInt();
	    	M = sc.nextInt();
	    	for(int i=0; i<M; i++) {
	            L[i] = sc.nextInt();
	            for(int j=0; j<L[i]; j++)
	            	B[i][j] = sc.nextInt();
	        }
	        
	    	long ret = User.solve(N,M,L,B);
	        System.out.println(ret);  
	    }
	    sc.close();
	}
}
