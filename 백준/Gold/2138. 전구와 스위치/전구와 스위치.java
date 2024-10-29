import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, cnt1, cnt2, ans;
	static boolean now1[], now2[], res[];
	public static void main(String[] args) throws IOException {
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N=Integer.parseInt(st.nextToken());
		ans = Integer.MAX_VALUE;
		now1=new boolean[N];
		now2=new boolean[N];
		res=new boolean[N];
		st = new StringTokenizer(br.readLine());
		String str = st.nextToken();
		for(int i=0;i<N;i++) {
			if(str.charAt(i)=='0') now1[i]=false;
			else {
				now1[i]=true;
				now2[i]=true;
			}
		}
		st = new StringTokenizer(br.readLine());
		str = st.nextToken();
		for(int i=0;i<N;i++) {
			if(str.charAt(i)=='0') res[i]=false;
			else res[i]=true;
		}
		
		//첫번째 눌렀을 때
		cnt1=1;
		now1[0]=!now1[0];
		now1[1]=!now1[1];
		for(int i=1;i<N;i++) {
			if(now1[i-1]!=res[i-1]) {
				cnt1++;
				now1[i-1]=!now1[i-1];
				now1[i]=!now1[i];
				if(i==N-1) continue;
				now1[i+1]=!now1[i+1];
			}
		}
		if(now1[N-1]==res[N-1]) ans=Math.min(ans, cnt1);
		
		//첫번째 안 눌렀을 때 
		for(int i=1;i<N;i++) {
			if(now2[i-1]!=res[i-1]) {
				cnt2++;
				now2[i-1]=!now2[i-1];
				now2[i]=!now2[i];
				if(i==N-1) continue;
				now2[i+1]=!now2[i+1];
			}
		}
		if(now2[N-1]==res[N-1]) ans=Math.min(ans, cnt2);
		if(ans==Integer.MAX_VALUE) System.out.println(-1);
		else System.out.println(ans);
	}

}
