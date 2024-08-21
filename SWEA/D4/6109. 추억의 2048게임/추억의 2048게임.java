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
	static void move(String S) {
		if(S.equals("left")) {
			for(int i=0;i<N;i++) {
				Queue<Integer> q = new LinkedList<>();
				for(int j=0;j<N;j++) {
					if(board[i][j]!=0) q.add(board[i][j]);
				}
				int idx = 0;
				while(!q.isEmpty()) {
					int top=q.poll(); //가장 위의 값
					if(q.size()>=1) {
						if(top==q.peek()) {
							board[i][idx]=top*2;
							q.poll();
						}
						else {
							board[i][idx]=top;
						}
					}
					else board[i][idx]=top;
					idx++;
				}
				while(idx<N) {
					board[i][idx]=0;
					idx++;
				}
			}
		}
		else if(S.equals("right")) {
			for(int i=0;i<N;i++) {
				Queue<Integer> q = new LinkedList<>();
				for(int j=N-1;j>=0;j--) {
					if(board[i][j]!=0) q.add(board[i][j]);
				}
				int idx = 0;
				while(!q.isEmpty()) {
					int top=q.poll(); //가장 위의 값
					if(q.size()>=1) {
						if(top==q.peek()) {
							board[i][N-1-idx]=top*2;
							q.poll();
						}
						else {
							board[i][N-1-idx]=top;
						}
					}
					else board[i][N-1-idx]=top;
					idx++;
				}
				while(idx<N) {
					board[i][N-1-idx]=0;
					idx++;
				}
			}
			
		}
		else if(S.equals("up")) {
			for(int i=0;i<N;i++) {
				Queue<Integer> q = new LinkedList<>();
				for(int j=0;j<N;j++) {
					if(board[j][i]!=0) q.add(board[j][i]);
				}
				int idx = 0;
				while(!q.isEmpty()) {
					int top=q.poll(); //가장 위의 값
					if(q.size()>=1) {
						if(top==q.peek()) {
							board[idx][i]=top*2;
							q.poll();
						}
						else {
							board[idx][i]=top;
						}
					}
					else board[idx][i]=top;
					idx++;
				}
				while(idx<N) {
					board[idx][i]=0;
					idx++;
				}
			}
		}
		else {
			for(int i=0;i<N;i++) {
				Queue<Integer> q = new LinkedList<>();
				for(int j=N-1;j>=0;j--) {
					if(board[j][i]!=0) q.add(board[j][i]);
				}
				int idx = 0;
				while(!q.isEmpty()) {
					int top=q.poll(); //가장 위의 값
					if(q.size()>=1) {
						if(top==q.peek()) {
							board[N-1-idx][i]=top*2;
							q.poll();
						}
						else {
							board[N-1-idx][i]=top;
						}
					}
					else board[N-1-idx][i]=top;
					idx++;
				}
				while(idx<N) {
					board[N-1-idx][i]=0;
					idx++;
				}
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
			for(int i=0;i<N;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<N;j++) {
					board[i][j]=Integer.parseInt(st.nextToken());
				}
			}
			move(S);
			System.out.println("#"+tc);
			print();
		}
	}
}
