import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.Stack;
import java.util.StringTokenizer;

public class Solution {
	
	static int ans = 0; 
	static int N, M;
	static int arr[][];
	static boolean isSelected[];
	
	static void dfs(int cnt) {
		//cnt번째까지 넣음
		if(cnt==N) {
			//arr을 순회하며 현재 isSelected 배열에 같이 있으면 안되는 재료가 포함되어 있으면 return, 
			//아니면 ans++ 후 return
			int S = 0; //현재 선택
			for(int i=0;i<N;i++) {
				if(isSelected[i]) {
					S|=(1<<i);
				}
			}
			for(int i=0;i<M;i++) {
				int a=arr[i][0]; //첫번째 재료
				int b=arr[i][1]; //두번째 재료
				
				if((S&(1<<a))!=0 && ((S&(1<<b))!=0)) {
					//둘 다 포함
					//System.out.println("포함 "+(a+1)+" "+(b+1));
					return;
				}
			}
			ans++;
			return;
			
		}
		isSelected[cnt]=true;
		dfs(cnt+1);
		isSelected[cnt]=false;
		dfs(cnt+1);
	}

	public static void main(String[] args) throws IOException {
			
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			StringTokenizer st = new StringTokenizer(br.readLine());
			int T = Integer.parseInt(st.nextToken());
			for(int tc=1;tc<=T;tc++) {
				st = new StringTokenizer(br.readLine());
				ans = 0;
				N = Integer.parseInt(st.nextToken());
				M = Integer.parseInt(st.nextToken());
				//arr = new int[N][N]; //[i][j]가 1이면 같이 못넣음
				arr = new int [M][2];
				isSelected = new boolean[N];
				for(int i=0;i<M;i++) {
					st = new StringTokenizer(br.readLine());
					int a = Integer.parseInt(st.nextToken())-1;
					int b = Integer.parseInt(st.nextToken())-1;
					//arr[a][b]=1;
					//arr[b][a]=1;
					arr[i][0]=a;
					arr[i][1]=b;
				}
				
				dfs(0);
				System.out.println("#"+tc+" "+ans);
				
			}
		}
			
		
		
}


