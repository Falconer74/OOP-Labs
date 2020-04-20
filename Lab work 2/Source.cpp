#include <fstream>
#include <iostream>
using namespace std;

#define BLACK 0x000000  ///    1
#define WHITE 0xFFFFFF ///     2
#define RED 0xFF0000 ///       3
#define PURPLE 0xFF00FF ///    4
#define GREEN 0x00FF00 ///     5
#define YELLOW 0xFFFF00 ///    6
#define BLUE 0x0000FF ///      7

typedef uint16_t WORD;
typedef uint32_t DWORD;
typedef int32_t LONG;
//щоб уникнути округлення розміру структури до максимального
//4х-байтного розміру
#pragma pack(push,1)
struct BitmapFileHeader {
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
};
#pragma pack(push,1)
struct BitmapInfoHeader {
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount; DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
};
//створення .bmp файла
//задання параметрів полям заголовка .bmp файла і зображення
void CreateBmp(const char* fileName, unsigned int** colors, int
    height, int width)
{
    BitmapFileHeader bfh = { 0 };
    BitmapInfoHeader bih = { 0 };
    bfh.bfType = 0x4D42; //символи 'BM'
    bfh.bfOffBits = sizeof(bfh) + sizeof(bih); //
    bfh.bfSize = bfh.bfOffBits + sizeof(colors[0][0]) * width * height;
    // розмір кінцевого файлу
    bih.biSize = sizeof(bih); // розмір структури
    bih.biBitCount = 32; // 32 біт (4 байта) на піксель
    bih.biHeight = -height; // Висота
    bih.biWidth = width; // Ширина
    bih.biPlanes = 1; // містить 1
    // інші поля дорівнюють нулю
    ofstream f;
    f.open(fileName, ios::binary); // Відкриваємо файл для запису
    f.write((char*)&bfh, sizeof(bfh)); // Записуємо заголовки
    f.write((char*)&bih, sizeof(bih));
    // Записуємо зображення
    for (int i = 0; i < height; i++)
        f.write((char*)colors[i], sizeof(colors[0][0]) * width);
    f.close(); // Закриваємо файл
}
#pragma pack (pop)

void drawCircle(unsigned int** color, int h, int w, int r, int foreground, int background) {
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            //Перевод начала координат с верхнего левого края к центру экрана
            int x = j - w / 2;
            int y = -i + h / 2;
    
            if (sqrt(pow(x, 2) + pow(y, 2)) <= r) {
                color[i][j] = foreground; //задання червоного коліру
            }
            else {
                color[i][j] = background;
            }
        }
    }
}

void drawTriangle(unsigned int** color, int h, int w, int background, int foreground) {
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            color[i][j] = background;
        }
    }

    double step = ((double)h / 2) / ((double)w / 2);
    for (int j = 0; j < w / 2; j++)
    {
        for (int i = (int)(step * j); i < h - (step * j); i++)
        {
            color[i][j] = foreground;
        }
    }
}

int main(int argc, char* argv[])
{
    int w = 0, h = 0, background, foreground;
    cout << "Input height in px" << endl;
    cin >> h;
    cout << "Input width in px" << endl;
    cin >> w;
    //int r = 0;
    //cout << "Input radius in px" << endl;


    int choice;

    cout << "Select background color\n";
    cout << "[1] - Black\n";
    cout << "[2] - White\n";
    cout << "[3] - Red\n";
    cout << "[4] - Purple\n";
    cout << "[5] - Green\n";
    cout << "[6] - Yellow\n";
    cout << "[7] - Blue\n";
    cin >> choice;
    
    switch (choice) {
        case 1:
            background = BLACK;
            break;
        case 2:
            background = WHITE;
            break;
        case 3:
            background = RED;
            break;
        case 4:
            background = PURPLE;
            break;
        case 5:
            background = GREEN;
            break;
        case 6:
            background = YELLOW;
            break;
        case 7:
            background = BLUE;
            break;
        default:
            cout << "Wrong color, default background color will be used.";
            background = WHITE;
            break;
    }

    cout << "Select foreground color\n";
    cout << "[1] - Black\n";
    cout << "[2] - White\n";
    cout << "[3] - Red\n";
    cout << "[4] - Purple\n";
    cout << "[5] - Green\n";
    cout << "[6] - Yellow\n";
    cout << "[7] - Blue\n";
    cin >> choice;

    switch (choice) {
    case 1:
        foreground = BLACK;
        break;
    case 2:
        foreground = WHITE;
        break;
    case 3:
        foreground = RED;
        break;
    case 4:
        foreground = PURPLE;
        break;
    case 5:
        foreground = GREEN;
        break;
    case 6:
        foreground = YELLOW;
        break;
    case 7:
        foreground = BLUE;
        break;
    default:
        cout << "Wrong color, default foreground color will be used.";
        foreground = WHITE;
        break;
    }

    unsigned int** color = new unsigned int* [h];
    for (int i = 0; i < h; i++)
        color[i] = new unsigned int[w];

    drawTriangle(color, h, w, background, foreground);
    

    CreateBmp("test.bmp", color, h, w);
    for (int i = 0; i < h; i++)
        delete[]color[i];
    delete[]color;

    return 0;
}