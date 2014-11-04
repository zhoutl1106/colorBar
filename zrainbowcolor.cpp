#include "zrainbowcolor.h"
#include <stdlib.h>

ZRainbowColor::ZRainbowColor()
{
    maxRange = 0;
    bar = NULL;
    pivotR[0] = 255;
    pivotR[1] = 255;
    pivotR[2] = 255;
    pivotR[3] = 0;
    pivotR[4] = 0;
    pivotR[5] = 0;
    pivotR[6] = 255;
    pivotG[0] = 0;
    pivotG[1] = 122;
    pivotG[2] = 255;
    pivotG[3] = 255;
    pivotG[4] = 255;
    pivotG[5] = 0;
    pivotG[6] = 0;
    pivotB[0] = 0;
    pivotB[1] = 0;
    pivotB[2] = 0;
    pivotB[3] = 0;
    pivotB[4] = 255;
    pivotB[5] = 255;
    pivotB[6] = 255;
}

ZRainbowColor::ZRainbowColor(int max)
{
    ZRainbowColor();
    setRange(max);
}

ZRainbowColor::~ZRainbowColor()
{
    if(bar != NULL)
        delete bar;
}

void ZRainbowColor::setRange(int max)
{
    maxRange = max;
    if(bar == NULL)
        bar = new color[max];
}

void ZRainbowColor::buildColorBar()
{
    if(bar == NULL)
        return;
    int pivotIndex[7];
    for(int i = 0;i<7;i++)
    {
        pivotIndex[i] = maxRange * i / 6;
    }
    for(int i = 0;i<6;i++)
    {
        for(int j = pivotIndex[i];j<pivotIndex[i+1];j++)
        {
            int delta = pivotIndex[i+1] - pivotIndex[i];
            int deltaR = pivotR[i+1] - pivotR[i];
            int deltaG = pivotG[i+1] - pivotG[i];
            int deltaB = pivotB[i+1] - pivotB[i];
            bar[j].r = deltaR * (j-pivotIndex[i]) / delta + pivotR[i];
            bar[j].g = deltaG * (j-pivotIndex[i]) / delta + pivotG[i];
            bar[j].b = deltaB * (j-pivotIndex[i]) / delta + pivotB[i];
        }
    }
}

color* ZRainbowColor::colorBar()
{
    return bar;
}
