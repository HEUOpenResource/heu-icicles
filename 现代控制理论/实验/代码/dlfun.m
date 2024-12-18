
function xdot=dlfun(t,x);
m1=0.200; m2=0.052; L1=0.10; L2=0.12; r1=0.20; km=0.0236; ke=0.2865; 
g=9.8; J1=0.004; J2=0.001; f1=0.01; f2=0.001; % value of parameter 
a=J1+m2*r1*r1; b=m2*r1*L2; c=J2; d=f1+km*ke; e=(m1*L1+m2*r1)*g;  f=f2;  h=m2*L2*g;
K=[ -60.6992 -316.1745  -30.0745  -33.7643]
u=-K*[x(1);x(2);x(3);x(4)]; % control variable 
xdot=zeros(5,1); %derivative of x 
xdot(1)=x(3); 
xdot(2)=x(4); 
xdot(3)=((-d*c).*x(3)+(f*b*cos(x(2)-x(1))).*x(4)+b*b*sin(x(2)-x(1)).*cos(x(2)-x(1)).*x(3).*x(3)-b*c*sin(x(1)-x(2)).*x(4).*x(4)+e*c*sin(x(1))-h*b*sin(x(2)).*cos(x(2)-x(1))+km*c*u)/(a*c-b*b.*cos(x(1)-x(2)).*cos(x(2)-x(1))); 
xdot(4)=((d*b*cos(x(1)-x(2))).*x(3)-(a*f).*x(4)-a*b*sin(x(2)-x(1)).*x(3).*x(3)+b*b*sin(x(1)-x(2)).*cos(x(1)-x(2)).*x(4).*x(4)-e*b*sin(x(1)).*cos(x(1)-x(2))+a*h*sin(x(2))-b*cos(x(1)-x(2))*km*u)/(a*c-b*b.*cos(x(1)-x(2)).*cos(x(2)-x(1))); % differential equations to describe the nonlinear model
xdot(5)=-K*[xdot(1);xdot(2);xdot(3);xdot(4)]; % derivative of control variable