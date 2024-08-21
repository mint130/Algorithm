import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
	
	static int T, N;
	static int dir;
	static int board[][];
	static int temp[][];
	static void move(int a, int b) {
		//0 0 left 
		//0 1 right
		//1 0 up
		//1 1 down
		
		//a가 0이면 board[i][j]
		//a가 1이면 board[j][i]
		//b가 0이면 0부터 N-1
		//b가 1이면 N-1부터 0
		
		for(int i=0;i<N;i++) {
			Queue<Integer> q = new LinkedList<>();
			int ni=0;
			int nj=0;
			for(int j=0;j<N;j++) {
				if(a==0 && b==0) {ni=i; nj=j;}
				if(a==1 && b==0) {ni=j; nj=i;}
				if(a==0 && b==1) {ni=i; nj=N-1-j;}
				if(a==1 && b==1) {ni=N-1-j; nj=i;}
				if(board[ni][nj]!=0) q.add(board[ni][nj]);
			}
			int idx = 0;
			while(!q.isEmpty()) {
				int top = q.poll();
				if(!q.isEmpty() && top==q.peek()) {
					top*=2;
					q.poll();
				}
				if(a==0 && b==0) {ni=i; nj=idx;}
				if(a==1 && b==0) {ni=idx; nj=i;}
				if(a==0 && b==1) {ni=i; nj=N-1-idx;}
				if(a==1 && b==1) {ni=N-1-idx; nj=i;}
				board[ni][nj]=top;
				idx++;
			}
			while(idx<N) {
				if(a==0 && b==0) {ni=i; nj=idx;}
				if(a==1 && b==0) {ni=idx; nj=i;}
				if(a==0 && b==1) {ni=i; nj=N-1-idx;}
				if(a==1 && b==1) {ni=N-1-idx; nj=i;}
				board[ni][nj]=0;
				idx++;
			}
		}
	
	}

	static void print() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				System.out.print(board[i][j]+" ");
			}
			System.out.println();
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		T=Integer.parseInt(st.nextToken());
		
		for(int tc=1;tc<=T;tc++) {
			
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			String S = st.nextToken();

			board=new int[N][N];
			temp=new int[N][N];
			for(int i=0;i<N;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<N;j++) {
					board[i][j]=Integer.parseInt(st.nextToken());
					temp[i][j]=board[i][j];
				}
			}
			switch(S) {
			case "left":
				move(0, 0);
				break;
			case "right":
				move(0, 1);
				break;
			case "up":
				move(1, 0);
				break;
			case "down":
				move(1, 1);
				break;
			}
			
			System.out.println("#"+tc);
			print();
		}
	}
}
