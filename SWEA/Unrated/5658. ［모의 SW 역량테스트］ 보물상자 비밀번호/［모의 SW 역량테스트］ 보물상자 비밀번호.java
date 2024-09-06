import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Deque;
import java.util.List;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Solution {

	static int T, N, K;
	static TreeSet<String> set;
	public static void main(String[] args) throws IOException {
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		T=Integer.parseInt(st.nextToken());
		
		for(int tc=1;tc<=T;tc++) {
			st= new StringTokenizer(br.readLine());
			N=Integer.parseInt(st.nextToken());
			K=Integer.parseInt(st.nextToken());
			int n=N/4; //한변에 있는 문자열 길이  
			set= new TreeSet<>(Collections.reverseOrder());
			String str=br.readLine();	
			StringBuilder sb;
			//dq에 들어가있음 
			int i=0;
			while(i++<=n-1) {
				//회전 
				sb=new StringBuilder();
				sb.append(str); 
				for(int j=0;j<str.length();j+=n) {
					//잘라서 넣음 
					String s=sb.substring(j, j+n);
					//System.out.println(s);
					set.add(s); //set에 넣음 
				}
				sb.insert(0, str.charAt(str.length()-1)); 
				sb.deleteCharAt(sb.length()-1);
				str=sb.toString();
				//뒤에서 앞으로 보냄 
				//System.out.println(sb);
			}
			List <String> list= new ArrayList<>(set);
			String res=list.get(K-1);
			System.out.println("#"+tc+" "+Long.parseLong(res, 16));
		}

	}

}
