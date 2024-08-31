import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static int input[];
	static ArrayList<Integer> v[]; //인접 리스트 
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		input=new int[N+1]; //진입차수 표현 
		//1>4>3
		v=new ArrayList[N+1];
		for(int i=1;i<=N;i++) {
			v[i]=new ArrayList<Integer>();
		}
		//가수는 번호 N으로 표시  
		//M개의 순서  
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int k=Integer.parseInt(st.nextToken());
			
			int a = Integer.parseInt(st.nextToken());
			int b = 0;
			for(int j=0;j<k-1;j++) {
				b=Integer.parseInt(st.nextToken());
				input[b]++;
				v[a].add(b);
				a=b;
			}
		}
		//위상 정렬  
		Queue<Integer> q=new ArrayDeque<>();
		for(int i=1;i<=N;i++) {
			if(input[i]==0) {
				q.add(i);
			}
		}
		ArrayList<Integer> res=new ArrayList<>(); //결과 리스트 
		while(!q.isEmpty()) {
			int cur = q.poll();
			//cur과 연결된 간선의 갯수를 -1
			//input이 0이되면 다시 q에 넣음 
			res.add(cur);
			for(int i:v[cur]) {
				input[i]--;
				if(input[i]==0) {
					q.add(i);
				}
			}
		}
		if(res.size()!=N) {
			System.out.println(0); //사이클 발생  
		}else {
			for(int i=0;i<res.size();i++) {
				System.out.println(res.get(i));
			}
		}
	}

}
