#include "mapforcontest.h"

mapforcontest::mapforcontest() {}

bool mapforcontest::check_fit_map()
{
    bool flag=true;int num_4=0;
    for(int i=0;i<size&&flag;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(valuestorage[i][j]==4)num_4++;
            if(valuestorage[i][j]>4||num_4>1)
            {
                flag=false;
                break;
            }
        }
    }
    if(flag&&num_4==1)return true;
    else
    {
        valuestorage.resize(size,QVector<int>(size,0));
        return false;
    }

}

void mapforcontest::generatingmap_forcontest()
{
    srand(QTime(0,0,0).secsTo(QTime::currentTime()));
    valuestorage.resize(size,QVector<int>(size,0));
    while(!check_fit_map()&&!ifover)
    {
        QCoreApplication::processEvents();

        QThread::msleep(1);
        if (QThread::currentThread()->isInterruptionRequested()) {
            qDebug() << "Stop signal received. Stopping...";
            break;
        }

        int sx4=std::rand()%3,sy4=std::rand()%3;
        for(int i=sx4;i<=sx4+3;i++)
        {
            for(int j=sy4;j<=sy4+3;j++)
            {
                valuestorage[i][j]++;
            }
        }
        for(int i=0;i<2;i++)
        {

            int sx3=std::rand()%4,sy3=std::rand()%4;
            int sx2=std::rand()%5,sy2=std::rand()%5;
            int sx1=std::rand()%6,sy1=std::rand()%6;

            bool flag=true;
            for(int k=sx3;k<=sx3+2&&flag;k++)
            {
                for(int j=sy3;j<=sy3+2;j++)
                {
                    valuestorage[k][j]++;
                    if(valuestorage[k][j]>4)
                    {
                        flag=false;
                        break;
                    }
                }
            }
            if(!flag)break;

            for(int k=sx2;k<=sx2+1&&flag;k++)
            {
                for(int j=sy2;j<=sy2+1;j++)
                {
                    valuestorage[k][j]++;
                    if(valuestorage[k][j]>4)
                    {
                        flag=false;
                        break;
                    }
                }
            }
            if(!flag)break;
            valuestorage[sx1][sy1]++;
        }
    }

    if(!ifover)
    {
        emit finish_mapgenerating(valuestorage);
        qDebug() << "finished";
    }
    else
    {
        emit stop_out1();
        qDebug() << "task has stoped";

    }
}

void mapforcontest::stop()
{
    ifover=true;
    emit stop_out2();
     qDebug() << "task request stop";
}
