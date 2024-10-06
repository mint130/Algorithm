import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int N, M, startX, startY;	//출구는 적어도 한개 
	static char board[][];
	static int dx[]= {1, 0, -1, 0};
	static int dy[]= {0, 1, 0, -1};
	static int move[][][];
	static int min=Integer.MAX_VALUE;
	static class point{
		int x, y, key;
		//boolean key[]; // a b c d e f 
		public point(int x, int y, int key) {
			super();
			this.x = x;
			this.y = y;
			this.key = key;
		}
		
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		board=new char[N][M];
		move=new int[N][M][(1<<6)];
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				for(int k=0;k<64;k++) {
					move[i][j][k]=-1;
				}
			}
		}
		Queue<point> q = new ArrayDeque<>();
		//key를 가지고 있는 경우의 수 
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			String s = st.nextToken();
			for(int j=0;j<M;j++) {
				board[i][j]=s.charAt(j);
				if(board[i][j]=='0') {
					startX=i;
					startY=j;
				}
			}
			
		}
		//시작점 
		move[startX][startY][0]=0; 
		q.add(new point(startX, startY, 0));
		
		
		while(!q.isEmpty()) {
			point p = q.poll();
			int x = p.x;
			int y = p.y;
			int key = p.key; //지금 갖고 있는 열쇠 정보 
			
			if(board[x][y]=='1') {
				//미로 탈출 
				for(int i=0;i<64;i++) {
					//System.out.println(move[x][y][i]);
					if(move[x][y][i]==-1) continue;
					min=Math.min(min, move[x][y][i]);
				}
				System.out.println(min);
				return;
			}
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx<0||nx>=N||ny<0||ny>=M) continue; 
				if(board[nx][ny]=='#') continue; //언제나 이동할 수 없는 벽 
				if(board[nx][ny]=='.' || board[nx][ny]=='1' || board[nx][ny]=='0') {
					//이미 들렀던 곳인지 확인 
					if(move[nx][ny][key]==-1) {
						move[nx][ny][key]=move[x][y][key]+1;
						q.add(new point(nx, ny, key));
					}
				}
				else if(board[nx][ny]=='a'||board[nx][ny]=='b'||board[nx][ny]=='c'
				||board[nx][ny]=='d'||board[nx][ny]=='e'||board[nx][ny]=='f') {
					int k=board[nx][ny]-'a';
					int nkey=key|(1<<k);
					// 열쇠 흭득 
					if(move[nx][ny][nkey]==-1) {
						//이 열쇠를 가지고 온 적이 없음 
						move[nx][ny][nkey]=move[x][y][key]+1;
						q.add(new point(nx, ny, nkey));
					}
					
				}
				else if(board[nx][ny]=='A'||board[nx][ny]=='B'||board[nx][ny]=='C'
						||board[nx][ny]=='D'||board[nx][ny]=='E'||board[nx][ny]=='F') {
					int k=board[nx][ny]-'A';
					if((key&(1<<k))!=0) {
						//k번째 키가 있음 -> 건너갈 수 있음  
						if(move[nx][ny][key]==-1) {
							move[nx][ny][key]=move[x][y][key]+1;
							q.add(new point(nx ,ny, key));
						}
					} 
					
				}
			}
			
			
		}
		System.out.println(-1);

	}

}
