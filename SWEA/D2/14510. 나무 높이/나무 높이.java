import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	static int T, N, ans, tree[], max, even, odd;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		T = Integer.parseInt(st.nextToken());
		for (int tc = 1; tc <= T; tc++) {
			ans = 0;
			max = 0;
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken()); // 나무 갯수
			tree = new int[N];
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				tree[i] = Integer.parseInt(st.nextToken());
				max = Math.max(tree[i], max);
			}
			even = 0; // 짝수날에 물을 몇번 줘야하는지
			odd = 0; // 홀수날에 물을 몇번 줘야하는지

			// max가 가장 큰 나무의 높이
			for (int i = 0; i < N; i++) {
				int num = max - tree[i];
				if (num == 0) continue;
				even += num / 2;
				odd += num % 2;
			}

			// 짝수가 홀수보다 크다면 짝수날을 홀수날 2번으로 바꿀 수 있음
			// 둘의 차이를 최대한 줄인다

			if (even > odd) {
				while (Math.abs(odd - even) > 1) {
					// 둘의 차이가 1보다 작거나 같아질 때까지
					even--;
					odd += 2;
				}
			}
			if (even == odd) {
				ans = even + odd;
			} else if (even > odd) {
				ans = even * 2;
			} else {
				ans = 2 * odd - 1;
			}
			System.out.println("#" + tc + " " + ans);
		}

	}

}
