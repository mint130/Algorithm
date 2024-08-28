import java.util.Arrays;
import java.util.Scanner;

public class Main {

	static char map[][];
	static boolean visit[][];
	static int dx[]= {-1, 0, 1};
	static int R, C;
	static int ans;
	static boolean flag;
	static void dfs(int x, int y) {
		
		if(y==C-1) {
			//끝에 도달
			ans++;
			//한번끝에 도달했으면 탐색 중단
			flag=true;
			return;
			
		}
		
		for(int i=0;i<3;i++) {
			int nx=x+dx[i];
			int ny=y+1;
			if(nx<0||nx>=R||ny<0||ny>=C) continue;
			if(map[nx][ny]=='x' || visit[nx][ny]) continue;
			visit[nx][ny]=true;
			dfs(nx, ny);
			if(flag) {
				return;
			}
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		R=sc.nextInt();
		C=sc.nextInt();
		map=new char[R][C];
		visit=new boolean[R][C];
		for(int i=0;i<R;i++) {
			String s=sc.next();
			for(int j=0;j<C;j++) {
				map[i][j]=s.charAt(j);
			}
		}
		for(int i=0;i<R;i++) {
			visit[i][0]=true;
			flag=false;
			dfs(i,0);
		}
		System.out.println(ans);
	}

}
