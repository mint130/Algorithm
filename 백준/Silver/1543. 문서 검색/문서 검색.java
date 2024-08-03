import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		String s= br.readLine(); //입력 받은 문자열
		String f = br.readLine();
		int cnt = 0;
		int find = s.indexOf(f); //f가 가장 먼저 나온 위치 반환
		while(find != -1) {
			cnt++;
			find = s.indexOf(f, find + f.length());
		}
		System.out.println(cnt);
	}

}
