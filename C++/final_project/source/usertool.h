#ifndef USERTOOL_H
#define USERTOOL_H

#include<QLabel>
class usertool
{
public:
    usertool();
};

class cancelbox
{
public:
    cancelbox(QLabel*label,int x,int t,int z):selectedlabel(label),selectedlabel_x(x),selectedlabel_y(t),size(z) {}
    int selectedlabel_x,selectedlabel_y,size;
    QLabel*selectedlabel;
};



#endif // USERTOOL_H
