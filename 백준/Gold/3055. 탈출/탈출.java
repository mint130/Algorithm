import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	static class Point{
		int x, y;
		public Point(int x, int y) {
			this.x=x;
			this.y=y;
		}
	}
	static int dx[]= {1, 0, -1, 0};
	static int dy[]= {0, 1, 0, -1};
	static char map[][];

	static int R, C, destX, destY, startX, startY;
	static Queue<Point> water = new ArrayDeque<>();
	static Queue<Point> dochi = new ArrayDeque<>();
	static int move[][]; //고슴도치가 움직이는 경로 
	static int wet[][]; //물이 움직이는 경로 
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		R=sc.nextInt();
		C=sc.nextInt();
		map=new char[R][C];
		move=new int[R][C];
		wet=new int[R][C];
		for(int i=0;i<R;i++) {
			Arrays.fill(wet[i], -1);
			Arrays.fill(move[i], -1);
		}
		//visit=new boolean[R][C];
		for(int i=0;i<R;i++) {
			String str=sc.next();
			for(int j=0;j<C;j++) {
				map[i][j]=str.charAt(j);
				if(map[i][j]=='*') {
					//물
					water.add(new Point(i, j));
					wet[i][j]=0; 
				}
				if(map[i][j]=='D') {destX=i; destY=j;}
				if(map[i][j]=='S') {startX=i; startY=j;}
			}
		}
		//물의 도착 시간 먼저
		while(!water.isEmpty()) {
			int x=water.peek().x;
			int y=water.peek().y;
			water.poll();
			for(int dir=0;dir<4;dir++) {
				int nx=x+dx[dir];
				int ny=y+dy[dir];
				if(nx<0||nx>=R||ny<0||ny>=C) continue;
				if(wet[nx][ny]!=-1 || map[nx][ny]=='X' || map[nx][ny]=='D') continue;
				//돌, 비버 못지나감
				wet[nx][ny]=wet[x][y]+1;
				water.add(new Point(nx, ny));
			}
		}
		
		//도치 이동 
		move[startX][startY]=0; //물이 먼저 도착하면 이동할 수 없다=water[i][j]>move[i][j]면 이동 
		dochi.add(new Point(startX, startY));
		while(!dochi.isEmpty()) {
			int x=dochi.peek().x;
			int y=dochi.peek().y;
			dochi.poll();
			if(x==destX && y==destY) {
				System.out.println(move[x][y]);
				return;
			}
			for(int dir=0;dir<4;dir++) {
				int nx=x+dx[dir];
				int ny=y+dy[dir];
				if(nx<0||nx>=R||ny<0||ny>=C) continue;
				if(move[nx][ny]!=-1 || map[nx][ny]=='X') continue;
				//wet[nx][ny]>move[nx][ny]||wet[nx][ny]==-1면 이동 가능 
				if(wet[nx][ny]>move[x][y]+1||wet[nx][ny]==-1) {		
					//갈 수 있음 
					move[nx][ny]=move[x][y]+1;
					dochi.add(new Point(nx, ny));
				}
				else {
					//갈 수 없음 
					map[nx][ny]='X';
				}
				
				
			}
		}
		
		System.out.println("KAKTUS");
	}

}
