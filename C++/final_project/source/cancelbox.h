#ifndef CANCELBOX_H
#define CANCELBOX_H

#include<QLabel>
class cancelbox
{
public:
    cancelbox();
public:
    cancelbox(QLabel*label,int x,int y,int z):labelforcancel(label),selectedlabel_x(x),selectedlabel_y(y),size(z){}
    QLabel*labelforcancel;
    int selectedlabel_x,selectedlabel_y,size;


};

#endif // CANCELBOX_H
