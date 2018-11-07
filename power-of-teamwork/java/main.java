import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class main {
	private static int N;
    private static int P[] = new int[100000];
    private static final int END = 2;
    private static final int POWERUP = 1;
    private static final int TEAMWORK = 0;
    
	public static void main(String[] args) throws FileNotFoundException {
	    System.setIn(new FileInputStream("sample_input.txt"));
	    Scanner sc = new Scanner(System.in);
	    int T = sc.nextInt();

	    long time = System.currentTimeMillis();
        for(int case_num=1; case_num<=T; case_num++) {
        	N = sc.nextInt();
        	for(int i=0; i<N; i++)
        		P[i] = sc.nextInt();
        	
        	mysolution.init(N, P);
            
            boolean first = true;
            while(true) {
                int command = sc.nextInt();
                
                if(command==END)
                    break;
                else if(command==POWERUP) {
                    int x = sc.nextInt();
                    int y = sc.nextInt();
                    mysolution.powerup(x,y);
                }
                else if(command==TEAMWORK) {
                    int a = sc.nextInt();
                    int b = sc.nextInt();
                    if(first)
                        first = false;
                    else
                        System.out.print(' ');
                    System.out.print(mysolution.teamwork(a,b));
                }
            }
            System.out.println();
        }

	    time = (System.currentTimeMillis() - time);
	    System.out.println("execution_time:" + time);

	    sc.close();
	}
}
