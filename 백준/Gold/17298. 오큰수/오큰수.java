import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {
	private static class Number {
		int idx, value;
		
		Number(int idx, int value) {
			this.idx = idx;
			this.value = value;
		}
	}
	
	private static int N;
	private static int[] Numbers;
	
	public static void main(String[] args) throws Exception {

		// stack? -> 내림차순을 유지해야겠네
		// stack.top < Ai   -> Ai > stack.top인 top들은 모두 Ai가 오큰수
		// stack.top >= Ai  -> 아직 오큰수를 모르므로 삽입만 ㄱㄱ
		// 스택에는 그러면 (인덱스, 숫자) 이렇게 저장을 해야겠네
		
		// 1. 입력 받기
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in), 1 << 16);
		N = Integer.parseInt(br.readLine());
		Numbers = new int[N];
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++)	Numbers[i] = Integer.parseInt(st.nextToken());
		
		// 2. 오큰수 찾기
		ArrayDeque<Number> stack = new ArrayDeque<>();
		int[] answers = new int[N];
		
		for (int i = 0; i < N; i++) {
			if (!stack.isEmpty() && stack.getLast().value < Numbers[i]) {
				// Ai > top일 때 -> 스택에 있는 숫자들 중 이 숫자보다 작은 숫자들은 모두 Ai가 오큰수
				while (!stack.isEmpty() && stack.getLast().value < Numbers[i]) {
					Number num = stack.pollLast();
					answers[num.idx] = Numbers[i];
				}
			}
			
			// 스택이 비었거나, top >= Ai -> 그냥 넣기
			stack.add(new Number(i, Numbers[i]));
		}
		
		// 스택에 남아 있는 애들은 모두 오큰수가 없는 애들
		while (!stack.isEmpty()) {
			Number num = stack.pollLast();
			answers[num.idx] = -1;
		}
		
		// 3. 정답 출력
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < N; i++)	sb.append(answers[i]).append(" ");
		
		System.out.println(sb.toString());
		br.close();
	}
}