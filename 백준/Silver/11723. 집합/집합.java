import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		StringBuilder sb = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int M = Integer.parseInt(st.nextToken());
		int S = 0;
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			String s=st.nextToken();
			
			int x;
			switch (s) {
			case "add":
				x = Integer.parseInt(st.nextToken());
				S=S|(1<<x);
				break;
			case "remove":
				x = Integer.parseInt(st.nextToken());
				S=S&(~(1<<x));
				break;
			case "check":
				x = Integer.parseInt(st.nextToken());
				if((S&(1<<x))!=0) sb.append(1).append("\n");
				else sb.append(0).append("\n");
				break;
			case "toggle":
				x = Integer.parseInt(st.nextToken());
				S=S^(1<<x);
				break;
			case "all":
				S=2097150;
				x=0;
				break;
			case "empty":
				S=0;
				x=0;
				break;
		}
			
	}
	System.out.println(sb);

}
}
