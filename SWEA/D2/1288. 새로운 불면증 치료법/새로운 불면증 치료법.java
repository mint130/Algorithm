import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Solution {

	static int n;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int T =Integer.parseInt(st.nextToken());
		
		for(int tc=1;tc<=T;tc++) {
			st = new StringTokenizer(br.readLine());
			n =Integer.parseInt(st.nextToken());
			int first = n;
			Set<Integer> set = new TreeSet<>();
			int k = 1;
			while(set.size()!=10) {
				String s = Integer.toString(n);
				for(int i=0;i<s.length();i++) {
					set.add(s.charAt(i)-'0');
				}
				if(set.size()==10) {
					System.out.println("#"+tc+" "+first*k);
					break;
				}
				k++;
				n=first*k;
			}
		}

	}

}
