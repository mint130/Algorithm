import java.util.ArrayList;
import java.util.Arrays;

public class Solution {

    public static int[][] solution(int n, int[][] build_frame) {
        boolean[][][] map = new boolean[n + 1][n + 1][2];

        for (int[] frame : build_frame) {
            int x = frame[0], y = frame[1];
            int building = frame[2], operation = frame[3];

            if (operation == 0) { // 삭제
                map[y][x][building] = false;
                if (!isValid(map, n)) { // 전체 구조물 안정성 확인
                    map[y][x][building] = true;
                }
            } else { // 설치
                map[y][x][building] = true;
                if (!isValid(map, n)) { // 전체 구조물 안정성 확인
                    map[y][x][building] = false;
                }
            }
        }

        ArrayList<int[]> list = new ArrayList<>();
        for (int y = 0; y <= n; y++) {
            for (int x = 0; x <= n; x++) {
                if (map[y][x][0]) list.add(new int[]{x, y, 0});
                if (map[y][x][1]) list.add(new int[]{x, y, 1});
            }
        }

        int[][] answer = new int[list.size()][];
        for (int i = 0; i < list.size(); i++) answer[i] = list.get(i);

        Arrays.sort(answer, (a, b) -> {
            if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
            else if (a[1] != b[1]) return Integer.compare(a[1], b[1]);
            else return Integer.compare(a[2], b[2]);
        });

        return answer;
    }

    private static boolean isValid(boolean[][][] map, int n) {
        for (int y = 0; y <= n; y++) {
            for (int x = 0; x <= n; x++) {
                if (map[y][x][0] && !canPlaceColumn(map, x, y)) return false;
                if (map[y][x][1] && !canPlaceBeam(map, x, y)) return false;
            }
        }
        return true;
    }

    private static boolean canPlaceColumn(boolean[][][] map, int x, int y) {
        return y == 0 || (y > 0 && map[y - 1][x][0]) || (x > 0 && map[y][x - 1][1]) || map[y][x][1];
    }

    private static boolean canPlaceBeam(boolean[][][] map, int x, int y) {
        return (y > 0 && map[y - 1][x][0]) || (y > 0 && map[y - 1][x + 1][0]) || (x > 0 && map[y][x - 1][1] && map[y][x + 1][1]);
    }
}
