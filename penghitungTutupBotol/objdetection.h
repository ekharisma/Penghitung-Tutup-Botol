#ifndef OBJDETECTION_H
#define OBJDETECTION_H


class ObjDetection
{
public:
    ObjDetection();

    void setMinrad(int minRad);
    void set_maxRad(int maxRad);
    void set_blur_coef(int blur_coef);
    void set_threshold(int threshold);
private:
    int threshold = 200;
    int minRad = 1;
    int maxRad = 30;
    int blur_coef = 5;
};

#endif // OBJDETECTION_H
