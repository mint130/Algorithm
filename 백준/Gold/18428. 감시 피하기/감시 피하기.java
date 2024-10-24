import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static List<int[]> student;
	static boolean flag;
	static char board[][];
	static int dx[]= {1, 0, -1, 0};
	static int dy[]= {0, 1, 0, -1};
	static boolean isOk() {
		//감시 피할수있는지 
		for(int cur[]:student) {
			int x = cur[0];
			int y = cur[1];
			//상 
			//하
			//좌
			//우 
			boolean o=false;
			for(int i=x;i>=0;i--) {
				//상 
				if(board[i][y]=='O') o=true;
				if(board[i][y]=='T' && !o) return false;
			}
			o=false;
			for(int i=x;i<N;i++) {
				//하 
				if(board[i][y]=='O') o=true;
				if(board[i][y]=='T' && !o) return false;
			}
			o=false;
			for(int i=y;i>=0;i--) {
				if(board[x][i]=='O') o=true;
				if(board[x][i]=='T' && !o) return false;
			}
			o=false;
			for(int i=y;i<N;i++) {
				if(board[x][i]=='O') o=true;
				if(board[x][i]=='T' && !o) return false;
			}
		}
		return true;
	}
	static void dfs(int cnt) {
		if(cnt==3) {
			if(flag) {
				//이미 피할수있음 
				return;
			}
			else {
				//학생들을 감시로부터 피하도록 할 수 있음 
				if(isOk()) {
					flag=true;
					return;
				}
			}	
			
			return;
		
		}
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(board[i][j]=='X') {
					//빈칸에 장애물 넣음 
					board[i][j]='O';
					dfs(cnt+1);
					board[i][j]='X';
				}
				
			}
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st =new StringTokenizer(br.readLine());
		N=Integer.parseInt(st.nextToken());
		board =new char[N][N];
		student = new ArrayList<>();
		for(int i=0;i<N;i++) {
			st=new StringTokenizer(br.readLine());
			for(int j=0;j<N;j++) {
				String s = st.nextToken();
				board[i][j]=s.charAt(0);
				if(board[i][j]=='S') {
					student.add(new int[] {i,j});
				}
			}
		}
		
		dfs(0);
		if(flag) System.out.println("YES");
		else System.out.println("NO");
		
	}

}
