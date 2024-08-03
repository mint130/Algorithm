import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		String s= br.readLine(); //입력 받은 문자열
		String f = br.readLine();
		s=s.replaceAll(f, "1");
		int cnt = 0;
		for(int i =0;i<s.length();i++) {
			if(s.charAt(i)=='1') cnt++;
		}
		System.out.println(cnt);
	}

}
