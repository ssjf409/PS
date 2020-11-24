import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    static final int alphaNum = 26;

    public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] arr = new int[alphaNum];

        Arrays.fill(arr, -1);

        String str = br.readLine();
        

        for(int i = 0; i < str.length(); i++) {
            int index = str.charAt(i) - 'a';
            if(arr[index] == -1) {
                arr[index] = i;
            }
        }

        for(int i = 0; i < alphaNum; i++) {
            System.out.print(arr[i]);
            System.out.print(' ');
        }


    }
}