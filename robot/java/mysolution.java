@SuppressWarnings("unchecked")
public class mysolution {

    private static String getPresses(char c) {
        switch (c) {
            case 'a': return "2";
            case 'b': return "22";
            case 'c': return "222";
            case 'd': return "3";
            case 'e': return "33";
            case 'f': return "333";
            case 'g': return "4";
            case 'h': return "44";
            case 'i': return "444";
            case 'j': return "5";
            case 'k': return "55";
            case 'l': return "555";
            case 'm': return "6";
            case 'n': return "66";
            case 'o': return "666";
            case 'p': return "7";
            case 'q': return "77";
            case 'r': return "777";
            case 's': return "7777";
            case 't': return "8";
            case 'u': return "88";
            case 'v': return "888";
            case 'w': return "9";
            case 'x': return "99";
            case 'y': return "999";
            case 'z': return "9999";
        }
        return "";
    }
    static int solve(int N, char[] message, char[] presses) {
        int num_presses = 0;
        for (int i = 0; i < N; i++) {
            final String p = getPresses(message[i]);
            final int len = p.length();
            p.getChars(0, len, presses, num_presses);
            num_presses += len;
        }
        return num_presses;
    }
}
