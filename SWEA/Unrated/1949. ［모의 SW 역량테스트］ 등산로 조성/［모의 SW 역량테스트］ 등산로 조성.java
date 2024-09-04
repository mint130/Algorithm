import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {

	static int dx[]= {1, 0, -1, 0};
	static int dy[]= {0, 1, 0, -1};
	static boolean visit[][];
	static int T, N, K, ans, max, longLen; //가장 긴 경로 저장 
	static boolean flag; 
	static int map[][];
	static class p{
		int x, y;

		public p(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
		
	}
	static int dfs(int x, int y, int len) {
		longLen=Math.max(longLen, len);
		for(int dir=0;dir<4;dir++) {
			int nx=x+dx[dir];
			int ny=y+dy[dir];
			if(nx<0||nx>=N||ny<0||ny>=N) continue;
			if(visit[nx][ny]) continue; 
			if(map[nx][ny]-K>=map[x][y]) continue; //K만큼 줄여도 갈 수 없음 
			if(map[nx][ny]<map[x][y]) {
				//안 깎아도 갈 수 있음 
				visit[nx][ny]=true;
				dfs(nx, ny, len+1);
                visit[nx][ny]=false;
			}
			if(!flag && map[nx][ny]>=map[x][y]) {
				flag=true;
				int height=map[nx][ny];
				visit[nx][ny]=true;
				map[nx][ny]=map[x][y]-1; //등산로 깎음 
				dfs(nx, ny, len+1);
				flag=false;
				visit[nx][ny]=false;
				map[nx][ny]=height; //원상복구 
			}
			
		}
	
		return longLen; //가장 긴 경로 반환 
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		T=Integer.parseInt(st.nextToken());
		for(int tc=1;tc<=T;tc++) {
			ans=0;
			st=new StringTokenizer(br.readLine());
			N=Integer.parseInt(st.nextToken());
			K=Integer.parseInt(st.nextToken());
			map=new int[N][N];
			longLen=0;
			max=0; //등산로에서 가장 높은 높이
			for(int i=0;i<N;i++) {
				st=new StringTokenizer(br.readLine());
				for(int j=0;j<N;j++) {
					map[i][j]=Integer.parseInt(st.nextToken());
					if(map[i][j]>max) max=map[i][j];
				}
			}
			for(int i=0;i<N;i++) {
				for(int j=0;j<N;j++) {
					if(map[i][j]==max) {
						
						visit=new boolean[N][N];
						visit[i][j]=true;
						flag=false; //바꿨는지 
						ans=dfs(i, j, 1);
						//dfs
						
					}
				}
			}
			
			
			
			System.out.println("#"+tc+" "+ans);
		}
	}

}
