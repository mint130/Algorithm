import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static int N, M, x, y, k;
	static int dx[] = { 0, 0, -1, 1 };
	static int dy[] = { 1, -1, 0, 0 }; // 동 서 북 남
	static int board[][];
	static int[] diceR; // 세로 2 1 5 6 (가장 마지막이 아랫면)
	static int[] diceC; // 가로 4 1 3 6 (가장 마지막이 아랫면)

	static int roll(int dir, int x, int y) {
		if (dir == 0) {
			// 동
			int last = diceC[3];
			for (int i = 3; i >= 1; i--) {
				diceC[i] = diceC[i - 1];
			}
			diceC[0] = last;
			diceR[3] = diceC[3];
			diceR[1] = diceC[1];
		} else if (dir == 1) {
			// 서
			int first = diceC[0];
			for (int i = 0; i < 3; i++) {
				diceC[i] = diceC[i + 1];
			}
			diceC[3] = first;
			diceR[3] = diceC[3];
			diceR[1] = diceC[1];
		} else if (dir == 2) {
			// 북
			int first = diceR[0];
			for (int i = 0; i < 3; i++) {
				diceR[i] = diceR[i + 1];
			}
			diceR[3] = first;
			diceC[3] = diceR[3];
			diceC[1] = diceR[1];
		} else {
			int last = diceR[3];
			for (int i = 3; i >= 1; i--) {
				diceR[i] = diceR[i - 1];
			}
			diceR[0] = last;
			diceC[3] = diceR[3];
			diceC[1] = diceR[1];
		}

		if (board[x][y] == 0) {
			// 이동한 칸에 쓰인 수가 0이면 바닥 수->칸 복사
			board[x][y] = diceR[3];
		} else {
			// 이동한 칸에 쓰인 수가 0이 아니면 칸->바닥
			diceR[3] = board[x][y];
			diceC[3] = board[x][y];
			board[x][y] = 0;
		}
		return diceR[1];
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		diceR = new int[4];
		diceC = new int[4];

		board = new int[N][M];
		x = Integer.parseInt(st.nextToken());
		y = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < k; i++) {
			int dir = Integer.parseInt(st.nextToken()) - 1;
			// 명령
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			// 주사위 굴림
			// 윗면에 쓰인 수 출력
			System.out.println(roll(dir, nx, ny));
			x = nx;
			y = ny;

		}

	}

}
