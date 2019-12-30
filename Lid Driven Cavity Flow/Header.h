//
//  Header.h
//  Assignment 3
//
//  Created by Sanketh on 06/09/19.
//  Copyright © 2019 Sanketh. All rights reserved.
//

#ifndef Header_h
#define Header_h


// Declare constants

const int nx = 100;           // Grid points along X
const int ny = 100;           // Grid points along Y [CHOOSE ODD NUMBER OF POINTS]
const int q = 9;              // Discretised velocity directions
const double ro = 36.0;        // Density initial guess
const double tau = 0.52;       // Relaxation time scale
const double h = ny;          // Length of the domain in X and Y
const double dy = 1.0/ny;     // Grid size in X and Y
const double Re = 400.0;          // Reynolds number
const double mu   = ro*(tau-0.5)/3.0;  // Dynamic viscosity
const double u_wall = Re*mu/(ro*h);    // Wall velocity
const double error_max = 1e-7; // Maximum error for convergence
// D2Q9
const double ex[] = {0,1.0,0,-1.0,0,1.0,-1.0,-1.0,1.0}; // X velocities
const double ey[] = {0,0,1.0,0,-1.0,1.0,1.0,-1.0,-1.0}; // Y velocities
const double w[]  =  {16.0/36.0,4.0/36.0,4.0/36.0,4.0/36.0,4.0/36.0,1.0/36.0,1.0/36.0,1.0/36.0,1.0/36.0};  // Weights
double err_con = 100.0; // Convergence error
int n = 0;              // Number of iterations


// Declare macroscopic variables

double rho[nx][ny] ;        // Density array
double f[q][nx][ny];        // Probability density functions
double f_old[q][nx][ny];    // Probability density functions for last time step
double f_eq[q][nx][ny];     // Equilibrium probability density functions
double f_temp[q][nx][ny];   // Temporary probability density functions
double ux[nx][ny];          // Macroscopic X velocity
double uy[nx][ny];          // Macroscopic Y velocity
double u_abs[nx][ny];       // Macroscopic absolute velocity
double u_abs_temp[nx][ny];  // Temporary variable for macroscopic absolute velocity
double y[ny];               // Y grid
double x[ny];               // X grid

// Declare functions

void initialise();
void update(int n);
void collide();
void stream();
void convergence_error(int n);
void absolute_error();
void write(int nx, int ny,int Re );
void write_grid(int nx,int ny);


#endif /* Header_h */
