import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		int w = Integer.parseInt(st.nextToken());
		
		int [][] dp = new int[31][31];
		for(int i=1;i<=30;i++) {
			for(int j=1;j<=30;j++) {
				if(i==j || j==1) dp[i][j]=1;
				else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
				//파스칼의 삼각형
			}
		}
		int ans = 0;
		for(int i=r;i<r+w;i++) {
			for(int j=c;j<c+w;j++) {
				if(i-r>=j-c) ans+=dp[i][j];
			}
		}
		System.out.println(ans);
	}

}
