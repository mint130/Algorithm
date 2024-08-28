import java.util.Scanner;

public class Main {
	static int R, C, ans; //ans는 지나갈 수 있는 칸의 개수
	static char map[][];
	static boolean visit[][]; //좌표를 지나감
	static boolean alpha[]=new boolean[26]; //A부터 Z까지
	static int dx[]= {1, 0, -1, 0};
	static int dy[]= {0, 1, 0, -1};
	static class Point{
		int x; int y;
		public Point(int x, int y) {
			this.x=x;
			this.y=y;
		}
	}
	public static void dfs(int x, int y, int cnt) {
		ans=Math.max(cnt, ans); 
		visit[x][y]=true;
		alpha[map[x][y]-'A']=true;
		
		
		//지금까지 밟은 알파벳은 alpha[ch-'A']=true
		for(int i=0;i<4;i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0 || nx>=R ||ny<0 || ny>=C) continue;
			if(visit[nx][ny]) continue; //방문했던 곳이면 방문 x
			if(alpha[map[nx][ny]-'A']) continue; //알파벳 썼으면 x
			dfs(nx, ny, cnt+1);
			alpha[map[nx][ny]-'A']=false;
			visit[nx][ny]=false;
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		R=sc.nextInt();
		C=sc.nextInt();
		map = new char[R][C];
		visit = new boolean[R][C];
		
		for(int i=0;i<R;i++) {
			String s=sc.next();
			for(int j=0;j<C;j++) {
				map[i][j]=s.charAt(j);
			}
		}
		
		dfs(0, 0, 1);
		System.out.println(ans);
	}

}
