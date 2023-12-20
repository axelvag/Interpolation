// apps/LIFAMI/TPInterpolation.cpp
#include<Grapic.h>
#include <math.h>
#include <iostream>
//#include "poly1.h"

using namespace grapic;
using namespace std;

const int TAILLE=1000;

/*const int MAX=500;

struct Polygon
{
    int n;
    float p[MAX];
};

struct Point
{
    float x,y;
};

void draw_polygon(Polygon p)
{
    for(int i=0;i<89;i++)
    {
        line(p.p[i],p.p[i+1];
    }
}

void interpolation_polygon()
{

}
*/

struct Complex
{
    float x,y;
};

struct Color
{
    unsigned char r,g,b;
};

Complex make_complex(float x,float y)
{
    Complex z;
    z.x=x;
    z.y=y;
    return z;
}

Complex operator+(Complex opg,Complex opd)
{
    Complex res;
    res.x=opg.x+opd.x;
    res.y=opg.y+opd.y;
    return res;
}

Complex operator*(float opg, Complex opd)
{
    return make_complex(opg*opd.x,opg*opd.y);
}

Complex operator*(Complex opg, float opd)
{
    return opd*opg;
}

Complex operator*(Complex opg,Complex opd)
{
    Complex res;
    res.x=opg.x*opd.x-opg.y*opd.y;
    res.y=opg.x*opd.y+opg.y*opd.x;
    return res;
}

Color operator+(Color opg,Color opd)
{
    Color res;
    res.r=opg.r+opd.r;
    res.g=opg.g+opd.g;
    res.b=opg.b+opd.b;
    return res;
}

Color make_color(float r,float g,float b)
{
    Color z;
    z.r=r;
    z.g=g;
    z.b=b;
    return z;
}

Color operator*(float opg, Color opd)
{
    return make_color(opg*opd.r,opg*opd.g,opg*opd.b);
}

Color operator*(Color opg, float opd)
{
    return opd*opg;
}

void dessinedroite(Complex A,Complex B,float tA,float tB,int n)
{
    Color bleu = make_color(0,0,255);
    Color rouge = make_color(255,0,0);
    for(int i=0;i<n;i++)
    {
        float t0=((float)i)/n;
        float t1=(i+1.0)/n;
        Complex p0=(1-t0)*A+t0*B;
        Complex p1=(1-t1)*A+t1*B;
        float temp0=(1-t0)*tA+t0*tB;
        float temp1=(1-t1)*tA+t1*tB;
        float temp=(temp0+temp1)/2;
        float k=(temp+30.0)/70.0;
        Color C=(1-k)*bleu+k*rouge;
        color(C.r,C.g,C.b);
        line(p0.x,p0.y,p1.x,p1.y);
    }
}


int main(int argc, char**argv)
{
    Menu m;
    bool stop=false;
    winInit("Droitecolor",TAILLE,TAILLE);
    backgroundColor(220,220,220);
    float ta=-30;
    float tb=40;
    Complex ca=make_complex(200,200);
    Complex cb=make_complex(800,800);
    menu_add( m, "Droite");
    menu_add( m, "Polygon");
    while(!stop)
    {
        winClear();
        menu_draw(m, 5,5, 100, 102);
        switch(menu_select(m))
        {
            case 0 : dessinedroite(ca,cb,ta,tb,10); break;
            case 1 : dessinedroite(ca,cb,ta,tb,10); break;
            default: dessinedroite(ca,cb,ta,tb,10); break;
        }
        dessinedroite(ca,cb,ta,tb,10);
        stop=winDisplay();
    }
    winQuit();
    return 0;
}

