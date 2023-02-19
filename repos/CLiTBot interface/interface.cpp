#pragma warning(disable:4996)
#include <iostream>
#include <fstream>
#include<cstring>
#define SPACE ' '
using namespace std;


// constants
const int MAX_OPS = 32;
const int MAX_PROCS = 8;
const int MAX_ROW = 16;
const int MAX_COL = 16;
const int MAX_LIT = 16;
const int MAX_PATH_LEN = 512;

struct Position {
    int x, y; // x 表示列号，y 表示行号
};

// 方向枚举类型，可用来表达机器人朝向，只有四种取值
enum Direction {
    LEFT,   // 左前方
    DOWN,   // 左后方
    RIGHT,  // 右后方
    UP,     // 右前方
};

// 机器人类型
struct Robot {
    Position pos;  // 机器人位置
    Direction dir; // 机器人朝向
};

// 灯类型
struct Light {
    Position pos; // 灯位置
    bool lighten; // 是否被点亮
};

// 单元格类型
struct Cell {
    int height;   // 高度
    int light_id; // 灯标识，-1表示该单元格上没有灯
    bool robot;   // true/false分别表示机器人在/不在该单元格上
};

// 指令类型
enum OpType {
    TL,
    TR,
    MOV,
    JMP,
    LIT,
    CALL
}; // TL为左转，TR为右转，MOV为向前行走，JMP为跳跃，LIT为点亮灯；
// 使用CALL表示调用MAIN，CALL + 1表示调用P1，以此类推。

// 过程类型
struct Proc {
    OpType ops[MAX_OPS];
    // 指令记录，MAX_OPS为合理常数
    int count; // 有效指令数
};

// 指令序列类型
struct OpSeq {
    // 过程记录，MAX_PROCS为合理常数
    // procs[0]为MAIN过程，procs[1]为P1过程，以此类推
    Proc procs[MAX_PROCS];
    int count; // 有效过程数
};

// 地图状态类型
struct Map {
    // 单元格组成二维数组，MAX_ROW、MAX_COL为合理常数
    Cell cells[MAX_ROW][MAX_COL];
    int row, col; // 有效行数、有效列数 

    // 灯记录，MAX_LIT为合理常数
    Light lights[MAX_LIT];
    int num_lights; // 有效灯数 

    // 地图上同时只有一个机器人
    Robot robot;

    // 每个过程的指令数限制
    int op_limit[MAX_PROCS];
};

// 游戏状态类型
struct Game {
    char map_name[MAX_PATH_LEN]; // 当前地图的文件路径名
    Map map_init;                // 地图初始状态 
    Map map_run;                 // 指令执行过程中的地图状态 

    // 自动保存的文件路径名，MAX_PATH_LEN为合理常数
    char save_path[MAX_PATH_LEN];
    int auto_save_id; // 自动保存标识
    int limit;        // 执行指令上限（用来避免无限递归）
};
Game game; // 全局唯一的Game变量


//test
void generateMapFile() {
    char path[MAX_PATH_LEN];
    int tmp, rows, cols, num_lights, num_procs, light_id;
    cout << "Save the file at path: ";
    cin >> path;
    ofstream map;
    map.open(path);
    cout << "rows: ";
    cin >> rows;
    map << rows << SPACE;
    cout << "cols: ";
    cin >> cols;
    map << cols << SPACE;
    cout << "num_lights: ";
    cin >> num_lights;
    map << num_lights << SPACE;
    cout << "num_procs: ";
    cin >> num_procs;
    map << num_procs << endl;
    for (int i = 0; i < rows; i++) {
        cout << "heights of row " << i << ": ";
        for (int j = 0; j < cols; j++) {
            cin >> tmp;
            map << tmp << SPACE;
        }
        map << endl;
    }
    int x, y, d;
    for (int i = 0; i < num_lights; i++) {
        cout << "position of light No." << i << ": ";
        cin >> x >> y;
        map << x << SPACE << y << endl;
    }
    for (int i = 0; i < num_procs; i++) {
        cout << "limit of proc No." << i << ": ";
        cin >> tmp;
        map << tmp << SPACE;
    }
    map << endl;
    cout << "info of the robot (x, y, d): ";
    cin >> x >> y >> d;
    map << x << SPACE << y << SPACE << d;
    map.close();
}

Proc test;

//interface

int load(char map_path[])
{
    int direct;
 
    ifstream fin(map_path);
    if (!fin)
    {
        strcpy(game.map_name, "");
        return 0;
    }
    else
    {
        strcpy(game.map_name, map_path);
        //将文件名为map_path的地图文件的属性读取到game.map_init
        fin >> game.map_init.row >> game.map_init.col >> game.map_init.num_lights;
        //最大proc
        fin >> test.count;
        //heights of row
        for (int i = 0; i < game.map_init.row; i++)
        {
            for (int j = 0; j < game.map_init.col; j++)
            {
                fin >> game.map_init.cells[i][j].height;
            }
        }
        //
        for (int i = 0; i < game.map_init.num_lights; i++)
        {
            fin >> game.map_init.lights[i].pos.x >> game.map_init.lights[i].pos.y;
            game.map_init.lights[i].lighten = 0;
        }
        for (int i = 0; i < game.map_init.row; i++)
        {
            for (int j = 0; j < game.map_init.col; j++)
            {
                if ((i != game.map_init.lights[i].pos.x) || (j != game.map_init.lights[i].pos.y))
                    game.map_init.cells[i][j].light_id = -1;
            }
        }
        for (int i = 0; i < test.count; i++)
        {
            fin >> game.map_init.op_limit[i];
        }
        fin >> game.map_init.robot.pos.x >> game.map_init.robot.pos.y;
        fin >> direct;
        if (direct == 0)
            game.map_init.robot.dir = LEFT;
        else if (direct == 1)
            game.map_init.robot.dir = DOWN;
        else if (direct == 2)
            game.map_init.robot.dir = RIGHT;
        else if (direct == 3)
            game.map_init.robot.dir = UP;
        for (int i = 0; i < game.map_init.row; i++)
        {
            for (int j = 0; j < game.map_init.col; j++)
            {
                if ((i != game.map_init.robot.pos.x) || (j != game.map_init.robot.pos.y))
                    game.map_init.cells[i][j].robot = false;
                else
                    game.map_init.cells[i][j].robot = true;
            }
        }
        return 1;
    }
}

void auto_save() {
    if (!game.save_path[0]) return;//如果不是空字符串就不用自动保存
    save(game.save_path);
}

int interface()
{
    //初始情况下应将game.map_name设为空字符串
    int ifload = 0;
    char order[MAX_PATH_LEN], map_path[MAX_PATH_LEN], char autosave_code[20];
    for (int steps = 1; steps <= game.limit; steps++)
    {
        int steps_set;
        cin >> order;
        //load
        if (strcmp(order, "LOAD") == 0)
        {
            cin >> map_path;
            ifload = load(map_path);
        }
        //autosave
        else if (strcmp(order, "AUTOSAVE") == 0)
        {
            cin >> autosave_code;
            if (strcmp(autosave_code, "OFF") == 0)
                game.save_path[0] = 0;
            else
                strcpy(game.save_path, autosave_code);
        }
        //limit of steps
        else if (strcmp(order, "LIMIT") == 0)
        {
            cin >> steps_set;
            game.limit = steps_set;
        }
        //output set
        else if (strcmp(order, "STATUS")==0)
        {
            if (ifload == 1)
            {
                cout << "Map Name:" <<' '<< game.map_name << endl;
                cout << "Autosave:" << ' ' << game.save_path << endl;
                cout << "Step Limit" << ' ' << game.limit;
                //输出地图状态,还没做呢
                cout << "Robot is facing ";
                if (game.map_init.robot.dir == LEFT)
                    cout << "left." << endl;
                else if (game.map_init.robot.dir == DOWN)
                    cout << "down." << endl;
                else if (game.map_init.robot.dir == RIGHT)
                    cout << "right." << endl;
                else if (game.map_init.robot.dir == UP)
                    cout << "up." << endl;
                cout << "Proc Limit:" << ' ' << '[';
                for (int i = 0; i < test.count - 1; i++)
                    cout << game.map_init.op_limit[i] << ',';
                cout << game.map_init.op_limit[test.count - 1] << ']';
            }
        }

    }
    return 0;
}

int main()
{
    game.limit = 100;
    generateMapFile();
    interface();
    return 0;
}