import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	static int R, C;
	static int map[][];
	static boolean visit[][];
	static int dx[]= {1, 0, -1, 0};
	static int dy[]= {0, 1, 0, -1};
	static int cnt;
	static int total;
	
	static class Point{
		int x, y;
		public Point(int x, int y) {
			this.x=x;
			this.y=y;
		}
	}
	static void bfs() {
		for(int i=0;i<R;i++) {
//			for(int j=0;j<C;j++) {
//				System.out.print(map[i][j]+" ");
//			}
//			System.out.println();
			Arrays.fill(visit[i], false); //방문 배열 초기화 
		}
		
		//0, 0에서 시작
		Queue<Point> q = new ArrayDeque<>();
		q.add(new Point(0, 0));
		cnt++; //걸린 시간 = bfs를 수행하는 횟수
		int cheese=0;
		while(!q.isEmpty()) {
			int x = q.peek().x;
			int y = q.peek().y;
			q.poll();
			
			for(int i=0;i<4;i++) {
				int nx = dx[i]+x;
				int ny = dy[i]+y;
				if(nx<0 || nx>=R || ny<0 || ny>=C ) continue;
				if(visit[nx][ny]) continue;
				if(map[nx][ny]!=0) {
					//인접한 칸이 치즈면 0으로 바꿈, 치즈 갯수 증가
					visit[nx][ny]=true;
					map[nx][ny]=0;
					cheese++;
				}
				else {
					//인접한 칸이 0이면 계속 탐색 
					visit[nx][ny]=true;
					q.add(new Point(nx, ny));
					
				}
				
			}
			
		}
		total -= cheese; //총 갯수에서 녹은 치즈 갯수 뺴기
		if(total<=0) {
			System.out.println(cnt); //걸린 시간
			System.out.println(cheese); //녹은 치즈 
		}
		else {
			bfs();
		}
		
		
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		R=sc.nextInt();
		C=sc.nextInt();
		map=new int[R][C];
		visit=new boolean[R][C];
		for(int i=0;i<R;i++) {
			for(int j=0;j<C;j++) {
				map[i][j]=sc.nextInt();
				if(map[i][j]==1) total++;
			}
		}
		//치즈가 없는 곳에서 bfs, map이 1인 곳을 만나면 0으로 바꿔줌		
		bfs();
		
	}

}
