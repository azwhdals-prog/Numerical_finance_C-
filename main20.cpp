#include <iostream>
#include <fstream>
#include <iomanip>
#include "mathlib20.h"
using namespace std;

int main()
{
    int i, nctime, coupon_frequency;
    double* ctime;     
    double* crate;
    nctime = 15;
    coupon_frequency = 4;

    ctime = new double[nctime];
    crate = new double[nctime];

    ctime[0] = 0.25;    crate[0] = 0.05360;
    ctime[1] = 1.0;     crate[1] = 0.05030;
    ctime[2] = 2.0;     crate[2] = 0.04890;
    ctime[3] = 3.0;     crate[3] = 0.04780;
    ctime[4] = 4.0;     crate[4] = 0.04738;
    ctime[5] = 5.0;     crate[5] = 0.04758;
    ctime[6] = 6.0;     crate[6] = 0.04778;
    ctime[7] = 7.0;     crate[7] = 0.04785;
    ctime[8] = 8.0;     crate[8] = 0.04810;
    ctime[9] = 9.0;     crate[9] = 0.04830;
    ctime[10] = 10.0;   crate[10] = 0.04855;
    ctime[11] = 11.0;   crate[11] = 0.04880;
    ctime[12] = 12.0;   crate[12] = 0.04905;
    ctime[13] = 15.0;   crate[13] = 0.04930;
    ctime[14] = 20.0;   crate[14] = 0.04955;

    int nztime;
    double* ztime;      
    double* zrate;

    nztime = int(ctime[nctime - 1] * coupon_frequency);
    ztime = new double[nztime];
    zrate = new double[nztime];

    for (i = 0; i < nztime; i++)
        ztime[i] = double(i + 1) / coupon_frequency;

    par_to_zero_bootstrapping(nctime, ctime, crate, nztime, ztime, zrate, coupon_frequency);

    ofstream outf("result.txt", ios::out | ios::trunc);

    outf << setprecision(5);
    outf << "만기   액면가수익률" << endl;
    for (i = 0; i < nctime; i++) outf << ctime[i] << "     " << crate[i] << endl; outf << endl << endl;

    outf << "만기   현물이자율" << endl;
    for (i = 0; i < nztime; i++) outf << ztime[i] << "     " << zrate[i] << endl;
    outf.close();

    delete[] ctime;
    delete[] crate;
    delete[] ztime;
    delete[] zrate;
}
