clear
clc
% P=[-1+3i,-1-3i,-30+6i,-30-6i];
% P=[-2+3i,-2-3i,-30+6i,-30-6i];
% P=[-3+3i,-3-3i,-30+6i,-30-6i];
% P=[-5+3i,-5-3i,-30+6i,-30-6i];
% P=[-6+3i,-6-3i,-30+6i,-30-6i];
% P=[-6+3i,-6-3i,-30+6i,-30-6i];
% P=[-7+3i,-7-3i,-30+6i,-30-6i];
% P=[-8+3i,-8-3i,-30+6i,-30-6i];
% P=[-9+3i,-9-3i,-30+6i,-30-6i];
% P=[-10+3i,-10-3i,-30+6i,-30-6i];

%%%%%%%%%%% exp_3 %%%%%%%%%%%%%
% P=[-4+3i,-4-3i,-10+2i,-10-2i];
% P=[-4+3i,-4-3i,-20+4i,-20-4i];
% P=[-4+3i,-4-3i,-30+6i,-30-6i];
% P=[-4+3i,-4-3i,-40+8i,-40-8i];
% P=[-4+3i,-4-3i,-50+10i,-50-10i];




P=[-4+3i,-4-3i,-30+6i,-30-6i];
% P1=[-20+3i,-20-3i,-80-1i,-80+1i];
% P1=[-10+3i,-10-3i,-80-1i,-80+1i];
% P1=[-5+3i,-5-3i,-80-1i,-80+1i];
% P1=[-2+3i,-2-3i,-80-1i,-80+1i];
P1=[-20+3i,-20-3i,-80-1i,-80+1i];


%str_p = sprintf('P = [%g+%gi, %g%+gi, %g%+gi, %g%+gi]', real(P(1)), imag(P(1)), real(P(2)), imag(P(2)), real(P(3)), imag(P(3)), real(P(4)), imag(P(4)));
str_p = sprintf('P_1 = [%g+%gi, %g%+gi, %g%+gi, %g%+gi]', real(P1(1)), imag(P1(1)), real(P1(2)), imag(P1(2)), real(P1(3)), imag(P1(3)), real(P1(4)), imag(P1(4)));
tf=10;
r=[-0.1;0.05;0;0];
A=[     0       0         1         0
         0       0         0         1 
     65.8751  -16.8751    -3.7062     0.2760
    -82.2122   82.2122    4.6254     -1.3444] ; % System matrix
B=[0;0;5.2184;-6.5125]; % Control Matrix
C=[1,0,0,0;0,1,0,0]; % output matrix
disp(['r(Qc)=',num2str(rank (ctrb (A, B)))]);%可控
disp(['r(Qo)=',num2str(rank (obsv (A, C)))]);%可观测
disp('λ=');
disp(num2str(eig (A))); % stability 特征根
[K,L,t,x]=dlb(r,P,P1,tf,A,B,C);
disp(['K=',num2str(K)]);
str_k = sprintf('K = [%g, %g, %g, %g]', K(1), K(2), K(3), K(4));
str_l = sprintf('L = [%g, %g, %g, %g, %g, %g, %g, %g]', L(1,1), L(1,2),L(2,1), L(2,2), L(3,1), L(3,2), L(4,1), L(4,2));
disp('L=');
disp(num2str(L));
figure;
plot(t,x(:,1)*180/pi,'r',t,x(:,2)*180/pi,'b',t,x(:,5),'g')
text(0.3, 0.7, str_p, 'Units', 'normalized');
% text(0.3, 0.6, str_k, 'Units', 'normalized');
text(0.3, 0.6, str_l, 'Units', 'normalized');

title('Display of Complex Array P1');
%text(1,1,str(P1))
legend('spiral arm angle','the pendulum angle','control value');

function [K,L,t,x]=dlb(r,P,P1,tf,A,B,C)
global K;
K=place(A,B,P); % state feedback gain matrix
L=place(A',C',P1)';
t0=0;
u0=-K*r; 
x0=[r;u0];%initial value 
[t,x]=ode45(@dlfun,[t0,tf],x0);% solve differential equations

function xdot=dlfun(~,x)
m1=0.200; m2=0.052; L1=0.10; L2=0.12; r1=0.20; km=0.0236; ke=0.2865; 
g=9.8; J1=0.004; J2=0.001; f1=0.01; f2=0.001; % value of parameter 
a=J1+m2*r1*r1; b=m2*r1*L2; c=J2; d=f1+km*ke; e=(m1*L1+m2*r1)*g;  f=f2;  h=m2*L2*g;
x(1)=x(1,:);
x(2)=x(2,:);
x(3)=x(3,:);
x(4)=x(4,:);
x(5)=x(5,:);
u=-K*[x(1);x(2);x(3);x(4)]; % control variable 
xdot=zeros(5,1); %derivative of x 
xdot(1)=x(3); 
xdot(2)=x(4); 
xdot(3)=((-d*c).*x(3)+(f*b*cos(x(2)-x(1))).*x(4)+b*b*sin(x(2)-x(1)).*cos(x(2)-x(1)).*x(3).*x(3)-b*c*sin(x(1)-x(2)).*x(4).*x(4)+e*c*sin(x(1))-h*b*sin(x(2)).*cos(x(2)-x(1))+km*c*u)/(a*c-b*b.*cos(x(1)-x(2)).*cos(x(2)-x(1))); 
xdot(4)=((d*b*cos(x(1)-x(2))).*x(3)-(a*f).*x(4)-a*b*sin(x(2)-x(1)).*x(3).*x(3)+b*b*sin(x(1)-x(2)).*cos(x(1)-x(2)).*x(4).*x(4)-e*b*sin(x(1)).*cos(x(1)-x(2))+a*h*sin(x(2))-b*cos(x(1)-x(2))*km*u)/(a*c-b*b.*cos(x(1)-x(2)).*cos(x(2)-x(1))); % differential equations to describe the nonlinear model
xdot(5)=-K*[xdot(1);xdot(2);xdot(3);xdot(4)]; % derivative of control variable
end
end