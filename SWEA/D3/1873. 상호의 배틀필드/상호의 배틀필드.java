import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Solution {

	static int T, H, W, N;
	static int x, y; //전차의 좌표 
	static int dir=0; //위 0 아래 1 왼 2 오른 3
	static int dx[]= {-1, 1, 0, 0};
	static int dy[]= {0, 0, -1, 1};
	static char map[][];
	static void func(char ch) {
		switch (ch) {
		case 'S':
			//dir방향으로 ++하다가 *만나면 *를 .로 바꾸고 멈춤
			//#만나면 멈춤
			//만나지 않으면 맵 밖 나갈떄까지 ++

			for(int i=0;i<N;i++) {
				int nx=dx[dir]*i+x;
				int ny=dy[dir]*i+y;
				if(nx<0 || nx>=H || ny<0 || ny>=W) return;
				if(map[nx][ny]=='*') {
					map[nx][ny]='.';
					return;
				}
				if(map[nx][ny]=='#') break;
			}
			break;
		case 'U':
			//위쪽으로 바꾸고 
			dir = 0;
			map[x][y]='^';
			//한칸 위가 평지라면 이동
			if(x-1>=0 & x-1<H) {
				if(map[x-1][y]=='.') {
					map[x][y]='.'; //기존 맵 바꿔줌 
					map[x-1][y]='^';
					x=x-1; //전차 좌표 갱신 
				}
			}
			break;
		case 'D':
			//아래쪽으로 바꾸고
			dir = 1;
			map[x][y]='v';
			//한칸 아래 평지라면 이동
			if(x+1>=0 && x+1<H) {
				if(map[x+1][y]=='.') {
					map[x][y]='.';
					map[x+1][y]='v';
					x=x+1;
				}
			}
			break;
		case 'L':
			dir = 2;
			map[x][y]='<';
			if(y-1>=0 && y-1<W) {
				if(map[x][y-1]=='.') {
					map[x][y]='.';
					map[x][y-1]='<';
					y=y-1;
				}
			}
			break;
		case 'R':
			dir = 3;
			map[x][y]='>';
			if(y+1>=0 && y+1<W) {
				if(map[x][y+1]=='.') {
					map[x][y]='.';
					map[x][y+1]='>';
					y=y+1;
				}
			}
			break;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		T = Integer.parseInt(st.nextToken());
		for(int tc=1;tc<=T;tc++) {
			st = new StringTokenizer(br.readLine());
			H = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
			map = new char[H][W];
			for(int i=0;i<H;i++) {
				st = new StringTokenizer(br.readLine());
				String s= st.nextToken();
				for(int j=0;j<W;j++) {
					
					map[i][j]=s.charAt(j);
					
					if(map[i][j]=='^') {
						x=i;
						y=j;
						dir=0;
					}
					else if(map[i][j]=='v') {
						x=i;
						y=j;
						dir=1;
					}
					else if(map[i][j]=='<') {
						x=i;
						y=j;
						dir=2;
					}
					else if(map[i][j]=='>'){
						x=i;
						y=j;
						dir=3;
					}
				}
			}

			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			String s=st.nextToken();
			for(int i=0;i<N;i++) {
				char ch = s.charAt(i);
				func(ch);
			}
			
			System.out.print("#"+tc+" ");
			for(int i=0;i<H;i++) {
				for(int j=0;j<W;j++) {
					System.out.print(map[i][j]);					 
				}
				System.out.println();
			}
		}

	}

}
