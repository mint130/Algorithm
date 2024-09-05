import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	static boolean flag=true;
	static int T;
	static int change(char c) {
		if(c=='B') {
			return 2;
		}
		if(c=='A'||c=='D'||c=='O'||c=='P'||c=='Q'||c=='R') {
			return 1;
		}
		return 0;
				
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
	
		T=Integer.parseInt(st.nextToken());
		for(int tc=1;tc<=T;tc++) {
			flag=true;
			st=new StringTokenizer(br.readLine());
			String str1=st.nextToken();
			String str2=st.nextToken();
			if(str1.length()!=str2.length()) {
				flag=false;
			}
			if(flag) {
				for(int i=0;i<str1.length();i++) {
					char c1=str1.charAt(i);
					char c2=str2.charAt(i);

					int i1=change(c1);
					int i2=change(c2);

					if(i1!=i2) {
						flag=false;
						break;
					}
					
				}	
			}
			
			System.out.print("#"+tc+" ");
			System.out.println(flag?"SAME":"DIFF");
		}
	
	}

}
