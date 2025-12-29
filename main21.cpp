// main.cpp
#include <iostream>
#include <iomanip>
using namespace std;

#include "mathlib21.h"

int main()
{
    // display points
    cout << setprecision(20);

    int i, ntime;
    double* rtime;   // day base
    double* zrate;
    ntime = 9;

    rtime = new double[ntime];
    zrate = new double[ntime];

    rtime[0] = 1;      zrate[0] = 0.0627;
    rtime[1] = 92;     zrate[1] = 0.0630;
    rtime[2] = 365;    zrate[2] = 0.0641;
    rtime[3] = 730;    zrate[3] = 0.0651;
    rtime[4] = 1095;   zrate[4] = 0.0661;
    rtime[5] = 1461;   zrate[5] = 0.0672;
    rtime[6] = 1826;   zrate[6] = 0.0682;
    rtime[7] = 2556;   zrate[7] = 0.0693;
    rtime[8] = 3652;   zrate[8] = 0.0704;

    int nctime;
    double* ctime;      // day base
    double* zerorate;
    int ncoupon;
    ncoupon = 4;        // caplet floorlet ¼ö
    nctime = ncoupon + 1;

    ctime = new double[nctime];
    zerorate = new double[nctime];

    ctime[0] = 0;
    ctime[1] = 92;
    ctime[2] = 181;
    ctime[3] = 273;
    ctime[4] = 365;

    for (i = 0; i < nctime; i++)
        zerorate[i] = linear_interpolation(ntime, rtime, zrate, ctime[i]);

    double strike, fixed_vol, day_basis, ini_forward_rate;
    double cap_price, floor_price;

    fixed_vol = 0.2;
    strike = 0.063;
    day_basis = 365.0;
    ini_forward_rate = 0.062;

    cap_price = cap_floor_price(1, ini_forward_rate, strike, fixed_vol, ncoupon,
        zerorate, ctime, day_basis);

    floor_price = cap_floor_price(-1, ini_forward_rate, strike, fixed_vol, ncoupon,
        zerorate, ctime, day_basis);

    delete[] rtime;
    delete[] zrate;
    delete[] ctime;
    delete[] zerorate;
}
