import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {

	static int N, T, minLen, maxCnt; 
	static class Point{
		int x, y;
		Point(int x, int y){
			this.x=x; this.y=y;
		}
	}
	static int map[][];
	static ArrayList<Point> list; //코어마다 방향 정해줌  
	static int dx[]= {1, 0, -1, 0};
	static int dy[]= {0, 1, 0, -1};
	static int core; //가장자리를 뺀 코어 갯수 
	static void dfs(int depth, int cnt, int len) {
		//cnt는 현재 연결한 코어 갯수
		//len은 현재 이어진 전선 갯수 
		if(depth==core) {
			//최대한 많은 코어에 전원 연결 
			if(cnt>maxCnt) {
				maxCnt=cnt;
				minLen=len;
			}
			else if(cnt==maxCnt) {
				//전선의 길이 최소
				minLen=Math.min(len, minLen);
			}
			return;
		}
		
		int x = list.get(depth).x;
		int y = list.get(depth).y;
		
		for(int dir=0;dir<4;dir++) {
			int nx=x;
			int ny=y;
			int count=0; //연결할 수 있는 전선 갯수 
			//dir 방향대로 가면서 끝에 닿는지 확인 
			while(true) {
				nx+=dx[dir];
				ny+=dy[dir];
				
				if(nx<0||nx>=N||ny<0||ny>=N) {
					//연결 가능 
					break;
				}
				
				if(map[nx][ny]==1) {
					//연결 불가 
					count=0;
					break;
				}
				
				count++;
			}
			int r=x;
			int c=y;
			//전선 갯수만큼 1로 채움 
			for(int i=0;i<count;i++) {
				r+=dx[dir];
				c+=dy[dir];
				map[r][c]=1;
			}
			
			if(count==0) {
				dfs(depth+1, cnt, len);
			}
			else {
				dfs(depth+1, cnt+1, len+count);
				//원상 복구 
				r=x;
				c=y;
				for(int i=0;i<count;i++) {
					r+=dx[dir];
					c+=dy[dir];
					map[r][c]=0;
				}
			}
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		T= Integer.parseInt(st.nextToken());
		for(int tc=1 ;tc<=T;tc++) {
			st =new StringTokenizer(br.readLine());
			core=0;
			N=Integer.parseInt(st.nextToken());
			map=new int[N][N];
			list= new ArrayList<>();
			maxCnt=0;
			minLen=Integer.MAX_VALUE;
			for(int i=0;i<N;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<N;j++) {
					map[i][j]=Integer.parseInt(st.nextToken());
					if(i==0 || j==0 || i==N-1 || j==N-1) continue;
					if(map[i][j]==1) {
						core++; //가장자리뺀 코어갯수 더해줌  
						list.add(new Point(i, j));
					}
				}
			}
			dfs(0, 0, 0);
			System.out.println("#"+tc+" "+minLen);
			
		}
	}

}
