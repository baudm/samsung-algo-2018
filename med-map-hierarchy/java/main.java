import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class main {
	static private int N,M,Q;
    static private int C[][] = new int[100000][2];
    static private int query[][] = new int[100000][2];

	public static void main(String[] args) throws FileNotFoundException {
	    System.setIn(new FileInputStream("sample_input.txt"));
	    Scanner sc = new Scanner(System.in);
	    int T = sc.nextInt();

	    long time = System.currentTimeMillis();

	    for(int case_num=1; case_num<=T; case_num++) {
	    	N = sc.nextInt();
	    	M = sc.nextInt();
	    	for(int i=0; i<M; i++)
                for(int j=0; j<2; j++)
                    C[i][j] = sc.nextInt();
            
            Q = sc.nextInt();
            for(int i=0; i<Q; i++) {
                for(int j=0; j<2; j++)
                    query[i][j] = sc.nextInt();
            }

	    	mysolution.init(N,M,C);
		
            for(int i=0; i<Q; i++) {
				if(i>0)
					System.out.print(' ');
				System.out.print(mysolution.superior(query[i][0],query[i][1]));
			}
			System.out.println();
	    }

	    time = (System.currentTimeMillis() - time);
	    System.out.println("execution_time:" + time);

	    sc.close();
	}
}