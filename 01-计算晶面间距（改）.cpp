#include <iostream>
#include <math.h>  //包含数学运算符数据库；
#include <fstream> //读写文件的头文件；
#define max 1000
#include <Windows.h>
using namespace std;
double mianjianju;
void menu() //创建菜单界面函数；    //"\t"
{
    cout << "***************************" << endl;
    cout << "***** 晶面间距计算器  *****" << endl;
    cout << "***** 1、面心立方FCC  *****" << endl;
    cout << "***** 2、体心立方BCC  *****" << endl;
    cout << "***** 3、密排六方HCP  *****" << endl;
    cout << "***** 4、清空计算内容 *****" << endl;
    cout << "***** 5、显示计算结果 *****" << endl;
    cout << "***** 6、保存计算结果 *****" << endl;
    cout << "***** 7、退出计算软件 *****" << endl;
    cout << "***** 8、查找计算结果 *****" << endl;
    cout << "***************************" << endl;
}
struct FCC
{
    string type;
    double a;
    long h;
    long k;
    long l;
    double mianjianju;
};
struct FCCstatics
{
    struct FCC FCCARRAY[max];
    int m_size;
};
double sqr01(double a, long h, long k, long l, double cal)  //FCC当hkl不全为奇或不全为偶时，有附加面，要乘1/2；
{
    
    if (h % 2 != 0 && k % 2 != 0 && l % 2 != 0)
    {
        double mianjianju = (a / sqrt(cal));
        return mianjianju;
    }
    else if (h % 2 == 0 && k % 2 == 0 && l % 2 == 0)
    {
        double mianjianju = (a / sqrt(cal));
        return mianjianju;
    }
    else
    {
        double mianjianju = (a / sqrt(cal)) / 2;
        return mianjianju;
    }
    return mianjianju;
}
double sqr02(double a, long h, long k, long l, double cal)  //BCC当h+k+l为奇时，有附加面，要乘1/2；
{
    if ((h + k + l) % 2 == 0)
    {
        double mianjianju = (a / sqrt(cal));
        return mianjianju;
    }
    else
    {
        double mianjianju = (a / sqrt(cal)) / 2;
        return mianjianju;
    }
    return mianjianju;
}
double sqr03(double a, long h, long k, long l)  //HCP当h+k=3n且当l为奇时，有附加面，要乘1/2；
{
    double c = a * 1.633;
    double cal = (((h * h + h * k + k * k) / (a * a)) * 4 / 3) + (l / c) * (l / c);
    if ((h + k) % 3 != 0 && l % 2 == 0)
    {
        double mianjianju = (1 / sqrt(cal));
        return mianjianju;
    }
    else
    {
        double mianjianju = (1 / sqrt(cal)) / 2;
        return mianjianju;
    }
    return mianjianju;
}
void addFCC(FCCstatics* p1)
{
    double a = 0;
    long h = 0;
    long k = 0;
    long l = 0;
    double cal = 0;
    if (p1->m_size == max)
    {
        cout << "记录已满，无法添加" << endl;
    }
    else
    {
        cout << endl;
        cout << "下面将计算面心立方FCC的晶面间距" << "\t" << endl;
        cout << "下面请输入点阵常数a的值：" << "\t" << endl;
        cin >> a;
        cout << "下面请输入晶面指数h的值：" << "\t" << endl;
        cin >> h;
        cout << "下面请输入晶面指数k的值：" << "\t" << endl;
        cin >> k;
        cout << "下面请输入晶面指数l的值：" << "\t" << endl;
        cin >> l;
        cal = h * h + k * k + l * l;
        p1->FCCARRAY[p1->m_size].type = "FCC";
        p1->FCCARRAY[p1->m_size].a = a;
        p1->FCCARRAY[p1->m_size].h = h;
        p1->FCCARRAY[p1->m_size].k = k;
        p1->FCCARRAY[p1->m_size].l = l;
        p1->FCCARRAY[p1->m_size].mianjianju = sqr01(a, h, k, l, cal);
        p1->m_size++;
        cout << "该面心立方FCC晶胞的面间距为： " << sqr01(a, h, k, l, cal) << endl;
    }
}
void addBCC(FCCstatics* p1)
{
    double a = 0;
    long h = 0;
    long k = 0;
    long l = 0;
    double cal = 0;
    if (p1->m_size == max)
    {
        cout << "记录已满，无法添加" << endl;
    }
    else
    {
        cout << endl;
        cout << "下面将计算体心立方BCC的晶面间距" << "\t" << endl;
        cout << "下面请输入点阵常数a的值：" << "\t" << endl;
        cin >> a;
        cout << "下面请输入晶面指数h的值：" << "\t" << endl;
        cin >> h;
        cout << "下面请输入晶面指数k的值：" << "\t" << endl;
        cin >> k;
        cout << "下面请输入晶面指数l的值：" << "\t" << endl;
        cin >> l;
        cal = h * h + k * k + l * l;
        p1->FCCARRAY[p1->m_size].type = "BCC";
        p1->FCCARRAY[p1->m_size].a = a;
        p1->FCCARRAY[p1->m_size].h = h;
        p1->FCCARRAY[p1->m_size].k = k;
        p1->FCCARRAY[p1->m_size].l = l;
        p1->FCCARRAY[p1->m_size].mianjianju = sqr02(a, h, k, l, cal);
        p1->m_size++;
        cout << "该体心立方FCC晶胞的面间距为： " << sqr02(a, h, k, l, cal) << endl;
    }
}
void addHCP(FCCstatics* p1)
{
    double a = 0;
    long h = 0;
    long k = 0;
    long l = 0;
    double cal = 0;
    if (p1->m_size == max)
    {
        cout << "记录已满，无法添加" << endl;
    }
    else
    {
        cout << endl;
        cout << "下面将计算密排六方HCP的晶面间距" << "\t" << endl;
        cout << "下面请输入点阵常数a的值：" << "\t" << endl;
        cin >> a;
        cout << "下面请输入晶面指数h的值：" << "\t" << endl;
        cin >> h;
        cout << "下面请输入晶面指数k的值：" << "\t" << endl;
        cin >> k;
        cout << "下面请输入晶面指数l的值：" << "\t" << endl;
        cin >> l;
        cal = h * h + k * k + l * l;
        p1->FCCARRAY[p1->m_size].type = "HCP";
        p1->FCCARRAY[p1->m_size].a = a;
        p1->FCCARRAY[p1->m_size].h = h;
        p1->FCCARRAY[p1->m_size].k = k;
        p1->FCCARRAY[p1->m_size].l = l;
        p1->FCCARRAY[p1->m_size].mianjianju = sqr03(a, h, k, l);
        p1->m_size++;
        cout << "该密排六方HCP晶胞的面间距为： " << sqr03(a, h, k, l) << endl;
    }
}
void clean(int yesornot)     //创建追加确认以及清屏函数；
{
    if (yesornot == 1)
    {
        system("pause");
        system("cls");
        menu();
    }
    else
    {
        cout << "下面可选择重新运行菜单界面的选项" << endl;
    }
}
void ShowCal(FCCstatics* p1)
{
      if (p1->m_size == 0)
        {
          cout << "无FCC的计算结果" << endl;
        }
        else
        {
          cout <<"您的FCC计算结果为：" << endl;
          for (int i = 0; i < p1->m_size; i++)
          {
              if (p1->FCCARRAY[i].type == "FCC")
              {
                  cout << p1->FCCARRAY[i].type << ": a=" << p1->FCCARRAY[i].a << " h=" << p1->FCCARRAY[i].h << " k=" << p1->FCCARRAY[i].k << " l=" << p1->FCCARRAY[i].l << " 面间距=" << p1->FCCARRAY[i].mianjianju << endl;
              }
          }
          cout << "您的BCC计算结果为： " << endl;
          for (int i = 0; i < p1->m_size; i++)
          {
              if (p1->FCCARRAY[i].type == "BCC")
              {
                  cout << p1->FCCARRAY[i].type << ": a=" << p1->FCCARRAY[i].a << " h=" << p1->FCCARRAY[i].h << " k=" << p1->FCCARRAY[i].k << " l=" << p1->FCCARRAY[i].l << " 面间距=" << p1->FCCARRAY[i].mianjianju << endl;
              }
          }
          cout << "您的HCP计算结果为： " << endl;
          for (int i = 0; i < p1->m_size; i++)
          {
              if (p1->FCCARRAY[i].type == "HCP")
              {
                  cout << p1->FCCARRAY[i].type << ": a=" << p1->FCCARRAY[i].a << " h=" << p1->FCCARRAY[i].h << " k=" << p1->FCCARRAY[i].k << " l=" << p1->FCCARRAY[i].l << " 面间距=" << p1->FCCARRAY[i].mianjianju << endl;
              }
          }
        }
 }
void File_Save(FCCstatics* p1)
{
    ofstream ofs;    //创建流对象
    ofs.open("save.txt", ios::out);//文件路径，打开方式 ios::in为读文件而打开文件 ios::out 为写文件而打开文件 ios::binary：二进制
    if (p1->m_size != 0)
    {
        for (int i = 0; i < p1->m_size; i++)
        {
            if (p1->FCCARRAY[i].type == "FCC")
            {
                ofs << p1->FCCARRAY[i].type << ": a=" << p1->FCCARRAY[i].a << " h=" << p1->FCCARRAY[i].h << " k=" << p1->FCCARRAY[i].k << " l=" << p1->FCCARRAY[i].l << " 面间距=" << p1->FCCARRAY[i].mianjianju << endl;
            }
        }
        for (int i = 0; i < p1->m_size; i++)
        {
            if (p1->FCCARRAY[i].type == "BCC")
            {
                ofs << p1->FCCARRAY[i].type << ": a=" << p1->FCCARRAY[i].a << " h=" << p1->FCCARRAY[i].h << " k=" << p1->FCCARRAY[i].k << " l=" << p1->FCCARRAY[i].l << " 面间距=" << p1->FCCARRAY[i].mianjianju << endl;
            }
        }
        for (int i = 0; i < p1->m_size; i++)
        {
            if (p1->FCCARRAY[i].type == "HCP")
            {
                ofs << p1->FCCARRAY[i].type << ": a=" << p1->FCCARRAY[i].a << " h=" << p1->FCCARRAY[i].h << " k=" << p1->FCCARRAY[i].k << " l=" << p1->FCCARRAY[i].l << " 面间距=" << p1->FCCARRAY[i].mianjianju << endl;
            }
        }
    }
    ofs.close();

}
//void Find(FCCstatics* p)
//{
//    double a;
//    long h;
//    long k;
//    long l;
//    double cal;
//    cout << "下面请输入面间距的值：" <<endl;
//    cin >> cal;
//    if (cal in p->FCCARRAY.mianjianju)
//    {
//
//    }
//}
int main()
{
    menu();
    FCCstatics p1;
    p1.m_size = 0;
    int yesornot = 0;
    double a = 0;
    long h = 0;
    long k = 0;
    long l = 0;
    double cal = 0;
    while (1)
    {
        int select = 0;
        cin >> select;
        switch (select)
        {
        case 1:
            addFCC(&p1);
            cout << "计算结束，已保留计算结果，下面可选择重新运行菜单界面的选项" << endl;
            cout << endl;
            continue;
        case 2:
            addBCC(&p1);
            cout << "计算结束，已保留计算结果，下面可选择重新运行菜单界面的选项" << endl;
            cout << endl;
            continue;
        case 3:
            addHCP(&p1);
            cout << "计算结束，已保留计算结果，下面可选择重新运行菜单界面的选项" << endl;
            cout << endl;
            continue;
        case 4:
            cout << "您确定要清空所有以计算的结果吗？" << "\t" << endl;
            cout << "确认:1" << "\t" << endl;
            cout << "取消:非1的任意数字" << "\t" << endl;
            cin >> yesornot;
            clean(yesornot);
            cout << endl;
            continue;
        case 5:
            cout << endl;
            ShowCal(&p1);
            continue;
        case 6:
            File_Save(&p1);
            cout << "您的计算结果已保存，下面清重新选择菜单界面选项以继续操作" << endl;
            continue;
        case 7:
            cout << endl;
            cout << "您确定要退出本程序吗？" << endl;
            cout << "确认:1" << endl;
            cout << "取消:非1的任意数字" << endl;
            cin >> yesornot;
            if (yesornot == 1)
            {
                cout << "欢迎下次再次使用本程序" << endl;
                system("pause");
                return 0;
                break;
            }
            else
            {
                cout << "下面可选择重新运行菜单界面的选项" << endl;
                continue;
            }
        default:
            cout << "请输入正确的序号" << endl;
            cout << endl;
            continue;
        }
    }
    system("pause");
    return 0;
}