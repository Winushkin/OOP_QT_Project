#include "application.h"
#include "../common/communicator.h"
#include "polynom.h"
#include "functions.h"

TComplex* ServerApplication::pushBack(TComplex *arr, TComplex elem){
    auto* resizeArr = new TComplex[rootsAmount + 1];
    for(int i = 0; i < rootsAmount; i++){
        *(resizeArr + i) = *(arr + i);
    }
    rootsAmount++;
    *(resizeArr + rootsAmount - 1) = elem;

    delete []arr;
    arr = resizeArr;
    return arr;
}


float* ServerApplication::pushBack(float *arr, float elem){
    auto* resizeArr = new float[rootsAmount + 1];
    for(int i = 0; i < rootsAmount; i++){
        *(resizeArr + i) = *(arr + i);
    }
    rootsAmount++;
    *(resizeArr + rootsAmount - 1) = elem;

    delete []arr;
    arr = resizeArr;
    return arr;
}


ServerApplication::ServerApplication(int argc, char *argv[]): QCoreApplication(argc,argv) {
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000,
                         QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);

    connect(comm,SIGNAL(recieved(QByteArray)),this,SLOT(recieve(QByteArray)));
}

//обработать моды
void ServerApplication::recieve(QByteArray msg) {
    TFsin<double> *SinDouble;
    TFSi<double> *SiDouble;
    TFsin<TComplex> *SinComplex;
    TFSi<TComplex> *SiComplex;
    double pointD;
    TComplex pointC;
    QString answer = "";
    std::string out;
    TComplex ComplexRoot;
    TComplex ComplexPoint;
    float floatRoot;
    float floatPoint;
    int index;
    double valueOfFunctionD;
    TComplex valueOfFunctionC;
    int pos = msg.indexOf(separator.toLatin1());
    int mode = msg.left(pos).toInt();
    msg.remove(0, 2);
    pos = msg.indexOf(separator.toLatin1());
    int t = msg.left(pos).toInt();
    if (t == DECOMPOSE_SI || t == DECOMPOSE_SIN) {
        msg.remove(0, 3);
    }else {
        msg.remove(0, 2);
    }
    switch (t) {
        case DECOMPOSE_SIN:
            if (mode == REAL_MODE) {
                pos = msg.indexOf(separator.toLatin1());
                index = msg.left(pos).toInt();
                SinDouble = new TFsin<double>(index);
                msg.remove(0, pos + 1);
                pos = msg.indexOf(separator.toLatin1());
                pointD = msg.left(pos).toDouble();
                valueOfFunctionD = SinDouble->value(pointD);
                answer << QString().setNum(DECOMPOSE_SIN);
                answer += QString::number(valueOfFunctionD);
                delete SinDouble;
            } else {
                pos = msg.indexOf(separator.toLatin1());
                index = msg.left(pos).toInt();
                SinComplex = new TFsin<TComplex>(index);
                msg.remove(0, pos + 1);
                msg >> pointC;
                valueOfFunctionC = SinComplex->value(pointC);
                answer << QString().setNum(DECOMPOSE_SIN);
                answer += QString::fromStdString(valueOfFunctionC.to_str());
                delete SinComplex;
            }
            break;

        case DECOMPOSE_SI:
            if (mode == REAL_MODE) {
                pos = msg.indexOf(separator.toLatin1());
                index = msg.left(pos).toInt();
                SiDouble = new TFSi<double>(index);
                msg.remove(0, pos + 1);
                pos = msg.indexOf(separator.toLatin1());
                pointD = msg.left(pos).toDouble();
                valueOfFunctionD = SiDouble->value(pointD);
                answer << QString().setNum(DECOMPOSE_SI);
                answer += QString::number(valueOfFunctionD);
                delete SiDouble;
            } else {
                pos = msg.indexOf(separator.toLatin1());
                index = msg.left(pos).toInt();
                SiComplex = new TFSi<TComplex>(index);
                msg.remove(0, pos + 1);
                msg >> pointC;
                valueOfFunctionC = SiComplex->value(pointC);
                answer << QString().setNum(DECOMPOSE_SI);
                answer += QString::fromStdString(valueOfFunctionC.to_str());
                delete SiComplex;
            }
            break;

        case PRINT_CLASSIC_REQUEST:
            answer << QString().setNum(PRINT_POLYNOM_ANSWER);
            if (mode == COMPLEX_MODE){
                out = polynom->polynomWithRoots().str();
            } else if (mode == REAL_MODE){
                out = floatPolynom->polynomWithRoots().str();
            }
            answer << QString::fromStdString(out);
            break;

        case PRINT_CANONIC_REQUEST:
            answer << QString().setNum(PRINT_POLYNOM_ANSWER);
            if (mode == COMPLEX_MODE){
                out = polynom->polynomWithDegrees().str();
            } else if (mode == REAL_MODE){
                out = floatPolynom->polynomWithDegrees().str();
            }
            answer << QString::fromStdString(out);
            break;

        case ADD_ROOT_REQUEST:
            if (mode == COMPLEX_MODE) {
                msg >> ComplexRoot;
                if ( rootsAmount == 0 ){
                    roots = new TComplex[0];
                }
                roots = pushBack(roots, ComplexRoot);
                polynom = Polynom<TComplex>().fill(An, roots, rootsAmount + 1);
            } else if (mode == REAL_MODE) {
                pos = msg.indexOf(separator.toLatin1());
                floatRoot = msg.left(pos).toFloat();
                if ( rootsAmount == 0 ){
                    floatRoots = new float[0];
                }
                floatRoots = pushBack(floatRoots, floatRoot);
                floatPolynom = Polynom<float>().fill(floatAn, floatRoots, rootsAmount + 1);
            }
            break;
        case ADD_COEFFICIENT_REQUEST:
            if (mode == COMPLEX_MODE) {
                msg >> An;
                polynom = Polynom<TComplex>().fill(An, roots, rootsAmount+1);
            } else if (mode == REAL_MODE) {
                pos = msg.indexOf(separator.toLatin1());
                floatAn = msg.left(pos).toFloat();
                floatPolynom = Polynom<float>().fill(floatAn, floatRoots, rootsAmount + 1);
            }
            break;
        case CHANGE_ROOT_REQUEST:
            if (mode == COMPLEX_MODE){
                pos = msg.indexOf(separator.toLatin1());
                index = msg.left(pos).toInt();
                msg.remove(0, pos + 1);
                msg >> ComplexRoot;
                roots[index] = ComplexRoot;
                polynom = Polynom<TComplex>().fill(An, roots, rootsAmount+1);
            } else if (mode == REAL_MODE) {
                pos = msg.indexOf(separator.toLatin1());
                index = msg.left(pos).toInt();
                msg.remove(0, pos + 1);
                pos = msg.indexOf(separator.toLatin1());
                floatRoot = msg.left(pos).toFloat();
                floatRoots[index] = floatRoot;
                floatPolynom = Polynom<float>().fill(floatAn, floatRoots, rootsAmount + 1);
            }
            break;
        case VALUE_AT_POINT_REQUEST:
            if (mode == COMPLEX_MODE) {
                answer << QString().setNum(VALUE_AT_POINT_ANSWER);
                msg >> ComplexPoint;
                answer += "p(" + ComplexPoint.to_str() + ") = ";
                if ( rootsAmount == 0 ){
                    answer << QString::fromStdString(An.to_str());
                }else{
                    TComplex value = polynom->valueAtPoint(ComplexPoint);
                    answer << QString::fromStdString(value.to_str());
                }
            } else if (mode == REAL_MODE) {
                answer << QString().setNum(VALUE_AT_POINT_ANSWER);
                pos = msg.indexOf(separator.toLatin1());
                floatPoint = msg.left(pos).toFloat();
                answer += "p(" + QString::number(floatPoint) + ") = ";
                if ( rootsAmount == 0 ){
                    answer << QString::number(floatAn);
                }else{
                    float value = floatPolynom->valueAtPoint(floatPoint);
                    answer += QString::number(value);
                }
            }
            break;
        default:
            return;
    }
    comm->send(QByteArray().append(answer.toLatin1()));
}