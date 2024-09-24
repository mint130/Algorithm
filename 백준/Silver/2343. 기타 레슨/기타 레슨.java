import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, M, arr[], ans;
	static int start, end; 
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		start=0;
		arr=new int[N];
		st=new StringTokenizer(br.readLine());
		for(int i=0;i<N;i++) {
			arr[i]=Integer.parseInt(st.nextToken());
			start=Math.max(arr[i], start);
			end+=arr[i];
		}
		ans=Integer.MAX_VALUE;
		//start는 블루레이 중 가장 작은 값
		//end는 전부 합
		//mid는 블루레이의 최종 크기
		int mid=0;
		while(start<=end) {
			mid=(start+end)/2;
			int cnt=1;
			int sum=0;
			for(int i=0;i<N;i++) {
				if(sum+arr[i]>mid) {
					cnt++;
					sum=arr[i];
				}
				else {
					sum+=arr[i];
				}
			}
			if(cnt<=M) {
				end=mid-1;
			}
			else {
				//분 늘려야 함
				start=mid+1;
			}
		}
		System.out.println(start);
		
	}

}
