#ifndef ZRAINBOWCOLOR_H
#define ZRAINBOWCOLOR_H

struct color
{
    int r;
    int g;
    int b;
};

class ZRainbowColor
{
public:
    ZRainbowColor();
    ZRainbowColor(int max);
    ~ZRainbowColor();
    void setRange(int max);
    void buildColorBar();
    color* colorBar();

private:
    int maxRange;
    color* bar;
    int pivotR[7];
    int pivotG[7];
    int pivotB[7];
};

#endif // ZRAINBOWCOLOR_H
