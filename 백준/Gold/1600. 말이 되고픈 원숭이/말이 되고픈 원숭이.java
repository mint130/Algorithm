import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	static int K, m, n, board[][], move[][][];
	static int dx[]= {1, 0, -1, 0};
	static int dy[]= {0, 1, 0, -1};	
	static int horsex[]= {1, 1, -1, -1, 2, 2, -2, -2};
	static int horsey[]= {2, -2, 2, -2, 1, -1, 1, -1};	
	static class pair{
		int x, y, k;

		public pair(int x, int y, int k) {
			super();
			this.x = x;
			this.y = y;
			this.k = k;
		}
		
		
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		K=sc.nextInt();
		m=sc.nextInt(); 
		n=sc.nextInt(); 
		board = new int[n][m];
		move = new int[n][m][K+1];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				for(int l=0;l<=K;l++) {
					move[i][j][l]=-1;
				}
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				board[i][j]=sc.nextInt();
			}
		}
		Queue<pair> q= new ArrayDeque<>();
		q.add(new pair(0, 0, K));
		move[0][0][K]=0;
		while(!q.isEmpty()) {
			pair p=q.poll();
			int x=p.x;
			int y=p.y;
			int k=p.k;
			
			//k가 0보다 크면 말처럼 움직일 수 있음, 말은 장애물을 뛰어넘을 수 있음 
			int nx=0;
			int ny=0;
			if(k>0) {
				//말 처럼 움직일 수 있음 
				//말처럼 움직이는 경우 
				for(int i=0;i<8;i++) {
					nx=x+horsex[i];
					ny=y+horsey[i];
					if(nx<0||nx>=n||ny<0||ny>=m) continue;
					if(board[nx][ny]==1) continue;
					
					if(move[nx][ny][k-1]==-1) {
						move[nx][ny][k-1]=move[x][y][k]+1;
						q.add(new pair(nx, ny, k-1));
					}
 				}
				
				//말처럼 안 움직이는 경우 
				for(int i=0;i<4;i++) {
					nx=x+dx[i];
					ny=y+dy[i];
					if(nx<0||nx>=n||ny<0||ny>=m) continue; 
					if(board[nx][ny]==1) continue;
					if(move[nx][ny][k]==-1) {
						move[nx][ny][k]=move[x][y][k]+1;
						q.add(new pair(nx, ny, k));
					}
				}
			
			}
			else {
				//그냥 원래대로 움직여야 함 
				for(int i=0;i<4;i++) {
					nx=x+dx[i];
					ny=y+dy[i];
					if(nx<0||nx>=n||ny<0||ny>=m) continue; 
					if(board[nx][ny]==1) continue;
					if(move[nx][ny][k]==-1) {
						move[nx][ny][k]=move[x][y][k]+1;
						q.add(new pair(nx, ny, k));
					}
				}
				
			}
			
			
		}
		
		int res = Integer.MAX_VALUE;
		boolean flag=false;
		for(int i=0;i<=K;i++) {
			if(move[n-1][m-1][i]!=-1) {
				flag=true;
				res=Math.min(res, move[n-1][m-1][i]);
			}
			
		}
		if(res==Integer.MAX_VALUE) System.out.println(-1);
		else System.out.println(res);
	}

}
