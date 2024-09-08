import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N, S, len, ans;
	static int arr[];
	static long sum;
	public static void main(String[] args) throws IOException {
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N=Integer.parseInt(st.nextToken());
		S=Integer.parseInt(st.nextToken());
		arr=new int[N+1];
		st=new StringTokenizer(br.readLine());
		for(int i=0;i<N;i++) {
			arr[i]=Integer.parseInt(st.nextToken());
		}
		ans=Integer.MAX_VALUE; //가장 긴 길이 
		int s=0;
		int e=0; 
		sum=arr[0]; //시작 
		while(e<N && s<=e) {
			if(sum<S) {
				//아직 누적합보다 작다 
				e++;
				sum+=arr[e]; 
			}
			else {
				//누적합보다 크다 
				len=e-s+1;
				ans=Math.min(ans, len); //길이가 더 작다면 갱신 
				sum-=arr[s];
				s++;
			}
		}
		if(ans==Integer.MAX_VALUE) ans=0;
		System.out.println(ans);
	}

}
