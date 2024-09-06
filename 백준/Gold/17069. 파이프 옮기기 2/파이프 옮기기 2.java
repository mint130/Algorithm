import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int map[][];
	static long dp[][][]; //파이프가 놓이는 방향, 위치 
	static int d[][];
	//0 가로 1 세로 2 대각선 
	public static void main(String[] args) throws IOException {
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N=Integer.parseInt(st.nextToken());
		dp=new long [3][N][N];
	
		map=new int [N][N];
		for(int i=0;i<N;i++) {
			st=new StringTokenizer(br.readLine());
			for(int j=0;j<N;j++) {
				map[i][j]=Integer.parseInt(st.nextToken());
			}
		}
		
		dp[0][0][1]=1;

		for(int j=1;j<N;j++) {
			if(map[0][j]!=0) continue;
			dp[0][0][j]+=dp[0][0][j-1];
			
		}
		for(int i=1;i<N;i++) {
			for(int j=1;j<N;j++) {
				//if(i==0 && j==1) continue;
				if(map[i][j]!=0) continue;
				
				//i, j에 가로 
				dp[0][i][j] += dp[0][i][j-1];
				dp[0][i][j] += dp[2][i][j-1];
				
				//i, j에 세로 
				dp[1][i][j]+=dp[1][i-1][j];
				dp[1][i][j]+=dp[2][i-1][j];
				
				//i, j에 대각선 
				if(map[i-1][j]==0 && map[i][j-1]==0) {
					dp[2][i][j]+=dp[0][i-1][j-1];
					dp[2][i][j]+=dp[1][i-1][j-1];
					dp[2][i][j]+=dp[2][i-1][j-1];
				}
			}
		}
		
		System.out.println(dp[0][N-1][N-1]+dp[1][N-1][N-1]+dp[2][N-1][N-1]);
	
	}
}
