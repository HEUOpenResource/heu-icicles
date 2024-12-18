clear; 
clc; 
A=[ 0 0 1 0 
 0 0 0 1 
 65.8751 -16.8751 -3.7062 0.2760 
 -82.2122 82.2122 4.6254 -1.3444] ; % System matrix 
B=[0;0;5.2184;-6.5125]; % Control Matrix 
C=[1,0,0,0;0,1,0,0]; % output matrix 
P=[-3+3i,-3-3i,-30-6i,-30+6i]; % expect pole 
rank (ctrb (A, B)) % controllability 
rank (obsv (A, C)) % observability 
eig (A) % stability 
K=place(A,B,P) % state feedback gain matrix 
% P1=[-20+3i,-20-3i,-80-10i,-80+10i]%观测器极点
% P1=[-10+3i,-10-3i,-80-1i,-80+1i];
% P1=[-5+3i,-5-3i,-80-1i,-80+1i];
% P1=[-2+3i,-2-3i,-80-1i,-80+1i];
%%% real
% P1=[-20+3i,-20-3i,-80-1i,-80+1i];
% P1=[-10+3i,-10-3i,-80-1i,-80+1i];
% P1=[-5+3i,-5-3i,-80-1i,-80+1i];
%%% im
% P1=[-20+3i,-20-3i,-80-1i,-80+1i];
P1=[-20+5i,-20-5i,-80-1i,-80+1i];
% P1=[-20+10i,-20-10i,-80-1i,-80+1i];


L=place(A',C',P1)' %状态观测器增益矩阵