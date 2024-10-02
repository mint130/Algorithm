import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	static int N, M, board[][];
	static int dist[][][];
	static int dx[]= {1, 0, -1, 0};
	static int dy[]= {0, 1, 0, -1};
	static class pair {
		int x, y, b;
		//b가 0이면 아직 안 부숨 

		public pair(int x, int y, int b) {
			super();
			this.x = x;
			this.y = y;
			this.b = b;
		}
		
		
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N=sc.nextInt();
		M=sc.nextInt();
		board = new int[N][M];
		dist = new int[N][M][2];
		Queue<pair> q= new ArrayDeque<>();
		for(int i=0;i<N;i++) {
			String s= sc.next();
			for(int j=0;j<M;j++) {
				board[i][j]=s.charAt(j)-'0';			
			}
		}
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				dist[i][j][0]=-1;
				dist[i][j][1]=-1;
			}
		}
		q.add(new pair(0, 0, 0));
		dist[0][0][0]=1;
		dist[0][0][1]=1;
		while(!q.isEmpty()) {
			pair p=q.poll();
			int x =p.x;
			int y =p.y;
			int b =p.b;
			for(int i=0;i<4;i++) {
				int nx =x+dx[i];
				int ny=y+dy[i];
				if(nx<0||nx>=N||ny<0||ny>=M) continue;
				if(board[nx][ny]==0) {
					//지나갈 수 있음 
					if(dist[nx][ny][b]==-1) {
						dist[nx][ny][b]=dist[x][y][b]+1;
						q.add(new pair(nx, ny, b));
					}
				}else {
					//지나갈 수 없음 
					if(b==0) {
						board[nx][ny]=0;
						if(dist[nx][ny][1]==-1) {
							dist[nx][ny][1]=dist[x][y][0]+1;
							q.add(new pair(nx, ny, 1));
						}
						//안 깨는 방법
						board[nx][ny]=1;
					}
				}
			}
			
		}
		
		int a=dist[N-1][M-1][0];
		int b=dist[N-1][M-1][1];
		if(a==-1 && b==-1) {
			System.out.println(-1);
		}
		else if(a!=-1 && b!=-1) {
			System.out.println(Math.min(a, b));
		}
		else {
			System.out.println(a==-1?b:a);
		}
		
	}

}
