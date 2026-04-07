1class Robot {
2public:
3    int w, h;
4    int x, y;
5    int dir; // 0=East, 1=North, 2=West, 3=South
6    int cycle;
7
8    Robot(int width, int height) {
9        w = width;
10        h = height;
11        x = 0;
12        y = 0;
13        dir = 0; // East
14        cycle = 2 * (w + h) - 4;
15    }
16
17    void step(int num) {
18        if (cycle == 0) return;
19
20        num %= cycle;
21
22        // special case: if num == 0, direction should be South if not at origin
23        if (num == 0) {
24            if (x == 0 && y == 0) {
25                dir = 3; // South
26            }
27            return;
28        }
29
30        while (num--) {
31            if (dir == 0) { // East
32                if (x + 1 < w) x++;
33                else dir = 1, y++;
34            }
35            else if (dir == 1) { // North
36                if (y + 1 < h) y++;
37                else dir = 2, x--;
38            }
39            else if (dir == 2) { // West
40                if (x - 1 >= 0) x--;
41                else dir = 3, y--;
42            }
43            else { // South
44                if (y - 1 >= 0) y--;
45                else dir = 0, x++;
46            }
47        }
48    }
49
50    vector<int> getPos() {
51        return {x, y};
52    }
53
54    string getDir() {
55        if (dir == 0) return "East";
56        if (dir == 1) return "North";
57        if (dir == 2) return "West";
58        return "South";
59    }
60};
61
62/**
63 * Your Robot object will be instantiated and called as such:
64 * Robot* obj = new Robot(width, height);
65 * obj->step(num);
66 * vector<int> param_2 = obj->getPos();
67 * string param_3 = obj->getDir();
68 */