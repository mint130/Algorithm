import java.util.Arrays;
import java.util.Scanner;

public class Solution {
	 
	static int T, ans, N; //가장 많이 먹을때의 디저트 수가 답 
	static int map[][];
	static int dx[]= {1, 1, -1, -1};
	static int dy[]= {-1, 1, 1, -1}; //대각선 
	static int startX, startY;
	static boolean eat[];
	static void dfs(int x, int y, int dir, int cnt) {
		if(x==startX && y==startY && cnt>=4) {
			//자기 자신에게로 돌아옴
			ans=Math.max(cnt, ans);
			return;
		}
		for(int i=dir;i<4;i++) {
			//같은 방향이거나 다음 방향으로만 진행 가능, 이전 방향으로는 진행 x 
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx<0||nx>=N||ny<0||ny>=N) continue;
			if(eat[map[nx][ny]]) continue; //이미 방문 했거나 먹었던 디저트 번호 있으면 가지않음 
			eat[map[nx][ny]]=true;
			dfs(nx, ny, i, cnt+1);
			eat[map[nx][ny]]=false;
		
		}
		
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T=sc.nextInt();
		
		for(int tc =1;tc<=T;tc++) {
			ans=-1;
			N=sc.nextInt();
			map=new int[N][N];
			for(int i=0;i<N;i++) {
				for(int j=0;j<N;j++) {
					map[i][j]=sc.nextInt();
				}
			}
			for(int i=0;i<N-2;i++) {
				for(int j=1;j<N-1;j++) {
					startX=i;
					startY=j;
					eat=new boolean[101];
					dfs(i, j, 0, 0);
					
				}
			}
			
			System.out.println("#"+tc+" "+ans);
		}
	}

}
