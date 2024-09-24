import java.util.Arrays;
import java.util.Scanner;

public class Main {

	static int N, C;
	static long home[], ans;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		C = sc.nextInt();
		ans=0;
		home= new long [N];
		for(int i=0;i<N;i++) {
			home[i]=sc.nextLong();
		}
		Arrays.sort(home);
		long st=1;
		long en=home[N-1]-home[0]; //가장 인접한 거리 찾기 -> 최대는 가장 큰 위치 - 가장 작은 위치 
		while(st<=en) {
			long mid = (st+en)/2;
			int cnt = 1;
			int s=0, e=0;
			while(s<=e && e<N) {
				if(home[e]-home[s]<mid) {
					//아직 인접한 거리 못찾음 
					e++;
				}
				else {
					cnt++;
					s=e;
				}
			}
	
			if(cnt>=C) {
				ans=Math.max(ans, mid);
				st=mid+1;
				//최대 거리 구해야 하므로 
			}
			else {
				en=mid-1;
			}
			
		}
		
		System.out.println(ans);
	}

}
