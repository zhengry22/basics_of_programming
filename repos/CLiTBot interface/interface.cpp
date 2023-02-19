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
    int x, y; // x ��ʾ�кţ�y ��ʾ�к�
};

// ����ö�����ͣ��������������˳���ֻ������ȡֵ
enum Direction {
    LEFT,   // ��ǰ��
    DOWN,   // ���
    RIGHT,  // �Һ�
    UP,     // ��ǰ��
};

// ����������
struct Robot {
    Position pos;  // ������λ��
    Direction dir; // �����˳���
};

// ������
struct Light {
    Position pos; // ��λ��
    bool lighten; // �Ƿ񱻵���
};

// ��Ԫ������
struct Cell {
    int height;   // �߶�
    int light_id; // �Ʊ�ʶ��-1��ʾ�õ�Ԫ����û�е�
    bool robot;   // true/false�ֱ��ʾ��������/���ڸõ�Ԫ����
};

// ָ������
enum OpType {
    TL,
    TR,
    MOV,
    JMP,
    LIT,
    CALL
}; // TLΪ��ת��TRΪ��ת��MOVΪ��ǰ���ߣ�JMPΪ��Ծ��LITΪ�����ƣ�
// ʹ��CALL��ʾ����MAIN��CALL + 1��ʾ����P1���Դ����ơ�

// ��������
struct Proc {
    OpType ops[MAX_OPS];
    // ָ���¼��MAX_OPSΪ������
    int count; // ��Чָ����
};

// ָ����������
struct OpSeq {
    // ���̼�¼��MAX_PROCSΪ������
    // procs[0]ΪMAIN���̣�procs[1]ΪP1���̣��Դ�����
    Proc procs[MAX_PROCS];
    int count; // ��Ч������
};

// ��ͼ״̬����
struct Map {
    // ��Ԫ����ɶ�ά���飬MAX_ROW��MAX_COLΪ������
    Cell cells[MAX_ROW][MAX_COL];
    int row, col; // ��Ч��������Ч���� 

    // �Ƽ�¼��MAX_LITΪ������
    Light lights[MAX_LIT];
    int num_lights; // ��Ч���� 

    // ��ͼ��ͬʱֻ��һ��������
    Robot robot;

    // ÿ�����̵�ָ��������
    int op_limit[MAX_PROCS];
};

// ��Ϸ״̬����
struct Game {
    char map_name[MAX_PATH_LEN]; // ��ǰ��ͼ���ļ�·����
    Map map_init;                // ��ͼ��ʼ״̬ 
    Map map_run;                 // ָ��ִ�й����еĵ�ͼ״̬ 

    // �Զ�������ļ�·������MAX_PATH_LENΪ������
    char save_path[MAX_PATH_LEN];
    int auto_save_id; // �Զ������ʶ
    int limit;        // ִ��ָ�����ޣ������������޵ݹ飩
};
Game game; // ȫ��Ψһ��Game����


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
        //���ļ���Ϊmap_path�ĵ�ͼ�ļ������Զ�ȡ��game.map_init
        fin >> game.map_init.row >> game.map_init.col >> game.map_init.num_lights;
        //���proc
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
    if (!game.save_path[0]) return;//������ǿ��ַ����Ͳ����Զ�����
    save(game.save_path);
}

int interface()
{
    //��ʼ�����Ӧ��game.map_name��Ϊ���ַ���
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
                //�����ͼ״̬,��û����
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