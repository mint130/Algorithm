import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

//SWEA 4008 숫자 만들기
public class Solution {
	
	static int T, N;
	static int op[]=new int[4]; //연산자 갯수 저장
	static int arr[];
	static int max =-987654321; //음수가 max인 경우도 가능하기 때문에 0이 아님 유의
	static int min=987654321;
	public static void main(String[] args) throws IOException {
		//숫자의 순서는 안바뀜
		//연산자 순서 바뀜
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		T=Integer.parseInt(st.nextToken());
		for(int tc = 1;tc<=T;tc++) {
			max =-987654321;
			min=987654321;
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<4;i++) {
				op[i]=Integer.parseInt(st.nextToken());
			}
			arr=new int[N];
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<N;i++) {
				arr[i]=Integer.parseInt(st.nextToken());
			}
			dfs(0, arr[0]); //sum의 초기값 0이 아니고 arr[0]
			System.out.println("#"+tc+" "+(max-min));
		}
	}
	static void dfs(int depth, int sum) {
		//중복 순열
		if(depth==N-1) {
            //max, min 연산
			max=Math.max(max, sum);
			min=Math.min(min, sum);
			return;
		}
		for(int i=0;i<4;i++) {
			if(op[i]==0) continue; //연산자의 갯수가 0이면 건너뜀
			op[i]--;
			if(i==0) dfs(depth+1, sum+arr[depth+1]);
			if(i==1) dfs(depth+1,  sum-arr[depth+1]);
			if(i==2) dfs(depth+1,  sum*arr[depth+1]);
			if(i==3) dfs(depth+1,  sum/arr[depth+1]);
			op[i]++;
		}
	}

}
