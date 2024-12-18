% Close all;  
t0=0;tf=3;%simulation time  
K=[  -60.6992 -316.1745  -30.0745  -33.7643];% State feedback gain matrix obtained according to the desired pole; 
r= [-0.1;0.05;0;0];%initial value of x1,x2,x3,x4 
u0=-K*r;  
x0=[r;u0];%initial value  
[t,x]=ode45('dlfun',[t0,tf],x0);  % solve differential equations  
figure; 
plot(t,x(:,1)*180/pi,'r',t,x(:,2)*180/pi,'b',t,x(:,5),'g'); 
legend('spiral arm angle','the pendulum angle','control value');
