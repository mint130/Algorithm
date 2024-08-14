import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Solution {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int T =10;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		for(int tc=1;tc<=T;tc++) {
			st = new StringTokenizer(br.readLine());
			int n= Integer.parseInt(st.nextToken()); //문자의 길이
		
			st = new StringTokenizer(br.readLine());
			String str = st.nextToken();
			
			int flag = 1; //1은 유효, 0은 유효하지 않음
			Stack<Character> s = new Stack<Character>();
			for(int i=0;i<str.length();i++) {
				char ch=str.charAt(i);
				if(ch=='}'||ch==']'||ch=='>'||ch==')') {
					if(!s.empty()) {
						char ch2=s.pop();

						if(ch-ch2==2 || ch-ch2==1) {
						
						}
						else {
							flag=0;
							break;
						}
					}
				}
				else {
					s.add(ch);
				}
				
			}
			
			
			System.out.println("#"+tc+" "+flag);
		}
		
	
		
	}

}
