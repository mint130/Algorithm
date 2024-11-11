import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static ArrayList<Integer> list[];
	static int K;
	static int ans;
	static boolean check[];
	static void rotate(int num, int dir) {

		check[num]=true; //이미 회전한 톱니를 다시 돌리는 경우 방지하기 위해 방문배열 
		
		// 오른쪽과 닿 idx:2, 왼쪽과 닿는 idx: 6
		int right = list[num].get(2);
		int left = list[num].get(6);
		

		//num을 dir로 회전 
		if(dir==-1) {
			//반시계 
			int first=list[num].get(0);
			list[num].add(first);
			list[num].remove(0);

		}
		else {
			//시계 
			int last=list[num].get(7);
			list[num].add(0, last);
			list[num].remove(list[num].size()-1);
			
		}

		int prev=0;
		int nxt=0;
		// num번째를 dir로 회전하기 위해서는 nxt에 있는 톱니바퀴의 6번째, prev에 있는 톱니바퀴의 2번째 확인
		if(num!=0) prev=list[num-1].get(2);
		if(num!=3) nxt=list[num+1].get(6);
		//맞닿은 톱니가 다르다면 반대로 회전 
		if(prev!=left) {
			if(num-1>=0 && !check[num-1]) rotate(num-1, 0-dir);
		}
		if(nxt!=right) {
			if(num+1<4 && !check[num+1]) rotate(num+1, 0-dir);
		}
		
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		list = new ArrayList[4];
		for (int i = 0; i < 4; i++) {
			list[i] = new ArrayList<>();
			st = new StringTokenizer(br.readLine());
			String str = st.nextToken();
			for (int j = 0; j < 8; j++) {
				int n = str.charAt(j) - '0';
				list[i].add(n);
			}

		}

		st = new StringTokenizer(br.readLine());
		K = Integer.parseInt(st.nextToken());
		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			int num = Integer.parseInt(st.nextToken()) - 1;
			int dir = Integer.parseInt(st.nextToken());
			check=new boolean[4];
			rotate(num, dir);
			
			
		}
		for(int i=0;i<4;i++) {
			if(list[i].get(0)==1) {
				ans += Math.pow(2, i);
			}
		}
		System.out.println(ans);

	}

}
