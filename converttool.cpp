#include "converttool.h"
#include <vector>
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <QQuaternion>
using namespace  std;
void split1(const std::string& str, vector<string>& cont)
{
    string token;
    std::istringstream iss(str);
    while(getline(iss,token,','))
        cont.push_back(token);

}
convertTool::convertTool(QObject *parent) : QObject(parent)
{

}

bool convertTool::cvtStrToMats(QString str)
{
    bool correctRun = true ;
    QStringList partMats;
    QList<QString> qquans ,  poss;
    partMats = str.split("@@");
    if(partMats.size() == 0){
        qDebug()<<"partMats is Null !";
        correctRun = false ;
    }else{
        foreach (str, partMats) {
            QList<QString> tmp = cvtStrToMat(str);
            if(tmp.size() == 1 ){
                qquans.push_back(tmp[0]);
                emit cppGetQQuanResult(qquans);
                correctRun = false ;
            }
            else{
                qquans.push_back(tmp[0]);
                poss.push_back(tmp[1]);
            }
        }
    }
    emit cppGetQQuanResult(qquans);
    emit cppGetPossResult(poss);
    return correctRun ;
}

QList<QString> convertTool::cvtStrToMat(QString str)
{
    QList<QString> result ;
    std::vector<std::string> words;
    split1(str.toStdString(),words);
    if(words.size()<16){
        result.push_back("Wrong Mat Data");
        return result;
    }
    Eigen::Matrix3f mat3f;
    mat3f<<std::atof(words[0].c_str()),std::atof(words[4].c_str()),std::atof(words[8].c_str()),std::atof(words[1].c_str()),std::atof(words[5].c_str()),std::atof(words[9].c_str()),std::atof(words[2].c_str()),std::atof(words[6].c_str()),std::atof(words[10].c_str());
    //        mat3f<<std::atof(words[0].c_str()),std::atof(words[1].c_str()),std::atof(words[2].c_str()),std::atof(words[4].c_str()),std::atof(words[5].c_str()),std::atof(words[6].c_str()),std::atof(words[8].c_str()),std::atof(words[9].c_str()),std::atof(words[10].c_str());
    Eigen::Quaternionf q;
    q=mat3f;
    //        QMatrix4x4 rot;
    //        rot.rotate(90, 1, 0, 0);
    //ori_rotations.push_back(/*QQuaternion::fromAxisAndAngle(QVector3D(1,0,0),90)**/quanAfter);
#ifdef NotRelease
    //std::cout<<data[i-1]<<std::endl;
    std::cout<<"QQuaternion :"<<std::endl;
    std::cout<<q.w()<<","<<q.x()<<","<<q.y()<<","<<q.z()<<std::endl;
    std::cout<<std::atof(words[12].c_str())<<","<<std::atof(words[13].c_str())<<","<<std::atof(words[14].c_str())<<std::endl;
#endif
    std::stringstream qquanstr , v3dstr;
    qquanstr << q.w()<<","<<q.x()<<","<<q.y()<<","<<q.z() ;
    v3dstr << std::atof(words[12].c_str())<<","<<std::atof(words[13].c_str())<<","<<std::atof(words[14].c_str()) ;
    result.push_back(QString::fromStdString( qquanstr.str()));
    result.push_back(QString::fromStdString( v3dstr.str()));
    return result;

}

QList<QString> convertTool::test()
{
    QString str1 = "hello";
    QString str2 = "world";
    QList<QString> lst;
    lst.push_back(str1);
    lst.push_back(str2);
//    QList<QQuaternion> lst;
//    lst.push_back(QQuaternion());

//    lst.push_back(QQuaternion());
    return lst;
}

void convertTool::getResult(QList<QString> result)
{

}
