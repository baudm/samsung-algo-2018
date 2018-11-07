import java.util.Map;
import java.util.HashMap;

@SuppressWarnings("unchecked")
public class mysolution {

    private static final Map<Character, String> m = new HashMap<>();
    static {
        m.put('a', "2");
        m.put('b', "22");
        m.put('c', "222");
        
        m.put('d', "3");
        m.put('e', "33");
        m.put('f', "333");
        
        m.put('g', "4");
        m.put('h', "44");
        m.put('i', "444");
        
        m.put('j', "5");
        m.put('k', "55");
        m.put('l', "555");
        
        m.put('m', "6");
        m.put('n', "66");
        m.put('o', "666");
        
        m.put('p', "7");
        m.put('q', "77");
        m.put('r', "777");
        m.put('s', "7777");
        
        m.put('t', "8");
        m.put('u', "88");
        m.put('v', "888");
        
        m.put('w', "9");
        m.put('x', "99");
        m.put('y', "999");
        m.put('z', "9999");
    }

	static int solve(int N, char[] message, char[] presses) {
        int num_presses = 0;
        for (int i = 0; i < N; i++) {
            final String p = m.get(message[i]);
            final int len = p.length();
            p.getChars(0, len, presses, num_presses);
            num_presses += len;
        }
	    return num_presses;
	}
}
